class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        // t[i][j] means ki s1 of size i and s2 of size j ka LCA kya hai

        // toh by this method overall ans will be t[m][n], ie LCA of s1 of size
        // m, and s2 of size n

        // first row and first column will be 0 since, agar string ka size==0
        // hai toh kisse compare karoge

        // pehle column ko 0 kardo
        for (int row = 0; row < m + 1; row++) {
            t[row][0] = 0;
        }
        // pehle row ko 0 kardo
        for (int col = 0; col < n + 1; col++) {
            t[0][col] = 0;
        }

        // ab iss tabulation ko bharo
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                // curr banda is i,j

                // toh agar i-1 th char of s1 same as j=1 th char of s2
                if (s1[i - 1] == s2[j - 1]) {
                    // means char same hai

                    // next wale par jao, toh usially we wouldve done
                    // t[i+1][j+1] lekin yaha apan peeche se chalu krre hai toh
                    // ans aage se nai nikal sakte(since vo solved hi nai h
                    // abhi)

                    // toh instead ans nikalo peeche waale se
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    // means 2 options hai, ya toh i-1,j jao, ya toh i,j-1 jao

                    // dono me se jo maxm ans de vo lelo
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[m][n];
    }
};