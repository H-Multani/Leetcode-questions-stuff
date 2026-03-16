class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // stores 3 biggest rhombus sums
        set<int> st;

        // addset ka lambda likh do yehi
        auto addset = [&](int ttl) {
            st.insert(ttl);

            if (st.size() > 3)
                st.erase(st.begin());
        };

        // har bande par jao
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // now we are at (r,c) , ye rhombus ka centre hoga, yaha se
                // rhombus ke different sides ke corner nikalenge and add
                // karenge lengths ko

                // yaha se loop chalao har size ka rhombus banao

                // for size 0 only current element considered, daal do set me
                addset(grid[r][c]);

                // ab side ke size ke liye loop chala do
                for (int side = 1; r + side < m && r - side >= 0 &&
                                   c + side < n && c - side >= 0;
                     side++) {
                    // we here means current side length is valid, nikalo
                    // rhombus ke sides ka sum

                    int ttl = 0;

                    // toh we have 4 corners

                    // top-> (r-side,c)
                    // bottom-> (r+side,c)
                    // right-> (r,c+side)
                    // left-> (r,c-side)

                    // toh first add all diagonal values from top to right
                    for (int k = 0; k < side; k++) {
                        ttl += grid[r - side + k][c + k];
                    }

                    // add all diagonal values from top to left
                    for (int k = 0; k < side; k++) {
                        ttl += grid[r - k][c - side + k];
                    }
                    
                    // add all diagonal values from right to bottom
                    for (int k = 0; k < side; k++) {
                        ttl += grid[r + k][c + side - k];
                    }
                    // add all diagonal values from left to bottom
                    for (int k = 0; k < side; k++) {
                        ttl += grid[r + side - k][c - k];
                    }

                    // ye hone ke baad we have ttl, which has current waale
                    // rhombus ka side sum, add kardo set me
                    addset(ttl);
                }
            }
        }

        // set ke elements ko vector me daal kar bhej do

        // set me toh ascending order me hai, apan ko descending me bhejna hai,
        // reverse bhejna

        return vector<int>(rbegin(st), rend(st));
    }
};