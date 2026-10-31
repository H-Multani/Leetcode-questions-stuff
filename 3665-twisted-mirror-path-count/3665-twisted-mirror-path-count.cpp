class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    // denotes ki banda left se aaya ya upar se
    // if current node pr khade left ka value mila means apan current node par
    // left se aaye hai and vice versa
    int left = 0, up = 1;
    int solve(int i, int j, vector<vector<int>>& grid, int camefrom,vector<vector<array<int, 2>>>& memo) {
        // agar out of range hai toh return 0
        if (i >= m || j >= n)
            return 0;

        // agar (m-1,n-1) pahuch gaye toh
        if (i == m - 1 && j == n - 1) {
            // 1 path mil gaya
            return 1;
        }

        // memo me hai toh yehi se bhejdo
        if(memo[i][j][camefrom]!=-1) return memo[i][j][camefrom];

        // ab yaha 2 cases ho sakte hai
        if (grid[i][j] == 1) {
            // means apan mirror par aaye hai

            // toh yaha rukenge nai bilkul bhi

            // agar current node par left se aaye hai (ie previous node me right
            // gaye honge)
            if (camefrom == left) {
                // means apan left se aaye hai toh down chale jayenge yehi se

                // since apan yaha se down jaa rahe hai toh aage wale node ke
                // liye apan UP se aaye matlab yehi up bhej denge camefrom me
                return memo[i][j][camefrom]=solve(i + 1, j, grid, up,memo);
            } else {
                // means apan up se aaye hai toh right chale jayenge yehi se

                // since apan yaha se right jaa rahe hai toh aage wale node ke
                // liye apan LEFT se aaye matlab yehi left bhej denge camefrom
                // me
                return memo[i][j][camefrom]=solve(i, j + 1, grid, left,memo);
            }
        }

        // we here means apan 0 par hai, yaha ka case simple hai dono raste
        // explore karke dekh lo

        int ans = 0;

        // right jaa kar dekho, and since apan yaha se right jaa rahe means aage
        // wale node ke liye apan left se aaye, toh yehi left bhejna camefrom me
        ans = (ans + solve(i, j + 1, grid, left,memo)) % mod;
        // down jaa kar dekho, and since apan yaha se down jaa rahe means aage
        // wale node ke liye apan up se aaye, toh yehi up bhejna camefrom me
        ans = (ans + solve(i + 1, j, grid, up,memo)) % mod;

        // ab ans bhej do
        return memo[i][j][camefrom]=ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // TLE fatega pakka pakka, yaha 3 things change, i,j,camefrom
        // i,j-> n tak jayega max
        // camefrom-> ya left ya up, toh only 2 values toh array lelo, -1 to
        // indicate ki yaha nai aaye abhi tak
        vector<vector<array<int, 2>>> memo(m + 1,
                                           vector<array<int, 2>>(n, {-1, -1}));

        // 0,0 par start karenge, ab yaha par toh kahi se bhi aye hai koi bhi
        // lelo kya hi hai direction
        return solve(0, 0, grid, left,memo);
        // yaha maine left se mana aaya hai, up daal do same effect padega
    }
};