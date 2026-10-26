class Solution {
public:
    int m, n;
    long long solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<bool>>& vis) {
        // base case kuch nai hoga yaha

        // current bande ko visited mark kardo
        vis[i][j] = true;

        // explore all 4 directions and jo total aaya grid ka nikal kar lao
        long long ttl = grid[i][j];

        // check down
        if (i + 1 < m && !vis[i + 1][j] && grid[i + 1][j] != 0) {
            // means ye wala jagah unvisited hai and island ke andar hai,
            // include in ttl and explore
            ttl = ttl + solve(i + 1, j, grid, vis);
        }
        // check up
        if (i>0 && !vis[i - 1][j] && grid[i - 1][j] != 0) {
            // means ye wala jagah unvisited hai and island ke andar hai,
            // include in ttl and explore
            ttl = ttl + solve(i - 1, j, grid, vis);
        }

        // check left
        if (j>0 && !vis[i ][j-1] && grid[i][j-1] != 0) {
            // means ye wala jagah unvisited hai and island ke andar hai,
            // include in ttl and explore
            ttl = ttl + solve(i, j-1, grid, vis);
        }
        // check right
        if (j+1<n && !vis[i][j+1] && grid[i][j+1] != 0) {
            // means ye wala jagah unvisited hai and island ke andar hai,
            // include in ttl and explore
            ttl = ttl + solve(i, j+1, grid, vis);
        }

        // return the ttl
        return ttl;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        // DSU se bhi kar sakte hai lekin mai ye DFS se karra simple

        m = grid.size();
        n = grid[0].size();

        // ek visited vector lelo to keep track of areas visited
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // ab traverse through the grid and agar koi island start hora ho toh
        // explore karlo
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // agar unvisited hai and location par 0 nai hai
                if (!vis[i][j] && grid[i][j] != 0) {
                    // we here means ye island unvisited hai explore karke sum
                    // nikal kar lao

                    if (solve(i, j, grid, vis) % k == 0) {
                        // means jo total value of island mili hai vo k se
                        // divisible hai, ans me +1 kardo
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};