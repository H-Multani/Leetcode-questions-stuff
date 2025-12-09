class Solution {
public:
    int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        // 2 map lelo ek store karega ki current element ke left me kitne bande
        // hai with their freq, and second map will store ki current element ke
        // right me kitne bande ki kya freq hai

        // by this we will have left and right element since we need left
        // element same as right element , ab beech wale elements par iterate
        // kar lenge

        // ab jab array par iterate karenge toh current element ko centre wala
        // element leke chalenge then right left wale elements needed will have
        // value curr*2, toh ek map se nikal lenge ki left me curr*2 ke kitne
        // instances hai, and second map se nikal lenge ki right me curr*2 ke
        // kitne instances hai

        // agar maan lo left me x instances hai of curr*2 and right me y hai,
        // means we can make triplets like {(x values), current value, (y
        // values)}, this will make x*y jitne triplets since for each banda in
        // right side we have y options for left side and aisa x elements ke
        // liye hai toh x*y triplets ttl banenge

        // aisa har bande ke liye karenge count kar lenge
        long long ans = 0;

        unordered_map<long long, long long> left, rt;

        for (auto it : nums) {
            rt[it]++;
        }

        // ab start karte hai

        // yaha 2 options hai ki ya toh current element and prev element leke
        // chalu ya toh loop me chalau aisa ki ye karna hi nai pade

        // first option includes prev wale element ko left map me include karna
        // and current wale ko right se alag karna then cheking for ans

        // start karne se pehle idx=0 wale ko right se alag kar dena nai toh
        // dikkat hogi since we start at i=1 toh right wala element idx 1 se
        // alag hora toh edge case ye hai ki idx 0 wala abhi bhi hai toh alag
        // kar dena
        rt[nums[0]]--;
        for (int i = 1; i < nums.size(); i++) {
            // current element ko right wale map se alag karo, toh current
            // element not included in right side
            rt[nums[i]]--;
            // prev wale element ko left me add kardo, toh prev element now
            // included in left side
            left[nums[i - 1]]++;

            // isse ye hua hai ki current wala element is not in either of the 2
            // maps, toh ab current element ko centre leke chal sakte hai

            // agar centre wala element is odd means curr/2 karne se aisi value
            // nai aayegi which will get us nums[i]=2*nums[j] like nums[j]=5
            // then nums[i]=2 which will not hold for nums[i]=2*nums[j], toh
            // such case me aage badh jao


            // otherwise curr/2 ka freq nikalo left se (x) and right se (y)
            long long x = (left[nums[i] * 2])%mod;
            long long  y = (rt[nums[i] * 2])%mod;

            // ans me add kardo x*y triplet count
            ans = (ans + (x * y) % mod) % mod;
        }

        return ans;
    }
};