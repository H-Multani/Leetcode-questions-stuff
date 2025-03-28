class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();

        // ans vector banao
        vector<int> ans(queries.size(), 0);

        // points bana lo
        int points = 0;

        // vector banao which will store queries with indexes
        vector<pair<int, int>> newquery;

        for (int i = 0; i < queries.size(); i++) {
            newquery.push_back({queries[i], i});
        }

        // ab newqueries me stores hai {query value,idx of query}
        // ab sort kardo new query ko
        sort(newquery.begin(), newquery.end());

        // toh isse kya hua ki smallest value waali queries start me aa gaii,
        // toh ab aage build kar sakte hai apan, like agar value 3 ke liye
        // points=4 hai, toh next value=5 ek liye iss previous ans 4 se aage
        // build karenge

        // ab pq bana lenge apan, which will store smallest value alongwith
        // location like {4,0,6}, ie grid me (0,6) par value 4 hai

        // lets just use vector to store stuff
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        // firstly pq me elft corner wala element dall do
        pq.push({grid[0][0], 0, 0});

        // ab ek index i lo which will terate over the new queries
        int i = 0;

        // ek visited vector bana lo so that ek location par 1 baaar hi jaaya
        // jaaye
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // (0,0) wale bande ko visited mark kardo
        vis[0][0] = true;

        // ab queries ke liye ek ek karke ans banate jao
        for (i = 0; i < queries.size(); i++) {
            // ab current query me BFS ka loop chalega
            // ye hint mik ne diya

            // current query ka value is
            int val = newquery[i].first;
            // current query ka index is
            int idx = newquery[i].second;

            // loop chala do jab tk pq empty na ho ya, value nikal gaii ho
            while (!pq.empty() && pq.top()[0] < val) {
                // current banda nikalo
                vector<int> curr = pq.top();
                pq.pop();

                // pq.top[0] is the value of top wala banda in the grid, agar
                // this value<val, means current query ke liye points abhi aa
                // sakte hai since we need ki grid ka value<query ka value

                // we are here means current top wala banda is counted for
                // points for current query, toh points +1 kardo
                points++;

                // ab current waale bande ke neighbours me jana hai apan ko
                // current bande ka coordinates are
                int x = curr[1], y = curr[2];

                // directions array bana lo
                vector<vector<int>> directions = {
                    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

                // {0,1} means new coordinates are(x,y+1), type shii

                for (auto nbr : directions) {
                    // new waale coordinates will be
                    int x_ = x + nbr[0];
                    int y_ = y + nbr[1];

                    // now we coordinates are (x_,y_)

                    // agar ye neighbour valid(index inbounds) hai and unvisited
                    // hai toh grid wali value value ke saath pq me daal do for
                    // firther processing
                    if (x_ < m && y_ < n && x_ >= 0 && y_ >= 0 &&
                        !vis[x_][y_]) {
                        // we here means ye nwighbour univisited hai, toh sabse
                        // pehle isko visited mark kado
                        vis[x_][y_] = true;

                        // ab isko grid ki value ke saath pq me daal do for
                        // further processing
                        pq.push({grid[x_][y_],x_,y_});
                    }
                }
            }

            // we are here means jitne points milne the saare mil chuke hai, ab
            // query ke correct index ke against ans me points daal do
            ans[idx] = points;

            // move to the next query
        }

        return ans;
    }
};