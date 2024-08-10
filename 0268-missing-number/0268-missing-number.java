class Solution {
    public int missingNumber(int[] nums) {
        int len=nums.length;
        long arrsum=0;
        long actualsum=(len*(len+1))/2;
        for(int i=0;i<len;i++){
            arrsum+=nums[i];
            // arraysum=arraysum+arr[i]
        }

        return (int)(actualsum-arrsum);

    }
}