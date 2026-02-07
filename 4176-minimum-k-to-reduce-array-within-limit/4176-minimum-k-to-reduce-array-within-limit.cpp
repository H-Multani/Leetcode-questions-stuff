class Solution {
public:
    long long solve(vector<int>& nums, int k) {
        // har element par jaa ke calculate ki kitne steps lagenge to get this
        // element to non +ve

        long long ans = 0;

        for (auto it : nums) {
            // it/k steps lagne hai ki
            ans += it / k;

            // agar it%k==0 means koi extra step nai lagega, otherwise ek step
            // aur lagega since remainder is +ve still, isko non +ve banane ke liye karna pdega
            if(it%k!=0) ans++;
        }

        return ans;
    }
    int minimumK(vector<int>& nums) {
        // looks like binary search on ans, maxm value of k is maxm value of
        // nums, since maxm value will require 1 step to get all values to non
        // +ve

        // r cannot be max element, since ho sakta vo dikkat kare, INT_MAX se lelo

        int l = 1, r = INT_MAX;

        int ans = -1;
        while (l <= r) {
            // mid wale ko lelo as k
            int k = l + (r - l) / 2;

            if (solve(nums, k) <= (1LL*k * k)) {
                // means possible ans hai ye

                // update
                ans = k;

                // check left for better ans
                r = k - 1;
            } else {
                // means valid ans nai hai check right for possible ans
                l = k + 1;
            }
        }

        return ans;
    }
};