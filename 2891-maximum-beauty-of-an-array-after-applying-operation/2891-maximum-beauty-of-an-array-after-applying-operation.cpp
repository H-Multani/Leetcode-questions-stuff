class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // dq waali approach
        vector<pair<int, int>> intervals;
        // stores intervals of each value of nums

        for (auto it : nums) {
            // interval will be (it-k,it+k), yehi push kardo
            intervals.push_back({it - k, it + k});
        }

        // now sort the intervals accd to starting point
        sort(intervals.begin(), intervals.end());

        // dq liya, since front se pop karenge, back se push karenge
        deque<pair<int, int>> dq;

        int ans = 1;
        // since minm to minm 1 interval toh hoga hi hoga

        for (auto curr : intervals) {
            // current interval is in curr

            // check if current interval overlaps with the interval at front of
            // dq

            // current ka start is curr.first, and dq ke front ka end is
            // dq.front().second, agar curr wale ka start greater than dq front
            // ka end means overlapping nai hori hai
            // dq.empty(), dq empty nai hona chahiye, nai toh front wala element
            // kaha se milega
            while (!dq.empty() && dq.front().second < curr.first) {
                // we here means overlapping nai hori hai front waale ke saath,

                // hence, since overlapping nai hori hai hence dq ke front wale
                // ko pop kardo
                dq.pop_front();
            }

            // we here means ab dq ke front wale interval se curr wala interval
            // overlap karra hai
            // hence since overlap krra hai toh ye interval dq me push kardo
            dq.push_back(curr);

            // now we have ki dq me jitne intervals hai saare overalap karre hai
            // ek dusre se, and we have to find how many intervals overlap at
            // max hence update ans with dq ka size
            ans = max(ans, (int)dq.size());
        }

        return ans;
    }
};