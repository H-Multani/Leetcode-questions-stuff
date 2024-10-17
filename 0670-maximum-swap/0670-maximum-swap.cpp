class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        bool issorted = true;
        for (int i = 0; i < n; i++) {
            if (s[i] < s[i + 1])
                issorted = false;
        }
        if (issorted)
            return num;

        for (int i = 0; i < n; i++) {
            int maxm = i;
            for (int j = i + 1; j < n; j++) {
                if (s[j] >= s[maxm]) {
                    maxm = j;
                }
            }
            if (s[maxm] > s[i]) {
                swap(s[i], s[maxm]);
                return stoi(s);
            }
        }
        num = stoi(s);
        return num;
    }
};