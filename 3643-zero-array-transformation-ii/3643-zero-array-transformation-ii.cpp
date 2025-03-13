class Solution {
public:
    int n, q;
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        // yaha par diff array technique laga do
        vector<int> diff(n, 0);

        // first k queries par iterate karo bss update diff array
        for (int i = 0; i < k; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            // query ka start par val add kardo diff me
            diff[start] += val;
            // query ka end+1 par val substract kardo diff me, so that prefix
            // sum kare toh start se end idx tak sum sahi bane
            if (end + 1 < n)
                diff[end + 1] -= val;

            // thats all folks ab next query iterate karo, thats the diff array technique
        }

        // after all queries have been iterated, prefix sum nikalo diff array ka
        for (int i = 1; i < n; i++) {
            diff[i] = diff[i - 1] + diff[i];
        }
        // ab diff me saari values stored hai, which would be the total changes
        // after k queries

        // diff[3]=4 means nums ke idx 3 me -4 hoyega at max
        // diff[i]=j means nums ke idx i me -j hoyega at max

        // yehi chek karo nums ke against, agar kahi bhi nums[i]>diff[i] mil
        // jaaye means ki maxm diff lagane ke bad bhi nums[i] cannot be made 0,
        // in such case return false, since nums couldnt be made all 0 array
        for (auto i = 0; i < n; i++) {
            if (nums[i] > diff[i])
                return false;
        }

        return true;
    }
    bool checkall0(vector<int>& nums) {
        for (auto it : nums) {
            if (it != 0)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();

        // agar already saare 0 hai toh koi query nai lagegi in such case return
        // 0 frm here
        if (checkall0(nums))
            return 0;

        // TLE aa rha hai, iss loop me apan O(q) tak chala rahe hai, checking if
        // current i se answer aa raha hai ki nai, notice that this is similar
        // to lower bound technique, since lower bound me kya karte the ki we
        // find smallest index such that nums[idx]>=val

        // yaha bhi similar kuch kar sakte hai thoda imporve karne ke lie
        // solution, how??
        // apan mid nikal lenge, phir mid(count) ke liye check karenge, ki mid
        // jitne queries lagane se ans aayega ki nai, agar mid(count) tak
        // queries lagane se nums becomes all 0, means mid is a posisble answer,
        // in such case check left for smaller possible answer, otherwise mid
        // jitni queries lagane par bhi ans nai mila, need to check right side,
        // thoda efficiently chk hoga isse bass, could help with TLE

        // for (auto i = 1; i <= q; i++) {
        //     if (check(nums, queries, i)) {
        //         // i th query tak chk karne ke baad nums 0 array ban gaya toh
        //         // yehi se i return kardo
        //         return i;
        //     }
        // }

        // laga do yehi binary search logic
        int l = 1, r = q;
        // start frm 1 to q, since minm we can take 1 query, and maxm we can
        // take all q queries, dont worry index ka masla check() funcn me handle
        // kiya hai
        int ans = -1;
        while (l <= r) {
            // mid nikalo
            int mid = l + (r - l) / 2;

            // mid ke liye check karo
            // agar mid(count) jitni query chalane se ans aa jaaye toh means its
            // a possible ans, update kar do
            if (check(nums, queries, mid)) {
                // we here means mid jitne queries chalayenge toh nums will
                // become all 0, means mid is a possible ans, updatet kardo
                ans = mid;

                // ab possible hai ki <mid queries chalate toh bhi ans aa jata,
                // toh check left side
                r = mid - 1;
            } else {
                // we here means mid jitne queries chalane ke baad bhi ans nai
                // aaya, means aur queries chalani hongi, for this visit right
                // side
                l = mid + 1;
            }
        }

        // we here means saari queries proces karne ke baad bhi nums cannot
        // become 0 array, in such case return -1, ans=-1 agar pehle kahi ans
        // nai mila hoga toh
        return ans;
    }
};