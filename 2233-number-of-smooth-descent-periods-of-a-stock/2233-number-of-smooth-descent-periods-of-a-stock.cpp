class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // count lelo ek which will count ki kitne elements are in smooth
        // descent consecutively

        long long cnt = 1;

        // start cnt with 1 since minm 1 element toh rahega hi always in smooth
        // descent(based on the egs given)

        // iterate karo compare current and peeche wala banda
        long long ans = 0;

        for (int i = 1; i < prices.size(); i++) {
            if ((prices[i] - prices[i - 1]) == -1) {
                // we here means ki current element is in smooth descent with
                // peeche wala element, toh dono consecutive descent me hai toh
                // seedha count badha do since we have one more element in
                // smooth descent now
                cnt++;
            } else {
                // we here means yaha se smooth descent band ho gai hai

                // toh jitne bhi elements smooth descent me mile usme formula
                // laga kar ans me add kardo

                // if cnt=4 means 4 elements were in smooth descent toh we would
                // have 10 smooth descent periods like as in for [7.6.5.4] we
                // have (size 1)[7],[6],[5],[4], (size 2)[7,6],[6,5],[5,4],
                // (size 3)[7,6,5],[6,5,4], (size 4)[7,6,5,4] which is 10 ways
                // we can choose

                // toh for n we have n*(n+1)/2 jitne descent periods count karlo
                // ans me daal do
                ans = ans + ((cnt * (cnt + 1)) / 2);

                // count kar liye purane wale, ab new element se new count chalu
                // hoga from 2
                cnt = 1;
                // starts again from 1 since 1 element will always be in smooth
                // descent , and the element being counted right now is current
                // element prices[i]
                cout<<"here "<<i<<endl;
            }
        }

        // ho sakta hai ki end me cnt ka value bada ho gaya ho lekin abhi tak
        // count na kiya ho last elements wale periods ko, toh one last time
        // count karlo
        ans += ((cnt * (cnt + 1)) / 2);

        return ans;
    }
};