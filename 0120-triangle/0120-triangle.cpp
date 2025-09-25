class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& t,vector<vector<int>>& memo) {
        // agar range ke bahar hai toh return kardo
        if (i >= m || j >= n)
            return 0;

        // memo me ans hai toh bhej do
        if(memo[i][j]!=INT_MIN) return memo[i][j]; 

        // take nottake approach hai lekin thodi different, like 2 choice me
        // take nottake na leke apan (i,j) se (i+1,j) and (i+1,j+1) explore
        // karenge
        int op1 = t[i][j] + solve(i + 1, j, t,memo);
        int op2 = t[i][j] + solve(i + 1, j + 1, t,memo);

        // update memo
        memo[i][j]=min(op1,op2);

        // dono me se jo bhi minm sum wala hai return kardo
        return min(op1, op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // (i,j) wale bande se apan (i+1,j) and (i+1,j+1) wale bande par jaa
        // sakte hai, ye question hi bolra hai and thoda sense lagane par bhi
        // yehi samajh aara hai

        // this is classic backracking+memo
        m = triangle.size();
        n = triangle.size();

        // normal TLE de dega, use memo
        vector<vector<int>> memo(m, vector<int>(n, INT_MIN));
        // at max this will take a 200x200 grid

        // i,j bhej dena kaafi hai ig
        return solve(0, 0, triangle,memo);
    }
};