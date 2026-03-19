class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // lc 3070 wala logic but usme ek value ka prefix bana rahe the, yaha
        // pair ka prefix banayenge, baaki sab same, since 3070 me bhi [0][0] ko
        // include karke submatrice banane the, yaha bhi same karna hai exactly

        int m = grid.size();
        int n = grid[0].size();

        // yaha pair ka prefix banayenge, pair ka first is x count, second is y
        // count
        vector<vector<pair<int, int>>> arr(
            m, vector<pair<int, int>>(n, pair<int, int>({0, 0})));

        // initial value set kardo, x and y cnt alag se
        if (grid[0][0] == 'X') {
            arr[0][0].first = 1;
        }
        if (grid[0][0] == 'Y') {
            arr[0][0].second = 1;
        }

        // prefix sum se bhar do
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    continue;

                // jo kaam pehle ek value ke liye karte the, ab same kaam,same
                // exact formula lagao 2 baar for x cnt and y cnt
                if (grid[row][col] == 'X') {
                    arr[row][col].first = 1;
                }
                if (grid[row][col] == 'Y') {
                    arr[row][col].second = 1;
                }

                // ab first and second (ie x and y cnt) dono update kardo ek
                // sath
                if (row - 1 >= 0) {
                    // og formula
                    // arr[row][col] += arr[row - 1][col];

                    // for x
                    arr[row][col].first += arr[row - 1][col].first;
                    // for y
                    arr[row][col].second += arr[row - 1][col].second;
                }
                if (col - 1 >= 0) {
                    // og formula
                    // arr[row][col] += arr[row][col - 1];

                    // for x
                    arr[row][col].first += arr[row][col - 1].first;
                    // for y
                    arr[row][col].second += arr[row][col - 1].second;
                }

                if (row - 1 >= 0 && col - 1 >= 0) {
                    // og formula
                    // arr[row][col] -= arr[row - 1][col - 1];

                    // for x
                    arr[row][col].first -= arr[row - 1][col - 1].first;
                    // for y
                    arr[row][col].second -= arr[row - 1][col - 1].second;
                }
            }
        }

        int ans = 0;
        for (auto it : arr) {
            for (auto [xcnt, ycnt] : it) {
                // agar x and y ka cnt same hua and freq of x is atleast 1, then
                // consider this banda for ans
                if (xcnt == ycnt && xcnt > 0)
                    ans++;
            }
            // cout<<endl;
        }

        return ans;
    }
};