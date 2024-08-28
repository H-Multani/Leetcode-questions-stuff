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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head=new ListNode(-1);
        ListNode curr=head;
        while(list1!=null && list2!=null){
            if(list1.val<=list2.val){
                // list 1 wala element chhota hai
                // add this list1 wala element to our ans list
                curr.next=list1;
                // list 1 ko aage badhao
                list1=list1.next;
                //curr ko aage badhao
                curr=curr.next;
            }
            else{
                // list 2 wala element chhota hai
                // add this list2 wala element to our ans list
                curr.next=list2;
                // list 2 ko aage badhao
                list2=list2.next;
                //curr ko aage badhao
                curr=curr.next;

            }
        }
        // we are here means, list 1 and list 2 me se 1 list end ho chuki hai
        // curr is at last element of the list that ended

        if(list1!=null){
            // list 1 is not ended yet
            curr.next=list1;
        }

        if(list2!=null){
            // list 2 end nai hui hai
            curr.next=list2;
        }

        // return head;
        return head.next;

    }
}