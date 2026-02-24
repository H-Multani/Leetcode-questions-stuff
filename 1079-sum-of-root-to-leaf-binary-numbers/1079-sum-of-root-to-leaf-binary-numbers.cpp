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
    int solve(TreeNode* root, int val) {
        // agar leaf par aa gaye hai toh val ko return kardo, since yehi value
        // bani hai abhi tak

        if (root->left == nullptr && root->right == nullptr) {
            // cout << "value bani " << (val<<1)+(root->val) << endl;
            // value update karke bhejna, ie root->val ko consider karke bhejna

            // val is 10010, and current leaf node included is 100101, world of
            // difference, dont forget this
            return (val << 1) + (root->val);
        }

        // we here means beech kisi node par hai

        // toh abhi tak apan ne val value banayi hai, ab current wale node ke
        // value ko daalne ke liye apan iss val ko left shift karenge by 1, then
        // root ka value add kar denge isme

        // for example agar apan neeche aate aate 10011(we here means val=19 hai
        // abhi apne paas) tak aa chuke hai, and current node ka value is 0

        // toh 10011 becomes 100110 which is 38, which is nothing but previous
        // val ka left shift one time

        // agar current node ka value was 1, toh 10011 becomes 100111, which is
        // 39, which is nothing but val ka left shift +1

        // toh overall new value will be (val<<1) +(root->val)

        // yehi logic bana denge, and agar aage kuch nodes possible hai neeche
        // toh new wala val bhej denge so that isme hi build hoye solution, and
        // end me saare add karke bhej denge final val

        // toh itll be like ki left side SE saare left side se banne wale value
        // ke sum aa rahe hai and right side me same logic

        // toh if we are at 1001 rn and left me jaane me we make 10010 and
        // 100110, toh ye saari values calculate hoke add hoke aayengi apne paas
        // which we return

        int newval = (val << 1) + (root->val);

        // left side se jo bhi strings ke values banke aaye hai store karlo
        int ans1 = 0;
        // right side se jo bhi strings ke values banke aaye hai store karlo
        int ans2 = 0;

        if (root->left != nullptr) {
            ans1 = solve(root->left, newval);
        }
        if (root->right != nullptr) {
            ans2 = solve(root->right, newval);
        }

        // dono ans ko add karke bhej do
        return ans1 + ans2;
    }
    int sumRootToLeaf(TreeNode* root) {

        // logic is simple, tree me chalte jao value banate jao, end me leaf par
        // jab aa jao toh leaf tak me jo value construct hui hogi usko return
        // karte jana, toh upar wale node me right se banne wali saari final
        // strings ke decimal values aayenge, toh right side and left side se
        // aaye answers ko club karke bhej dena

        if (root == nullptr)
            return 0;

        // solve karke bhej do ans
        return solve(root, 0);
    }
};