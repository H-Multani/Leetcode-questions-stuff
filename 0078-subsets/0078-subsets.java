class Solution {
    public static void solve(int i,int[] arr,List<Integer> temp,List<List<Integer>> ans){
        if(i>arr.length) return;
        if(i==arr.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

        // take current element
        temp.add(arr[i]);
        solve(i+1,arr,temp,ans);
        temp.remove(temp.size()-1);

        // dont take
        solve(i+1,arr,temp,ans);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        solve(0,nums,temp,ans);
        return ans;
    }
}