class Solution {
    public static List<List<Integer>> ans;
    public static void solve(int i,int n,int k, List<Integer> temp){
        if(i>n+1) return;
        if(k==0){
            ans.add(new ArrayList(temp));
            return;
        }


        // 2 options
        // 1 st option: take curent element
        // i th wala lena hai
        temp.add(i);
        solve(i+1,n,k-1,temp);
        temp.remove(temp.size()-1);


        // 2nd option: dont take current element
        solve(i+1,n,k,temp);

    }
    public List<List<Integer>> combine(int n, int k) {
        ans=new ArrayList<>();
        List<Integer> temp=new ArrayList();
        // solve(i,n,k,temp);
        solve(1,n,k,temp);
        return ans;
    }
}