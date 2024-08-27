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
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode curr=head;
        ListNode nxt=head;
        ListNode ans=null;

        while(nxt!=null){
            // move nxt ahead
            nxt=nxt.next;
            // join curr to ans
            curr.next=ans;
            // move ans ptr back to new node that is at curr
            ans=curr;
            // move curr back to prev list
            curr=nxt;
        }

        return ans;
    }
}