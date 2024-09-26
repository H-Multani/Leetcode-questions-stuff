class MyCalendar {
    // unordered_map<int,int>
    vector<pair<int, int>> events;

public:
    MyCalendar() {
        // events = new vector<pair<int, int>>;
        events.clear();
        // events stores all the event times

        // this whole storing in a vector thing works simply bcoz the cnstraints
        // say that at most 1000 elements will be stored in vector, if it was
        // like 10^5 or smth, this approach wouldnt have worked, in that case,
        // kuch aur soln dhundo
    }

    bool book(int start, int end) {
        // curr event is start to end

        // iterate over all values in events to check if any 2 events collide
        for (auto it : events) {
            // curr event is
            int curr_start = it.first;
            int curr_end = it.second;

            // check if the reqd element and current elements collide
            if (start < curr_end && curr_start < end) {
                // take already booked value as s to e(s is start and e is end)
                // and we are trying to insert a new booking a to b(a start and
                // b end)
                // now theres 2 conditions for collisions to not happen those
                // are 1st-> b<s, ie the booking we are trying to insert is
                // before the current booking eg s=10,e=20(ie booked frm 10 to
                // 20) and a=5, b=7, in this case we are trying to book frm 5 to
                // 7 which can be done(since currently only 10-20 is booked,
                // rest values are free, so booking can be done)

                // 2nd-> e<a, ie the booking we are trying to insert is
                // after the current booking eg s=10,e=20(ie booked frm 10 to
                // 20) and a=25, b=27, in this case we are trying to book frm 25
                // to 27 which can be done(since currently only 10-20 is booked,
                // rest values are free, so booking can be done)

                // then theres 4 ways that booking cant be done
                // let 'se' be the already booked slot and 'ab' be the new slot

                // 1st->ab collides with se half part(front half of se),can be
                // checked by s<b

                // 2nd->ab collides with se half part(second half of se),can be
                // checked by a<e

                // 3rd->ab collides with se fully(ab
                // is fully inside se),can be checked by s<b && a<e

                // 4th->ab collides with se fully(ab is fully outside se),can be
                // checked by s<b && a<e

                // all these 3 break conditions can be checked by a simple check
                // s<b && a<e, thats exactly whats written in the if stmt

                // we here means booking cant be done
                // dont add the booking and return false;
                return false;
            }
        }

        // we here means booking can be done, add the booking to vector and
        // return true
        events.push_back({start, end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */