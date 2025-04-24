class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // sliding window obvv

        // ye quesn is similar to lc 2537, usme bhi similar count nikalne the ,
        // similar yaha bhi nikalenge, 2537 ka n-r wala logic lagega bss yaha,
        // baaki pura chal jaega

        // toh logic apan banate jayenge window banate banate

        // first calculate ki kitne distict element hai nums me
        unordered_map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;

        int distinct = mpp.size();

        // map clear kardo, to be used again
        mpp.clear();
        // ab apan windo bana kar count karte jayenge, distinct elements ko map
        // me store krenge
        int n = nums.size(), l = 0, r = 0;

        int ans = 0;

        while (r < n) {
            // current bande ko map me include karo
            mpp[nums[r]]++;

            // ab agar current wala windo valid hai(no of distinct element in
            // windo same as of nums)

            // windo valid hai toh count karenge
            while (mpp.size() == distinct && l <= r) {
                // we here means current waali window valid hai, ab logic suno,
                // agar current waali windo valid hai means iske aage r se n tak
                // jitne elements lagaoge saare subarrays valid bnenge, since
                // current subarray me saare distinct hai already, element add
                // karenge toh vo elements rahenge wahi par already making them
                // all valid, toh unko count kar na hai

                // for eg in eg1 valid window is [1,3,1,2], l=0,r=3, ye window
                // valid hai since no of distinct elements in windo same as no
                // of distinct elements in nums

                // toh ab yaha se end tk jitne subarrays banenge all will be
                // valid and all should be counted, the subarrrays will be
                // [1,3,1,2], and [1,3,1,2,2], ie n-r=5-3=2, yehi subarrays
                // count honge

                // also notice that dono ka starting is 1(L=0), ie we are
                // basically counting all the valid subarrays starting frm this
                // l=0,

                // count karne ke baad we shrink the window we get new
                // window as [3,1,2] at l=1,r=3, which is still valid windo

                // ab iss new window ke liye bhi r=3 se aage elements add karte
                // karte jitne subarrays banenge sab valid rahenge, the
                // subarrays will be [3,1,2] and [3,1,2,2], ie n-r=5-3=2, yehi
                // subarrays count honge

                // also notice that dono ka starting is 3(L=1), ie we are
                // basically counting all the valid subarrays starting frm this
                // l=1,

                // again windo shrink krke yehi process repeat krte jaenge jab
                // tak window valid hai, counting all valid subarrays starting
                // at that idx l

                // toh current wale l se chalu hone wale jitne possible valid
                // subarrays hai(made by adding elements frm r side) count karo
                ans += n - r;

                // ab count kar liye hai apan ne curr l se start hone waale
                // valid subrrays

                // shrink the windo

                // sbse pehle l waale ko map se nikalo
                mpp[nums[l]]--;

                if (mpp[nums[l]] == 0) {
                    // agar freq reach 0 remove the element
                    mpp.erase(nums[l]);
                }

                // windo shrink kro
                l++;
            }

            // ab counting and shrinking wala kaam apan ne ek saath kar liye
            // already, windo aage badhao bss
            r++;
        }

        return ans;
    }
};