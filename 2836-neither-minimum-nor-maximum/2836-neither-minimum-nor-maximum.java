class Solution {
    public int findNonMinOrMax(int[] nums) {
        if(nums.length<=2) return -1;
        int minm=nums[0],maxm=nums[0];
        for(int it:nums){
            minm=Math.min(minm,it);
            maxm=Math.max(maxm,it);
        }

        for(int i=0;i<nums.length;i++){
            if(nums[i]!=maxm && nums[i]!=minm) return nums[i];
        }

        return -1;
    }
}