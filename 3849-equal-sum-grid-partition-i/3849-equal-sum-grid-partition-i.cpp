class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // ok toh prefix sums bana sakte hai apan horizontal and verticals ke
        // liye

        // first horizontal cuts ke liye banao prefix sums

        vector<long long> horiz;

        for (auto it : grid) {
            long long ttl = 0;

            for (auto it2 : it) {
                ttl += it2;
            }

            if (horiz.size() == 0) {
                horiz.push_back(ttl);
            } else {
                horiz.push_back(horiz.back() + ttl);
            }
        }

        // toh isse apne paas prefix sums aa jaenge horizontal cuts ke
        // horiz[i]=x means start se i th row tak ek section hai and uska sum is
        // x (ie rows 0 to i ka sum is x)

        // we need both sides to have same sum, toh upper side ka sum is simply
        // horiz[i], lower side ka sum=total-upper side ka sum, agar ye dono
        // side ka sum same aa gaya means ans possible, return true yehi se

        // yehi logic laga do zara

        for (int i = 0; i < horiz.size(); i++) {
            // upper side ka sum
            long long upper = horiz[i];

            // lower side ka sum
            long long lower = horiz.back() - upper;

            // agar ye dono ka value same hai means ki upper wale values ka sum
            // is same as lower wale values ka sum, in such case return true

            if (upper == lower)
                return true;
        }

        // do the same exact thing for vertical cuts, bas yaha apan rows ka sum
        // nikal kar prefix me include karre the, ab apan same cheez columns ke
        // sath bhi karenge

        vector<long long> vert;

        for (int i = 0; i < grid[0].size(); i++) {
            long long ttl = 0;
            for (int j = 0; j < grid.size(); j++) {
                ttl += grid[j][i];
            }

            if (vert.size() == 0) {
                vert.push_back(ttl);
            } else {
                vert.push_back(vert.back() + ttl);
            }
        }

        // ab apna vertical cuts wala prefix sum ban chuka, dhundo ki koi actual
        // cut possible hai ki nai

        for (int i = 0; i < vert.size(); i++) {
            // left side ka sum
            long long left = vert[i];

            // right side ka sum
            long long rt = vert.back() - left;

            // agar ye dono ka value same hai means ki left wale values ka sum
            // is same as right wale values ka sum, in such case return true

            if (left == rt)
                return true;
        }

        // ab dono me se koi bhi cuts possible nai hai toh false hi bhejdo
        return false;
    }
};