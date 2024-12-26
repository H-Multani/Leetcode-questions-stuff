class Solution {
public:
    int ans;
    void solve(vector<int>& nums, int target, int currsum, int i) {
        // base condn
        if (i == nums.size()) {
            // 2 condns here
            // agar target sum phoch gaye hai toh ye possible ans hai, ans cnt
            // increase karo
            if (currsum==target) ans++;

            // return since aage kuch nai hai ab aur
            return;
        }

        // current banda ke liye 2 options, either a + or a -
        // take +
        solve(nums, target, currsum + nums[i], i + 1);
        // take -
        solve(nums, target, currsum - nums[i], i + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        solve(nums, target, 0, 0);

        return ans;
    }
};