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
    int ans;
    int solve(TreeNode* root) {
        // base case
        if (root == nullptr)
            return 0;

        // hypothesis
        // left and right side se maxm depth nikal lo
        int l = solve(root->left);
        int r = solve(root->right);

        // induction
        // temp ans banao, this temp is ans for when current node is part of
        // ans, means yaha se overall ans nai ban raha hai, lekin ye node ka
        // ans, actual wale ans wale node ke left ya right side par hai
        int temp = max(l, r) + 1;
        // toh agar left se bada ans milega toh vo le lenge, or right se ans le
        // lenge, +1 is to count current node
        // then ye apan return kar denge as ans to subproblem

        // ab just incase ye wala node me actual ans mile, nikal lo

        // if current node is actual node jaha ka left and right se best ans
        // aayega toh overall diameter will be left wale nodes+right wale nodes
        // +current wala node

        // ie l+r+1

        // that ya temp wala could be ans for aane wali sub problem

        // maxm ko update kardo aur kya
        int tempans=max(temp,l+r+1);

        // ab ye current wala tempans could be best overall ans we have found, update ans
        ans=max(tempans,ans);

        // ab temp return krdo, since temp stores the ans if current node is part of bigger subproblem
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;

        solve(root);

        return ans-1;
    }
};