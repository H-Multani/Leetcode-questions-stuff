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
            // har index par ek ek node laga do kaafi hai
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

            // har index par kitne nodes aaenge in ans
            // if this value=3 means at each idx in ans, har list me 3 nodes honge thats it
            int nodesperlist = len / k;

            if (len % k == 0) {
                // all parts split equally
                // har index par equally no of nodes dal kar end kar do
                temp = head;
                ListNode prev = temp;
                int i = 1;
                int idx = 0;
                while (temp != null) {
                    if (i % nodesperlist != 0) {
                        // jab tak reqd length ka list nai bane, prev and temp ko age badhao
                        prev = temp;
                        temp = temp.next;
                    } else {
                        // means reqd list length mil gya hai, ek baar age badhao so that prev is at the
                        // end node where we have to break
                        prev = temp;
                        temp = temp.next;

                        // current wala head bhej do as an ans for the current index(idx)
                        ans[idx] = head;
                        System.out.println(head.val);
                        // idx++, we move to next node of ans
                        idx++;
                        // break the list from prev node
                        prev.next = null;
                        // head ko temp pr laa kar new list start karo banana
                        head = temp;
                    }
                    i++;
                }

            } else {
                // first len%k parts will get one node extra(hint1)
                int extra = len % k;
                temp = head;
                ListNode prev = temp;
                int i = 1;
                int idx = 0;
                // first fill the list of extra nodes
                while (temp != null && extra > 0) {

                    // each list gets one extra value
                    // System.out.println("here now");
                    // nodesperlist+1, since har list me ek node extra dena hai yaha
                    if (i % (nodesperlist + 1) != 0) {
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
                        // extra-- since we have now completed one of the total extra wali list, hence
                        // extra--
                        extra--;
                    }

                    i++;
                }
                System.out.println(" restart frm here " + head.val);

                // now start again frm here(current node) and fill the remaining lists with
                // nodesperlist no of nodes only
                // head ko temp pr le aao since we starting again frm base, same with prev
                temp = head;
                prev = head;
                i = 1;// restart index i from 1 since we starting from the new head once again
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
                    }
                    i++;
                }

            }
        }
        return ans;
    }
}