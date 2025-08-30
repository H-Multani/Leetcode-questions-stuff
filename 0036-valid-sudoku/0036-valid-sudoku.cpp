class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // har row me freq <2 honi chahiye, har column me freq <2 honi chahiye,
        // har 3x3 ke grid me freq <2 honi chahiye

        // check each row

        for (auto it : board) {
            unordered_map<char, int> mpp;

            for (auto it2 : it) {
                mpp[it2]++;
            }

            mpp.erase('.');
            for (auto it : mpp) {
                if (it.second > 1) {
                    return false;
                }
            }
        }

        // check each column
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> mpp;
            for (int j = 0; j < 9; j++) {
                mpp[board[j][i]]++;
            }
            mpp.erase('.');
            for (auto it : mpp) {
                if (it.second > 1)
                    return false;
            }
        }

        // check each 3x3 sub board
        // iss se start karke 3x3 me chalo, take use from lc 37

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_map<char, int> mpp;

                for (int k = 0; k < 9; k++) {
                    mpp[board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]]++;
                }

                mpp.erase('.');
                for (auto it : mpp) {
                    if (it.second > 1)
                        return false;
                }
            }
        }

        // means sab places par values rakhh sakte hai easily, return true since
        // board valid hai
        return true;
    }
};