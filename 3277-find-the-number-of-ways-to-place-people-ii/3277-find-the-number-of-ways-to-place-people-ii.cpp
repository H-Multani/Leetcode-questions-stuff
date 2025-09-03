class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) {
        // x same hai
        if (v1[0] == v2[0]) {
            // y wala bada hai toh return true
            if (v1[1] > v2[1])
                return true;
            return false;
        }

        // we here means different hai x

        // smaller x comes first
        if (v1[0] < v2[0])
            return true;
        return false;
    }
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();

        int ans = 0;

        // custom sort kardo
        // sort accd to x, and agar x same hue toh descending order me y sort
        // kardo
        sort(p.begin(), p.end(), comp);

        for (int i = 0; i < n; i++) {
            // ye hai point A
            int x1 = p[i][0];
            int y1 = p[i][1];

            // maxm y wala banda lelo
            int maxy = INT_MIN;

            // ab B wala pt dekho
            for (int j = i + 1; j < n; j++) {
                // this is point B
                int x2 = p[j][0];
                int y2 = p[j][1];

                // agar current bande ka y is greater than y1, means current
                // point is no longer in the right lower rectangle ka range of
                // point A, toh continue kar jao
                if (y2 > y1)
                    continue;

                // ab agar current bande(B) ka y is bigger than the max y that
                // we have found till here means ki current point B aur point A
                // ke beech me koi point nai aayega, since y2 aur y1 ke beech me
                // koi y nai hai, this is bcoz y2 is bigger than the max y
                // coordinate we have found between all points frm A to B yet,

                // toh matlab ki current wala A and B ka pair is valid ans,
                // update
                if (y2 > maxy) {
                    ans++;
                    // update max y for upcoming points
                    maxy=y2;
                }
            }
        }

        return ans;
    }
};