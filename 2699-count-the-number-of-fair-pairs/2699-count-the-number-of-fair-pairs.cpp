class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long x=0,y=0;

        for(auto i=0;i<nums.size();i++){
            long long index_x=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            long long cntx=index_x-i-1;
            x+=cntx;
            long long index_y=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            long long cnty=index_y-i-1;
            y+=cnty;
        }

        return y-x;

    }
};