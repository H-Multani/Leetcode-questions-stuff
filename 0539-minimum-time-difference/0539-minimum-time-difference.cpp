class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert the time to overall minuites so 01:45 means 60+45=105 mins
        // and store the mins in an array, then sort the array
        vector<int> mins;
        for (auto it : timePoints) {
            int a = 0;
            a = ((it[0] - '0') * 10) + (it[1] - '0'); // hrs
            a *= 60;                                  // hrs to mins
            a += ((it[3] - '0') * 10) + (it[4] - '0');
            cout << a << endl;
            mins.push_back(a);
        }
        sort(mins.begin(), mins.end());

        int minm = INT_MAX;
        // find the minm diff, comapare the 2 adjacent mins
        int len = mins.size();
        for (auto i = 0; i < len; i++) {
            // current
            int curr = mins[i % len];
            // aage wala
            int nxt = mins[(i + 1) % len];

            // diff is of 2 types
            // eg we have 110 mins and 1300 mins
            // ........110.................1300.........(1439(the end))
            // we have 2 differences in time, first is 110 to 1300 straight, ie
            // 1300-110=1190
            // then 1300 to 1439 then frm start to 110, ie
            // 140(1300 to 1440) + 110(0 to 110)=249
            // find the minm of the 2 differences
            int diff1=abs(curr-nxt);
            int diff2=1440-(max(curr,nxt))+(min(curr,nxt));
            int overalldiff=min(diff1,diff2);

            // one of these could be an ans, update ans
            minm=min(minm,overalldiff);
        }

        return minm;

        // return 0;
    }
};