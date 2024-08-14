class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        int[] arr=new int[n];

        for(int i=0;i<n;i++){
            // int index=i;
            // index=index+k;
            // index=index%n;
            // arr[index]=nums[i];
            arr[(i+k)%n]=nums[i];
        }

        for(int i=0;i<n;i++){
            nums[i]=arr[i];
        }

        return;
    }
}