class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=0,j=0;
        ArrayList<Integer> arr=new ArrayList<>();

        // common loop
        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                arr.add(nums1[i]);
                arr.add(nums2[j]);
                i++;j++;
            }
            else if(nums1[i]>nums2[j]){
                // j wala element chhota hai, add first
                // since sorted order me chahiye
                arr.add(nums2[j]);
                j++;
            }
            else{
                // here means, i wala element chhota hai, add thos first
                arr.add(nums1[i]);
                i++;
            }
        }

        // in case nums1 se m elemnts nai liye hai
        while(i<m){
        // directly add the elements
        // since nums1 ke elements already sorted order me hai
        arr.add(nums1[i]);
        i++;
        }
        // in case nums2 se n elemnts nai liye hai
        while(j<n){
        // directly add the elements
        // since nums2 ke elements already sorted order me hai
        arr.add(nums2[j]);
        j++;
        }

        for(i=0;i<m+n;i++){
            nums1[i]=arr.get(i);
        }
        // arraycopy() can be used

        return;



    }
}