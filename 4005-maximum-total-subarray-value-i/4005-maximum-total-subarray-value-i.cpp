class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // sabse pehle toh overall maxm lagane ke liye subarrays aise lenge
        // jisme nums ka maxm and minm aaye, so that subarray ka formula most
        // optimal way se lag jaaye and overall formula would then become diff
        // bw maxm element of nums and minm element of nums

        // and since we can take the same subarray multiple times hence yehi
        // most optimal wala k bari leke send ans

        return (*max_element(nums.begin(), nums.end()) -
               *min_element(nums.begin(), nums.end()))*1LL * k;
    }
};