class Solution {
    public static int m,n;
    public static int solve(int i, int j, int[][] og){
        if(i==m-1 && j==n-1) return 1;

        if(i>=m || j>=n) return 0;

        if(og[i][j]==1) return 0;

        int down=solve(i+1,j,og);
        int right=solve(i,j+1,og);

        return down+right;
    }
    public int uniquePathsWithObstacles(int[][] og) {
        int m=og.length;
        int n=og[0].length;
        int[][] dp = new int[m][n];

        if(og[0][0]==1) return 0;

        // T.C-> O(m*n)
        // S.C-> O(m*n)
        dp[0][0] = 1;
        // if(i<0 || j<0) return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(og[i][j]==1){
                    // yaha par rock hai
                    dp[i][j]=0;
                } 
                else {
                    int up=0,left=0;
                    
                    if(i>0) up = dp[i - 1][j];
                    // temp[j]=dp[i-1][j]
                    if(j>0) left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
            // temp=newarr;
        }

        return dp[m - 1][n - 1];
    }
}