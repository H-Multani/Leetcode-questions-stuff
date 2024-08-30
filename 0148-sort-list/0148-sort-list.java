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
    // used to merge the 2 sorted half lists
    //lc 21
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head=new ListNode(-1);
        ListNode curr=head;
        
        //common loop
        while(list1!=null && list2!=null){
            if(list1.val<=list2.val){
                curr.next=list1;
                list1=list1.next;
                curr=curr.next;
            }
            else{
                curr.next=list2;
                list2=list2.next;
                curr=curr.next;
            }
        }

        // common loop end
        // curr is at end of the empty list
        if(list1!=null){
            // list 1 me elements hai abhi
            curr.next=list1;
        }
        if(list2!=null){
            // list 2 me elements baaki hai
            curr.next=list2;
        }

        return head.next;

    }

    // funcn that ginds us the middle element
    // lc 876
    public ListNode middleNode(ListNode head) {
        if(head==null || head.next==null) return head;

        ListNode slow=head;
        ListNode fast=head.next;

        while(fast!=null && fast.next!=null){
            // move slow 1 step
            slow=slow.next;
            // move fast 2 steps
            fast=fast.next.next;
        }

        return slow;

    }

    public ListNode mergesort(ListNode head){
        if(head==null || head.next==null) return head;

        // first find midddle node
        ListNode middle=middleNode(head);
        // ab ek node aage wali list ke liye banao

        // left list starts at head

        // right side list starts at right(ye name hai node ka)
        ListNode right=middle.next;

        // break the list from middle
        middle.next=null;

        // now we have 2 lists, one starts at head, other starts at right
        // now merge the 2 lists

        // left wala sorted part
        ListNode leftsorted= mergesort(head);
        // right wala sorted part
        ListNode rightsorted= mergesort(right);

        // now we have divided the whole list, now we merge the list
        // using the merge 2 list funcn
        ListNode overall_list=mergeTwoLists(leftsorted,rightsorted);
        return overall_list;
    }

    public ListNode sortList(ListNode head) {
        // basic approach is 
        // merge sort lagao
        // break the list from mid point
        // keep breaking
        // then merge left and right sorted half
        
        ListNode ans=mergesort(head);

        return ans;

    }
}