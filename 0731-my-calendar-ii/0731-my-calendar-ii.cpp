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
        for (auto it : overlaps) {
            if (max(start, it.first) < min(end, it.second)) {
                // triple overlap found, return false frm here direct
                return false;
            }
        }
        // chk the rest of the events now
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
                // overlap), push the region to overlaps

                //  no need to check for triple overlap, since curr region
                //  (start,end) tk ke liye already chk kar liye hai, if triple
                //  overlaps ho rha ki nai, no need to chk again
                pair<int,int> currregion;
                currregion.first=max(start,currstart);
                currregion.second=min(end,currend);
                // directly push the 2 overlap region to 
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