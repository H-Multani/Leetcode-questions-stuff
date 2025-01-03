class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // simple prefix sum
        int n=nums.size();
        vector<long long> leftsum(n);
        leftsum[0]=nums[0];
        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i];
        }

        int ans=0;
        long long ttl=0;
        for(auto it:nums){
            ttl+=it;
        }

        for(int i=0;i<n-1;i++){
            // left ka sum is , idx 0 se i tak ka sum
            long long lsum=leftsum[i];

            // right ka sum is, i+1 se end tak ka sum
            // that sum will be totalsum-leftsum
            long long rtsum=ttl-lsum;
            if(lsum>=rtsum) ans++;
        }

        return ans;
    }
};