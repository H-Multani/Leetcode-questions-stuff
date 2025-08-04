class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // basically get largest subarray with 2 distinct values only like
        // 1,2,2,1,2,2-> here theres 6 trees but all are of type 1 or type 2

        // we need to find biggest subarray that satisfies this condition that,
        // only 2 distinct elements should be in the subarray

        // ye logic mereko egs dekh kar samajh aaya, since 2 basket hai, toh
        // apan aise bharenge such that ek saath maxm trees se le paaye, toh 1
        // approach ye tha ki biggest and 2nd biggest freq wala element nikalo,
        // and un dono ke longest continous subarrays nikalo, which posed a
        // problem since 2nd maxm wale multiple elements possible, dikkat

        // phir eg dekha toh laga ki valid wale answers pehle toh subarrays hai,
        // secondly valid waale ans me hamesha 2 elements hai distinct toh vahi
        // se socha iske baare me

        // toh sliding window best for this
        int ans = 0;
        int n = fruits.size();
        int l = 0, r = 0;

        // map lelo which will store ki hamesha 2 distinct elements hi rahe
        unordered_map<int, int> mpp;

        while (r < n) {
            // current bande ko include karo
            mpp[fruits[r]]++;

            // ab agar map.size>2, means subarray me >=3 distnct elements h
            // which is not needed, shrink
            while (l < r && mpp.size() > 2) {
                // shrink the window

                // l wala banda alag karo
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0) {
                    // means freq=0 ho gai h, remove frm map
                    mpp.erase(fruits[l]);
                }

                //  l ko aage badhao
                l++;
            }

            // ab valid wala subarray hoga apne paas, get biggest subarray

            // valid subarray ka size=r-l+1
            ans=max(ans,r-l+1);


            // window aage badhao
            r++;
        }

        return ans;
    }
};