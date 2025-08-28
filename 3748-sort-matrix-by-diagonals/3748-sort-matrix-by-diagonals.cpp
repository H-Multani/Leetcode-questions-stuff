class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // pehle diagonal nikal kar store karlo
        int n = grid.size();

        // ek jisme normal sort karna hai
        vector<vector<int>> temp1(n);
        // ek jisme reverse sort karna hai
        vector<vector<int>> temp2(n);

        int j = 0;
        for (int i = 0; i < n; i++) {

            // iss i se chalu karke saare (i,j) wale nikal lo
            int tempi = i;

            for (int j = 0; j < n && tempi < n; j++, tempi++) {
                temp2[i].push_back(grid[tempi][j]);
            }

            // ab iss i th wale vector ko sort kardo reverse me
            sort(temp2[i].begin(), temp2[i].end(), greater<int>());

            tempi = i;
            // ab yehi par replace kardo original grid me hi
            for (int j = 0; j < n && tempi < n; j++, tempi++) {
                // new values se replace kardo old values ko
                grid[tempi][j] = temp2[i][j];
            }
        }

        // do the same thing for temp1 wale, ie jinko normal sort karna hai,
        // yaha scene will be reverse outer loop control column, toh loop me j
        // use karo

        // ye neeche wala code samajh naa aaye toh tnsion nai lena, banaya maine
        // khud hi hai upar wale logic ka reverse hai bass
        for (int j = 1; j < n; j++) {

            int tempj = j;

            for (int i = 0; i < n && tempj < n; i++, tempj++) {
                temp1[j].push_back(grid[i][tempj]);
            }

            // ab iss j th wale vector ko sort kardo
            sort(temp1[j].begin(), temp1[j].end());

            tempj = j;
            // ab yehi par replace kardo original grid me hi
            for (int i = 0; i < n && tempj < n; i++, tempj++) {
                // new values se replace kardo old values ko
                grid[i][tempj] = temp1[j][i];
            }
        }

        return grid;
    }
};