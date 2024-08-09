class Solution {
    public int missingNumber(int[] nums) {
        long normalsum=0;
        int n=nums.length;
        long formulasum=n*(n+1)/2;

        for(int it:nums){
            normalsum+=it;
        }

        return (int)(formulasum-normalsum);

    }
}