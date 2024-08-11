class Solution {
    public int minimumOperations(int[] nums) {
        int ans=0;
        int len=nums.length;

        for(int it:nums){
            if(it%3!=0){
                // if remainder is 1 , subtract 1
                // if remainder is 2 , add 1
                ans++;
            }
        }
        return ans;

    }
}