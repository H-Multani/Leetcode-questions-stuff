class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // brute force
        int n = times.size();
        int reqd_arrival_time = times[targetFriend][0];

        // sort the ppl based on arrival time, so that jo pehle arrive hora hai,
        // usko pehle chair milegi, like its given in the questn too
        sort(times.begin(),times.end());

        vector<int> chairs(n, -1);
        // set up only n chairs since at worst case scenario, har n bando ko
        // separate chairs mili, in such case we have used n chairs only

        for (auto it : times) {
            int curr_arrival = it[0];
            int curr_depart = it[1];

            // iterate over the chairs array, to find empty chairs to seat
            // current banda in
            for (int i = 0; i < n; i++) {
                if (chairs[i] <= curr_arrival) {
                    // means current chair pr baith sakta hai current banda,
                    // baitha do
                    // and set the value to ki ab ye banda yaha se kab depart
                    // karega
                    chairs[i] = curr_depart;
                    // if current banda was the reqd banda, return the chair
                    // jisme usko bethaya hai
                    if (curr_arrival == reqd_arrival_time)
                        return i;
                    // now we have seated current banda in a chair, hence no
                    // need to check for open chairs anymore, hence break frm
                    // loop
                    break;
                }
            }
        }

        // yaha tak pahuchenge hi nai we do this so that error na aaye
        return -1;
    }
};