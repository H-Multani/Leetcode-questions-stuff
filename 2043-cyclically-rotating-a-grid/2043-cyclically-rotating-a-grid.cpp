class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        // similar to spiral matrix

        // har array nikal lo cycle karlo, reset kardo original posns par, thats
        // all

        int m = grid.size();
        int n = grid[0].size();

        // left,rt,top,down nikal lo
        int l = 0, r = n - 1, top = 0, down = m - 1;

        // ab loop chal do

        while (l <= r && top <= down) {
            // vector bana lo which will be rotated
            vector<int> temp;
            // ab spiral me elements bhar do,in order

            // top to down jao pehle toh
            for (int i = top; i <= down; i++) {
                temp.push_back(grid[i][l]);
            }

            // ab left to right jao, starting from l+1, since upar wale loop ne
            // last element utha liya already, no need to repeat again
            for (int i = l + 1; i <= r; i++) {
                temp.push_back(grid[down][i]);
            }

            // ab down to top jao, start from down-1, since down idx wala
            // element already considered in prev loop
            for (int i = down - 1; i >= top; i--) {
                temp.push_back(grid[i][r]);
            }

            // ab right to left jao, start from r-1 since r idx wala element
            // already considered in prev loop

            // also stop at l+1 instead of l since l wala element will be the
            // very first element we had already considered in the very first
            // loop

            for (int i = r - 1; i > l; i--) {
                temp.push_back(grid[top][i]);
            }

            // now we have the spiral wale elements of current layer, rotate
            // kardo

            int len = temp.size();
            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[(i + k) % len] = temp[i];
            }

            // ab ye rotated array par chal kar saare elements original array me
            // hi place kardo, jis order me nikale the same exact order me

            // toh value extraction wala loop reused here same , bass yaha apan
            // ko elements rakhne hai rotated array se nikal kar ab
            int idx = 0;
            for (int i = top; i <= down; i++) {
                grid[i][l] = rotated[idx];
                idx++;
            }
            for (int i = l + 1; i <= r; i++) {
                grid[down][i] = rotated[idx];
                idx++;
            }
            for (int i = down - 1; i >= top; i--) {
                grid[i][r] = rotated[idx];
                idx++;
            }
            for (int i = r - 1; i > l; i--) {
                grid[top][i] = rotated[idx];
                idx++;
            }

            // now elements have been placed, saare pointers badha do aage, left
            // aage badhega, right peeche aayega ek bari, top badhega, down
            // peeche aayega ek bari
            top++;
            l++;
            r--;
            down--;
        }

        return grid;
    }
};