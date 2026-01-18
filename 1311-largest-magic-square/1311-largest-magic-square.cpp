class Solution {
public:
    bool valid(int i, int j, vector<vector<int>>& grid, int k) {
        // first row ka sum karlo and sabme check karte jana
        long long ttl = 0;

        for (int l = 0; l < k; l++) {
            ttl += grid[i + l][j];
        }

        // loop chalao and row sum nikalte jana, check karate jana, same stuff
        // with column sum, nikalte jana and check karate jana, as for diagonal
        // sum, nikal lena dono diagonal ke sum, end me check kar lena

        // ek loop chala denge row sum ke liye, usme hi diagonal sum nikal lenge
        long long diag1 = 0, diag2 = 0;

        for (int row = 0; row < k; row++) {
            // row sum nikalo
            long long sm = 0;
            //  sum nikalo
            long long sm2 = 0;
            for (int col = 0; col < k; col++) {
                sm += grid[i + row][j + col];
                sm2 += grid[i + col][j + row];

                // agar diagonal ka part hai toh add kardo
                if (row == col) {
                    diag1 += grid[i + row][j + col];
                }
                if (row + col == k - 1) {
                    diag2 += grid[i + row][j + col];
                }
            }

            // agar row ka sum not same as ttl, means nai hai grid valid
            if (sm != ttl || sm2!=ttl)
                return false;
        }

        // diagonal ke sum check karlo
        if (diag1 != ttl || diag2 != ttl)
            return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int kmax = min(m, n);
        int ans = -1;

        // har possible size ka grid chla kar dekhna
        for (int k = 1; k <= kmax; k++) {

            // har possible position se chalu karke dekhna
            for (int i = 0; i < n - k+1; i++) {
                for (int j = 0; j < m - k+1; j++) {

                    if (valid(i, j, grid, k)) {
                        // means valid hai i side length ka matrix, ans update
                        // kardo
                        ans = k;
                    }
                }
            }
        }

        return ans;
    }
};