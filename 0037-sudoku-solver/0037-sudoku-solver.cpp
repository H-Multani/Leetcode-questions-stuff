class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        bool ans = solve(board);
        return;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // agar current banda empty hai
                if (board[i][j] == '.') {
                    // yaha se elements bharna chalu karo
                    for (char c = '1'; c <= '9'; c++) {
                        // curr char daal kar dekho

                        // valid hai curr char toh explore
                        if (valid(board, i, j, c)) {
                            // means yaha cur char rakh sakte h, explore further
                            // do
                            board[i][j] = c;

                            // explore
                            if (solve(board)) {
                                // we here means ans mil gaya hai
                                // return true frm here
                                return true;
                            } else {
                                // undo
                                board[i][j] = '.';
                            }
                        }
                    }

                    // we here means curr empty char ke liye kuch nai mila,
                    // return false
                    return false;
                }
            }
        }
        return true;
        // agar saare char already filled honge toh if wale me jayenge hi nai,
        // toh means board is filled, return true
    }

    bool valid(vector<vector<char>>& board,int row,int col, char c){
        for(int i=0;i<9;i++){
            // agar current column me kahi bhi mila ye char toh return false
            if(board[i][col]==c) return false;
            // agar current row me kahi bhi mila ye char toh return false
            if(board[row][i]==c) return false;

            // agar current sub box me mile toh return false
            if(board[3*(row/3)+ i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }
};