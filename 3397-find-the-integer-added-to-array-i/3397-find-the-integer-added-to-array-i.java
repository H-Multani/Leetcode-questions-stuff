class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        int small1=nums1[0];
        int small2=nums2[0];

        for(int it:nums1){
            small1=Math.max(it,small1);
        }
        for(int it:nums2){
            small2=Math.max(it,small2);
        }

        return small2-small1;
    }
}