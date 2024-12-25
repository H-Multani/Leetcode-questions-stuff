class Solution {
public:
    int solve(vector<string>& strs, int n, int zerocnt, int onecnt,
              vector<vector<vector<int>>>& memo) {
        // base case
        if (n == 0) {
            return 0;
        }

        if (zerocnt == 0 && onecnt == 0) {
            // not used || since agar 0s khatam ho gaye hai phir bhi apan 1's le
            // sakte hai, lekin agar dono khatam ho gaye toh kuch nai kar skte,
            // in such case return 0
            return 0;
        }

        // agar memo me ans hai toh wahi se return kardo
        if (memo[n][zerocnt][onecnt] != -1) {
            return memo[n][zerocnt][onecnt];
        }

        // we here means memo me nai mila, ans nikalo

        // 2 options, take and not take, for that we need current string ke 1's
        // and 0's ka cnt
        int cnt1 = count(strs[n - 1].begin(), strs[n - 1].end(), '1');
        int cnt0 = count(strs[n - 1].begin(), strs[n - 1].end(), '0');

        // no of elements in take and nottake
        int take = 0, nottake = 0;

        // 2 options for current element take not take
        if (cnt1 <= onecnt && cnt0 <= zerocnt) {
            // means we can take current element , lelo
            take = 1 + solve(strs, n - 1, zerocnt - cnt0, onecnt - cnt1, memo);
            // the +1 since apan ne current element ko le liya hai
        }

        nottake = solve(strs, n - 1, zerocnt, onecnt, memo);

        // now take and nottake me element ke cnt hai, maxm return kardo

        // ans memo me store kardo
        memo[n][zerocnt][onecnt] = max(take, nottake);

        return max(take, nottake);
    }
    int findMaxForm(vector<string>& strs, int zero, int ones) {
        // memoize kardo, pehle sirf n and ttlsum change hora tha(lc 416
        // me)(tabhi 2d dp), yaha 3 cheezein change hori hai, n toh change ho hi
        // rha hai, uske alava onecnt and zerocnt bhi change hora hai, toh vo
        // memo me rakhna padega

        // hence sirf onecnt and zerocnt ka dp lene se wrong ans aayega , thats
        // literally the only reason

        // 3D dp banao
        // vector<vector<int>> memo(zero + 1, vector<int>(ones + 1, -1));
        int n = strs.size();
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(zero+1,vector<int>(ones+1,-1)));
        return solve(strs, n, zero, ones, memo);
    }
};