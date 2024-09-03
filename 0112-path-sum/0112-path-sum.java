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
     public static boolean isfound;
     public static int traverse(TreeNode root, int currsum,int tgtsum){
        if(isfound) return Integer.MIN_VALUE;
        if(root==null) return Integer.MIN_VALUE;

        currsum+=root.val;
        int left=traverse(root.left,currsum,tgtsum);
        int right=traverse(root.right,currsum,tgtsum);

        if(left==Integer.MIN_VALUE && right==Integer.MIN_VALUE){
            // means we are at leaf node, if reached target, return
            if(currsum==tgtsum){
                isfound=true;
            }
        }

        return Integer.MAX_VALUE;

     } 
    public boolean hasPathSum(TreeNode root, int targetSum) {
        isfound=false;
        int ans=traverse(root,0,targetSum);
        return isfound;
    }
}