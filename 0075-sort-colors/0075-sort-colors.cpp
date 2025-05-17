class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int j=0;
        if(mpp.find(j)==mpp.end()) j++;
        if(mpp.find(j)==mpp.end()) j++;
        for(auto i=0;i<nums.size();i++){
            nums[i]=j;
            mpp[j]--;

            if(mpp[j]==0){
                j++;
                if(mpp.find(j)==mpp.end())j++;
            }
        }
    }
};