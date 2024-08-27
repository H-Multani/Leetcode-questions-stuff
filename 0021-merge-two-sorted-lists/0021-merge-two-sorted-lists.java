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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // the new list
        ListNode ans = new ListNode(-1);
        ListNode newlist = ans;

        // iterate over both the lists an push elements
        ListNode firstlist = list1;
        ListNode secondlist = list2;
        while (firstlist != null && secondlist != null) {
            // if firstlist ka element chhota hai, toh usko connect karo pehle
            if (firstlist.val <= secondlist.val) {
                // new list ka next set to 1st ka node
                newlist.next = firstlist;
                // firstlist ko aage badha do
                firstlist = firstlist.next;
                // newlist ko bhi aage badha ho
                newlist = newlist.next;
            } else {
                // new list ka next set to 2nd ka node
                newlist.next = secondlist;
                // secondlist ko aage badha do
                secondlist = secondlist.next;
                // newlist ko bhi aage badha ho
                newlist = newlist.next;
            }
        }

        // we here means one of the lists ended and newlist is at last node of the ended
        // list now
        // set newlist ka next to the the list that hasnt ended yet

        // this is done only once since ek list end ho chuki hai, and connect karne ke
        // bad jo list hai vo apne aap order me hogi since given is ki lists are
        // themselves in sorted order
        if(firstlist!=null){
            // set newlist to firstlist ka node
            newlist.next=firstlist;
        }
        if(secondlist!=null){
            // set newlist to secondlist ka node
            newlist.next=secondlist;
        }

        return ans.next;
    }
}