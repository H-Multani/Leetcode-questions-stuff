class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // optimal approach

        auto mod=1000000007;

        // even and odd count lelo
        int evencnt = 1, oddcnt = 0;
        // even cnt start frm 1 since empty subarray is also of even size toh
        // leke chalna padega 1 se hi

        // prefix sum leke chalo
        int prefixsum = 0;

        // ans cnt leke chalo
        int ans = 0;

        // now iterate over the array
        for (auto it : arr) {
            // current banda prefixsum me lelo
            prefixsum += it;

            if (prefixsum % 2 == 1) {
                // means 0 se yaha tak ka prefix sum is odd, must have been
                // even+odd=odd wala case, toh iss case me evecnt jitne
                // subarrays banenge, hence add kardo ans me
                ans += evencnt;

                // also current wala prefix sum odd hai toh oddcnt increase
                // kardo
                oddcnt++;
            } else {

                // means 0 se yaha tak ka prefix sum is even, must have been
                // odd+odd=even wala case, toh iss case me oddcnt jitne
                // subarrays banenge(pehle hi bane honge prefix sum of odd ttl,
                // seedhe seedhe add karo), hence add kardo ans me
                ans += oddcnt;

                // also current wala prefix sum even hai toh evencnt increase
                // kardo
                evencnt++;
            }

            // ans ko mod karo
            ans=ans%mod;
        }

        // ab return kardo seedhe seedhe ans
        return ans;
    }
};