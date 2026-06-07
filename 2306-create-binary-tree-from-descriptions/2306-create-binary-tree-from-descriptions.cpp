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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // constraints kam hai toh vector bana lena jisme addresses store
        // karenge nodes ke

        // root ke liye alag iterate kar lenge, jo root ek baari bhi child me
        // nai aaya vo hoga main root

        // ek map rakh lo which will store address of nodes
        unordered_map<int, TreeNode*> mpp;
        // ye store karega ki konse integer value wale node kaha hai

        // iterate karo aur add karte jao mast

        for (auto it : descriptions) {
            int root = it[0];
            int child = it[1];
            bool left = it[2];

            if (mpp.find(root) == mpp.end()) {
                // means root wala node bhi nahi bana hai

                // root bana do
                TreeNode* parent = new TreeNode(root);
                mpp[root] = parent;
            }

            // ab child ka node bana hai already ki nai check karo
            if (mpp.find(child) == mpp.end()) {
                // means child ka node bhi nai bana hai bana do
                TreeNode* c1 = new TreeNode(child);
                mpp[child] = c1;
            }

            // we are here means saare nodes bane hue hai connection kardo mast
            // bas

            if (left) {
                // means current ke left me daal dena child ko

                mpp[root]->left = mpp[child];
            } else {
                // right me daal do
                mpp[root]->right = mpp[child];
            }
        }

        // now iterate through the array once again, find node jo kisi ka child
        // nai hai

        unordered_set<int> ischild;

        for (auto it : descriptions) {
            ischild.insert(it[1]);
        }

        for (auto it : descriptions) {

            if (ischild.find(it[0]) == ischild.end()) {
                // means current wala node kisi ka child nai hai this is the
                // ans, return it
                return mpp[it[0]];
            }
        }

        // we here means kuch node nai nikal, null bhej do
        return nullptr;
    }
};