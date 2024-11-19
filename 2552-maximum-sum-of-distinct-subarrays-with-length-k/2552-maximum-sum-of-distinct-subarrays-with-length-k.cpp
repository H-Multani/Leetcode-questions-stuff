class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // simple sliding window laga do
        // aur maxm sum calculate krte chalo
        // map bhi maintain krte chalo, so that we know ki har element bs 1 baar
        // aa raha hai

        long long ans = 0;

        unordered_map<int, int> freq;
        int n = nums.size();
        int left = 0, right = 0;
        // current sum bhi leke chalo
        long long currsum = 0;
        while (right < n) {
            // current banda include karo
            currsum += nums[right];
            // map me bhi include karo
            freq[nums[right]]++;

            // shrink subarray if necessary
            // i noticed that ye below wala while ke jagah if stmt bhi
            // chalega(ac soln 1)(purely by chance) toh if laga dena agar man
            // kare toh, since neeche wala loop max 1 baar chalega
            while (left <= right && right - left + 1 > k) {
                // k se bada subarray mil chuka hai, shrink karo

                // remove left wala element frm ttl sum
                currsum -= nums[left];
                // map se bhi alag kardo
                freq[nums[left]]--;
                // agar map me freq 0 ho gai, remove frm map
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                // left ptr aage badhao
                left++;
            }

            // if current subarray is valid, update ans
            // for valid->
            // subarray me k elements hai ie right-left+1==k
            // saare elements distinct hai, ie mpp.size()==k
            // if both above satisfy update ans
            if (right - left + 1 == k && freq.size() == k) {
                ans = max(ans, currsum);
            }

            // window aage badhao
            right++;
        }

        return ans;
    }
};