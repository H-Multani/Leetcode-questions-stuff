class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int solve(int i, int m, vector<int>& p) {
        // agar range ke bahar hai toh 0 bhej do
        if (i >= n)
            return 0;

        // we here means jo bhi current banda hai usko score dena hai

        // toh for current banda we can take 1 pile,2 piles etc depending on M
        // ka value

        // toh M ke value ke hisab se chala do loop and best ans nikal kar bhej
        // dena

        // agar memo me ans hai bhej do
        if(memo[i][m]!=INT_MIN) return memo[i][m];

        // cout << "current at " << i << endl;
        int ans = INT_MIN;
        int ttl = 0;
        // i+x<n isliye so that index valid bhi toh ho
        for (int x = 1; x <= (2 * m) && i + x - 1 < n; x++) {
            ttl += p[i + x - 1];

            // agar x jitni piles uthai toh kya ans banega explore karo best leo

            // aage i+x wala bande se explore karna since i+x-1 wala banda toh
            // yaha count kar liya hai, and x sahi wala bhejna accd to formula
            // given in question

            // aage ke liye - kar dena since dusre bande ka turn hai, current
            // alice ka + score count hoga and bob ka -ve score count hoga
            ans = max(ans, ttl - solve(i + x, max(m, x), p));
        }
        cout << "best ans is " << ans << endl;
        return memo[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        // ok i think yaha par DFS laga sakte
        n = piles.size();
        // start from idx 0 and ofcourse alice ka turn hoga, alongwith that we
        // send M ka value too, ye m ka value change hoga, since iske hisab se
        // hi X ka value nikalenge

        // yaha instead of taking boolean for alice and bob we will take sum of
        // score of alice and usme se bob ka score - kar denge

        // toh like if overall score is +Ve means alice won, if overall score is
        // -ve means bob won

        // part 3 iss problem ka same type kiya hai

        // and dont worry the recursion will solve - wala dikkat , like if alice
        // ka score hai toh uske bahar wale 2 funcn calls will make the - into +

        // ok toh harne jeetne se kuch nai hai apan ko, bas alice ke stones
        // count karne hai, meaning apan nikal lete ki best score kya hoga alice
        // ka, and we know ki saare piles lenge hi

        // suppose x and y are alice and bob ka scores respectively

        // x+y=ttl stones
        // x-y= kitne stones se jeete
        // if -ve means bob jeetega, if +Ve means alice jeetega

        // first equation ttl nikal sakte yehi se
        // second equation DP laa kar dega
        // subtract both we get 2x=(ttl stone)+(kitne se jeeta)
        // means x=((ttl stone)+(kitne se jeeta))/2

        int ttl = 0;
        for (auto it : piles)
            ttl += it;

        // TLE dega memo laga do, i and m change here
        // i can go max till n and
        // m can also go max till n since x wala loop n ke range ke bahar jaane
        // nai dega
        memo.resize(n+1,vector<int>(n+1,INT_MIN));
        int kitnesejeeta = solve(0, 1, piles);
        return (ttl + kitnesejeeta) / 2;
        // idx 0 se start kar,  rahe hai, and initially m is 1
    }
};