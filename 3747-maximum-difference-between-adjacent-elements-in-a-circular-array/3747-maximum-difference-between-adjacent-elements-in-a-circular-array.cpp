class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);

        int maxm=-1;

        for(auto i=0;i<nums.size()-1;i++){
            maxm=max(maxm,abs(nums[i]-nums[i+1]));
        }

        return maxm;
    }
};