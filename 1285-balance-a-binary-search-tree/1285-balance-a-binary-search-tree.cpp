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
    vector<int> vals;

    TreeNode* solve(int l,int r){
        // base case
        if(l>r) return nullptr;

        // agar l and r is valid then mid nikalo
        int mid=l+(r-l)/2;

        cout<<"mid is "<<mid<<" "<<vals[mid]<<endl;

        // ye element ka node banao ek
        TreeNode* node=new TreeNode(vals[mid]);

        // ab left chale jao l,mid-1 leke, and tree ka left wala pointer bhejna
        node->left=solve(l,mid-1);
        // ab right chale jao mid+1,r leke, and tree ka right wala pointer bhejna
        node->right=solve(mid+1,r);

        return node;
    }
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return;

        // inorder means left root right

        // go left
        traverse(root->left);
        // root store karlo
        vals.push_back(root->val);
        // go right
        traverse(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        // same tree ko balance karne ka need nai hai, shanti se sorted array
        // bana lo ek, fir uss array ke elements se new tree bana lo

        // tree already order me store karta toh inorder traveral se elements
        // order me hi store karlo

        vals.clear();

        traverse(root);

        int n=vals.size();

        // ab koi random ass tareeke se nai construct kar sakte tree ko since we
        // need balanced tree, for arrayr[1,2,3,4] agar apan tree me 1 se
        // elements insert karte gaye toh unbalanced tree banega pakka , toh
        // usse bachne ke liye binary search type se bharenge apan , essentially
        // what we will do is ek insert funcn likh dunga mai, fir firstly mai
        // insert karunga mid wala element, fir insert karunga left wala element
        // and explore, then insert right wala element and explore, isse
        // elements will be inserted in order and this way mid wala element will
        // become the root of new tree and left and right me elements add hote
        // jaenge

        TreeNode* ans=new TreeNode();

        // ans treenode me banate jana hai

        return solve(0,n-1);
    }
};