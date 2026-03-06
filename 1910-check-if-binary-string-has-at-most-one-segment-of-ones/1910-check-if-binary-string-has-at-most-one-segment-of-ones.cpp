class Solution {
public:
    bool checkOnesSegment(string s) {
        // 1's ka count nikal lo, and segment ka size nikal lo, agar dono same
        // size ke then only 1 segment present, otherwise more segments present

        int onecnt = 0;
        for (auto it : s) {
            if (it == '1')
                onecnt++;
        }

        int cnt = 0;

        for (auto it : s) {
            if (it == '1') {
                cnt++;
            } else {
                // agar count 0 nai hai, means 1 ka segment tha jo khatam hua
                // hai, in such case compare karo, if segment size same as
                // onecnt, means 1 hi segment hai pure string me,otherwise zyada
                // segments hai, in which case return false;

                if (cnt != 0) {
                    // means yaha ek 1 ka segment khatam hua hai, if this
                    // segment same as onecnt, means 1 hi segment tha return
                    // true, otherwise if not same as onecnt means, more than 1
                    // segments present in which case return false
                    return onecnt == cnt;
                }
            }
        }

        // edge cases, pure string me only 1s hai ya only 0s hai, in which case
        // yaha bhi if cnt==onecnt, return true, else false

        return onecnt == cnt;
    }
};