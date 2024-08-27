/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        // next node ka value saved in current node ka value
        node.val=(node.next).val;
        // remove aage wala node
        node.next=(node.next).next;
    }
}