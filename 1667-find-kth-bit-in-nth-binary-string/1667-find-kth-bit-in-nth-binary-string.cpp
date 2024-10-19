class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 1; i < n; i++) {
            string snew = s;
            string inverted_s = s;
            // s ke saare bits reverse kar do
            for (int j = 0; j < inverted_s.size(); j++) {
                if (inverted_s[j] == '1') {
                    inverted_s[j] = '0';
                } else {
                    inverted_s[j] = '1';
                }
            }
            reverse(inverted_s.begin(), inverted_s.end());
            snew = snew + "1" + inverted_s;
            s = snew;
            if (s.size() >= k)
                break;
            // cout << s << endl;
        }
        // cout << s << endl;

        return s[k - 1];
    }
};