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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // same as pichla wal potd,(of oct 23), level sum nikal lo pehle toh
        // uske aage mik ka btaya approach hai, step 1 tk banta tha mereko, aage
        // uske mik ka approach hai
        if (root == nullptr)
            return root;
        queue<TreeNode*> q;
        q.push(root);

        // step 1
        // vector bana do that stores level sum
        vector<long long> lvlsum;

        while (!q.empty()) {
            // current level me kitne bande
            int n = q.size();

            // curr level ka sum nikal lo
            long long currlvlsum = 0;
            for (int i = 0; i < n; i++) {
                // current banda of current level is
                TreeNode* curr = q.front();
                q.pop();

                // curr bande ko add kar do sum me of this level
                currlvlsum += curr->val;

                // children ko push krdo q me, so that we can go to aane wale
                // levels
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            // now we have sum of nodes of current level, push to vector
            lvlsum.push_back(currlvlsum);
        }

        for (auto it : lvlsum) {
            cout << it << " ";
        }

        // now q is empty, reuse this q again for second BFS traversal
        // step 2

        // root node ko push krdo q me since we are going to traverse again
        q.push(root);
        // root has no cousins, toh uska value ho jaega 0
        root->val = 0;

        // currently on level
        int currlvl = 1;
        // start frm lvl 1 since lvl 0 pr toh root hai bas, uske aage se jayenge
        // start BFS
        while (!q.empty()) {
            // current lvl me kitne nodes hai
            int n = q.size();
            // basic idea is curr level ke har node ke children par jaake unka
            // value yehi se change kar denga, ie in eg 1, 4 wale node pr khade
            // hoke 1 and 10 wale node ka value badal denge

            for (int i = 0; i < n; i++) {
                // curr banda is
                TreeNode* curr = q.front();
                q.pop();
                // ie currently we are at 5 value wala node(eg 1)

                // iss bande ke children par jana hai apan ko ab, aur children
                // par jaa kar sibling sum nikalna hai(ye mik ka approach hai)
                long long siblingsum = 0;
                if (curr->left != nullptr) {
                    // 4 value wala node ka value add kar diya
                    siblingsum += curr->left->val;
                }
                if (curr->right != nullptr) {
                    // 9 value wala node ka value add kar diya
                    siblingsum += curr->right->val;
                }

                // ab apne paas sibling sum hai, and inn children wale node ka
                // level sum kya hai vo bhi nikal lo

                // this is ttl sum of level 1 ke nodes(keep in mind apan abhi
                // khud level 0 par hai aur level 1 ke nodes ka value change kar
                // rhe hai)
                long long children_lvl_sum;
                // agar left and right nodes hi exist nai karte toh level sum
                // kaha se niklega toh agar left or right nodes exist, then only
                // ye sum nikalo, nai toh error aa jaega lol
                // basically chk kr lo, agar aage wala level exists or not, agar
                // level hi nai hai toh sum nikalna try karoge toh error aa
                // jaega
                if (curr->left != nullptr || curr->right != nullptr)
                    children_lvl_sum = lvlsum[currlvl];

                // ab in children(4 and 9 wale nodes) ke values change karo
                // children nodes ka new value hoga, children level ka ttl sum -
                // (sum of vo node and uske siblings)

                // so if left sibling exists(4 wala node), its new value will be
                if (curr->left != nullptr) {
                    // new value will be uske level ka ttl sum- sublingsum
                    curr->left->val = children_lvl_sum - siblingsum;
                    // ie 4 wale node ka new value= 13(lvlsum)-13(sibling sum)
                }
                // same thing with right sibing
                if (curr->right != nullptr) {
                    // new value will be uske level ka ttl sum- sublingsum
                    curr->right->val = children_lvl_sum - siblingsum;
                    // ie 9 wale node ka new value= 13(lvlsum)-13(sibling sum)
                }

                // ab apan ne values update kar diye hai, in children ko q me
                // push karo, so that aage wale levels par jaa kar changes kar
                // sake
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            // now apan ne saare children nodes ka value change kar diya hai,
            // move onto the next level, also lvl ko aage badha denge, so that
            // lvl sum nikalne ke liye seedha inde pr jaa ske
            currlvl++;
        }

        // now all nodes of tree have been updated, root return kar do
        return root;
    }
};