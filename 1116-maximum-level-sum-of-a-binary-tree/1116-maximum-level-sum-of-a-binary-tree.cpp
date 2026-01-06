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
    int maxLevelSum(TreeNode* root) {
        // level ka sum nikal leo, and level store kara kar rakh lena
        int lvlsum = INT_MIN;
        int ans = -1;

        // simple BFS chal jaega yaha
        queue<TreeNode*> q;
        // isme first bande ko dall do
        q.push(root);

        // BFS wala loop chala do

        // level count rakh lo ki currently iss level par hai starting from 1
        int level = 1;
        while (!q.empty()) {
            // kitne elements hai current level me
            int n = q.size();

            // saare n elements ka sum nikal kar store karlo
            int ttl = 0;
            while (n--) {
                // top nikal lo
                TreeNode* curr = q.front();

                // nikal do q se
                q.pop();

                // add kardo current level ke total me
                ttl += curr->val;

                // iske children ko q me daal do

                // agar child null nai hai toh daal do
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            // current level ke saare bande nikal liye, agar maxm update hora
            // hai iss level par toh ans wala level bhi update kar dena, isse
            // pata chalega ki konse level par hai maximum, also agar same maxm
            // jitna sum chahiye toh nai karna update since we need smallest
            // level
            if (lvlsum < ttl) {
                lvlsum = ttl;
                ans = level;
            }

            // level increase karlo since agle level par jaa rahe hai
            level++;
        }

        return ans;
    }
};