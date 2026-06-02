class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        // brute force hi karlo bhai

        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // 2 cases,
        // case 1-> pehle land wali ride then water wali ride
        for (int i = 0; i < n; i++) {
            // current land ride start karo ttl time lagega
            int time = landStartTime[i] + landDuration[i];

            // ab is ke baad dhundo ki next kab water wali ride le sakte apan

            for (int j = 0; j < m; j++) {
                // current water ride starts at
                int st = waterStartTime[j];
                // and is of duration
                int d = waterDuration[j];

                // ab agar ye st<=time, means water wali ride already khul chuki
                // hai we can directly jump to that ride, in which case sirf
                // duration consider karenge total time me for best ans
                if (st <= time) {
                    ans = min(ans, time + d);
                } else {
                    // we here means water wali ride khulne wali hai, toh st tak
                    // wait karna padega, means land wali ride kiye normally,
                    // fir water wali ride ke liye ruke hue hai, which will
                    // start at st, and will go on for d time, toh overall will
                    // end at (st+d) time

                    // toh yehi st+d hoga best and for current situation
                    ans = min(ans, st + d);

                    // assume land ride start at 3 and ends after 4 time at 7,
                    // and water ride starts at 10 and ends after 5 time at 15,
                    // toh yehi situation hogi ki first we wait 3 time to start
                    // land ride, then we take 4 time to finish land ride, then
                    // we wait 10-7=3 time to start water ride, then we take 5
                    // time to end water ride making total time as 15, ab this
                    // 15 which can easily be taken by doing st+d directly, vahi kiya hai
                }
            }
        }


        // case 2-> pehle water wali ride then land wali ride
        for (int i = 0; i < m; i++) {
            // current water ride start karo ttl time lagega
            int time = waterStartTime[i] + waterDuration[i];

            // ab is ke baad dhundo ki next kab land wali ride le sakte apan

            for (int j = 0; j < n; j++) {
                // current water ride starts at
                int st = landStartTime[j];
                // and is of duration
                int d = landDuration[j];
                if (st <= time) {
                    ans = min(ans, time + d);
                } else {
                    ans = min(ans, st + d);

                }
            }
        }

        // dono case me se best and le liye
        return ans;
    }
};