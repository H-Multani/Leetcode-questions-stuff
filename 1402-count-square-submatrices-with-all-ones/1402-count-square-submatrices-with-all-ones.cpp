class Solution {
    int m, n;

public:
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& memo) {
        if (i >= m || j >= n)
            return 0;

        if (matrix[i][j] == 0)
            return 0;

        if (memo[i][j] != -1) {
            // agar memory me hai, yehi se return kardo answer for urrent (i,j) wala banda
            return memo[i][j];
        }

        int right = solve(i, j + 1, matrix, memo);
        int down = solve(i + 1, j, matrix, memo);
        int diagonal = solve(i + 1, j + 1, matrix, memo);

        // answer for this [i][j] will be stored to memo[i][j]
        memo[i][j] = 1 + min({right, diagonal, down});
        // so that agar iss (i,j) par kabhi phir se aaye toh already pata rahe
        // ki iss curent (i,j) ke neeche/right/diagonal me kitne 1 hai

        // ie basically iss (i,j) ke liye answer yaad rahe apne ko pehle se, nai
        // toh same chez ke liye baar baar calculation hoga

        return 1 + min({right, diagonal, down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int ans = 0;

        // tle phek rha, memoization karna padega
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    ans += solve(i, j, matrix, memo);
                }
            }
        }

        return ans;
    }
};