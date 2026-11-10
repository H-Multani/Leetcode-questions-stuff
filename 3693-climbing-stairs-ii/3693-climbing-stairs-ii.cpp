class Solution {
public:
    int n;
    vector<int> memo;
    int solve(int i, vector<int>& costs) {
        // agar n pahuch gaye hai toh return krdo
        if (i == n)
            return 0;

        // we here means aage pahuch sakte hai

        // 3 options hai current i se start karke

        // teeno me se minm cost wala lena apan ko

        // memo me hai toh bhej do
        if(memo[i]!=-1) return memo[i];

        int ans = INT_MAX;

        // i+1 par jao
        // cost[i+1] add kar dena total me
        if (i + 1 <= n) {
            int j = i + 1;
            int cost = costs[j-1] + (j - i) * (j - i);
            ans = min(ans, cost + solve(i + 1, costs));
        }
        // i+2 par jao
        // cost[i+2] add kar dena total me
        if (i + 2 <= n) {
            int j = i + 2;
            int cost = costs[j-1] + (j - i) * (j - i);
            ans = min(ans, cost + solve(i + 2, costs));
        }
        // i+3 par jao
        // cost[i+3] add kar dena total me
        if (i + 3 <= n) {
            int j = i + 3;
            int cost = costs[j-1] + (j - i) * (j - i);
            ans = min(ans, cost + solve(i + 3, costs));
        }
        // jo minm ans aaya hai return kardo
        return memo[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        // DP laga sakte
        this->n = n;

        // costs array is i indexed, toh j-1 bhejna har jagah 

        // 1 value changes which is i, and can go to max n, toh memo bana lo
        memo.resize(n+1,-1);

        return solve(0, costs);
    }
};