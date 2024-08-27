/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // if starting from null(ie list is empty) return head since koi duplicates hai hi nai
        if(head==null) return head;

        ListNode curr = head.next;
        ListNode prev = head;
        // start from curr at next element and prev at head since head wala element ke
        // aage agar duplicate hua toh remove akr denge aage wale ko, we wont remove the
        // head
        // loop while current not reached end
        while (curr != null) {
            // curr!=null since curr aur prev wale ko compare karenge, agar same value hai,
            // remove current node

            // if curr and prev have same value, remove prev wala node
            if (curr.val == prev.val) {
                // means duplicate hai, remove current wala node
                // curr ko aage badhao
                curr = curr.next;
                // now curr ahead of the node to be deleted and prev is behind node to be
                // deleted
                // set prev ke next to curr, so that it skips the beech wala node(to be deleted)
                prev.next=curr;
                // prev ko aage nai badhana hai, since uske aage ab curr hai like normal intended
                // node successfully deleted
            }
            else{
                // means duplicates nai hai prev and curr me
                // dono ko aage badha do
                curr=curr.next;
                prev=prev.next;
            }
        }

        return head;
    }
}