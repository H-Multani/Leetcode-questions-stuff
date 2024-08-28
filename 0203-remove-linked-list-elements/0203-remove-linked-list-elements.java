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
    public ListNode removeElements(ListNode head, int val) {
        ListNode slow=head;
        ListNode prev=new ListNode(-1);
        ListNode start=prev;

        // connect prev ke next to head
        prev.next=head;

        while(slow!=null){
            // if curr wala node has value ==val means usko alag karna hai
            if(slow.val==val){
                // remove current node
                prev.next=slow.next;
                // move slow ahead
                slow=slow.next;
            }
            else{
                // means we move forward as normal
                // set prev to current
                prev=slow;
                // move slow ahead
                slow=slow.next;
            }
        }

        return start.next;
    }
}