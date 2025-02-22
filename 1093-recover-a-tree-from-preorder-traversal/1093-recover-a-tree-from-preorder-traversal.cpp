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
    int n;

    TreeNode* solve(string& s, int& i, int depth) {
        if (i >= n)
            return nullptr;

        int j = i;

        // dash count krlo
        while (j < n && s[j] == '-') {
            j++;
        }

        // dash cnt=j-i;

        int dash = j - i;

        if (dash != depth) {
            // means we have come to the wrong depth path, vapas jao yaha se
            return nullptr;
        }

        i += dash;
        int num=0;
        // ab number banao
        while (i < n && isdigit(s[i])) {
            num = (num * 10) + (s[i] - '0');
            i++;
        }

        // jo new number banaya hai node bana do uska
        TreeNode* root = new TreeNode(num);

        // recursion leap of faith
        // left me ghus jao, apne aap recursion kaam karega

        // depth+1 since aage jayenge toh depth+1 need hoga just below ke liye
        root->left = solve(s, i, depth + 1);

        // similarly for right, i is passed by reference, toh left me saare
        // changes krne ke baad hi i right wale side aayega
        root->right = solve(s, i, depth + 1);


        // ab kuch nai krne ke liye, left and rt explore kr liye hai, return krdo root ko
        return root;
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();

        int i = 0, depth = 0;

        return solve(traversal, i, depth);
    }
};