class Solution {
public:
    void solve(int i, string& s, unordered_set<string>& st, int currcnt,
               int& maxcnt) {

        // optional set pruning, halka sa optimization
        // bina iske bhi accept hoga code no worries
        if(currcnt+(s.size()-i)<=maxcnt){
            // means aage badhne par better ans nai milega, return frm here
            return;
        }



        if (i >= s.size()) {
            maxcnt = max(maxcnt, currcnt);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);
            if (st.find(sub) == st.end()) {
                // unique substring mila hai, update krdo
                // DO
                st.insert(sub);
                // EXPLORE
                //  j index tk string le liya hai, explore frm j+1, th index,
                //  also send currcnt+1, since apan ko ek new substring
                //  mila hai just abhi upar, toh counting that is why currcnt+1
                solve(j + 1, s, st, currcnt + 1, maxcnt);
                // UNDO
                // ie curr wala substring set se hata do, since explore kar
                // chuke hai ye path, toh jitna kachra push kiya tha remove
                // krdo, nai toh error aayenge, since we sent set as passby
                // reference, toh copies nai bani h set ki, and agar bani hoti
                // toh memory error phek deta
                // just remove the substring frm the set
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxcnt = 0, currcnt = 0;

        solve(0, s, st, currcnt, maxcnt);

        return maxcnt;
    }
};