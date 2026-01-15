class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        // sort maar do
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // nikal lo ab ranges, dono ki ranges alag vector me store karlo since
        // we need horiz wala maxm range and vertical wala maxm range
        // vector<vector<int>> hrange;

        // apan iterate kar rahe hai ki konse rods nikal sakte hai, toh agar
        // rods 2-5 can be taken out then we have 5-2+2=5 area jisme square ban
        // sakta hai since saari rods nikal lo, we have open area between rods
        // 1-2,2-3,3-4,4-5,5-6, ye 5 area open ho jayega if rods 2,3,4,5 removed

        // range store karane ka need nahi hai, jab ek range mil jaaye ki like
        // 2-5 ke saari rod nikal sakte toh bass open area nikal lo maxm kitna
        // open area mil raha square ke side ke liye, since square ka side
        // baithega na area me toh bass maxm jitna area nikal lo sufficient
        // rahega, for 2-5 wala eg, we have area 5-2+2=5 area jisme side baitha
        // sakte square ka, toh horizontal wale bars se nikal lo maxm area konsa
        // free hai,

        // then vertical bars se nikal lo kitna maxm area free kar sakte ye,for
        // dono ka minm leke ans de dena

        int hans = -1;

        int prev = hBars[0] - 1;
        // prev=hBars[0]-1 since ye rod koi nai kar raha alag, 1 rakhne se
        // dikkat ye ho sakti ki agar rods 1,2,3 not taken out lekin rod 4 taken
        // out toh 1 to 5 ka area is not empty 3 to 5 is empty, tabhi jaha se
        // first rod alag kar rahe waha se ek pehle se start karenge since that
        // will be correct selection ki yaha se rods nikal rhi
        for (auto i = 0; i < hBars.size() - 1; i++) {
            if (hBars[i] + 1 == hBars[i + 1]) {
                // consecutive hai aage badho
                continue;
            } else {
                // means consecutive nahi hai, toh jitni rods hai alag
                // kardo so we have rod at prev and rod at hBars[i]+1, beech ki
                // saari rods alag kar sakte hai,toh kardo alag and maxm area

                // so we have rods at prev and hBars[i]+1, beech ka area will be
                // hBars[i]+1-prev, since jab 2-5 tak ki rods alag kar sakte the
                // then next rods were at 1 and 6, here 1 is prev and 6 is the
                // hBars[i]+1 wala

                // in such case area we can have is 6-1=5 jitna tabhi ye formula
                hans = max(hans, hBars[i] + 1 - prev);

                // aage wale ke liye prev will be the rod just before hBar[i+1]
                // since hBars[i+1] wali rod bhi alag kar sakte hai apan tabhi
                // for aane wale bande prev will be hBars[i+1]-1
                prev = hBars[i + 1] - 1;
            }
        }

        // ek last baari check kar lena hans ka since ho sakta ki saari hi rods
        // nikal li, in such case last rod will be at hBars[size-1]+1, since
        // last bar we have taken out is from hBars[size-1], toh iske just baad
        // wali bar toh nikali nai hai na toh why should we go to the absolute
        // last wali bar at n+2 to consider ki ye bar nai nikali hogi, ye area
        // me dikkat kar sakta since agar last bar was taken out at 4, toh
        // ...4,5 tak ka area mila hai bas, rod 5 abhi hai present, fir agar rod
        // 5 ke aage rods 6,7,8 rahi toh rod 4 to 8 kyu consider karenge freee
        // area ke liye waha toh rods present hai , here 5 is the
        // hBars[size-1]+1 wala banda and 8 is the  n+2

        // tabhi use hBars[size-1]+1 wala rod as last resort
        hans = max(hans, hBars[hBars.size()-1] + 1 - prev);

        int vans = -1;
        prev = vBars[0] - 1;
        // prev=1 since ye rod koi nai kar raha alag
        for (auto i = 0; i < vBars.size() - 1; i++) {
            if (vBars[i] + 1 == vBars[i + 1]) {
                continue;
            } else {
                cout << "here" << endl;
                vans = max(vans, vBars[i] + 1 - prev);
                prev = vBars[i + 1] - 1;
            }

            cout << "vans is " << vans << endl;
        }
        vans = max(vans, vBars[vBars.size()-1] + 1 - prev);

        // ab horizontal and vertical ke maxm ans nikal chuke, ab square kitne
        // side length ka banega ye decide karega ki horiz me kam space hai ki
        // vert me, since jo kam space dega uske jitna hi square bana sakte apan
        int minm = min(hans, vans);
        cout << hans << " " << vans << endl;
        return minm * minm;
    }
};