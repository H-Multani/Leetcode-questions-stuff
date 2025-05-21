class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // boolean array lelo 2, phir matrix par iterate karo, agar 0 mile (i,j)
        // par toh i th row ke against false krdena and j th column ke against
        // false kar dena

        // phir ek baar iterate karke update kar dena
        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n, true);
        vector<bool> col(m, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = false;
                    col[j] = false;
                }
            }
        }

        // now we have ki konsi wali rows and konse cols me 0 bharne hai

        // ab ek baar matrix par iterate karke update kardo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!row[i] || !col[j]) {
                    // we here means ya toh i th row me kahi 0 mila h, ya j th
                    // column me 0 mila hai, and since current banda
                    // matrix[i][j] is in both i th row and j th column, hence
                    // iska against 0 kar do
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};