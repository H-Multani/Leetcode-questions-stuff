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
        // + (3*(1-3))

        // toh this can be written for [a1,a2,a3.....an]-> and suppose we are
        // making ans for ai, then overall formula will be

        // sum(ai+1,ai+2,...an)- sum(a0,a1....ai-1)
        // -ai*(count(ai+1,ai+2,...an)) + ai*(count(a0,a1....ai-1))

        // ye formula straight up example samajh kar nikala hai different
        // different, and each smol part in itself is easy, and sum karne ke
        // liye prefix sum use kar lenge

        // map me first of all store all common value wale elements ke indexes
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        // O(n)
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        // ab map ke har element par iterate karo and ans banao
        vector<long long> ans(n, 0);

        // outer loop runs on all unique elements, and andar wala loop runs on
        // indexes of those unique elements, overall O(n+n)-> O(n) for prefix
        // banane, and O(n) for ans update karne

        // overall O(2n)-> O(n)
        for (auto [ele, idx] : mpp) {

            // we here means apan ab saare ele value ke indexes ke liye ans bana
            // rahe hai, if ele=5 means saare nums[i]=5 wale indexes ke liye ans
            // bana rahe hai apan ek saath

            // sabse pehle ek prefix sum bana lenge
            int len = idx.size();

            vector<long long> pre(len, 0);
            pre[0] = idx[0];

            // bhar do prefix sum ko element ke sums se, since we need this for
            // sum(a0,a1,a2...ai)
            for (int i = 1; i < len; i++) {
                pre[i] = pre[i - 1] + idx[i];
            }

            // ab ans banao
            for (int i = 0; i < len; i++) {

                // for 'idx[i]' index ans banana hai

                // ie -> ans[idx[i]] banana hai

                // formula laga do
                long long ttl = 0;

                // sum(a0,a1...ai-1)
                ttl -= (i > 0) ? pre[i - 1] : 0;
                // ai*(count(a0,a1,a2...ai-1))
                ttl += (1LL * idx[i] * (i));

                // sum(ai+1,ai+2...an)
                ttl += pre.back() - pre[i];
                // ai*(count(ai+1,ai+2.....an))
                ttl -= (1LL * idx[i] * (len - i - 1) * 1LL);

                // ab ttl is made for ans[idx[i]], kardo update,

                // this ttl is sum talked about in question for ans[idx[i]]
                ans[idx[i]] = ttl;
            }
        }


        // overall complexity O(n)

        return ans;
    }
};