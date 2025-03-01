class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // apply the operation on nums
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        // new vector me saare non daal do
        vector<int> ans;
        for(auto it:nums){
            if(it!=0) ans.push_back(it);
        }

        // remaining 0 daal do
        while(ans.size()<n) ans.push_back(0);

        return ans; 
    }
};