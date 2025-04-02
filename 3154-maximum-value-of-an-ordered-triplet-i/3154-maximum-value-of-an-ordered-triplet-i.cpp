class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // brute force krdo yaar

        long long maxm=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    maxm=max(maxm,((long long)nums[i]-(long long)nums[j])*(long long)nums[k]);
                }
            }
        }
    
        return maxm;
    }
};