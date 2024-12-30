class Solution {
public:
    int solve(vector<int>& nums, int n, int op1, int op2, int k,vector<vector<vector<int>>>& memo) {
        if (n == 0)
            return 0;

        // nums[n-1];
        int val1 = INT_MAX;
        int val2 = INT_MAX;
        int val3 = INT_MAX;
        int val4 = INT_MAX;
        int val5 = INT_MAX;

        if(memo[op1][op2][n]!=-1) return memo[op1][op2][n];

        // apply op1
        if (op1 > 0) {
            val1 = (nums[n-1]+1) / 2;
            val1 += solve(nums, n-1, op1 - 1, op2, k,memo);
        }

        // apply op2
        if (op2 > 0 && nums[n-1] >= k) {
            val2 = (nums[n-1] - k);
            val2 += solve(nums, n-1, op1, op2 - 1, k,memo);
        }

        if (op1 && op2) {
            // pehle op1 lagao phir op2

            val3 = (nums[n-1]+1) / 2;

            // int updated = nums[n-1] / 2;

            if (val3 >= k) {
                val3 -= k;
                val3 += solve(nums, n-1, op1 - 1, op2 - 1, k,memo);
            }
            else
                // val3 me op2 nai laga skte, reset kardo value
                val3=INT_MAX;

            // pehle op2 lagao phir op1
            if (nums[n-1] >= k) {
                val4 = nums[n-1] - k;
                // updated = nums[n-1] - k;
                // val4 -= updated;
                val4 = (val4+1) / 2;
                val4 += solve(nums, n-1, op1 - 1, op2 - 1, k,memo);
            }
            else val4=INT_MAX;
        }

        val5 = nums[n-1] + solve(nums, n-1, op1, op2, k,memo);

        memo[op1][op2][n]=min({val1, val2, val3, val4, val5});
        return min({val1, val2, val3, val4, val5});
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // op1,op2, n changes, 3D dp laga do
        int n=nums.size();
        vector<vector<vector<int>>> memo(op1+1,vector<vector<int>>(op2+1,vector<int>(n+1,-1)));
        return solve(nums, nums.size(), op1, op2, k,memo);
    }
};