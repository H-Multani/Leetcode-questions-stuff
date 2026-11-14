class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // ok toh dikkat fategi ki shrink karne se window ka sum can become very +Ve or very -ve, toh better solution will be brute force

        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // yaha se saare subarrays that start with idx i honge sum lelo
            int ttl=0;
            for(int j=i;j<n;j++){
                // current subarray is from [i,j]

                // current bande ko include karo
                ttl+=nums[j];

                // agar ye ttl>0 hua AND iska subarray ka size [l,r] ke andar hua means this is possible ans, update kar denge

                int len=j-i+1;
                if(ttl>0 && len<=r && len>=l){
                    // means ttl>0 hai as well as length of subarray in range of l to r, update ans since we need minm sum wala subarray
                    ans=min(ans,ttl);
                }

            }
        }

        // agar abhi bhi ans is INT_MAX then subarray cannot be made, in such case return -1
        if(ans==INT_MAX) return -1;

        return ans;
    }
};