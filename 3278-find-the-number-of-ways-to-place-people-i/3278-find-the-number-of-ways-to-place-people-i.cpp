class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // too low constraints, check every single possible pair

        // point 2 baad wale question me dikkat de sakta hai ,yaha toh bas 2
        // points lene hai and uske andar ka square chk krna h bass

        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // current hai i th wala point and j th wala point
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];

                if ((x1 <= x2 && y1 >= y2) || (x2 <= x1 && y2 >= y1)) {
                    // means diagonal me toh hai, counting kar sakte hai, ab bas
                    // iske beech me koi nai ho uska check karna hai

                    // toh (x1,y1) and (x2,y2) ko diagonals leke chale toh koi
                    // bhi element agar simultaneously (x1,x2) ki range me and
                    // (y1,y2) ki range me hua toh nai le sakte apan
                    bool count = true;
                    cout << "here" << endl;
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            // means check for this
                            int newx = points[k][0];
                            int newy = points[k][1];
                            if (((newx <= x2 && newx >= x1) ||
                                 (newx <= x1 && newx >= x2)) &&
                                    ((newy <= y2 && newy >= y1) ||
                                (newy <= y1 && newy >= y2))) {
                                cout << "here2" << endl;
                                // we here means new point is inside i,j se
                                // banne wala point, ans cant be counted
                                count = false;
                                break;
                            }
                        }
                    }

                    if (count)
                        ans++;
                }
            }
        }

        return ans;
    }
};