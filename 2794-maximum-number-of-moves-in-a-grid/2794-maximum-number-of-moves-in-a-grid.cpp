class Solution {
    int maxdepth;
    int m, n;

    // solve funcn used to explore different paths
    void solve(int i, int j, vector<vector<int>>& grid, int currdepth,
               vector<vector<int>>& memo) {

        // max depth ko update kar do sbse pehle toh har (i,j) ke liye
        maxdepth = max(maxdepth, currdepth);

        // if i or j goes out of bounds, return krdo yehi se
        if (i >= grid.size() || j >= grid[0].size())
            return;

        // if memo me (i,j) ka value -1 nai h, means iss (i,j) se jaane wala
        // path already explore kar chuke hai pehle kabhi, no need to explore
        // again, hence yehi se return krdo
        if (memo[i][j] != -1)
            return;

        // memo me -1 hai means explore krna padega

        // current bande par visit kar rhe hai abhi, means (i,j) is visited for
        // path, memo me update kar do, memo me (i,j) par current depth save
        // kardo, as placeholder value(coz idk if this can be used again)
        // visited vector type kaam kar raha lagta ye \U0001f480
        memo[i][j] = currdepth;

        // ab (i,j) se explore karenge different paths jaisa questn bol rha hai

        // explore path of (i-1,j+1)
        if (i - 1 >= 0 && j + 1 < n && grid[i][j] < grid[i - 1][j + 1]) {
            // new location par jaa rahe hai, toh depth+1 hoga na
            solve(i - 1, j + 1, grid, currdepth + 1, memo);
        }
        // explore path of (i,j+1)
        if (j + 1 < n && grid[i][j] < grid[i][j + 1]) {
            // new location par jaa rahe hai, toh depth+1 hoga na
            solve(i, j + 1, grid, currdepth + 1, memo);
        }
        // explore path of (i+1,j+1)
        if (i + 1 < m && j + 1 < n && grid[i][j] < grid[i + 1][j + 1]) {
            // new location par jaa rahe hai, toh depth+1 hoga na
            solve(i + 1, j + 1, grid, currdepth + 1, memo);
        }
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        maxdepth = 0;
        m = grid.size();
        n = grid[0].size();

        // NOTE: no need for visited vector, since apan har baari (i,j) se aage
        // hi ja rahe hai like (i+1,j+1),(i,j+1),(i-1,j+1) etc, hamesha towards
        // right side jaate jayenge, peeche nai aa rahe hai kabhi exploration
        // me(except jab re start kar rahe from a different element of column 1)

        // although i can think that memo vector ek tarah se visited vector type
        // hi chal rah\U0001f480

        // tle phek rha, usse bachne ke liye memoization krlo
        // memo vector bana kr
        vector<vector<int>> memo(m, vector<int>(n, -1));
        // questn says ki apan column 0 ke koi bhi bande se chalu kar sakte hai,
        // toh har bande se chalu karke explore kar lenge options
        for (auto i = 0; i < m; i++) {

            // i th row ke first bande se explore karna chalu karo
            solve(i, 0, grid, 0, memo);
        }

        // end me maxm depth update ho gai hogi,return krdo
        return maxdepth;
    }
};