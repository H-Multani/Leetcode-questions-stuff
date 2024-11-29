#define pipii pair<int, pair<int, int>>
class Solution {
public:
    bool valid(int i, int j, int m, int n) {
        if ((i < m && i >= 0) && (j >= 0 && j < n))
            return true;

        return false;
    }
    // distance vector
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumTime(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        // edge case
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        // dist vector
        vector<vector<int>> distance(m, vector<int>(n, -1));
        // all nodes at dist -1 initially, -1 indicates ki uss node tak abhi
        // apan nai pahuche hai
        distance[0][0] = 0;
        // (0,0) is at dist 0 frm (0,0);

        // yehi par phatega, else to-fro karte karte time badha sakte hai apan

        // dijkstra ke liye pq bana do
        // pq stores <time frm curr node to reqd node,<x ccod of read node, y
        // coode of reqd node >>
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        // (0,0) ko push kardo pq me, since (0,0) is at time 0 hence
        pq.push({0, {0, 0}});

        // visited array, since peeche nai jana hai
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // dijkstra ka bfs chala do
        while (!pq.empty()) {
            // curr node ka dist is
            int currdist = pq.top().first;
            // curr node ka coordinates i and j
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i==m-1 && j==n-1){
                return currdist;
            }

            if (visited[i][j])
                continue;

            visited[i][j] = true;
            // check for (i-1,j)
            // if (valid(i - 1, j, m, n)) {
            //     // yaha 2 checks lagenge
            //     if (currdist + 1 >= grid[i - 1][j]) {
            //         distance[i - 1][j] = currdist + 1;
            //         pq.push({currdist + 1, {i - 1, j}});
            //     } else {
            //         if ((grid[i - 1][j] - currdist) % 2 == 1) {
            //             pq.push({grid[i - 1][j], {i - 1, j}});
            //             distance[i - 1][j] = grid[i - 1][j];
            //         } else {
            //             pq.push({grid[i - 1][j] + 1, {i - 1, j}});
            //             distance[i - 1][j] = grid[i - 1][j] + 1;
            //         }
            //     }
            // }
            // // check for (i+1,j)
            // if (valid(i + 1, j, m, n)) {
            //     // yaha 2 checks lagenge
            //     if (currdist + 1 >= grid[i + 1][j]) {
            //         distance[i + 1][j] = currdist + 1;
            //         pq.push({currdist + 1, {i + 1, j}});
            //     } else {
            //         if ((grid[i + 1][j] - currdist) % 2 == 1) {
            //             pq.push({grid[i + 1][j], {i + 1, j}});
            //             distance[i + 1][j] = grid[i + 1][j];
            //         } else {
            //             pq.push({grid[i + 1][j] + 1, {i + 1, j}});
            //             distance[i + 1][j] = grid[i + 1][j] + 1;
            //         }
            //     }
            // }
            // // check for (i,j-1)
            // if (valid(i, j - 1, m, n)) {
            //     if (currdist + 1 >= grid[i][j - 1]) {
            //         distance[i][j - 1] = currdist + 1;
            //         pq.push({currdist + 1, {i, j - 1}});
            //     } else {
            //         if ((grid[i][j - 1] - currdist) % 2 == 1) {
            //             pq.push({grid[i][j - 1], {i, j - 1}});
            //             distance[i][j - 1] = grid[i][j - 1];
            //         } else {
            //             pq.push({grid[i][j - 1] + 1, {i, j - 1}});
            //             distance[i][j - 1] = grid[i][j - 1] + 1;
            //         }
            //     }
            // }
            // // check for (i,j+1)
            // if (valid(i, j + 1, m, n)) {
            //     if (currdist + 1 >= grid[i][j + 1]) {
            //         distance[i][j + 1] = currdist + 1;
            //         pq.push({currdist + 1, {i, j + 1}});
            //     } else {
            //         if ((grid[i][j + 1] - currdist) % 2 == 1) {
            //             pq.push({grid[i][j + 1], {i, j + 1}});
            //             distance[i][j + 1] = grid[i][j + 1];
            //         } else {
            //             pq.push({grid[i][j + 1] + 1, {i, j + 1}});
            //             distance[i][j + 1] = grid[i][j + 1] + 1;
            //         }
            //     }
            // }

            // check for all (i-1,j),(i+1,j),(i,j-1),(i,j+1)
            for (auto it : direction) {
                int newi = i + it[0];
                int newj = j + it[1];

                if (!valid(newi, newj, m, n)) {
                    continue;
                }

                if (grid[newi][newj] <= currdist + 1) {
                    pq.push({currdist + 1, {newi, newj}});
                    distance[newi][newj] = currdist + 1;
                } else if ((grid[newi][newj] - currdist) % 2 == 0) {
                    pq.push({grid[newi][newj] + 1, {newi, newj}});
                    distance[newi][newj] = grid[newi][newj] + 1;
                } else {
                    pq.push({grid[newi][newj], {newi, newj}});
                    distance[newi][newj] = grid[newi][newj];
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};