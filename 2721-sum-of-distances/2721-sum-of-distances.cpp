class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // TLE de diya

        // sochte thoda

        // thoda optimize karte, har element ke indexes store kar sakte hai ki
        // kitni baar aa raha hai then lets say value 56 comes at indexes
        // [1,3,5,8,11]

        // now suppose we are making ans for index 3, then ans for this element
        // will be(abs alag karke) (3-1)+(5-3)+(8-3)+(11-3)-> 5+8+11 - (1)
        // +(3*(3-1))

        // toh this can be written for [a1,a2,a3.....an]-> and suppose we are
        // making ans for ai, then overall formula will be

        // sum(ai+1,ai+2,...an)- sum(a0,a1....ai-1)
        // +ai*(abs(count(ai+1,ai+2,...an)-count(a0,a1....ai-1)))

        // ye formula straight up example samajh kar nikala hai, and each smol
        // part in itself is easy, and sum karne ke liye prefix sum use kar
        // lenge

        // map me first of all store all common value wale elements ke indexes
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        // ab map ke har element par iterate karo and ans banao
        vector<long long> ans(n, 0);

        for (auto [ele, idx] : mpp) {

            // we here means apan ab saare ele value ke indexes ke liye ans bana
            // rahe hai, if ele=5 means saare nums[i]=5 wale indexes ke liye ans
            // bana rahe hai apan ek saath

            // sabse pehle ek prefix sum bana lenge
            int l = idx.size();

            vector<long long> pre(l, 0);
            pre[0] = idx[0];

            for (int i = 1; i < l; i++) {
                pre[i] = pre[i - 1] + idx[i];
            }

            // ab ans banao
            for (int i = 0; i < l; i++) {

                // for idx[i] index ans banana hai

                // ans[idx[i]] banana hai

                // formula laga do
                long long ttl = 0;

                // sum(a0,a1...ai-1)
                ttl -= (i > 0) ? pre[i - 1] : 0;
                ttl += (1LL*idx[i] * (i));

                // sum(ai+1,ai+2...an)
                ttl += pre.back() - pre[i];
                ttl -= (1LL*idx[i] * (l - i - 1)*1LL);

                ans[idx[i]] = ttl;
            }
        }

        return ans;
    }
};