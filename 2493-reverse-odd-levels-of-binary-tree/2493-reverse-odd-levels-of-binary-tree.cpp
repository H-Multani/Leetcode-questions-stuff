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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // bfs wala approach

        int lvl = 0;
        // to keep track of level odd hai ki even hai

        queue<TreeNode*> q;
        q.push(root);

        // bfs chala do ab
        while (!q.empty()) {
            // current level par kitne nodes hai
            int n = q.size();

            // itne n nodes nikal kar store kardo ek vector me
            vector<TreeNode*> nodes;

            // ab ek ek node q se nikal kar daal do nodes vector me
            while (n--) {
                // current node ko daal do vector me
                nodes.push_back(q.front());
                auto currnode = q.front();
                // q se nikal do iss node ko ab
                q.pop();
                // ab iss node ke neighbours par jao and unn neighbours ko push
                // kardo q me

                // go left side
                if (currnode->left != nullptr) {
                    q.push(currnode->left);
                }
                // go right side
                if (currnode->right != nullptr) {
                    q.push(currnode->right);
                }
            }

            // ab level konsa hai

            // agar odd level hai toh do the following
            if (lvl % 2 == 1) {
                // means odd level hai,
                // saare nodes ka values swap kardo, front to back
                auto i = 0;
                auto j = nodes.size() - 1;

                while (i < j) {
                    // swap i th and j th wale nodes ka value, by doing this we
                    // are effectively swapping the nodes at this level, yehi
                    // karne bola hai question me
                    long long temp=nodes[i]->val;
                    nodes[i]->val=nodes[j]->val;
                    nodes[j]->val=temp;
                    i++;
                    j--;
                }

                // now all nodes at this level have been swapped,move onto the next level 
            }

            lvl++;
        }

        return root;
    }
};