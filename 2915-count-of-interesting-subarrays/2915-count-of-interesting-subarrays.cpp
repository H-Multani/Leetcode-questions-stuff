class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        // prefix sum banane se accha nums me hi changes kardo
        for (int i = 0; i < n; i++) {
            if (nums[i] % m == k) {
                // means isko count krna h toh nums me same posn par 1 rakh do
                nums[i] = 1;
            } else
                nums[i] = 0;
        }

        // ab map lelo which will store ki current i tak kitne remainder wale
        // kitne bande mile hai
        unordered_map<int, long long> mpp;

        long long sum = 0;
        // cnt of those elements which have element%m==k
        // ye basically prefix sum banate jaa rahe isse

        long long ans = 0;

        mpp[0] = 1;
        // since empty subarray me remainder 0 wala banda rahega(since no banda
        // present)

        for (int i = 0; i < n; i++) {
            // curr banda add karo sum me
            sum += nums[i];

            // we have ki ttl cnt of elements frm idx 0 upto idx i which satisfy
            // element%m==k is sum,

            // ab cnt%m nikalo
            int r1 = sum % m;

            // r1 is cnt%m of elements frm idx 0 to i

            // r2 bhi similar hoga with 0 to j, then (r1-r2)%m==k chahiye apan
            // ko to make [j+1,i] a valid subarray to be counted

            // toh r2 toh hai nai , lekin modulo ki prop ke hisaab se
            // (r1-r2)%m==k becomes r2=(r1-k+m)%m

            // ye value ka r2 chahiye rahega to make valid subarrays

            // isse apan r2 nikal sakte h, nikal lo
            // remembder that r2 is 0 to j and j<i chal rah h
            int r2 = (r1 - k + m) % m;

            // ab iss r2 wale maan lo 2 idx pehle mil chuke hai apan ko 0 to i
            // ke beech me, toh like if i=7 par hai maan lo and r2=3 chahiye,
            // and apan r2=3 waale 2 element pehle dekh chuke hai toh apan 2
            // possible subarrays bana payenge

            // like if r2=3 is found at idx 2 and 5, then apan 2 valid subarrays
            // bana sakte hai which will be [2,7] and [5,7], which will be valid
            // since apan ne r1 ko fix karke r2 vo wala nikala hai which will
            // make [r2,r1] a valid subarray to be counted

            // ab ye count apan ka map me hai toh waha map me agar 2 elements
            // hai to means 2 valid subarrays ban sakte hai ending at current
            // idx i, toh vahi count ans me add kar denge

            // if r2 is in the map, ans me count daal do
            if (mpp.find(r2) != mpp.end())
                ans += mpp[r2];

            // current r1 aage wale ke liye r2 ban sakta hai toh usko count
            // karna mat bhulna

            mpp[r1]++;
        }

        return ans;
    }
};