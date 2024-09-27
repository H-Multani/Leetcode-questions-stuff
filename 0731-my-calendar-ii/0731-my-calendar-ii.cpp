class MyCalendarTwo {
    // stores events
    vector<pair<int, int>> events;
    // stores regions where 2 overlaps are taking place
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {
        // code of my calender 1 with some changes
        events.clear();
        overlaps.clear();
    }

    bool book(int start, int end) {
        // first chk kya current wale se already koi 2 overlap wale area me
        // overlap hora?
        for(auto it:overlaps){
            if(max(start,it.first)<min(end,it.second)){
                // triple overlap found, return false
                return false;
            }
        }

        for (auto it : events) {
            int currstart = it.first;
            int currend = it.second;

            // a better way to check the below condn, same condition, diff way
            // start < curr_end && curr_start < end
            if (max(start, currstart) < min(end, currend)) {
                // means overlap ho rha hai

                // the region of overlap is bw max(strt1,strt2) and
                // min(end1,end2)
                // ie region [ max(s1,s2),min(e1,e2) )
                // in this region 2 events are overlapping, push the region to
                // overlaps

                // before pushing the current region to overlaps, check if the
                // region is already overlapping with some other region in the
                // overlaps array, since if it does, that will mean that the
                // current region already overlaps with some region jaha 2
                // events hai pehle se, toh in that case return false straight
                // away
                pair<int, int> currregion;
                currregion.first = max(start, currstart);
                currregion.second = min(end, currend);

                // chk if curent region is already overlapping with some region
                for (auto it2 : overlaps) {
                    if (max(currregion.first, it2.first) <
                        min(currregion.second, it2.second)) {
                        // means triple overlap occuring here
                        // means this event cant be placed, return false
                        return false;
                    }
                }
                // we here
                // means no triple overlaps found, push the current 2 overlap
                // region to overlaps array(since in this region, 2 events
                // overlap)
                overlaps.push_back(currregion);
            }
        }

        // we here means currnt region doesnt overlap with anyone, push the
        // region to events vector and return true
        events.push_back({start, end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */