class Solution {
public:
    int m, n;
    int memo[100][100][201];
    bool solve(int i, int j, vector<vector<char>>& grid, int cnt) {
        // process current cell
        cnt += (grid[i][j] == '(') ? 1 : -1;

        // agar kahi bhi cnt<0 hua toh return false
        if (cnt < 0)
            return  false;

        // agar edge par aa chuke hai
        if (i == m - 1 && j == n - 1) {
            // check cnt, if its 0, means its valid, return true, else return
            // false
            if (cnt == 0)
                return true;
            return false;
        }

        // memo me ans hai toh bhej do, current bande ko process karne ke baad
        // memo chek karo
        if (memo[i][j][cnt] != -1)
            return memo[i][j][cnt];

        bool ans = false;

        // right and neeche jaane ka dekho

        // right jaane ka dekho
        if (j + 1 < n) {
            ans = ans | solve(i, j + 1, grid, cnt);
        }

        if (i + 1 < m) {

            ans = ans | solve(i + 1, j, grid, cnt);
        }

        return memo[i][j][cnt] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        // stack maintain karne ka need nai hai ig, since har open kisi close se
        // hi lagega, bas ek check karna padega ki count of open>=count of close
        // at all times, nai toh pata chala jitne open the usse zyada close wale
        // mil gaye ye dikkat

        // ya usko simulate krne ke liye we can keep a count, if ( mila toh
        // count increase, if ) mila toh count decrease, at any point cnt should
        // not reach -ve
        m = grid.size();
        n = grid[0].size();

        // agar starting hi closing bracket hai means kuch nai ho sakta give
        // false
        if (grid[0][0] == ')')
            return false;

        // ye pakka TLE patkega, 3 things change, i,j and cnt, i,j can reach
        // 100, cnt at best can reach 50, and since har posn par boolean ans
        // aayega wahi store kar lo, int leke chalenge type apan since -1 to
        // indicate ki yaha nai explore kiye hai, 0 to indicate false, 1 to
        // indicate true
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, grid, 0);
    }
};