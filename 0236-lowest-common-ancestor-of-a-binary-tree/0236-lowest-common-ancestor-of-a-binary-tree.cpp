/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> forp;
    vector<TreeNode*> forq;
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q,
                  vector<TreeNode*> &curr) {
        if (root == nullptr)
            return;

        // current node agar p ya q ke barabar aa jaaye toh means p and q ka
        // path nikal gaya hai, update kar do bs
        if (root == p) {
            curr.push_back(root);
            vector<TreeNode*> ans=curr;
            forp = ans;
            curr.pop_back();
        }
        if (root == q) {
            curr.push_back(root);
            vector<TreeNode*> ans=curr;
            forq = ans;
            curr.pop_back();
        }

        // current node path me add karo
        curr.push_back(root);
        // aage badho
        // to left
        traverse(root->left, p, q, curr);
        // to right
        traverse(root->right, p, q, curr);
        // ab jo element add kiya tha usko remove kar do, so that ye current banda apne path me aage problem na kare
        curr.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        forq.resize(0);
        forp.resize(0);
        vector<TreeNode*> curr;
        traverse(root, p, q, curr);

        for (auto it : forp) {
            cout << it->val << " ";
        }
        cout << endl;
        for (auto it : forq) {
            cout << it->val << " ";
        }
        cout << endl;

        for (int i = 0; i < min(forp.size(), forq.size()); i++) {
            if (forp[i]->val != forq[i]->val) {
                // means yaha tak path common tha, i-1 th wala common ancestor
                // ho gaya p and q ka
                // return i-1 th node, since that is the last common ancestor
                return forp[i - 1];
            }
        }

        // yaha pahuche means, p and q ka common ancestor passes through p or q,
        // eg 2 dekh lo
        // in such case, return forp(or forq) ka last element(dono me se jo bhi
        // pehle khatam hoga )

        return forp[min(forp.size(),forq.size())-1];
    }
};