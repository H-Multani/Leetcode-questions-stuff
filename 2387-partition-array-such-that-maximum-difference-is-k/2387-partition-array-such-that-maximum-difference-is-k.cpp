class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int cnt=0,n=nums.size();
        int st=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-st<=k) continue;

            st=nums[i];
            cnt++;
        }

        return cnt+1;
    }
};