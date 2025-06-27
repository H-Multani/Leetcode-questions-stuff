class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& memo) {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if(memo[i][j]!=-1) return memo[i][j];

        // up and left wala ke ans nikalo
        int up = solve(i - 1, j,memo);
        int left = solve(i, j - 1,memo);

        memo[i][j]=up+left;

        return up + left;
    }
    int uniquePaths(int m, int n) {
        // recursion+memo

        // T.C-> O(n*m)
        // S.C-> O((n-1)+(m-1))(for stack recursive) + O(m*n)(for memo)

        // i and j change hora hai, and dono ka maxm value is m-1,n-1, toh m,n
        // size ka memo banao
        vector<vector<int>> memo(m,vector<int>(n,-1));

        // start frm m-1,n-1
        return solve(m - 1, n - 1,memo);
    }
};