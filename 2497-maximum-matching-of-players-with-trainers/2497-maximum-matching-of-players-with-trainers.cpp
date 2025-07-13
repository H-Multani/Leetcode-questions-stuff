class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<bool> gbool(g.size(), false);
        int gi = 0, si = 0;

        // current player ko konsa wala trainer satisfy kar payega

        // toh iterate over the trainers, match trainers with corresposning
        // student, agar current trainer inadequate, move to next
        // trainer,otherwise if adequate, move to next trainer and the next
        // student

        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                gbool[gi] = true;
                gi++;
                si++;
            } else {
                si++;
            }
        }

        int truecnt = 0;

        // count kitne students satisfied till here
        for (auto it : gbool) {
            if (it)
                truecnt++;
        }

        return truecnt;
    }
};