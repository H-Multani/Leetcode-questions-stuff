class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        // mik wala solution chaega multisource BFS ka

        vector<vector<int>> ans(m, vector<int>(n, -1));

        // to keep track of already visited elements/positions
        // vector<vector<bool>> visited(m, vector<bool>(n));
        // no need for this, the -1 indicates that cell is not visited

        // queue for BFS, q stores (i,j) of the elements
        queue<pair<int, int>> q;

        // sabse pehle land dhundo, and queue me push kardo, update in visited
        // array as well
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    // this cell is water

                    // push this src to queue
                    q.push({i, j});

                    // visited mark kardo
                    // visited[i][j]=true;

                    // inka liye ans will be 0
                    ans[i][j] = 0;

                    // this is src for BFS
                }
            }
        }

        // BFS chala do
        while (!q.empty()) {

            // ab N nodes hai sabko ek baar me process karna hai, since multi
            // source BFS hai
            int N = q.size();

            // ek baar me saare nodes ko process karlo
            while (N--) {
                pair<int, int> curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                // iss location se 4 directions me jaao and ans update karo
                for (auto it : dir) {
                    // new posn ka index
                    int i_ = i + it[0];
                    int j_ = j + it[1];

                    // check if new posns are valid
                    if ((i_ < m && j_ < n && i_ >= 0 && j_ >= 0) &&
                        (ans[i_][j_] == -1)) {
                        // valid posn hai, and unvisited hai

                        // visit karlo, and update ans

                        ans[i_][j_] = ans[i][j] + 1;
                        // +1 only???, since maimize karna hai height ko, also
                        // making sure ki difference 1 se zyda na ho

                        // ab ye element will go to queue, for filling other
                        // positions
                        q.push({i_, j_});
                    }
                }
            }
        }

        return ans;
    }
};