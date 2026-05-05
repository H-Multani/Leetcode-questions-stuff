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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge case,
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return head;

        if (k == 0)
            return head;

        // the simple way is rotating banao pehle, ie last node ko head se jod
        // do, then k spaces aage chalo, and peeche wala connection tod do

        // make the list rotating
        ListNode* temp = head;

        int n = 1;

        while (temp->next != nullptr) {
            n++;
            temp = temp->next;
        }

        // ab edge case ye ban sakta ki maan lo list me 5 nodes hai lekin
        // k=2000000 steps chalne, toh itne chalne ka need nai hai, we just need
        // to run k%n steps, toh update k, so that TLE na aaye
        k = k % n;

        // ye rotation ke baad agar k==0 aa jaye toh no rotation needed, return head yehi se
        if(k==0) return head;

        // ab temp ke aage head ko jodd do, toh list becomes circular
        temp->next = head;

        // ab head se restart karo current and prev leke, k steps chalo

        // toh bhi prev temp par hoga, and curr will be on head
        ListNode* prev = temp;
        ListNode* curr = head;

        // ab aage chalte jao jab tak k steps na ho jaaye

        // ok toh yaha game ye hai ki k steps chal rahe toh wrong aa raha hai,
        // since k node travel karne par gaalt jagah pahuch rahe hai,

        // toh ye notice kiya maine ki n-k node travel kare apan only, tab sahi
        // jagah pahuch jaenge, toh yehi logic update kar dete hai k ki value
        // me, ie, instead of travelling k nodes, we travel n-k nodes, toh k ka
        // value update kar diya
        k = n - k;
        while (k > 0) {
            // prev ko aage badhao, curr ko aage badhao
            prev = prev->next;
            curr = curr->next;
            k--;
        }

        // now k steps later we are at new starting point, prev se curr ka join
        // tod do, so that the circular list becomes normal again
        prev->next = nullptr;

        // ab curr se start karke apni new rotated list chalegi return curr
        return curr;
    }
};