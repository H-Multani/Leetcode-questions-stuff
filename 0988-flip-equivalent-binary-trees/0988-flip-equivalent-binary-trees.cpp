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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        // base cases
        // dono null pr pohoch gaye, means equivalent hai, return true
        if (r1 == nullptr && r2 == nullptr)
            return true;
        // dono me se ek null pahuch gaya, dusra nai pahucha, means equivalent
        // nai hai, return false
        if (r1 == nullptr || r2 == nullptr)
            return false;

        // dono hi null nai pahuche meanc check karvana padega
        if (r1->val == r2->val) {
            // means dono current root pr toh equivalent hai,
            // aage left and rt subtree me dekhna pdega

            // now 2 options,
            // option 1, left and rt subtree of r1 and r2 are not flipped, ie r1
            // ke left me jo hai same cheez r2 ke left me bhi hai, similarly, r1
            // ke rt me jo hai same cheez r2 k right me bhi hai , in such case
            // ans nikal lo
            bool noflip = flipEquiv(r1->left, r2->left) &&
                          flipEquiv(r1->right, r2->right);
            // if this is true means r1 and r2 ke left and rt subtrees not
            // flipped hai

            // option 2, left and rt subtrees of r1 and r2 are flipped, ie r1 ke
            // left me jo hai same cheez r2 ke right me hai, similarly, r1 ke
            // right me jo hai same cheez r2 ke left me bhi hai,in this case ans
            // nikal lo kya hoga
            bool yesflip = flipEquiv(r1->left, r2->right) &&
                           flipEquiv(r1->right, r2->left);
            // if this is true means r1 and r2 ke left and rt subtrees flipped
            // hai

            // ab dono options me se ek bhi true nikla toh matlab trees
            // equivalent hai, since flip equivalent matlab x and y same ban
            // jaaye after some flips(at different or same levels), in such case
            // return true(question padh lena flip ka definition ke liye )
            if (noflip || yesflip) {
                return true;
            }

            // yaha aaye hai matlab kuch order me flipping nai hui hai, kahi bhi
            // kuch bhi nodes hai, r1 and r2 are 2 totally different trees and
            // are not flip equivalent, in such case return false
            return false;

        } else {
            // means root1 and root2 ka value same nai h, means dono equivalent
            // nai hai, return false
            return false;
        }
    }
};