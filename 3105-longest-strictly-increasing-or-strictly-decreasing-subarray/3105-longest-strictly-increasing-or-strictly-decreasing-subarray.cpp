class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxm=1,len=1;
        
        // increasing subarrray
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                len++;
            }
            else{
                maxm=max(maxm,len);
                len=1;
            }
        }
        
        maxm=max(maxm,len);
        
        len=1;// coz we are counting for new len
        // if len smth other than 1 we get wrong ans
        // decreasing subarray
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                len++;
            }
            else{
                maxm=max(maxm,len);
                len=1;
            }
        }
        
        maxm=max(maxm,len);
        
        return maxm;
    }
};