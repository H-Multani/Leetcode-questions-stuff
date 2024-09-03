/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static boolean ans;
    public static int solve(TreeNode root, int currsum, int target){
        // base case
        if(ans) return -1;
        // if(ans) return Integer.MIN_VALUE;
        if(root==null) return -1;

        // current element ko le lenge
        currsum+=root.val;

        // go left
        int left=solve(root.left,currsum,target);
        // go right
        int right=solve(root.right,currsum,target);

        // operation
        if(left==-1 && right==-1){
            // we are at leay node
            if(currsum==target){
                // path sum ml chuka hai
                ans=true;
            }
        }
        return Integer.MAX_VALUE;
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        ans=false;
        int temp=solve(root, 0,targetSum);

        return ans;
    }
}