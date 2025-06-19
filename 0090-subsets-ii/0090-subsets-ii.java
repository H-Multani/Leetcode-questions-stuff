class Solution {
    public static void solve(int i,int[] arr,List<Integer> temp,Set<List<Integer>> ans){
        // if(i>arr.length) return;
        if(i==arr.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

        // ye approach nai chalne wali, use the approach of combination sum 2
        // dont take
        solve(i+1,arr,temp,ans);

        // take current element
        temp.add(arr[i]);
        solve(i+1,arr,temp,ans);
        temp.remove(temp.size()-1);

        // for(int j=i;j<arr.length;i++){
        //     if(j>i && arr[j]==arr[j-1]) continue;

        //     // do
        //     temp.add(arr[j]);
        //     // explore
        //     solve(j+1,arr,temp,ans);
        //     // undo
        //     temp.remove(temp.size()-1);
        // }

    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>> ans=new HashSet<>();
        List<Integer> temp=new ArrayList<>();
        Arrays.sort(nums);
        solve(0,nums,temp,ans);
        return new ArrayList<>(ans);
    }
}