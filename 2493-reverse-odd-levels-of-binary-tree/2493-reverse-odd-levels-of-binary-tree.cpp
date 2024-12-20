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

        // simply bfs chala do, har level ke node ke ptr ek vector me store kara
        // lo, agar current level odd hai toh vector me iterate karke nodes ka
        // value swap karte jao(simple i and j leke swap karte jao bass, then
        // i++,j--)

        // at the end apan ke paas saare swapped nodes honge

        int lvl = 0;
        // to keep track of level, initially we are at lvl 0

        // queue to store pointer to root node
        queue<TreeNode*> q;

        // root bhej do q me
        q.push(root);

        // bfs chala do ab
        while (!q.empty()) {
            // current level par n nodes hai, nikal kar ek vector me daal do
            int n = q.size();

            // itne n nodes nikal kar store kardo ek vector me
            // NOTE: apan nodes nai store kar rhe hai vector me, apan pointer to
            // the node store kar rhe hai, so that values swap karne me problem
            // na jaaye
            vector<TreeNode*> nodes;

            // ab ek ek node q se nikal kar daal do nodes vector me
            while (n--) {
                // current node is
                auto currnode = q.front();
                // current node ko daal do vector me, since this is the node of
                // current level
                nodes.push_back(q.front());

                // q se nikal do iss node ko ab, since vector me daal diya hai
                // aur currnode me bhi stored hai for further use
                q.pop();

                // ab iss currnode node ke neighbours par jao and unn neighbours
                // ko push kardo q me(since ye neighbours next level me milenge)

                // go left side
                if (currnode->left != nullptr) {
                    // ie left me node hai, push kardo q me
                    q.push(currnode->left);
                }
                // go right side
                if (currnode->right != nullptr) {
                    // ie right me node hai, push kardo q me
                    q.push(currnode->right);
                }
            }

            // now we have stored all nodes(node ka ptrs) of current level in
            // the vector

            // ab level konsa hai ye dekho

            // agar odd level hai toh do the following
            if (lvl % 2 == 1) {
                // means odd level hai,
                // saare nodes ka values swap kardo, front to back
                auto i = 0;
                auto j = nodes.size() - 1;

                // ie node 0 ka value swapped with node n-1,
                // ie node 1 ka value swapped with node n-2,
                // ie node 2 ka value swapped with node n-3,...etc

                // by doing this, apan effectively level ko reverse kar rhe hai,
                // jaisa question me bola hai

                while (i < j) {
                    // swap i th and j th wale nodes ka value, by doing this we
                    // are effectively reversing the nodes at this level, yehi
                    // karne bola hai question me
                    long long temp = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = temp;
                    i++;
                    j--;
                }

                // now all nodes at this level have been swapped,move onto the
                // next level
            }

            // next lvl will be lvl+1
            lvl++;
        }

        // we are here means saare odd levels reverse ho chuke hai,ie apna kaam
        // done, return kardo root ko
        return root;
    }
};