/**
 * Definition for singly-linked list.
 * class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            // move both ptrs ahead, fast moves 2 steps and slow moves 1 step
            slow = slow.next;
            fast = fast.next.next;

            // in case if slow and fast meet at one position means linked list me cycle
            // present hai, since only in that case fast and slow meet, since fast moves 2
            // steps and slow moves 1 step, if cycle nai hai toh slow and fast kabhi meet
            // hi nai karenge, and agar hai cycle toh kabhi na kabhi meet zaroor karenge,
            // and in case meet kar gaye means cycle present, in such case return true
            if(fast==slow){
                return true;
            }
        }

        // we here means fast end tak pohoch gaya, ie list me cycle nai hai, return false
        return false;
    }
}