class Solution {
public:
    string decToBinary(int n) {
        string ans = "";
        // Size of an integer is assumed to be 32 bits
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                // cout << "1";
                ans += '1';
            else
                // cout << "0";
                ans += '0';
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string st = decToBinary(start);
        string end = decToBinary(goal);
        int overallsize = max(st.size(), end.size());
        // while(st.size()<overallsize) st='0'+st;
        // while(end.size()<overallsize) end='0'+end;
        cout << st << " " << end << endl;
        int cnt = 0;
        for (auto i = 0; i < st.size(); i++) {
            if (st[i] != end[i])
                cnt++;
        }
        return cnt;
    }
};