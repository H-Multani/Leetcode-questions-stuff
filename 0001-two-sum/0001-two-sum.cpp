class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length=nums.size();
        vector<int> ans;
        // stores values and indexes
        unordered_map<int,int> mpp;

        for(int i=0;i<length;i++){
            mpp[nums[i]]=i;
        }

        for(int i=0;i<length;i++){
            int reqd=target-nums[i];
            if(mpp.find(reqd)!=mpp.end() && mpp[reqd]!=i){
                return {i,mpp[reqd]};
            }
        }

        return {};
    }
};