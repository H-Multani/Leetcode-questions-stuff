class Solution {
public:
    int m, n;
    bool valid(int i, int j) {
        if ((i >= 0 && i < m) && (j >= 0 && j < n))
            return true;
        return false;
    }
    bool solve1(int i, int j, vector<vector<int>>& h, vector<vector<bool>>& vis,
                vector<vector<int>>& m1) {
        // base case, agar pacific edges par aa gaye hai toh return
        // true
        if (i == 0 || j == 0) {
            m1[i][j] = true;
            return true;
        }

        // we here means yaha par paani aaya hai ya start hora hai yaha se paani
        // girna hence explore in all 4 directions

        if (m1[i][j] != -1)
            return m1[i][j];

        // mark current banda true
        vis[i][j] = true;
        // cout << "now at s1 " << i << " " << j << endl;

        // remember to only explore if location valid (ie height<=current
        // height)

        bool ans1 = false, ans2 = false, ans3 = false, ans4 = false;

        // explore up (i-1,j)
        if (valid(i - 1, j) && h[i - 1][j] <= h[i][j] && !vis[i - 1][j]) {
            //  means can explore here, do explore
            ans1 = solve1(i - 1, j, h, vis, m1);
        }
        // explore down (i+1,j)
        if (valid(i + 1, j) && h[i + 1][j] <= h[i][j] && !vis[i + 1][j]) {
            //  means can explore here, do explore
            ans2 = solve1(i + 1, j, h, vis, m1);
        }
        // explore right (i,j+1)
        if (valid(i, j + 1) && h[i][j + 1] <= h[i][j] && !vis[i][j + 1]) {
            //  means can explore here, do explore
            ans3 = solve1(i, j + 1, h, vis, m1);
        }
        // explore left (i,j-1)
        if (valid(i, j - 1) && h[i][j - 1] <= h[i][j] && !vis[i][j - 1]) {
            //  means can explore here, do explore
            ans4 = solve1(i, j - 1, h, vis, m1);
        }

        vis[i][j] = false;

        // 4 locations me se kahi bhi ans mil jaaye toh return true kar dena
        bool canReach = ans1 || ans2 || ans3 || ans4;
        if (canReach)
            m1[i][j] = 1; // only cache true
        // otherwise leave m1[i][j] as -1 so it can be re-evaluated later
        return canReach;
    }

    bool solve2(int i, int j, vector<vector<int>>& h, vector<vector<bool>>& vis,
                vector<vector<int>>& m2) {
        // base case, agar atlantic edges par aa gaye hai toh return
        // true
        if (i == m - 1 || j == n - 1) {
            m2[i][j] = true;
            return true;
        }

        // we here means yaha par paani aaya hai ya start hora hai yaha se paani
        // girna hence explore in all 4 directions
        if (m2[i][j] != -1)
            return m2[i][j];

        // mark current banda true
        vis[i][j] = true;
        // cout << "now at s2 " << i << " " << j << endl;

        // remember to only explore if location valid (ie height<=current
        // height)

        bool ans1 = false, ans2 = false, ans3 = false, ans4 = false;

        // explore up (i-1,j)
        if (valid(i - 1, j) && h[i - 1][j] <= h[i][j] && !vis[i - 1][j]) {
            //  means can explore here, do explore
            ans1 = solve2(i - 1, j, h, vis, m2);
        }
        // explore down (i+1,j)
        if (valid(i + 1, j) && h[i + 1][j] <= h[i][j] && !vis[i + 1][j]) {
            //  means can explore here, do explore
            ans2 = solve2(i + 1, j, h, vis, m2);
        }
        // explore right (i,j+1)
        if (valid(i, j + 1) && h[i][j + 1] <= h[i][j] && !vis[i][j + 1]) {
            //  means can explore here, do explore
            ans3 = solve2(i, j + 1, h, vis, m2);
        }
        // explore left (i,j-1)
        if (valid(i, j - 1) && h[i][j - 1] <= h[i][j] && !vis[i][j - 1]) {
            //  means can explore here, do explore
            ans4 = solve2(i, j - 1, h, vis, m2);
        }

        vis[i][j] = false;

        // cout<<(ans1 || ans2 || ans3 || ans4)<<endl;
        // 4 locations me se kahi bhi ans mil jaaye toh return true kar dena
        bool canReach = ans1 || ans2 || ans3 || ans4;
        if (canReach)
            m2[i][j] = 1; // only cache true
        // otherwise leave m1[i][j] as -1 so it can be re-evaluated later
        return canReach;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        // okay yaha i guess mai explore kar sakta hai location se in each
        // direction, then in the end mai valid waale ans me daal sakte hai
        m = h.size();
        n = h[0].size();

        vector<vector<int>> ans;
        // ek visited leke chalo keeping track of locations visited
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // memo daalna padega heap buffer overflow hora
        vector<vector<int>> m1(m, vector<int>(n, -1));
        vector<vector<int>> m2(m, vector<int>(n, -1));

        // m1 me row=0 ya col=0 wale bande send true
        // m2 me row=m-1 ya col=n-1 wale bande send true

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // explore (i,j)
                // cout << " at " << i << " " << j << endl;
                if (solve1(i, j, h, vis, m1) && solve2(i, j, h, vis, m2)) {
                    // we here means yaha se paani can go to both oceans,
                    // include in ans
                    // cout << "here " << i << " " << j << endl;
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};