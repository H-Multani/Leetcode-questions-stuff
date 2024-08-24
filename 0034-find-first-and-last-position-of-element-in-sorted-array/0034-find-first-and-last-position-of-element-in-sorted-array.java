class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left=0,right=nums.length-1;
        int startidx=-1;
        int endidx=-1;
        
        //startidx ke liye
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                // possible ans, update
                startidx=mid;

                //go left
                right=mid-1;
            }
            else if(nums[mid]<target){
                // go right
                // kyuki left me chhote values milenge, target nai milega kabbhi
                left=mid+1;
            }
            else{
                // go left
                // kyuki right me bade values milenge, target nai milega kabbhi
                right=mid-1;
            }
        }
        // startidx mil gaya hai
        // same cheez for endidx

        // for end index
        left=0;right=nums.length-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                // possible ans, update
                endidx=mid;

                //go right
                left=mid+1;
            }
            else if(nums[mid]>target){
                // go left
                right=mid-1;
            }
            else{
                // go right
                left=mid+1;
            }
        }

        int[] ans={startidx,endidx};

        return ans;
    }
}