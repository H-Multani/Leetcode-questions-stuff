class Solution {
    public int search(int[] nums, int target) {
        int left=0,right=nums.length-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            // whihc part is sorted
            else if(nums[left]<=nums[mid]){
                // left side is sorted
                // kya apna target sorted side me hai???
                if(target>=nums[left] && target<=nums[mid]){
                    // means out target is in sorted side
                    // ie left side
                    // go left
                    right=mid-1;
                }
                else{
                    // target is not in sorted side
                    // go to the other side. even after that side is not sorted
                    // go rigt
                    left=mid+1;
                }
            }
            else if(nums[mid]<=nums[right]){
                // right side is sorted
                // kya apna target sorted side me hai???
                if(nums[mid]<=target && target<=nums[right]){
                    // nums[mid]<=target<=nums[right]
                    // go right
                    left=mid+1;
                }
                else{
                    // target not in sorted side
                    // go to the other side, even if that side is not sorted
                    // go left
                    right=mid-1;
                }
            }
        }
        return -1;
    }
}