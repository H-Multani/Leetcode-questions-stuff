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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // simple approach(shivansh btaya)
        // level order traversal kar lo
        // har level ke nodes nikal kar unka sum kar do, that will be the sum of
        // this level, saare ek array ya pq me push kar do, and in the end k th
        // largest value return kar do

        vector<long long> sums;

        // BFS ke liye queue bana do and root push kr do
        queue<TreeNode*> q;
        q.push(root);

        // bfs chala do
        while (!q.empty()) {
            // kitne nodes hai current level me ?, its q.size()
            int n = q.size();
            // current level ke saare n nodes q me hai abhi, saare nikalo and
            // values ka sum kar do, since we need sum of values in current
            // level
            long long levelsum = 0;

            // basically we have to find sum of next n nodes of the q
            for (int i = 0; i < n; i++) {
                // current wala node nikal lo and include in the sum of this
                // level
                levelsum += q.front()->val;

                // currnode is
                TreeNode* curr = q.front();
                q.pop();
                // ab agar iss node ke children hai, toh un children ko q me
                // push kardo since those children will be needed for traversing
                // in the next level
                // toh basically children nikal kar q me push kar do
                if (curr->left != nullptr) {
                    // means left me child present hai, push to queue
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    // means right me child present hai, push to queue
                    q.push(curr->right);
                }
            }

            // now we have sum of all nodes of current level, send this sum to
            // the vector
            sums.push_back(levelsum);

            // move to the next level , loop continue karo
        }

        // now we have the sums of all levels in vector, iss vector ka k th
        // largest sum nikalo

        sort(sums.begin(), sums.end());

        // ab edge case, what if k levels the hi nai, in such case koi k th
        // largest nai hoga, in such case return -1
        // the no of levels is sums.size(), since har level ka alag alag sum
        // push kiye hai sums array me
        if(sums.size()<k) return -1;

        return sums[sums.size()-k];
    }
};