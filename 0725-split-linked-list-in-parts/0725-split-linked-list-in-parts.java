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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode temp = head;
        int len = 0;
        while (temp != null) {
            len++;
            temp = temp.next;
        }
        ListNode[] ans = new ListNode[k];
        if (len < k) {
            temp = head;
            int i = 0;
            while (temp != null) {
                head = temp;
                ans[i] = temp;
                temp = temp.next;
                head.next = null;
                i++;
            }
        } else {
            // len>=k
            int nodesperlist=len/k;

            if (len % k == 0) {
                // all parts split equally
                temp = head;
                ListNode prev = temp;
                int i = 1;
                int idx = 0;
                while (temp != null) {
                    if (i % nodesperlist != 0) {
                        prev = temp;
                        temp = temp.next;
                    } else {
                        prev = temp;
                        temp = temp.next;
                        ans[idx] = head;
                        System.out.println(head.val);
                        idx++;
                        prev.next = null;
                        head = temp;
                        // prev=temp;
                        // temp=temp.next;
                    }
                    i++;
                }

            } else {
                System.out.println("here");
                // first len%k parts will get one node extra
                int extra = len % k;
                temp = head;
                ListNode prev = temp;
                int i = 1;
                int idx = 0;
                // first fill the list of extra values
                while (temp != null && extra > 0) {

                    // each list get one extra value
                    System.out.println("here now");
                    if (i % (nodesperlist+1) != 0) {
                        prev = temp;
                        temp = temp.next;
                    } else {
                        prev = temp;
                        temp = temp.next;
                        ans[idx] = head;
                        System.out.println(head.val);
                        idx++;
                        prev.next = null;
                        head = temp;
                        // prev=temp;
                        // temp=temp.next;
                        extra--;
                    }

                    i++;
                }
                System.out.println(" restart frm here " + head.val);

                // now start again frm here and fill the next k values
                temp = head;
                prev = head;
                i=1;// restart index i from 1 starting from the new head
                System.out.println(" idx is " + idx + " i is at " + i);
                while (temp != null) {
                    if (i % nodesperlist != 0) {
                        prev = temp;
                        temp = temp.next;
                    } else {
                        prev = temp;
                        temp = temp.next;
                        ans[idx] = head;
                        System.out.println(head.val);
                        idx++;
                        prev.next = null;
                        head = temp;
                        // prev=temp;
                        // temp=temp.next;
                    }
                    i++;
                }

            }
        }
        return ans;
    }
}