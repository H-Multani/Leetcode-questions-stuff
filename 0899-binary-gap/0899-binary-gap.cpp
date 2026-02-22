class Solution {
public:
    int binaryGap(int n) {
        // binary string bana do n ka
        string s = "";

        while (n > 0) {
            s += (n % 2 == 0) ? "0" : "1";

            n /= 2;
        }

        // ab adjacent 1s ka dist nikal lo

        int ans = 0;

        int idx = -1;

        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                // 0 hai toh aage badho kuch kaam nai apan ko
            } else {
                // current 1 and previous adjacent 1 ke beech ka dist nikal lo

                // prev 1 ka index stored in idx, toh distance between previous
                // adjacent 1 and current 1 is (i-idx)

                // edge case, agae first wala 1 hai toh iska koi previous
                // adjacent nai hai, idx ko update karke aage badho
                if (idx == -1) {
                    idx = i;
                } else {

                    // we here means previous 1 hai idx index par, toh distance
                    // between current 1 and prev adjacent 1 is i-idx

                    // best ans le lena
                    ans = max(ans, i - idx);

                    // ab aage wale 1 ke liye current i will be previous
                    // adjacent, update and aage badho
                    idx = i;
                }
            }
        }

        return ans;
    }
};