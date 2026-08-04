class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();

        for (int i = nums[0], j = 0; i <= nums[n - 1] && j < n; i++) {
            if (i != nums[j]) {
                ans.push_back(i);
            }else{
                j++;
            }
        }

        return ans;
    }
};