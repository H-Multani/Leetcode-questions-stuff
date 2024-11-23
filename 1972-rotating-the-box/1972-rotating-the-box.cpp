class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // rotate kardo frst of all
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                ans[j][n - i - 1] = box[i][j];
            }
        }
        // earlier n rows and m columns

        // now m rows and n
        // for (auto it : ans) {
        //     for (auto it2 : it) {
        //         cout << it2 << " ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;

        // har ccolumn ke neeche jao, waha se iterate karte akrte swap karte jao
        for (int col = 0; col < n; col++) {
            int stoneidx = m - 1, emptyidx = m - 1;
            for (int row = m - 1; row >= 0; row--) {
                if (ans[row][col] == '#') {
                    // means yaha stone hai, swap stone with empty idx wala
                    // space
                    swap(ans[stoneidx][col], ans[emptyidx][col]);

                    // after swapping, ab previously empty space par stone aa
                    // jaega, toh emptyidx aage badhao, to get emptyidx to the
                    // new empty space, also ab previously stone wale space par
                    // empty ho jaega, toh stoneidx bhi aage badha do
                    // basically dono idx ko aage badha do
                    emptyidx--;
                    stoneidx--;
                } else if (ans[row][col] == '*') {
                    // empty idx ko curr location se 1 opar rakh do
                    emptyidx = row - 1;
                    // stone yaha bhi nai mila, stoneidx aage badhao
                    stoneidx--;
                } else {
                    // means ans[row][col]=='.'
                    // yaha stone nai hai, sone idx aage badhao
                    stoneidx--;
                }
            }

            // for (auto it : ans) {
            //     for (auto it2 : it) {
            //         cout << it2 << " ";
            //     }
            //     cout << endl;
            // }
            // cout<<endl;
        }

        return ans;
    }
};