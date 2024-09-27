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
        // 3rd overlap hora?

        // ie chk if current booking se koi 3rd overlap ho rha kya. do this by
        // checking for overlap in overlaps array
        for (auto it : overlaps) {
            // each region in this array has 2 overlaps already

            // chk if a 3rd overlap is happening
            if (max(start, it.first) < min(end, it.second)) {
                // triple overlap found, return false frm here direct
                return false;
            }
        }

        // we here means triple overlap toh nai de rha current wala event
        // chk the rest of the events now for any double overlaps
        for (auto it : events) {
            int currstart = it.first;
            int currend = it.second;

            // start < curr_end && curr_start < end
            // a better way to check the above condn, same condition, diff way
            if (max(start, currstart) < min(end, currend)) {
                // means overlap ho rha hai, double overlap

                // the region of overlap is bw max(strt1,strt2) and
                // min(end1,end2)
                // ie region [ max(s1,s2),min(e1,e2) )


                // in this region 2 events are overlapping(causing double
                // overlap), push the region to overlaps array

                //  no need to check for triple overlap here, since curr region
                //  (start,end) tk ke liye already chk kar liye hai, if triple
                //  overlaps ho rha ki nai, no need to chk again
                pair<int, int> currregion;
                currregion.first = max(start, currstart);
                currregion.second = min(end, currend);
                // directly push the 2 overlap region to overlaps array
                overlaps.push_back(currregion);

                // dont return false here, since 2 overlaps chalta hai, so this
                // event(if it exits this loop) will be added even if it causes
                // 2 overlaps
            }
        }

        // we here means current region doesnt overlap with anyone or is only
        // causing 2 overlaps total, push the region to events vector and return
        // true(since 2 overlaps are valid accd to questn)
        events.push_back({start, end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */