class Solution {
    public int searchInsert(int[] nums, int target) {
        int left=0,right=nums.length-1;
        int ans=0;

        while(left<=right){
            long mid=(left+right)/2;

            if(nums[(int)mid]==target){
                return (int)mid;
            }
            else if(nums[(int)mid]<target){
                ans=(int)mid+1;
                // go right
                left=(int)mid+1;
            }
            else{
                // nums[mid]>target
                // ans=(int)mid-1;
                // go left
                right=(int)mid-1;
            }
        }
        if(ans<0) return 0;

        return ans;
    }
}