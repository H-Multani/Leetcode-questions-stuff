class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // jo bola hai kardo
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                // start se i ka dist nikalo and update ans
                ans=min(ans,abs(i-start));
            }
        }

        return ans;
    }
};