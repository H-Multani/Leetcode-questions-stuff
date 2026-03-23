class Solution {
public:
    int m, n;
    typedef long long ll;
    int mod = 1e9 + 7;
    long long ans;
    vector<vector<pair<ll, ll>>> memo;
    // yaha pair vapas aayenge, to indicate ki urrent element par best +Ve
    // and best -ve value hai available, aage konsi bhejni decide karenge
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        // base case
        if (i == m - 1 && j == n - 1) {
            // means apan end me aa chuke hai, return kardo

            // iss case me maxm and minm ka same value jayega aage which is
            // grid[i][j]
            return {grid[i][j], grid[i][j]};
        }

        // ab yaha maxval and minval lelo
        // maxval ka initial value MINM rahega
        ll maxval = LLONG_MIN;
        // minval ka initial value MAXM rahega
        ll minval = LLONG_MAX;

        // agar map me hai kuch toh bhej do yehi se
        if (memo[i][j] != make_pair(LLONG_MIN, LLONG_MAX))
            return memo[i][j];

        // yaha 2 options hai right and down

        // down se jo pair aaya nikalo
        if (i + 1 < m) {
            auto [downmax, downmin] = solve(i + 1, j, grid);

            // maxval and minval ko update kardo
            maxval = max({maxval, grid[i][j] * downmax, grid[i][j] * downmin});
            minval = min({minval, grid[i][j] * downmax, grid[i][j] * downmin});
        }

        // right se jo pair aaya nikalo
        if (j + 1 < n) {
            auto [rtmax, rtmin] = solve(i, j + 1, grid);
            // maxval and minval ko update kardo
            maxval = max({maxval, grid[i][j] * rtmax, grid[i][j] * rtmin});
            minval = min({minval, grid[i][j] * rtmax, grid[i][j] * rtmin});
        }

        // end me maxval and minval bhej denge

        // memo update kar dena

        memo[i][j] = {maxval, minval};
        return {maxval, minval};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // solve karo jo nikle btao

        // memoize karna padega, i,j changes toh 2D vo lelo, and return me pair
        // aa raha hai toh andar pair le lena

        // initialize karo yaha
        memo = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        // {LLONG_MIN,LLONG_MAX} -> initial vector
        // since first value is for max and second is for min

        auto [maxans, minans] = solve(0, 0, grid);

        // agar maxm ans -ve hua toh -1 bhej dena otherwise maxans hi bhej dena
        return (maxans < 0) ? -1 : maxans % mod;
    }
};