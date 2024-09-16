class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert the time to overall minuites so 01:45 means 60+45=105 mins
        // and store the mins in an array, then sort the array
        // sorting will make sure all closer values are kept near each other so
        // that diff is minm when we compare
        // we do all this since it makes comparison of times easier
        vector<int> mins;
        for (auto it : timePoints) {
            int a = 0;
            a = ((it[0] - '0') * 10) + (it[1] - '0');  // hrs
            a *= 60;                                   // hrs to mins
            a += ((it[3] - '0') * 10) + (it[4] - '0'); // add the mins
            cout << a << endl;
            mins.push_back(a);
        }
        sort(mins.begin(), mins.end());

        int minm = INT_MAX;
        // find the minm diff, comapare the 2 adjacent mins for closest values
        // note: the last value compared to first(for cases like 00:00 ......
        // 23:59)
        int len = mins.size();
        for (auto i = 0; i < len; i++) {
            // current
            int curr = mins[i % len];
            // adjacent value
            int nxt = mins[(i + 1) % len];

            // diff is of 2 types,since after 23:59, time starts frm 00:00 again
            // eg we have curr= 110 mins and nxt= 1300 mins
            // 0........110.................1300.........(1439(the end))
            // we have 2 differences in time, first is 110 to 1300 straight, ie
            // 1300-110=1190 mins
            // second is, 1300 to 1440 then frm start to 110, ie
            // 140(1300 to 1440) + 110(0 to 110)=249
            // find the minm of the 2 differences
            int diff1 = abs(curr - nxt);
            int diff2 = 1440 - (max(curr, nxt)) + (min(curr, nxt));
            int overalldiff = min(diff1, diff2);
            // minm taken since minm is useful to us

            // NOTE: 23:59 -> 1439 mins, and we subtracted frm 1440 above, since
            // 00:00->0 mins, we have to count this minute too since its a
            // valid minute value, hence we need to add 1 to the overall
            // difference(to account for the 0 th minute), this can be done by
            // simply using 1440 instead of 1439

            // one of these could be an ans, update ans
            minm = min(minm, overalldiff);
        }

        return minm;

        // return 0;
    }
};