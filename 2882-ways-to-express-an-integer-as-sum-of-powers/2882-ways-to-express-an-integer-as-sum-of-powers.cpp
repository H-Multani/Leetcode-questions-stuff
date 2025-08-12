class Solution {
public:
    int ans;
    int mod = 1e9 + 7;

    long long power(int a, int b) {
        if (b == 1)
            return a;

        long long half = power(a, b / 2);

        long long ans = (half * half) % mod;

        if (b % 2 == 1)
            ans = (ans * a) % mod;

        return ans;
    }

    int solve(int i, int remaining, int x,vector<vector<int>>& memo) {
        if (remaining == 0) {

            return 1;
        }
        if (remaining < 0 || i > 300)
            return 0;

        // memo me ans h toh lelo
        if(memo[i][remaining]!=-1) return memo[i][remaining];

        // 2 options, take and nottake

        // take
        int p = power(i, x);
        int ans1 = solve(i + 1, remaining - p, x,memo);

        // nottake
        int ans2 = solve(i + 1, remaining, x,memo);

        // update memo
        memo[i][remaining]=(ans1+ans2)%mod;

        return (ans1 + ans2)%mod;
    }
    int numberOfWays(int n, int x) {
        // brute force?, recursive try karke dekhte

        // agar x==1 bhi hua toh at max i will go upto like 25 at best

        // i and n changes only, i goes max upto 300, and n goes max frm 0 to
        // n,toh memo bana do

        vector<vector<int>> memo(301,vector<int>(n+1,-1));

        return solve(1, n, x,memo);
    }
};