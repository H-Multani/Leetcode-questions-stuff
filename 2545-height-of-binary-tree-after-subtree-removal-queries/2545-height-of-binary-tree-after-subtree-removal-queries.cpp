/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int level[100001];
    int height[100001];
    int maxlvlheight[100001];
    int secondmaxlvlheight[100001];

public:
    int findheight(TreeNode* root,int currlvl){
        if(root==nullptr) return 0;

        level[root->val]=currlvl;
        height[root->val]=max(findheight(root->left,currlvl+1),findheight(root->right,currlvl+1))+1;

        if(maxlvlheight[currlvl]<height[root->val]){
            secondmaxlvlheight[currlvl]=maxlvlheight[currlvl];
            maxlvlheight[currlvl]=height[root->val];
        }
        else if (secondmaxlvlheight[currlvl]<height[root->val]){
            secondmaxlvlheight[currlvl]=height[root->val];
        }

        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findheight(root,0);

        vector<int> ans;
        for(auto it:queries){
            // current node is 'it'
            // reqd node ka lvl
            int node_ka_lvl=level[it];

            // reqd node ka height
            int node_ki_height;
            if(height[it]==maxlvlheight[node_ka_lvl]){
                node_ki_height=secondmaxlvlheight[node_ka_lvl];
            }
            else{
                node_ki_height=maxlvlheight[node_ka_lvl];
            }


            int currresult=node_ka_lvl+node_ki_height-1;
            ans.push_back(currresult);
        }

        return ans;
    }
};