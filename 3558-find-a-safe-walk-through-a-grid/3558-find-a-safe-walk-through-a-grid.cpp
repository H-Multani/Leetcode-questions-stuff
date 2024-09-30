using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
class Solution {
    int row, col;
    bool isvalid(int i, int j) {
        // checks if i and j are valid values
        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;

        return true;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // dijkstra ka logic laga do,but keep a visited array, since we can go
        // up, down, right , left make sure ki already visited se naa jaaye
        row = grid.size();
        col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        // since we go up, down ,right,left, and dont want to visit already
        // visited nodes

        // dijkstra wala pq banao
        priority_queue<pair<int, pair<int, int>>> pq;
        // this pq stores {curr posn par health, {curr posn ka i, curr posn ka
        // j}} normal pq, stores bigest value at top, since apan full health
        // leke chalenge at start, and requirement ke hisaab se + or - karenge
        // health ko, making sure that the biggest health stays at top and if
        // end me pohoch kar health +ve mil gai, return true, else return false

        // if starting is 1, reduce health by 1
        if (grid[0][0] == 1)
            health--;
        // if health reaches 0 return false
        if (health == 0)
            return false;

        // starting with index {0,0} and updated health(original value if
        // starting posn(0,0) pr 1 nai hai)

        pq.push({health, {0, 0}});
        // set currrent location as visited
        visited[0][0] = true;
        // ab dijkstra wala loop chalao
        while (!pq.empty()) {
            // current wala health
            int currhealth = pq.top().first;
            // current wala i and j
            int curr_i = pq.top().second.first;
            int curr_j = pq.top().second.second;
            cout << currhealth << endl;

            pq.pop();
            // if health reaches 0, return false;
            if (currhealth == 0)
                return false;

            if (curr_i == row - 1 && curr_j == col - 1) {
                cout << currhealth << endl;
                // means apan +ve health ke saath end par aa chuke hai, means
                // path mil gaya hai, return true
                return true;
            }

            // now we go up,down, right,left

            // for up, new index is (i-1,j)
            // only go up if new i and j are valid and unvisited
            if (isvalid(curr_i - 1, curr_j) && !visited[curr_i - 1][curr_j]) {
                // go up side
                // health update karo
                cout << " going up" << endl;
                // currhealth -= grid[curr_i - 1][curr_j];

                // new coordinate par jaa rahe hai, visited kar do
                visited[curr_i - 1][curr_j] = true;
                // new coordinates ko push kar do, with new health
                pq.push({currhealth - grid[curr_i - 1][curr_j],
                         {curr_i - 1, curr_j}});
            }

            // for down, new index is (i+1,j)
            // only go up if new i and j are valid and unvisited
            if (isvalid(curr_i + 1, curr_j) && !visited[curr_i + 1][curr_j]) {
                // go up side
                // health update karo
                cout << " going down" << endl;
                // currhealth -= grid[curr_i + 1][curr_j];
                // new coordinate par jaa rahe hai, visited kar do
                visited[curr_i + 1][curr_j] = true;
                // new coordinates ko push kar do, with new health
                pq.push({currhealth - grid[curr_i + 1][curr_j],
                         {curr_i + 1, curr_j}});
            }

            // for right, new index is (i,j+1)
            // only go up if new i and j are valid and unvisited
            if (isvalid(curr_i, curr_j + 1) && !visited[curr_i][curr_j + 1]) {
                // go up side
                // health update karo
                cout << " going right" << endl;
                // currhealth -= grid[curr_i][curr_j + 1];
                // new coordinate par jaa rahe hai, visited kar do
                visited[curr_i][curr_j + 1] = true;
                // new coordinates ko push kar do, with new health
                pq.push({currhealth - grid[curr_i][curr_j + 1],
                         {curr_i, curr_j + 1}});
            }

            // for left, new index is (i,j-1)
            // only go up if new i and j are valid and unvisited
            if (isvalid(curr_i, curr_j - 1) && !visited[curr_i][curr_j - 1]) {
                // go up side
                // health update karo
                cout << " going left" << endl;
                // currhealth -= grid[curr_i][curr_j - 1];
                // new coordinate par jaa rahe hai, visited kar do
                visited[curr_i][curr_j - 1] = true;
                // new coordinates ko push kar do, with new health
                pq.push({currhealth - grid[curr_i][curr_j - 1],
                         {curr_i, curr_j - 1}});
            }
        }

        // we here means apan end tak nai pohoch paaye, return false
        return false;
    }
};
