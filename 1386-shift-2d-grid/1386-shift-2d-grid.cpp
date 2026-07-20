class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // ans bana denge logic banana hai bass

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // current banda is [i][j]

                // isko k steps aage badhana hai
                // j aage badhega k steps
                int newj = (j + k) % n;

                // i kitna aage badhega depends on (j+k) ne kitne baari n ke
                // range se aage badhe hai, if lets say (j+k)=13 and n=4, means
                // j+k ne 3 baari n ke range se out gaye hai, and %n ne vapas
                // range me laya hai 3 baari, uske hisab se hi i badlega

                int newi = (i + ((j + k) / n)) % m;

                // iska logic samjho we know i se i+1 tabhi jayenge jab se aage
                // badhna padega 1 step(2nd rule in question), toh vahi logic
                // agar k steps ke liye dekhe toh overall j se k steps aage jana
                // hai means j+k jitna aage jana hai frm overall start, and utne
                // steps me kitni baar we will reach column ka end and will have
                // to move to next row will be (j+k)/n, itni baari hi apan i se
                // i+1 par jaenge toh ek sath add kardo, ab scene ye hai ki this
                // i to i+1 karna ek baari me could make i go out of range, toh
                // usko range me laane ke liye %m

                // element daal do ans me
                ans[newi][newj]=grid[i][j];
            }
        }

        return ans;
    }
};