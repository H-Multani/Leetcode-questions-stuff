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

        // second option includes ek loop me element smartly iterate karu mai
        // like so
        for (auto curr : nums) {
            // now we are at nums[i], this element is not in left wala map, but
            // is currently present in right wala map

            // toh removing it from right wala map will make this element not be
            // in both the map, tab iss element ko apan consider kar payenge for
            // centre element

            // remove frm right wala map
            rt[curr]--;

            // ab current element is not in both map, x and y nikal lo
            long long x = (left[curr * 2]) % mod;
            long long y = (rt[curr * 2]) % mod;

            // ab ans me add kardo
            ans = (ans + (x * y) % mod) % mod;

            // ab curr wale element ka kaam ho gaya hai as middle element, aage
            // aane wale elements ke liye ye current element should be included
            // in left wala side toh left me daal do
            left[curr]++;
        }
        // toh basically what we did here is, remove element frm right map, so
        // now it became part of no maps, meansing it becomes centre element ,
        // after counting and all, add the element in left side since for
        // upcoming elements this will be in the left side
        return ans;
    }
};