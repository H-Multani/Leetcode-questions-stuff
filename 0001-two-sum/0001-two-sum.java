class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len=nums.length;
        int i=0,j=len-1;
        int[] temp=nums.clone();
        Arrays.sort(temp);
        while(i<j){
            int sum=temp[i]+temp[j];
            if(sum==target){
                break;
            }
            else if (sum<target){
                // increment sum ke liye move i ahead
                i++;
            }
            else j--;
        }

        int value1=temp[i];
        int value2=temp[j];

        // search for the values in the original array and store in array, the indexes
        int index1=-1,index2=-1;
        for(i=0;i<len;i++){
            if(nums[i]==value1 && index1==-1){
                index1=i;
            }
            else if(nums[i]==value2 && index2==-1){
                index2=i;
            }
        }

        int[] ans={index1,index2};
        return ans;

    }
}