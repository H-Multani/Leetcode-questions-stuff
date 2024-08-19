class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        ArrayList<Integer> num=new ArrayList<>(); 
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                num.add(nums1[i]);
                i++;
            }
            else{
                num.add(nums2[j]);
                j++;
            }
        } 

        // in case nums2 end first , and nums1 ke m element nai liye hai abhi tak
        while(i<m){
            num.add(nums1[i]);
            i++;
        }
        // in case nums1 end first,and nums2 ke n element nai liye hai abhi tak
        while(j<n){
            num.add(nums2[j]);
            j++;
        }

        for(i=0;i<num.size();i++){
            nums1[i]=num.get(i);
        }

        return;
    }
}