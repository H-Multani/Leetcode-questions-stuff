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
                    // next empty space, also ab previously stone wale space par
                    // empty ho jaega, toh stoneidx bhi aage badha do
                    // basically dono idx ko aage badha do

                    emptyidx--;
                    stoneidx--;
                } else if (ans[row][col] == '*') {
                    // means iss idx par apan ko obstacle mil gaya hai

                    // koi bhi iske upar aane wala stone iss obstacle ke neeche
                    // nai jaayega, ie agar stone neeche aaya toh iss obstacle
                    // ke upar rahega, hence stoneidx ko just stone ke upar wale
                    // idx par rakh do empty idx ko curr location se 1 opar rakh
                    // do
                    emptyidx = row - 1;

                    // stone yaha bhi nai mila, stoneidx aage badhao
                    stoneidx--;
                } else {
                    // means ans[row][col]=='.'
                    // ie yaha empty space mili hai
                    // now we dont set emptyidx to this posn, since emptyidx is
                    // already at empty index nearest to bottom
                    // yaha stone nai hai, stoneidx aage badhao
                    stoneidx--;
                }
            }
            // current column me se jitne stones gravity se neece girne the gir
            // gaye, agle colum par jao

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