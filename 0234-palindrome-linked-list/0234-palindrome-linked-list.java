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
    public boolean isPalindrome(ListNode head) {
        // push all elements to stack
        Stack<Integer> st=new Stack<>();
        ListNode curr=head;
        while(curr!=null){
            st.push(curr.val);
            curr=curr.next;
        }

        curr=head;
        while(curr!=null){
            if(curr.val!=st.peek()) return false;

            // pop frm stack
            st.pop();
            // move curr ahead
            curr=curr.next;
        }

        return true;
    }
}