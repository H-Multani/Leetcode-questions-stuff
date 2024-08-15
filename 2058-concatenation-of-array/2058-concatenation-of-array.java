class Solution {
    public int[] getConcatenation(int[] nums) {
        ArrayList<Integer> arr=new ArrayList<>();

        int len=nums.length;

        for(int it:nums){
            arr.add(it);
        }
        for(int it:nums){
            arr.add(it);
        }

        int[] ans=new int[arr.size()];

        for(int i=0;i<arr.size();i++){
            ans[i]=arr.get(i);
        }

        return ans;
    }
}