class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& memo) {
    //     if (i == 0 && j == 0)
    //         return 1;

    //     if (i < 0 || j < 0)
    //         return 0;

    //     if (memo[i][j] != -1)
    //         return memo[i][j];

    //     // up and left wala ke ans nikalo
    //     int up = solve(i - 1, j, memo);
    //     int left = solve(i, j - 1, memo);

    //     memo[i][j] = up + left;

    //     return up + left;
    // }
    int uniquePaths(int m, int n) {

        // tabulation

        // T.C->(n*m)
        // S.C->(n*m)

        // dp banao of size n,m
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // base case (0,0) ka ans=1 kardo
        dp[0][0] = 1;

        // second wala base case i<0 and j<0 wale ko apan express nai kar sakte
        // toh rhen denge

        // loop chalu karenge

        // pehle i apna change hora hoga 0 to n-1
        for (int i = 0; i < n; i++) {
            // yaha har i ke liye ek j hoga
            for (int j = 0; j < m; j++) {
                // yaha ab apan ke paas state aayengi

                if (i == 0 && j == 0) {
                    // base case
                    dp[i][j] = 1;
                } else {
                    // we here means apan i>0 || j>0 par aa gaye h
                    // yaha normal logic chalayenge

                    // lekin yaha i-1<0 ho sakta hai toh uske liye cases bana do
                    int up = 0, left = 0;
                    // initially up and left ka value=0 since agar i-1<0 ho gaya
                    // toh uss case me 0 return krna padega

                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    // store the ans
                    dp[i][j] = up + left;
                }
            }
        }

        // last wala banda return krdo
        return dp[n - 1][m - 1];
    }
};