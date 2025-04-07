class Solution {
public:
    bool solve(int ttlsum, int currsum, vector<int>& arr, int n,
               vector<vector<int>>& memo) {
        // base case
        if (ttlsum == currsum)
            return true;
        if (n == 0)
            return false;

        // agar memo me ans pehle se hai toh return kardo yehi se

        if (memo[n][ttlsum] != -1)
            return memo[n][ttlsum];

        // we here means memo me ans nai mila, explore karke ans nikalo

        // 2 options take, nottake
        bool take = false, nottake = false;

        if (currsum + arr[n - 1] <= ttlsum - arr[n - 1]) {
            take = solve(ttlsum - arr[n - 1], currsum + arr[n - 1], arr, n - 1,
                         memo);
        }
        nottake = solve(ttlsum, currsum, arr, n - 1, memo);

        // now iss subproblem ka answer memo me update kardo
        memo[n][ttlsum] = take || nottake;

        return take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        // simple take not take approach, ttlsum and currsum maintain karo, chal
        // jaega, kahi bhi ans mil jaaye toh return true
        int n = nums.size();
        int ttlsum = 0;
        for (auto it : nums) {
            ttlsum += it;
        }
        // memo bana do n and ttlsum ka
        vector<vector<int>> memo(n + 1, vector<int>(ttlsum + 1, -1));

        return solve(ttlsum, 0, nums, n, memo);
    }
};