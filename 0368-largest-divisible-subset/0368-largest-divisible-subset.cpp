class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // pehle sort karlo
        sort(nums.begin(), nums.end());
        // ab dp array banao bottum up wala(LIS wala, mik)

        int n = nums.size();
        vector<int> dp(n, 1);
        // dp[i]=6 means ki idx i tak me apan ko maxm 6 length ka subset mila
        // hai abhi takk

        // prev idx vector banao, it will store ki subset me, nums[i] waale se
        // pehle kisko liya tha
        vector<int> prev(n, -1);
        // prev[i]=5 means subset me nums[i] se just pehle idx 5 waale element
        // ie nums[5] ko liya tha, toh vaha chale jao

        // maxm length ke liye ek banalo. minm length will be 1
        int maxl = 1;
        // the index jis par ye maxm length mila rha
        int lastchosenidx = 0;

        // ab bottum up wala code likhenge
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // lis me yaha par nums[i]>nums[j] krte the, lekin yaha already
                // sorted hai, apan ko yaha divisible chk krna hai vahi karo

                if (nums[i] % nums[j] == 0) {
                    // agar nums[i] is divisible by nums[j], means nums[j] waale
                    // subset me ab nums[i] ko bhi daal sakte hai, dp[j]= is the
                    // length of maxm subset we got upto idx j

                    // here we check ki i tak ki current maxm subset length is
                    // smaller than j tak ki maxm length+1 , since agar hai toh
                    // it means ki apan ko maxm subset wala new mil gaya
                    if (dp[i] < dp[j] + 1) {
                        // we here means idx i tak ke liye new subset mil gaya
                        // hai with bigger length new length update kardo
                        dp[i] = dp[j] + 1;

                        // ab ye i ke subset me nums[i] se just pehle apan ne
                        // nums[j] ko liya toh previdx[i] me j daal do
                        prev[i] = j;
                    }

                    // ab maxm length update kardo agar need hai toh
                    if (dp[i] > maxl) {
                        // we here means new bigger length ka valid subset mila
                        // hai, toh maxl update kardo
                        maxl = dp[i];

                        // aur ue subset konse idx se chalu hora hai??, nums[i]
                        // se toh i idx save karlo
                        lastchosenidx = i;
                    }
                }
            }
        }

        // ab apna maxm length wala subset ban chuka hai, and uska length maxl
        // hai, lekin apan ko length thodi nikalni thi, apan ko subset chahiye
        // tha toh vo daaldo

        vector<int> ans;

        // ab maxl is found at idx lastchosenidx

        while (lastchosenidx != -1) {
            // we here means lastchosenidx is valid idx

            // toh ab biggest subset me nums[lastchosenidx] liya tha toh ans me
            // daal do
            ans.push_back(nums[lastchosenidx]);

            // ab iske just pehle apan ne konsa idx liya tha subset me??, we
            // took prev[lastchosenidx]

            // toh iss idx par chale jao waha wala element lene
            lastchosenidx=prev[lastchosenidx];
        }

        // we here matlab subset banna tha ban gaya , return kardo
        return ans;
    }
};