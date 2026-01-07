/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long ttl;
    long long ans;

    int mod = 1e9 + 7;
    int dfs1(TreeNode* root) {
        // agar node pr hai toh value bhej do bass
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        // left aur right side se total lao
        long long leftsum = 0;
        if (root->left != nullptr)
            leftsum += dfs1(root->left);
        long long rightsum = 0;
        if (root->right != nullptr)
            rightsum += dfs1(root->right);

        // ab iss sum me current ka value add kardo and return kardo
        return ((root->val) + leftsum + rightsum) % mod;
    }

    int dfs2(TreeNode* root) {

        // cout<<"at root "<<root->val<<endl;

        // agar leaf par aa gaye toh kuch nai hai karne ke liye return kardo
        // yehi se
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        // we here means leaf par nai hai apan bass

        // current node par 2 options hai, ya left wala edge alag kardo and ans
        // bana lo, ya toh right wala edge alag karke ans bana lo

        // left wala edge agar hai toh alag karke ek ans bana lo

        long long leftsum = 0;
        if (root->left != nullptr) {
            // means edge alag kar sakte hai, pehle left subtree ka sum nikal lo
            leftsum = dfs2(root->left);

            // ab ye left subtree ka sum nikal gaya hai, bache hue ka sum is
            // ttl-leftside, ans is (ttl-leftside)*(leftside) agar current wala
            // edge alag kare toh

            // ans will be
            ans = max(ans, (ttl - leftsum) * leftsum);
        }

        // same with right side
        // right wala edge agar hai toh alag karke ek ans bana lo
        long long rtsum = 0;
        if (root->right != nullptr) {
            // means edge alag kar sakte hai, pehle left subtree ka sum nikal lo
            rtsum = dfs2(root->right);

            // ab ye rt subtree ka sum nikal gaya hai, bache hue ka sum is
            // ttl-rtside, ans is (ttl-rtside)*(rtside) agar current wala
            // edge alag kare toh

            // ans will be
            ans = max(ans, (ttl - rtsum) * rtsum);
            // yah mod nai since end me ans bhejne se pehle karna mod
        }

        // left right me explore bhi karlo ab
        // if (root->left != nullptr)
        //     dfs2(root->left);
        // if (root->right != nullptr)
        //     dfs2(root->right);

        // iss exploration ka need nai hai, since dfs2 funcn call pehle hi hora
        // hai upar jab leftsum and rtsum nikal rhe hai

        // cout<<"returning from root "<<root->val<<endl;

        // ans kar hi diya hoga update, return kardo bss yaha se, sum return
        // karna dfs1() wale try ka
        return ((root->val) + leftsum + rtsum) % mod;
    }

    int maxProduct(TreeNode* root) {
        // pehle toh ek DFS chal lo ttl nikalne ke liye
        ttl = dfs1(root);
        ans = 0;

        // ab dfs2 chala do har edge ke liye, lag toh nai rha ki TLE aana
        // chahiye
        dfs2(root);

        // WA ka dikkat samaj aa gaya, discussion me kaafi logo ko aaya tha ye

        // baar baar mod karne ka need nai hai, bass return karne se pehle mod
        // kar dena

        // TLE dera hai, pata hai kyu, since DFS1 baar baar call kar rhe hai toh
        // merge maar do dfs1 ka logic dfs2 me

        // kuch zyada nai bass dfs1 wala logic dfs2 me add kardo(jo pehle logic
        // hai uske sath hi)

        // isse ye hoga ki sum nikalte jayenge, sath sath hi exploration bhi
        // hoga ki agar ye wali edge nikal le toh kya ans banega, since agar
        // rtsum nikal rha mai means right side me edge hoga hi, also rtsum se
        // right wale area ka sum already aa hi raha hai, toh agar edge remove
        // karte toh vaise bhi rtsum nikalna padta, toh ab aa gaya rtsum toh ans
        // bhi dekh lo kya pata yaha ans best aa sakta

        return ans % mod;
    }
};