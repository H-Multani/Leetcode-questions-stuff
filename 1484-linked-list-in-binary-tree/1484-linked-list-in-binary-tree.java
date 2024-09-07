/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    public static boolean traverse(TreeNode root, ListNode head) {
        if(head==null) return true;
        if(root==null) return false;

        // kya current wala ll ke head ke barabar hai?, nai hai toh return false
        if(root.val!=head.val) return false;
        // agar hai toh next elements(of linked list) k liye search in left and right subtree
        return traverse(root.left,head.next) || traverse(root.right,head.next);
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root==null) return false;
        // agar yehi se mil gaya toh return true
        if(traverse(root, head)) return true;
        // else check in right and left subtree
        return isSubPath(head,root.left) ||isSubPath(head,root.right) ;

    }
}