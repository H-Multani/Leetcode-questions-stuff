class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // freq array lelo, max value jitna hai utna+k size ka array lena hai
        int mx = *max_element(nums.begin(), nums.end()) + k;

        // itne size ka array lelo since max we do is max+k
        vector<int> prefix(mx + 1, 0);

        // iterate over nums
        for (auto it : nums)
            prefix[it]++;

        // ab cumulative freq nikal lo
        for (int i = 1; i < mx + 1; i++) {
            prefix[i] += prefix[i - 1];
        }

        int ans = 0;

        // ab har number ko target bana kar chalo dekho konsa best ans milta hai
        for (int target = 0; target < mx + 1; target++) {
            // sirf uss element ko pick karo jo present ho nums me, ie agar freq
            // becomes 0 we cant do shit
            if (prefix[target] == 0)
                continue;

            // ab target banane ke liye left me we can go till target-k value at
            // best
            int left = max(0,target - k);
            // ab target banane ke liye right me we can go till target+k value
            // at best
            int rt = min(mx,target + k);

            // ab kitne elements iss target value tak pahuch sakte hai vo nikalo
            // left idx possible hai ki valid na ho, chk hen use 
            int ttlcnt = prefix[rt] - ((left > 0) ? prefix[left - 1] : 0);

            // ab target par pehle se kitne elements hai vo nikalo
            int alreadythere =
                prefix[target] - ((target > 0) ? prefix[target - 1] : 0);

            // kitne ko convert karna padega
            int needconversion=ttlcnt-alreadythere;

            // max possible freq= of target
            int overall=alreadythere+min(needconversion,numOperations);

            // ans update kardo
            ans=max(ans,overall);
        }

        return ans;
    }
};