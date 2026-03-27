class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // matrix hi bana do new wala
        vector<vector<int>> ans(m, vector<int>(n));

        // har n steps ke baad original position aa jayegi, toh if k>n
        // hua toh ghum fir kar k%n steps hi shift karna hai, toh k ko update
        // kardo
        k = k % n;

        for (int row = 0; row < m; row++) {
            if (row % 2 == 1) {
                // means iss row ko right shift karna hai k steps

                for (int col = 0; col < n; col++) {

                    // ans me col me k baar shift karne ke baad value dena usme,
                    // and just incase col+k exceeds n we do %n to keep in
                    // range and also shift right
                    ans[row][(col + k) % n] = mat[row][col];
                }
            }
            else{
                // means iss row ko left shift karna hai k steps

                for(int col=0;col<n;col++){
                    // ans me col me k baar shift karne ke baad value dena usme,
                    // and just incase col-k reaches below 0 we do +n %n to keep in
                    // range and also shift right

                    ans[row][(col-k+n)%n]=mat[row][col];
                }
            }

        }

        // ab if both the arrays have same values then return true else false
        return ans==mat;
    }
};