class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort karlo, then use binary search to get third value of triangle

        if(nums.size()<3) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // ye 2 sides lelo i and j wala
                int sm = nums[i] + nums[j];

                // use binary search, find third slide that is strictly< than
                // this sum
                int idx = lower_bound(nums.begin() + j, nums.end(), sm) -
                          nums.begin();

                // this idx is the first banda with value>=sm, is se ban sakta
                // hai triplet, and iske aage walo se bhi ban sakta hai triplet

                // count karlo

                if (idx - j - 1 > 0)
                    ans += (idx - j - 1);
            }
        }

        return ans;
    }
};