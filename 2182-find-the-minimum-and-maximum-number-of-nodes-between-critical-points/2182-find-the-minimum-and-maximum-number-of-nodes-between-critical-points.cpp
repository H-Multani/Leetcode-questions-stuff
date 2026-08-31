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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // vector me daal do and usme explore karna

        vector<int> nodes;

        while(head!=nullptr){
            nodes.push_back(head->val);
            head=head->next;
        }

        // ab critical points dhundo

        int n=nodes.size();

        vector<int> crit;

        for(int i=1;i<n-1;i++){
            if((nodes[i]>nodes[i-1] && nodes[i]>nodes[i+1]) || (nodes[i]<nodes[i-1] && nodes[i]<nodes[i+1])){
                // daal do critical areas ko
                crit.push_back(i);
            }
        }

        // maxm dist is edges ka distance
        if(crit.size()<2) return {-1,-1};

        // else maxm and minm nikal lo
        int maxm=-1,minm=INT_MAX;
        n=crit.size();
        maxm=max(maxm,crit[n-1]-crit[0]);
        for(int i=1;i<n;i++){
            minm=min(minm,crit[i]-crit[i-1]);
        }

        return {minm,maxm};
    }
};