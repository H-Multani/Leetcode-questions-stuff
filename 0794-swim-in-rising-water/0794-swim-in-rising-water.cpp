#define pipii pair<int, pair<int, int>>

class Solution {
public:
    int m, n;
    bool valid(int i, int j) {
        if ((i < m && i >= 0) && (j >= 0 && j < n))
            return true;

        return false;
    }
    // distance vector
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        // simple dijkstras algo will work here

        m = grid.size();
        n = grid[0].size();

        // dijkstras ke liye result vector bana lo
        vector<vector<int>> dist(m, vector<int>(n, -1));
        // starting frm (0,0) toh uska dist store karlo
        dist[0][0] = grid[0][0];

        // pq bana lo which will store minm dist and location of cell, ki iss
        // cell tak aane ke liye minm dist itna laga bass
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        // we do this since we need smallest dist/time at top

        // (0,0) wale ko pq me daal do alongwith its time which is grid[0][0],
        // since itne time tak toh minm rukna padega apan ko to travel anywhere
        pq.push({grid[0][0], {0, 0}});

        // visited array bana lo since peeche nai jana hai
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // dijkstras ka bfs chala do ab
        while (!pq.empty()) {
            // current top wala banda nikalo, distance and coordinates
            int currdist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            // cout << "at " << i << " " << j << endl;

            // agar ye node already visited hai toh rehen do, since jab yaha
            // first time visit kiye honge vo already minm wala dist hua hoga,
            // and ab 2nd time visit karre hai toh obviously dist will be more
            // than last time, toh why save the newer distance which is more,
            // since apna kaam toh minm dist se hai na
            if (vis[i][j]) {
                continue;
            }

            // agar (m-1,n-1) wala mile toh yehi se bhej do
            if (i == m - 1 && j == n - 1)
                return currdist;

            // current location ko visited mark kardo
            vis[i][j] = true;

            // we here means this place is new location, explore all 4
            // directions

            for (auto it : direction) {
                // new i,j nikalo
                int newi = i + it[0];
                int newj = j + it[1];

                // kya location valid hai
                if (!valid(newi, newj)) {
                    // means new location not valid, aage badho
                    continue;
                }

                // explore new location simply, time ke liye new wale location
                // ka time and currtime ka maxm le lena bass, since building
                // climb karne ke liye itna time minm lagega to fill water, maxm
                // isliye since new building can be smalelr than current water
                // level or it can be taller than current water level, dono case
                // me apan ko maxm time rukna padega bass
                pq.push({max(currdist, grid[newi][newj]), {newi, newj}});
                // dist update kardo
                dist[newi][newj] = max(currdist, grid[newi][newj]);
            }
        }

        // ab simply bas (m-1,n-1) wale ka dist nikal kar bhej do
        return dist[m - 1][n - 1];
    }
};