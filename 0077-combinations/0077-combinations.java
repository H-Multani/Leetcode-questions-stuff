
class Solution {
    public static List<List<Integer>> ans;

    public static void solve(int i, int n, int k, List<Integer> temp) {
        // for the logic behind n+1, see previous accepted solution
        // basically since we are using the n th value as well here, so we have to stop
        // at n+1(like in arrays, idx stops at i=n-1, but we stop at i>n, since the i=n
        // wala case par checking and then breaking hota tha, similarly here, i=n+1 par
        // checking and breaking ho raha hai, so we stop at i>n+1)
        // base case
        if (i > n + 1)
            return;
        // operation
        if (k == 0) {
            // we here means apne paas k elements bhar chuke hai temp me, push to ans
            ans.add(new ArrayList(temp));
            // since list added, hence return, iske aage apan aur explore nai kar sakte
            return;
        }
        // recursive calls
        // 2 options
        // option 1: take current element
        temp.add(i);
        // since element added to temp, ie 1 out of the k elements we need are filled,
        // hence send k-1 in revursive call
        solve(i + 1, n, k - 1, temp);
        // now after use of element, remove the element frm the array
        temp.remove(temp.size() - 1);

        // option 2: dont take curr element
        // simple funcn call
        // no changes in temp or k, since element nai liya(ie temp jaisa tha vaisa hi
        // rahega also) that means we still need k elements in our combination,hence
        // simple recursive call without any changes
        // to k or temp
        // since curr element ko reject kar diya hai, hence we now move to i+1 th
        // element
        solve(i + 1, n, k, temp);
    }

    public List<List<Integer>> combine(int n, int k) {
        ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        // solve(index(start frm 1, since questn says to), n,k,temp);
        solve(1, n, k, temp);

        return ans;

    }
}