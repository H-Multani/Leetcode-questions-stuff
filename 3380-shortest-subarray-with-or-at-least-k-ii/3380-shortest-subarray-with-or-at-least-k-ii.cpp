class Solution {
public:
    // addn and removal ke function me zyada difference nai hai, man kare toh
    // merge kar dena

    // add current element to window
    void addinwndow(int x, vector<int>& vec) {
        for (int i = 0; i < 32; i++) {

            // condn x>>i, means x ko i times rt shift kiya, toh ab original x
            // ka ith bit comes to the rightmost posn(it becomes the least
            // significant bit LSB)
            // iss number ka AND kiya 1 se
            // if the 1 th bit was set means ye hoga ki 1 && 1 =>1
            // if the 1 th bit was not set means ye hoga ki 0 && 1 =>0
            // isse seedhe pata lag jayega ki original x ka i th bit set hai ki
            // nai
            if ((x >> i) & 1 == 1) {
                // means i th bit set hai, update karo
                // vec me i th bit par cnt increase krdo
                vec[i]++;
            }
        }
    }
    // remove current element frm window
    void removefrmwindow(int x, vector<int>& vec) {
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1 == 1) {
                // means i th bit set nai hai, update karo
                // vec me i th bit par cnt decrease krdo, to indicate that ye
                // given number(x) ka i th bit ka contribution remove kar diya
                vec[i]--;
            }
        }
    }

    // get current number from bitstore
    int getdecimalno(vector<int>& vec) {
        // current window ke saare nos ka or nikalo
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if (vec[i] > 0) {
                // means i th posn par 1 hai, toh ans ke i th posn kar 1 laga do
                // i th posn ka 1 will be 1 left shift i times
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        int i = 0, j = 0;
        vector<int> bitstore(32, 0);
        // bitstore[i]= ttl no of set bits in ith posn

        // sliding window
        while (j < n) {
            // current bande ko include karo
            // ie bitstore me uska values update karo
            addinwndow(nums[j], bitstore);

            // agar current ka OR >=k hai means window is possible ans and can
            // be shrinked for better answer, shrink krdo window ko
            while (i <= j && getdecimalno(bitstore) >= k) {
                // windo can be shrinked, shrink kro
                // update ans first
                ans = min(ans, j - i + 1);

                // shrink window, remove i th banda frm the overall OR
                // iw update the bitstore
                removefrmwindow(nums[i], bitstore);
                i++;
            }

            // window aage badhao
            j++;
        }

        if (ans == INT_MAX) {
            // means koi ans nai mila ab tk, return -1
            return -1;
        }

        return ans;
    }
};