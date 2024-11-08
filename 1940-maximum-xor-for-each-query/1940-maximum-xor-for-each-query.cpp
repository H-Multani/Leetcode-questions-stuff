class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // hint no 2 se help liya 
        long long maxrange = (1 << maximumBit) - 1;
        long long overallxor = 0;

        for (auto it : nums) {
            overallxor ^= it;
        }

        vector<int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            // long long maxmans=~(overallxor);
            // ye maxm value of k hai such that overall xor maxm aaye
            // now this value could go out of range, toh har baar me ek ek set
            // bit ko unset kardo peeche(left side) se and chk if range me hai
            // ki nai, agar range me hai toh ans hai, otherwise next wale set
            // bit ko unset karo and check again...until ek ans mil jaaye and
            // push to ans vector

            // both approaches do the same thing

            // either do this or the stuff above same ans rahega
            ans.push_back(overallxor ^ maxrange);

            // to get xor of all values frm 0 upto i-1 th value
            overallxor ^= nums[i];
        }

        return ans;
    }
};