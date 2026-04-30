class Solution {
public:
    int m, n;

    vector<vector<vector<int>>> memo;

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        // agar kahi bhi k<=0 aa gaya means cost khtam ho gai, means path is
        // invalid, in such case return INT_MIN
        if (k < 0)
            return INT_MIN;

        // agar m-1,n-1 aa gaye toh ans return kardo
        if (i == m - 1 && j == n - 1)
            return grid[m - 1][n - 1];

        // memo me ans hai toh bhejdo
        if(memo[i][j][k]!=-1) return memo[i][j][k];

        // we here means right ya down jaa sakte hai,

        int right = INT_MIN, down = INT_MIN;

        // right jaa sakte hai kya
        if (j < n - 1) {
            // means right ja sakte hai, explore right

            // agar current value 0 hai means cost 0 lagi, otherwise cost 1 lagi
            int cost = (grid[i][j + 1] == 0) ? 0 : 1;

            // current score ko include karo, and explore right
            right = grid[i][j] + solve(i, j + 1, grid, k - cost);
        }

        // down jaa sakte hai kya
        if (i < m - 1) {
            // means down ja sakte hai, explore down

            // agar current value 0 hai means cost 0 lagi, otherwise cost 1 lagi
            int cost = (grid[i + 1][j] == 0) ? 0 : 1;

            // current score ko include karo, and explore down
            down = grid[i][j] + solve(i + 1, j, grid, k - cost);
        }

        // ab dono me se jo bhi path maxm ans dede return that


        // update memo before ans
        return memo[i][j][k]=max(down, right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        // simple DP
        m = grid.size();
        n = grid[0].size();

        // ab we know that TLE fatega, toh memo laga do,3 things change, i,j,k,
        // toh inhi 3 ka memo bana denge
        
        memo.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = solve(0, 0, grid, k);

        return (ans < 0) ? -1 : ans;
    }
};