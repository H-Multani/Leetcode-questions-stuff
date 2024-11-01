class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 1;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                cnt++;
            } else {
                int reqd = min(2, cnt);
                while (reqd--) {
                    ans += s[i];
                }
                cnt = 1;
            }
        }
        int reqd = min(2, cnt);
        while (reqd--) {
            ans += s[n - 1];
        }

        return ans;
    }
};