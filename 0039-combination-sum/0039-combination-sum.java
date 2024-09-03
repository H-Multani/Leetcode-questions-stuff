class Solution {
    public static List<List<Integer>> ans;

    public static void solve(int i, int[] arr, int currsum, int target,List<Integer> temp) {
        if (currsum == target) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (i >= arr.length)
            return;
        if(currsum>target) return;

        // 2 options
        // if (currsum < target) {

            // 2nd option, take current element
            // i not updated sunce we may need to take current element again
            temp.add(arr[i]);
            solve(i, arr, currsum + arr[i], target,temp);
            temp.remove(temp.size()-1);
        // }
        // 1st option, dont take
        solve(i + 1, arr, currsum, target,temp);


    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        ans=new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(0, candidates, 0, target, temp);
        return ans;
    }
}