class Solution {
public:
    int n, m;
    // mod karte jana bhaiya plss
    int mod=1e9+7;
    int solve(int i, int j, int sum, vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& memo) {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;

        // sirf mod store karlo since vahi kaam ka hai, agar mod 0 aa jaaye
        // means current sum is exactly divisibly by k, yehi logic chek hota
        // jayega thats all
        sum = (sum + grid[i][j]) % k;

        // memo me hai toh return krdo yehi se
        if(memo[i][j][sum]!=-1) return memo[i][j][sum];
        if (i == n - 1 && j == m - 1) {
            if (sum % k == 0)
                return 1;
            return 0;
        }

        // 2 option go right and down
        int ans1 = solve(i + 1, j, sum, grid, k,memo);
        int ans2 = solve(i, j + 1, sum, grid, k,memo);
        memo[i][j][sum]=(ans1+ans2)%mod;
        return (ans1 + ans2)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // all paths explore kar lete hai

        // basic logic chal gaya ab efficient logic chala kar dekhte hai
        n = grid.size();
        m = grid[0].size();
        // memoise karte hai, yaha 3 items change hora hai i,j,sum, karalo
        // store, i and j can go upto n,m, and sum can go upto k max
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

        return solve(0, 0, 0, grid, k,memo);
    }
};