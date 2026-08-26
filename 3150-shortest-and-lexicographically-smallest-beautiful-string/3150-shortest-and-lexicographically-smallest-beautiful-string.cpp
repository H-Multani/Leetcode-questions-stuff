class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // sliding window chala do and compare karte jao best wali le lena

        string ans = "";

        // valid window banate jao and 1 ka count lete chalo, jaha valid ho
        // jaaye waha se best ans lete chalna

        int l = 0, r = 0;
        int n = s.size();
        // base ans is n times 1
        for (int i = 0; i < n + 1; i++)
            ans += '1';

        int cnt = 0;

        while (r < n) {
            // r wala banda andar leleo
            if (s[r] == '1')
                cnt++;

            // agar >k par hai toh shrink string

            while (l < r && cnt > k) {
                if (s[l] == '1')
                    cnt--;

                l++;
            }

            // we here means valid stirng mili hai,lekin ho sakta extra 0's ho l
            // wale side me, toh vo remove kar dena since we have to get
            // smallest valid substring

            // yaha bhi check karo ho sakta <k ho, valid ho tabhi karna ye sab
            if (cnt == k) {

                while (l < r && s[l] == '0')
                    l++;

                // valid substring mili hai update kardo ans

                string s1 = s.substr(l, r - l + 1);

                // update ans if of same length
                // if new string ka size bigger hai purane ans se then we dont
                // need to update
                if (s1.size() <= ans.size()) {

                    ans = min(ans, s1);
                    // agar better ans is smaller length take that
                    if (ans.size() > s1.size())
                        ans = s1;
                    // cout << "current is " << s.substr(l, r - l + 1) << endl;
                }
            }

            // pointer aage badha do
            r++;
        }

        // agar ans me end me bhi n+1 jitne 1's hai meaning ans cannot be made
        // in which case return khali

        string s1 = "";
        for (int i = 0; i < n + 1; i++)
            s1 += '1';

        if (s1 == ans)
            return "";

        return ans;
    }
};