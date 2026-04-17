class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // map me element ka reverse and uska index store kardo

        // agar koi element mila iteration time jo map me hai means uska reverse
        // exist karta hai

        // in such a situation, index nikalo map se and current idx se diff
        // nikal kar ans update kardo, then update the reverse wale ka index to
        // current element ka index since aage agar same reverse value mila toh
        // nearest wala element ka index kaam aayega, farthest ka nai since
        // overall minimize karna hai

        int n = nums.size();

        unordered_map<int, int> mpp;
        int ans=n+1;
        for (int i = 0; i < n; i++) {
            // agar current number map me mil jaaye means potential ans
            if (mpp.find(nums[i]) != mpp.end()) {
                // means potential ans for index mpp[nums[i]] and i

                // update ans
                ans = min(ans, abs(i - mpp[nums[i]]));
            }

            // we here means ya toh element nai mila, ya toh ans update kar
            // chuke hai, either way, current element ko reverse karo

            // ez way string banao
            string s = to_string(nums[i]);

            // reverse the string
            reverse(s.begin(), s.end());
            // vapas int bana lo
            int val = stoi(s);

            // ab mpp me ye reversed value along with index store kardo, agar ye
            // pehle se hai map me toh index update kardo, since aage agar aisa
            // element milega toh nearest wale reverse ka index chahiye

            mpp[val]=i;
        }

        if(ans==n+1){
            // means ans nai mila in such case return -1
            return -1;
        }

        return ans;
    }
};