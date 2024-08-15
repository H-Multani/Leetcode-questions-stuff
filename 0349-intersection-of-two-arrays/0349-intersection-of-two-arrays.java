class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        ArrayList<Integer> ans=new ArrayList<>();
        int[] finalans;
        if(nums1.length<nums2.length){
            ArrayList<Integer> num=new ArrayList<>();

            for(int it:nums2){
                if(!num.contains(it)){
                    num.add(it);
                }
            }

            for(int i=0;i<nums1.length;i++){
                if(!ans.contains(nums1[i]) && num.contains(nums1[i])){
                    ans.add(nums1[i]);
                }
            }

            finalans=new int[ans.size()];

            for(int i=0;i<ans.size();i++){
                finalans[i]=ans.get(i);
            }
        }
        else{
            ArrayList<Integer> num=new ArrayList<>();

            for(int it:nums1){
                if(!num.contains(it)){
                    num.add(it);
                }
            }

            for(int i=0;i<nums2.length;i++){
                if(!ans.contains(nums2[i]) && num.contains(nums2[i])){
                    ans.add(nums2[i]);
                }
            }

            finalans=new int[ans.size()];

            for(int i=0;i<ans.size();i++){
                finalans[i]=ans.get(i);
            }
        }

        return finalans;

    }
}