class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // it kind of seems like a simple sliding window problem lets try

        long long ttlsum = 0;

        long long ans = 0;

        int l = 0, r = 0, n = nums.size();

        while (r < n) {
            // curr waale bande ko include karo subarray/ window me
            ttlsum += nums[r];

            // agar window invalid hai ie score>=k, toh shrink karo windo ko
            // score is ttlsum*(r-l+1)
            while (ttlsum * (r - l + 1) >= k && l < r) {
                // means windo valid nai hai shrink karo
                ttlsum -= nums[l];
                l++;
            }

            // we here means current windo valid hai, current windo ends at r,
            // iss valid window ke andar jitni subarrays banenge saare valid
            // honge, why?

            // since current windo valid hai toh iske andar waale saare
            // subarrays jitne bhi bange sab valid honge since sabka score iss
            // window ke score se kam hi aayega and we need ki score<k

            // subarray cnt wala n*(n+1)/2 wala formula nai use karenge yaha
            // since usse repeat counting hogi, eg1 me dekho for eg current
            // subarray is [2], toh iske liye we counted no of suabrrays as 1
            // which is [2], extending the window we have [2,1] which is valid,
            // iske liye we counted 2*(3)/2=3 subarrays which are [2],[1],[2,1],
            // lekin isme [2] wala toh already count kar chuke hai na toh why
            // count again

            // toh instead we just count ki current r par khatam hone waale
            // kitne subarrays banenge which is r-l+1, in eg1 for [2], we have 1
            // subarray ie [2], for [2,1], we will have r-l+1 = 1-0+1 = 2
            // subarrays which will be [2,1] and [1]

            // yehi karenge apan

            // okay toh its possible ki current wala subarray valid na ho, in such case add krne se pehle chk krlo
            if(ttlsum*(r-l+1)<k)
                ans+=r-l+1;

            // subarray print karvao
            // cout<<r<<" se "<<l<<endl;

            // windo aage badhao
            r++;
        }

        return ans;
    }
};