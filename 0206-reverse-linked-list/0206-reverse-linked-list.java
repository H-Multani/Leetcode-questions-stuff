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
        ListNode ans=null;
        ListNode curr=head;

        while(head!=null){
            // head ko aage badhao
            head=head.next;
            // curr node ko ans par bhejo
            // set curr ka next to ans
            curr.next=ans;
            // ans ko curr par bhejo
            ans=curr;
            // curr ko head par bhejo
            curr=head;
        }

        return ans;

    }
}