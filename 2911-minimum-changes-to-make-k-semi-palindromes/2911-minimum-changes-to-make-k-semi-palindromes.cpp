class Solution {
public:
    int n;
    string s;
    vector<vector<int>> costmemo;
    vector<vector<int>> memo;

    int getcost(int i, int j) {
        // means [i,j] tak ki range me bifurcation karna hai ab

        // length will be
        int len = j - i + 1;

        // memo me ans hai toh bhej do
        if (costmemo[i][j] != -1)
            return costmemo[i][j];

        int ans = INT_MAX;

        // ab apan ko current string me d dabbe banane hai exactly

        // toh d ke values par iterate karenge such that len%d==0 since tabhi
        // toh exact d size ke dabbe banenge,

        // har dabbe ka string banega like
        // string is characters i,i+d,i+2d,i+3d....

        // ie groups will be like
        // 0,0+d,0+2d.....
        // 1,1+d,1+2d.....
        // 2,2+d,2+2d.....
        // ....
        // d-1,(d-1)+d,(d-1)+2d.....

        // chala do loop
        for (int d = 1; d < len; d++) {
            // means exact d size ke grps nai banenge toh kyu explore karna
            if (len % d != 0)
                continue;

            // jitne grps banenge cost nikal lo
            int cost = 0;

            // groups bana lo
            for (int group = 0; group < d; group++) {
                // for d, we have d groups, bole toh
                // 0,0+d,0+2d.....
                // 1,1+d,1+2d.....
                // 2,2+d,2+2d.....
                // ....
                // d-1,(d-1)+d,(d-1)+2d.....

                // current grp ka string ka chars wil be like
                // (i+group),(i+group)+d,(i+group)+2d,......
                // string banane se accha direct idx se check kara lo
                int l = i + group;
                // right wala bande ke liye l se start karenge

                // len ko d ke dabbo me baatna tha toh last wala banda len/d -1
                // wale posn par hoga toh idx will be like
                // l,l+d,l+2d,.....l+(len/d-1)*d

                // toh overall current string ke liye l=i+group and r will be
                // l+(len/d-1)*d
                int r = l + (len / d - 1) * d;

                // chala do loop direct compare karlo
                while (l < r) {
                    if (s[l] != s[r])
                        // means string nai hai palindrome, yaha ek cost lagega
                        // cost badha do
                        cost++;
                    // ab since d ka step lagega toh l increases by d and r
                    // decreases by d
                    l += d;
                    r -= d;
                }
            }

            // ab minm cost mili hai jo bhi ans me daal do
            ans = min(ans, cost);
        }

        return costmemo[i][j] = ans;
    }

    int solve(int start, int k) {
        // base case
        if (k == 0) {
            // means saare parts ban chuke hai
            if (start != n) {
                // means s ke kuch char abhi bache hai jo kisi bhi part me nai
                // gaye, iss case me invalid ans banega hence return INT_MAX
                return INT_MAX;
            } else {
                // we here means idx bhi saare khatam ho gye hai, iss case me
                // ans valid banega return 0
                return 0;
            }
        }

        // early return wala minor optimization
        // agar mai current idx par khada and abhi yaha se aage 2-2 length ka k
        // piece banaoge toh total idx pahuchna chahiye start+2k

        // agar ye start+2k>n ho gaya means yaha aage partition karne ka koi
        // sense nai hai iss case se early return lelo since aage banega hi nahi
        if (start + (2 * k) > n)
            return INT_MAX;

        // memo me ans hai toh bhej do
        if (memo[start][k] != -1)
            return memo[start][k];

        // ans lelo
        int ans = INT_MAX;

        // ab minm 2 size ka piece chahiye apan ko toh start idx se minm start+1
        // toh hoga hi current dabba string, means end ka value kam se kam
        // start+1 hoga and ending toh n tak jaa sakte
        for (int end = start + 1; end < n; end++) {
            // we here means start...end ek piece hai, ie [start,...,end]

            // iske aage agla piece will start from end+1 toh aage se uska cost
            // nikal lo explore karke
            int remaining = solve(end + 1, k - 1);
            // k-1 since ek dabba yaha bana liya na

            // edge case, agar remaining cost INT_MAX aaya means aage invalid
            // banega yehi se rok do
            if (remaining == INT_MAX)
                continue;

            // ab [start...end] tak ka cost nikal lo and ans update kardo

            // yaha case ka ans hoga current dabbe ka cost+ aage ka cost->
            // getcost(start,end)+remaining

            // ans update kardo minm cost chahiye
            ans = min(ans, getcost(start, end) + remaining);
        }

        // jo minm hai bhej do
        return memo[start][k] = ans;
    }

    int minimumChanges(string s, int k) {
        this->s = s;

        n = s.size();

        // 2 memo lagenge apan ko yaha ek cost minimize karega aur ek solve ko
        // minimize karega

        // cost ke liye i and j change hora bass, which can be at best n each
        // laga do
        costmemo.assign(n + 1, vector<int>(n + 1, -1));
        // solve ke liye 2 cheez change hori idx(best n tak jayega) and k ka
        // value, which can be at best k, toh laga do
        memo.assign(n + 1, vector<int>(k + 1, -1));

        return solve(0, k);
        // since idx 0 se start karenge and k pieces karne hai total string ke
    }
};