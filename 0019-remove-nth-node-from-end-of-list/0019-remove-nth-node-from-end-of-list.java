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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev=new ListNode(-1);
        prev.next=head;
        ListNode curr=head;
        int cnt=0;
        ListNode temp=head;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }

        int reqd=cnt-n+1;// 1 based indexing ka hai ye
        cnt=1;
        while(curr!=null){
            if(cnt==reqd){
                if(curr==head){
                    // head ko aage badhao
                    head=head.next;
                    // delete the curr element
                    // prev.next=head;
                    prev.next=curr.next;

                    // curr ko aage badhao
                    curr=curr.next;
                }
                else{
                    prev.next=curr.next;
                    curr=curr.next;
                }
            }
            else{
                // simple curr and prev ko aage badhao
                curr=curr.next;
                prev=prev.next;
            }

            cnt++;
        }

        return head;

    }
}