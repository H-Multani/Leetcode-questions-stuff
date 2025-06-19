class Solution {
    public void solve(int[] nums, List<Integer> dp, List<List<Integer>> ans, boolean[] freq) {
        if(dp.size()==nums.length){
             ans.add(new ArrayList<>(dp));
            return ;
        }

        for(int i=0;i<nums.length;i++){
            if(freq[i]!=true){
                // new location mil gai explore karne vaakste
                freq[i]=true;
                dp.add(nums[i]);
                solve(nums,dp, ans, freq);
                dp.remove(dp.size()-1);
                freq[i]=false;
            }
        }
    }   

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> dp = new ArrayList<>();
        boolean[] freq = new boolean[nums.length];
        solve(nums, dp, ans, freq);
        return ans;
    }
}