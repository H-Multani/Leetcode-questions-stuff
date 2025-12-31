class Solution {
public:
    int row, col;

    bool DFS(int i, int j, vector<vector<int>>& grid) {
        // base case, agar current location par water hai toh return false since
        // no path possible
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1) {
            // means ya ye invalid hai ya toh water hai, such case me return
            // false
            return false;
        }

        // base case, agar we have reached last row, means path is possible
        if (i == row - 1) {
            // means path is possible, in such case return true
            return true;
        }

        // we here means (i,j) se har possible direction me explore karna hai

        // sabse pehle current location par visited mark karo
        grid[i][j] = 1;
        // 1 means water hai ab yaha, but apan isko visited bhi maan sakte hai,
        // since agar yaha par backtrack kar rahe hai means yaha se aage koi
        // path valid nahi hai, toh agar aage vapas aayenge yaha toh phokat me
        // time waste hoga since path toh hai nai yaha se, toh why even keep the
        // option, mark kardo seedha as visited, so that aage wala new path koi
        // yaha se fir se explore karke time waste na kare

        // also agar yaha se path milna hoga toh backtrack karne ka need hi nai
        // banega since true return ho jayega seedha seedha(aisa surity kaise??
        // , ho sakta na ki current blocked path could be used by another for a
        // possible ans, lekin nai, since agar ans ka rasta banna tha toh
        // current path se hi pahuch jata since apan yaha possible path dhund
        // rahe hai smallest path nahi)

        // means visited hai ab ye, vapas peeche nai
        // jayega, agar yaha se path milna hoga toh aa jayega true , nai toh ye
        // path block ho jaega since yaha par re-explore nai karenge apan

        // ab current (i,j) se 4 directions me explore karo
        return DFS(i + 1, j, grid) || DFS(i, j + 1, grid) ||
               DFS(i - 1, j, grid) || DFS(i, j - 1, grid);

        // 4 path me se koi bhi agar true de diya means possible hai top to
        // bottom jana in such case return that true
    }

    bool cancross(vector<vector<int>>& cells, int mid) {
        // pehle mid jitne bando ko water mark karo

        // initial grid me all land hai

        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i <= mid; i++) {

            // -1 since 1 based indexing
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        // ab first row me har possible column se start karke path par DFS maar
        // kar dekho agar cross kar sakte hai, if yes means we can cross, send
        // true
        for (int i = 0; i < col; i++) {

            // pehle toh we start from grid[0][i], toh agar yaha pehle se water
            // hua toh cannot start, if grid[0][i]==0 means land we can start
            // from here
            if (grid[0][i] == 0 && DFS(0, i, grid)) {

                // DFS me we send 0,i since we start from coordinate (0,i) for
                // exploration of path we here means path possible hai
                return true;
            }
        }

        // we here means path nai hai possible
        return false;
    }

    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        // binary search ke sath DFS lagana padega
        row = R;
        col = C;

        // binary search
        int l = 0, r = cells.size() - 1;

        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // kya ye mid jitne days agar le, toh apan cross kar payenge??
            if (cancross(cells, mid)) {
                // means we can cross, update ans
                ans = mid + 1;
                // mid+1 since mid is 0 based count, if mid=3 means 4 days have
                // passed like 0,1,2,3, toh ans count me mid+1

                // ho sakta hai better ans ho right me go right
                l = mid + 1;
            } else {
                // we here means nai cross kar payenge , left me valid possible
                // ans dhundo
                r = mid - 1;
            }
        }

        return ans;
    }
};