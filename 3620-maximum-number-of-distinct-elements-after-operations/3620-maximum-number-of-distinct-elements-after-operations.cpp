class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        // sort krdo
        sort(nums.begin(), nums.end());

        int ans = 0;
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            // minm value possible for current element
            int minval = nums[i] - k;

            // agar ye value prev se aage hai means this can be new prev value
            if (prev < minval) {
                // new minm value ko prev bana do
                prev = minval;
                // and since new value hai toh count increase kardo
                ans++;
            } else {
                // we here means prev>=minval, toh iss case me check if we can
                // keep prev+1 as a possible arrangement instead of nums[i] accd
                // to nums[i] ki range (-k to +k )

                // since prev+1 would be unique value

                // rakh sakte hai agar nums[i] ke range me ho ie
                // prev+1<=nums[i]+k, dont compare with -k since peeche toh
                // smaller values toh rakh hi rahe hai clash na ho jaaye
                if (prev+1<=nums[i]+k){
                    // we here means prev+1 rakh sakte hai

                    // rakh lo, new distinct number found, cnt krlo
                    ans++;

                    // prev ko update kardo
                    prev++;
                }
            }
        }

        return ans;
    }
};