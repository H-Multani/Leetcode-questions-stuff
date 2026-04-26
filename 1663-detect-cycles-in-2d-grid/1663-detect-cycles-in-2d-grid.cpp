class Solution {
public:
    int m, n;
    bool solve(int i, int j, int previ, int prevj, vector<vector<bool>>& vis,
               vector<vector<char>>& grid) {
        if (i >= m || j >= n)
            return false;

        if (vis[i][j]) {
            // means circular aaye hai apan, return true
            return true;
        }

        // we here means we need to explore further frm here

        // current ko explored mark kardo
        vis[i][j] = true;

        // valid(means same char as current value AND index exist karta) hai
        // tabhi explore karna and make sure its not previous wala

        // explore right(i,j+1)
        bool ans1 = false;
        if (j < n - 1 && grid[i][j] == grid[i][j + 1] &&
            !(i == previ && j + 1 == prevj)) {
            // means we can explore here, dekh lo
            ans1 = solve(i, j + 1, i, j,vis,grid);
            // aage walo ke liye current wala will become previous
        }


        // explore left(i,j-1)
        bool ans2 = false;
        if (j > 0 && grid[i][j] == grid[i][j - 1] &&
            !(i == previ && j - 1 == prevj)) {
            // means we can explore here, dekh lo
            ans2 = solve(i, j - 1, i, j,vis,grid);
            // aage walo ke liye current wala will become previous
        }



        // explore top(i-1,j)
        bool ans3 = false;
        if (i > 0 && grid[i][j] == grid[i-1][j] &&
            !(i-1 == previ && j== prevj)) {
            // means we can explore here, dekh lo
            ans3 = solve(i-1, j , i, j,vis,grid);
            // aage walo ke liye current wala will become previous
        }


        // explore bottom(i+1,j)
        bool ans4 = false;
        if (i < m - 1 && grid[i][j] == grid[i+1][j] &&
            !(i+1 == previ && j== prevj)) {
            // means we can explore here, dekh lo
            ans4 = solve(i+1, j, i, j,vis,grid);
            // aage walo ke liye current wala will become previous
        }


        // 4 paths me se jaha ans mil jaaye return kar dena
        return ans1| ans2|ans3|ans4;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        // boolean array bana kar explore karo har jagah se aur kya, agar koi
        // bhi path se ghum kar aa gaye toh return true

        m = grid.size();
        n = grid[0].size();

        // boolean vector bana lo which will e useful for exploration
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j=0; j < n; j++) {
                // unvisited hai toh start and explore frm here
                if (!vis[i][j]) {
                    // start and explore frm here
                    bool ans = solve(i, j, -1, -1, vis, grid);
                    if (ans)
                        return ans;
                }
            }
        }

        // we here means koi bhi circular path not possible
        return false;
    }
};