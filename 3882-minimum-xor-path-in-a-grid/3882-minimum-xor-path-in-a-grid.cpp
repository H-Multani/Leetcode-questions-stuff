class Solution {
public:
    int m,n;
    int ans;
    // vector<vector<unordered_set<int>>> dp;
    // void solve(int i,int j,vector<vector<int>>& grid,int xr){
    //     if(i==m-1 && j==n-1){
    //         // means end aa chuke XOR bana kar update and return
    //         ans=min(ans,xr^grid[i][j]);
    //         return;
    //     }

    //     // we here means further explore karna hai xor update kardo current value se
    //     xr=xr^ grid[i][j];

    //     // agar yee state par pehle aa chuke hai toh return kar jao yaha se
    //     if (dp[i][j].count(xr)) {
    //         return;
    //     }

    //     // we here means pehle nai aaye yaha, update dp
    //     dp[i][j].insert(xr);

    //     // ya rigt jao ya down jao

    //     // right jaa kar dekho
    //     if(j+1<n){
    //         // means right jaa sakte jao and explore ans
    //         solve(i,j+1,grid,xr);
    //     }
    //     // down jaa kar dekho
    //     if(i+1<m){
    //         // means down jaa sakte jao and explore ans
    //         solve(i+1,j,grid,xr);
    //     }

    //     return ;
    // }
    int minCost(vector<vector<int>>& grid) {
        // exlore karva lo aur kya
        m=grid.size();
        n=grid[0].size();
        ans=INT_MAX;

        // bottom up wala code
        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );
        // used unordered map since boht value aa sakta [i][j] ke liye xor ka,and aage konse wale se minm aa jaaye nai pata since XOR alag kaam karta hence,maintain all possible XOR values not just the firs tone 


        // base case, (0,0) ke liye grid[0][0] laga dena dp me
        dp[0][0].insert(grid[0][0]);

        // traverse karlo by row and col
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                // yaha 2 case rahenge

                // ya left se aa rahe yaha, ya upar se

                // upar se aa rhe ans ka update
                if (i > 0) {
                    for (int x : dp[i - 1][j]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }

                // left se aa rhe ans ka update 
                if (j > 0) {
                    for (int x : dp[i][j - 1]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }
        
        // m-1,n-1 se minm jo hoga vohi ans hoga
        return *min_element(
            dp[m - 1][n - 1].begin(),
            dp[m - 1][n - 1].end()
        );
    }
};