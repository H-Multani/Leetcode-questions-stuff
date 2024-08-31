/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // in eg1
        // logic is 342+465=807
        // can think of this like
        // take starting nodes of both, add, we get 5+2=7, set first node of l1
        // as 7
        // take next node of both, we get 4+6=10, carry forward the digit 1
        // and set value of current node of l1 as 0

        // take next node of both, we get 3+4+1(of carry)=8,
        // set value of current node of l1 as 8

        // in the end, return start if list l1 as ans

        // take pointers of li and l2
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        // get length of both lists
        int len1 = 0;
        int len2 = 0;

        while (head1 != nullptr) {
            len1++;
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            len2++;
            head2 = head2->next;
        }

        // we make changes to the list that has the bigger length, since we will
        // return that list
        // we do this since the sum of a 4 digit no and a 2 digit no is a 4
        // digit no, or maybe a 5 digit based on carry, point is its the larger
        // number

        // reset head1 to l1 ka head and head2 to l2 ka head
        head1 = l1;
        head2 = l2;

        cout << len1 << " " << len2 << endl;
        int carry = 0;
        // initialize carry to 0

        if (len1 == len2) {
            // update l1 only, and in end return l1

            // keep l1 ka last node to some pointer, this will help in the edge
            // case if theres carry left after adding the 2 values, since its
            // possible for two 3 digit values to have a 4 digit sum
            ListNode* temp = l1;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // so now temp is pointing to last node of l1

            // loop until reach end of list
            while (head1 != nullptr) {
                // add the digits of both, and also add carry if present
                int sum = (head1->val) + (head2->val) + carry;

                int remainder = sum % 10;
                carry = sum / 10;

                // set the remainder as l1 ka current node ka new new value
                // we update values of list l1, bcoz its better than making
                // another list also in the end we can return l1 as ans since l1
                // and l2 of same length
                head1->val = remainder;

                // move both the pointers forward
                head1 = head1->next;
                head2 = head2->next;
            }
            // if in the end after this loop, we have carry remaining, means the
            // sum of the 3 digit values was a 4 digit value. we add that to a
            // new node, so if carry=1 we add a new node and set its value to 1
            // then we connect the node to end of l1
            if (carry == 1) {
                // create new node
                ListNode* ending = new ListNode(1);
                // ending ka next is nullptr

                // connect l1 ke last node to new ending node,
                // ie temp ka next=ending
                temp->next = ending;
            }

            // now we have accounted for all possible cases here, return l1,
            // since usko hi update kar rahe the since the start
            return l1;
        } else if (len1 > len2) {
            // means l1 is longer than l2
            // in this case also, we update values in l1, and loop till we reach
            // end of the smaller list , end of smaller list bcoz, sum utne me
            // hi hoga, like 12345+164=12491, notice that the sum of digits
            // happend only till end of smaller list,this is why we loop till
            // the smaller list ends after that, if carry is present, we loop
            // until we reach end of 1st list, and accomodate each of the carry

            // in the end we return list l1, bcoz we updated in it, also its the
            // bigger list

            // so overall

            // in case when sum of the 4 digit and 3 digit no is a 5 digit no
            ListNode* temp = l1;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // so now temp is pointing to last node of l1


            // loop until reach end of smaller list
            while (head2 != nullptr) {
                // add the digits of both, and also add carry if present
                int sum = (head1->val) + (head2->val) + carry;

                int remainder = sum % 10;
                carry = sum / 10;

                // set the remainder as l1 ka current node ka new new value
                // we update values of list l1, bcoz its better than making
                // another list also in the end we can return l1 as ans since l1
                // and l2 of same length
                head1->val = remainder;

                // move both the pointers forward
                head1 = head1->next;
                head2 = head2->next;
            }

            // now head2 is at end of list l2, and head1 is at next element of
            // list l1 if carry is 1 remaining,adjust it accd to normal addition
            // rules ie loop thru the rest of the 1st list, adjusting carry all
            // the way

            while (head1 != nullptr) {
                // if carry is 0, it wont affect the value of element any way,
                // dont worry abt it
                int value = (head1->val) + carry;

                int remainder = value % 10;
                carry = value / 10;

                // update the value of current node
                head1->val = remainder;

                // move head1 ahead
                head1 = head1->next;
            }
            // now head1 is at end of list l1
            // if carry still remains=1, means like the sum of the 5 digit value
            // and the 3 digit value became a 6 digit value, like foe eg
            // 99999+123=100122.we add that value to a
            // new node, so if carry=1 we add a new node and set its value to 1
            // then we connect the node to end of l1
            if (carry == 1) {
                // create new node
                ListNode* ending = new ListNode(1);
                // ending ka next is nullptr

                // connect l1 ke last node to new ending node,
                // ie temp ka next=ending
                temp->next = ending;
            }

            // now we have accounted for all possible cases here, return l1, since uske nodes ko hi manipulate kiya hai
            return l1;
        }
        else{
            // in this case l2 is longer than l1
            // do everything same as above case(l1 longer than l2) but reverse l1 things with l2 things

            // we basically return l2 in this case(since its longer), baaki ka logic upar waale case me hai, mai rewrite nahi karunga yaha


            ListNode* temp = l2;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            


           
            while (head1 != nullptr) {
               
                int sum = (head1->val) + (head2->val) + carry;

                int remainder = sum % 10;
                carry = sum / 10;

                head2->val = remainder;

                
                head1 = head1->next;
                head2 = head2->next;
            }

            while (head2 != nullptr) {
                int value = (head2->val) + carry;

                int remainder = value % 10;
                carry = value / 10;

               
                head2->val = remainder;

            
                head2 = head2->next;
            }

            if (carry == 1) {
                ListNode* ending = new ListNode(1);

                
                temp->next = ending;
            }

            return l2;
        }
    }
};