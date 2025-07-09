class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        // gaps ginn lo

        vector<int> gaps;
        int n = st.size();

        // 0 se lekek first meeting tkk ka gap
        if (st[0] > 0)
            gaps.push_back(st[0]);

        for (int i = 1; i < n; i++) {
            // if (st[i] > et[i - 1])
            //     gaps.push_back(st[i] - et[i - 1]);

            // gaps chkk krke mat dalo, jitna gap hai laga do, since agar 2
            // meeting continous hai , phir bhi unko rechedule karne me 2
            // operation lagenge since 2 meetings separately separately rechedule
            // hongi

            gaps.push_back(st[i]-et[i-1]);
        }

        // end me no gaps remaining, lekin ending wala time will be eventtime
        // toh last meeting ending se eventtime tkk ke gap ko bhi include karo
        if (et[n - 1] < eventTime)
            gaps.push_back(eventTime - et[n - 1]);

        // ya toh saare elements ko right side daba do, beech me maxm gap ke
        // liye ya toh saare elements ko left side daba do, beech me maxm gap ke
        // liye

        // sliding window chala do gaps par,get maxm valued window of size<=k,
        // return as ans

        int ans = 0;
        int ttl = 0;

        for (auto it : gaps)
            cout << it << " ";
        cout << endl;
        n = gaps.size();
        int l = 0, r = 0;

        while (r < n) {
            // current wala banda include karo
            ttl += gaps[r];

            // agar 3 gaps join ki hai means 2 meeting rechedule ki hai

            // agar >k meeting rechedule ki hai toh shrink windo
            // no of meetinggs done=r-l;
            if (r - l > k) {
                // window shrink kro
                ttl -= gaps[l];
                l++;
            }

            // means window valid hai, update ans
            ans = max(ans, ttl);

            // extend window
            r++;
        }

        return ans;
    }
};