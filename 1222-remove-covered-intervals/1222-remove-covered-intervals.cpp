class Solution {
public:
    static bool comp(vector<int>& a1, vector<int>& a2) {
        if (a1[0] != a2[0])
            return a1[0] < a2[0];

        // we here means same hai toh second ke hisab se sort karo abs
        return a1[1] < a2[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // first of all sort the intervals based on starting time
        sort(intervals.begin(), intervals.end(), comp);

        // sort karne ke baad har interval par iterate karenge to find if
        // current wala interval is covered
        int n = intervals.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // current wala is [st,end]
            int a = intervals[i][0];
            int b = intervals[i][1];

            // toh check karne ke liye the easy way is comparing with all
            for(int j=0;j<n;j++){
                if(i==j) continue;
                // this is [c,d]

                if(intervals[j][0]<=a && b<=intervals[j][1]){
                    ans++;
                    break;
                }
            }

            // second tareeka is using binary search to check in shorter area

            // toh agar current wala is [c,d] then this covers those intervals
            // jisme start>=c, toh start ke liye ye aa jaega normal binary
            // search se since ordered hai intervals,

            // and end is <=d, end ke liye custom binary search likhna pad sakte
            // hai, but even still the order isnt sorted for second wale
            // elements, toh thats not possible, itna hi theek hai
        }

        // ans jitne remove hue hai toh remaining are

        return n - ans;
    }
};