class Solution {
public:
    int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        // horiz and vertical fences me edges wale nai hai toh 1 and m daal do
        // horiz me and 1 and n daal do vertical me
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // sabko sort kardo so that order me mile
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // 2 sets lelo which will sore horizontal me kitni widths hai and
        // vertical me kitni widths hai
        unordered_set<int> heights;
        unordered_set<int> widths;

        // ab vFences par iterate karke all possible widths nikal kar set me dal
        // do
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];

                // insert kardo widths me
                widths.insert(width);
            }
        }

        // same cheez nikalo hFences ke liye, bass yaha agar same height wala
        // widths me mil gaya means square ban jayega, in such case ans update
        // kar dena

        // max side nikalte jayenge
        long long ans = 0;
        // initially the side length of square is 0
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {

                // horizontal fence alag karenge oh height milega
                long long height = hFences[j] - hFences[i];

                // agar ye same height ka banda width me available hai means
                // square can be made
                if (widths.find(height) != widths.end()) {
                    // means mil gaya, ie iss value(height) ka apan side length
                    // rakh kar square bana sakte hai

                    // update kardo maxm side length ke liye
                    ans=max(ans,height);
                }
            }
        }

        // agar max side is 0 means no square can be made , in such case return -1
        if(ans==0) return -1;

        // otherwise square ka area nikal kar bhej do
        return (ans*ans)%mod;
    }
};