class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // bubble sort laga go
        // with one condition, ki dono elements ke set bits commin hone chahiye

        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]  && __builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
                    swap(nums[j],nums[j+1]);
                }
            }
        }

        // now just check if sorted hai, if sorted hai, toh return true

        for(auto i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }

        return true;
    }
};