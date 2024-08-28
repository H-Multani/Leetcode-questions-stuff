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
    public ListNode deleteMiddle(ListNode head) {
        if(head==null) return head;
        if(head.next==null) return null;
        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=head;

        while(fast!=null && fast.next!=null){
            prev=slow;
            // slow ko aage badhao
            slow=slow.next;
            // fast ko aage badhao
            fast=fast.next.next;
        }

        // mid element mil gaya
        // mid element is at slow 
        // delete slow node
        prev.next=slow.next;
        return head;


    }
}