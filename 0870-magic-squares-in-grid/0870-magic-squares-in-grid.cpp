class Solution {
public:
    bool valid(int i, int j, vector<vector<int>>& grid) {

        // we here means we are at a valid 3x3 matrix

        // pehle check karo ki distinct elements hai ki nahi
        unordered_set<int> st;
        for (int row = i; row < i + 3; row++) {
            for (int col = j; col < j + 3; col++) {
                if (st.find(grid[row][col]) == st.end()) {
                    // means distinct chalra abhi tak toh
                    st.insert(grid[row][col]);
                } else
                    // we here means repeat hore elements which is wrong
                    return false;
            }
        }

        // 1-9 wale nahi hoye grid me toh means its not magic square
        for (int i = 1; i < 10; i++) {
            // agar 1-9 ke beech wala koi bhi banda grid me nai hua means its
            // not magic
            if (st.find(i) == st.end()) {
                // means ye banda grid me nahi hai return false since magic grid
                // me toh 1-9 wale bnde hote hai bass
                return false;
            }
        }

        // saari rows ka sum same hona chahiye
        int ttl = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        // first row ka sum nikal lo vahi sum baaki sab me check karenge
        // for (int start = i; start < i + 3; start++) {
        //     ttl += grid[0][start];
        // }

        // ab yehi ttl sab me check karenge

        // first check for row sum
        int row1 = 0, row2 = 0, row3 = 0;
        row1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        row2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        if (row1 != ttl || row2 != ttl || row3 != ttl)
            return false;
        // for (int row = i; row < i + 3; row++) {
        //     int rowsum = 0;
        //     for (int col = j; col < j + 3; col++) {
        //         rowsum += grid[row][col];
        //     }

        //     // rows ka sum common nai aaya means galat hai return false
        //     if (rowsum != ttl)
        //         return false;
        // }

        // check for columns sum
        int col1 = 0, col2 = 0, col3 = 0;
        col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        if (col1 != ttl || col2 != ttl || col3 != ttl)
            return false;
        // for (int row = i; row < i + 3; row++) {
        //     int colsum = 0;
        //     for (int col = j; col < j + 3; col++) {
        //         colsum += grid[col][row];
        //     }

        //     // rows ka sum common nai aaya means galat hai return false
        //     if (colsum != ttl)
        //         return false;
        // }

        // diagonals check karlo

        // diag1 sum will be (0,0),(1,1),(2,2)
        // diag2 sum will be (0,2),(1,1),(2,0)
        // (i,j) ke liye add kar dena i,j aur kya

        int diag1sum = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diag2sum = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        if (diag1sum != ttl || diag2sum != ttl)
            return false;

        // we here means columns sab same sum ke hai, rows sab same sum ki hai
        // aur diagonals bhi sab same sum ke hai, and saare elements distinct
        // hai toh means its a magic square, return true
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // count karlo

        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                // n-2 and m-2 since, we take 3x3 matrix from (i,j) onwards, toh
                // rows go i,i+1,i+2, and columns go j,j+1,j+2, toh bass valid
                // ho vahi kaafi hai

                if (valid(i, j, grid)) {
                    // agar (i,j) se start hone wala 3x3 matrix is magic square
                    // then count it
                    ans++;
                }
            }
        }

        return ans;
    }
};