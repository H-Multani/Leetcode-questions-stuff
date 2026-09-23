class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // sawal bolra element hata kar x se subtract karo until x reached 0,
        // which can also mean ki aise element nikale frm left and right ki the
        // elements sum to x

        // ulta socho, insted of playing with prefix and suffix, apan dekhenge
        // ki konsa biggest subarray hai jiske chalte ttl-subarraysum==x ban
        // jaaye

        // this is simple sliding window type problem

        // since subarray lenge beech ka kahi ka, toh subarray sum lete
        // chalenge, and we need ki left and rt se kitne nikale, toh subarray
        // beech me hai, toh left and rt walo ka sum will be ttl_sum-subarray ka
        // sum

        // since we need ki kitne minm values NIKAL kar bana sakte, hence
        // subarray has to be biggest such that removal waale minm rahe

        // aise socho ki instead of taking elements out from left and rt, apan
        // bole ki left and rt se nikal kar sum karo(and x se remove karo), ya
        // fir beech ka subarray lelo, and uske sum ko ttl me se remove kardo,
        // same sum banega, usko compare kara dena x se mast, if reach exactly
        // x, update ans

        // sliding windo bana lo

        int n = nums.size();

        // sum total nikal lo
        int ttl = 0;
        for (auto it : nums)
            ttl += it;
        int l = 0, r = 0;

        // ek curr sum lelo
        int curr = 0;

        int ans = INT_MAX;

        while (r < n) {
            // right wala ttl me lelo
            curr += nums[r];

            // apne kaam ka hai ttl-curr se hai, agar ye x se bada hai means
            // zyada elements delete kar diye apan ne(ye keh sakte hai ki
            // subarray boht bada le liya)

            // since zyada delete kar diye hai toh window badhao,

            // lekin agar ttl-curr<x ho jaaye meaning ki apan ne kam element
            // delete kiye hai left and rt side se , to zyada delete karne
            // padenge na so that difference reaches x

            // iss case me shrink karo subarray ko
            while (l<=r &&  ttl - curr < x) {
                // overall x se bada hai toh means zyada elements alag kar diye
                // left and rt se, iss case me shrink window until vapas range
                // me aa jaaye
                curr -= nums[l];
                l++;
            }

            // agar ttl-curr==x ho jaaye meaning exactly itne elements nikale
            // hai jitne me x reaches 0, ans update kardo

            // we need biggest subarray jo de ttl-curr==x bheje
            if (ttl - curr == x) {
                // update ans
                // cout<<l<<" "<<r<<endl;

                // l to r wala banda is subarray ie [l,r]

                // meaning left se l bande nikale hai , and right se n-r-1 bande
                // nikale hai

                // overall we have l+(n-r-1) bande remove kiye from left and rt
                // side, ye sum update kardo

                // we need ki ye sum minm ho since we need count of minm operations to reduce x to 0

                // hence minm lenge
                ans = min(ans, l + n - r - 1);
            }

            // right wala ptr aage badhao, extend windo
            r++;
        }

        // agar ans is still int_max means koi ans nai mila, return -1
        if(ans==INT_MAX) return -1;

        return ans;
    }
};