class Solution {
public:
    int mod = 1e9 + 7;
    // binary exponentiation ke liye code likh do fermat me kaam aayega
    long long pwr(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = pwr(a, b / 2);
        long long ans = (half * half) % mod;

        if (b % 2 == 1)
            ans = (ans * a) % mod;

        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blocksize = ceil(sqrt(n));

        // map lelo which stores all queries with k<n, har value of k par jitne
        // queries store karlo

        unordered_map<int, vector<vector<int>>> smolkmap;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            if (k >= blocksize) {
                // means yaha max to max sqrt(n) jitne steps lagenge brute force
                // bhi chalaoge toh, toh yaha simple rakho brute force chala do

                for (int i = l; i <= r; i+=k) {
                    nums[i] = (1LL*nums[i] * v) % mod;
                }
            } else {
                // means k<blocksize, cant use brute force since too much TLE

                // map me daal do baad me karenge iss par iterate efficiently
                smolkmap[k].push_back(query);
            }
        }

        // ab smoklmap ko process krte hai
        for (auto [k, allqueries] : smolkmap) {
            // har k ke liye saari queries par ek sath difference array
            // technique laga do

            // diff array technique ke liye vector lelo
            vector<long long> diff(n, 1);

            for (auto query : allqueries) {
                int l = query[0];
                int r = query[1];
                int v = query[3];

                // update kardo diff me, ye part hai diff array technique+jumps
                // ka
                diff[l] = (diff[l] * v) % mod;
                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                // upar multiply kiya neeche divide karo, lekin mod bhi lena hai
                // toh fermats apply karo

                // next wala idx range me bhi hona chahiye btw
                if (next < n) {
                    diff[next] = (diff[next] * pwr(v, mod - 2)) % mod;
                }
            }
            // ab saari queries ko ek baari me hi update kar diya difference array me

            // ab prefix(cumulative) product karte jao difference array banate jao
            for(int i=0;i<n;i++){
                if(i-k>=0){
                    diff[i]=(diff[i]*diff[i-k])%mod;
                }
            }


            // ab all done, just apply diff to nums for current wala k,

            for(int i=0;i<n;i++){
                nums[i]=(1LL*nums[i]*diff[i])%mod;

            }

            // all done now
        }

        // ab bass ans banane ke liye XOR lelo and bhej do
        int ans=0;

        for(auto it:nums){
            ans=ans^it;
        }

        return ans;
    }
};