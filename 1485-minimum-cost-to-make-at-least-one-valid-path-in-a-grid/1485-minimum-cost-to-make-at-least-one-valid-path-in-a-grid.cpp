class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        // mik wala approach, dijkstra
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currcost = curr[0];
            int i = curr[1];
            int j = curr[2];

            for (int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int grid_dir = grid[i][j];
                    int dircost = 0;

                    if (grid_dir - 1 != dir_i)
                        dircost=1;

                    int newcost = currcost + dircost;

                    if (newcost < ans[i_][j_]) {
                        ans[i_][j_] = newcost;
                        pq.push({newcost,i_,j_});
                    }
                }
            }
        }

        if(ans[m-1][n-1]==INT_MAX) return 0;

        return ans[m-1][n-1];
    }
};