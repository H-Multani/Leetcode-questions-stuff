class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len=nums.length;
        int[] ans;

        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(nums[i]+nums[j]==target){
                    ans=new int[]{i,j};
                    return ans;
                }
            }
        }
        ans=new int[2];
        return ans;

    }
}