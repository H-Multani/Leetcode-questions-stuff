
class Solution {
    public static List<List<Integer>> ans;

    public static void solve(int i, int n, int k, List<Integer> temp) {
        // base case ans operation
        // agar ye(k==0) pehle nai chk karaya toh error aaega, how?, suppose i=n hai,
        // iss
        // case me bhi apan n wale element ko le sakthe hai na toh its similar to when
        // we are in i=n-1 index of array, toh current wala lene ke baad dekhenge ki
        // return kaha karvana hai, hence apan ko ye sabse pehle heck karana padega, in
        // each call, even before we stop the recursive call(and return smth) we have to
        // check if we already have k elements, bcoz if we do, then we straight return
        // since we dont need any more elements

        // now if we want ki pehle toh base case hi chahiye, then what we can do is
        // instead of returning when we get i>n, we return when we get i>n+1, (like we
        // break when i>arr.length in array), since here we have a posisble ans at
        // i=n(due to the wording of the question), toh waha toh nai rok paenge, ek aage
        // hi rokna padega, ill maybe try that after i submit this solution
        if (k == 0) {
            // we here means apne paas k elements bhar chuke hai temp me, push to ans
            ans.add(new ArrayList(temp));
            // since list added, hence return, iske aage apan aur explore nai kar sakte
            return;
        }
        if (i > n)
            return;

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