class KthLargest {
    vector<int> newnums;
    int knew;
    // stores smallest at top, used this since we need k th largest, and k th
    // largest will be smaller than actual largest,so fill the pq upto k values,
    // so that when only k values are present in pq, the k th largest off
    // array(which will be smallest of all the k values in the pq) will be at
    // the top, so that we can easily access it

    // basically apan k values daalenge bas pq me, toh smallest will be at top
    // and largest at bottom and since sab sorted rehta hai, toh k th kargest
    // will be at the top, the k th largest array me hoga lekin ye top wali
    // value se bade k-1 aur values rahenge(jo isse neeche rahenge pq me, so
    // that current value top par ho)
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        // store the values in private variables
        newnums = nums;
        knew = k;

        // nai chal raha tha pichla wala, pq yahi bana lo, so that saare
        // elements object banate time hi pq me add ho jaaye, phir next funcn me
        // simply update kar dena

        // push values to a pq

        for (auto it : newnums) {
            if (pq.size() < knew)
                pq.push(it);
            else {
                // size=k hai
                // curr top se compare karo
                // if bigger, pop top element, and push current element in its
                // place, since we need the k th maxm values, and i we find
                // current top ke badi value hai, need to push it to the pq,
                // since pq stores k largest values of the array, out of which
                // the top value will be the k th largest of the array(and
                // smallest among the k values stored in the pq)
                if (pq.top() < it) {
                    // pop current top
                    pq.pop();
                    // add new element
                    pq.push(it);
                }
            }
        }
        // now k th biggest element will be at the top of the pq
    }

    int add(int val) {
        // use the private variables to access the vector and add the new val
        newnums.push_back(val);

        // compare val with top element of pq
        if (!pq.empty() && pq.size() == knew && val > pq.top()) {
            // if pq is not empty and pq me k elements pehle se bhare hai then
            // only chk if val>pq.top to update
            pq.pop();
            pq.push(val);
        } else if (pq.empty() || pq.size() < knew) {
            // agar empty hai pq ya pq me k elements se kam hai toh push kar do value ko
            // since agar pq me elements hi nai rahenge toh return kya karenge apan
            pq.push(val);
        }
        // return val;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */