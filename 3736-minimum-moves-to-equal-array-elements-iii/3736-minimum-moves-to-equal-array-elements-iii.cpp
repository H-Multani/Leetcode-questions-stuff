class Solution {
public:
    int minMoves(vector<int>& nums) {
        // same logic and code as of lc 453

        // waha par decrease 1 element karte the
        // yaha increase 1 element karna hai

        // toh waha minm leke chalte the yaha maxm leke chalenge, baaki logic exact same

        int maxm = nums[0];
        for (auto it : nums) {
            maxm = max(maxm, it);
        }

        int ans = 0;

        for (auto curr : nums) {

            ans += abs(curr - maxm);
        }

        return ans;
    }
};