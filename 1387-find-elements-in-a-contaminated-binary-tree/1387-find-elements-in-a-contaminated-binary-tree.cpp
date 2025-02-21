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
class FindElements {
    set<int> st;
    void DFS(TreeNode* root) {

        // ab current banda ko set me daaldo sabse pehle toh
        st.insert(root->val);

        // current bande ki value is x
        int x = root->val;

        // ab current bande ke liye 2 options hai, left and right

        if (root->left != nullptr) {
            // means left me banda hai, left wale bande ki value change krke DFS
            // chala do

            // left wale bande ki new value is accd to question
            root->left->val = (2 * x) + 1;
            // value badalne ke baad left side chale jao, DFS karo
            DFS(root->left);
        }

        if (root->right != nullptr) {
            // means right me banda hai, right wale bande ki value change krke
            // DFS chala do

            // right wale bande ki new value is accd to question
            root->right->val = (2 * x) + 2;
            // value badalne ke baad right side chale jao, DFS karo
            DFS(root->right);
        }

        // ab we are here means saare paths explore karke saare values change
        // kar diye hai, tree vapas non contaminated bana diya hai

        // nothing to do here, return
        return;
    }

public:
    FindElements(TreeNode* root) {
        // simple hi hai , contaminated tree diya hai, DFS chala do, ek ek karke
        // saare values ko rakho as well as saari values ek set me bhi daal do,
        // this will help in second function, nai toh second funcn me bhi DFS
        // chala kar iterate krna padega which may cause TLE

        // current node par 0 daal do pehle toh as required
        root->val = 0;

        // ab DFS chala do, root bhj do
        DFS(root);

        // we here means tree vapas decontaminate ho chuka hai, ie values rakh
        // di hai saari
    }

    bool find(int target) {

        // agar tree me banda hoga toh set me milega pakka, agar nai hai, set
        // me, means value is not in the tree,

        if(st.find(target)==st.end()){
            // means banda nai mila set me, ie banda is not in the tree too, hence return false
            return false;
        }

        // we here means banda mil gaya
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */