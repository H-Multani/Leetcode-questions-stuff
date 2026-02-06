class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // simple sliding window, hints hi bata diye

        // essentially we will use sliding window on sorted array to find
        // biggest valid ans, and fir bache kuche remove kar denge array se to
        // get final ans

        // we do this sliding window on sorted array since, sorting se order me
        // rahenge elements toh biggest valid array banane ke liye baar baar
        // smallest and largest dhundna nai padega, we know smallest is nums[i]
        // and biggest is nums[j], using these elements apan agar window ke
        // bahar dekhenge toh vaise bhi invalid arrays milenge which do not
        // follow the rule we have, toh window valid rahegi hamesha apni best
        // case scenario

        // sort the array first
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, ans = -1;

        // i wala element is minm, and j wala element is maxm

        while (j < n) {
            // current wala element andar lelo

            // yaha kuch hai nai as such karne ke liye

            // minm element is nums[i] and maxm element is nums[j]
            // agar nums[j]<=nums[i]*k, means apan windo badha sakte hai aage,
            // since question wala order follow hora, otherwise window ko shrink
            // karo
            while (i < n && (1LL * nums[j]) > (1LL * nums[i] * k)) {
                // means we need to shrink window since maxm has become greater
                // than minm * k

                // i++ kardo bass
                i++;
            }

            // we here means apan ke paas ek valid subarray hai which contains
            // all elements such that minm*k>=maxm

            // ye length ek possible ans hai update kardo
            ans = max(ans, j - i + 1);

            // extend window
            j++;
        }

        // ab ans is the length of biggest valid array, means baaki elements
        // nikalne padenge array se, toh overall ans is n-ans, since n-ans is
        // the no of elements we have to remove to get to that perfect array
        return n - ans;
    }
};