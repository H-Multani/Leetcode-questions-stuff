class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int cols = strs[0].size();

        // LIS bottom up padhe hai dp array lelo
        vector<int> dp(cols, 1);
        // dp[i]-> LIS ending at index i

        // maxm LIS ka length store karlo since need padega
        int ans = 1;

        // LIS wala code likh do
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < i; j++) {
                // yaha usually apan ek string ka check karte the str[i] aith
                // str[j] ab har string ka check karo

                bool valid = true;
                // this is true means current i,j wala har string par valid
                // baith raha hai

                // nahi baithe valid toh alag kar do column ko

                // iterating over the strings
                for (auto str : strs) {
                    if (str[j] > str[i]) {
                        // we here means dikkat hai since normal LIS me we check
                        // if str[j]<=str[i], toh dp[i]=max(dp[i],dp[j]+1) karte
                        // hai

                        // but we are here means dikkat hori hai order me nahi
                        // hai, remove kardo column ko
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    // means sab sahi chal raha hai everything is in order ie
                    // str[j]<=str[i] for each string

                    // toh dp me ans update kardo
                    dp[i] = max(dp[i], dp[j] + 1);

                    // maxm LIS length bhi lete chalna
                    ans = max(ans, dp[i]);
                }
            }
        }

        // we here means sab check kar chuke hai and ans stores ki best to best
        // we can have correct order of length ans for each string , toh kitne
        // cols remove kiye??-> cols-ans vahi pucha hai return kardo
        return cols-ans;
    }
};