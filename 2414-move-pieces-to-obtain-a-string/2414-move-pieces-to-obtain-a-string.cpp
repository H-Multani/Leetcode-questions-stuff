class Solution {
public:
    bool canChange(string start, string target) {
        string s1 = "";
        string s2 = "";
        for (auto it : start) {
            if (it != '_')
                s1 += it;
        }
        for (auto it : target) {
            if (it != '_')
                s2 += it;
        }

        if (s1 != s2)
            return false;
        // we here means saare characters sahi order me hai atleast

        // bhale sahi posn me naa ho,
        // isse corner cases handle ho jaenge like eg2 wala case and
        // eg case where start="_L" & target="LL", iss case me false aayega ans
        // iss case me bhi return false, handled above

        // ab bas posn ka check karna hai karlo chk

        int n = start.size();
        int i = 0;
        // i iterates on start
        int j = 0;
        // j iterates on target
        // j ko sabse pehle wale non _ character par le jao

        while (j < n && target[j] == '_')
            j++;

        for (i = 0; i < n; i++) {
            if (start[i] == '_')
                continue;

            // we here means yaha i th wala
            // ab upar wala false me nai aaye apan means current i par jo char
            // hai and curr j par jo char hai dono same hai toh chk krne ka need
            // nai

            if (start[i] == 'R') {
                // means current wala bas right jaa sakta hai
                // agar iska target me posn(j) iss posn(i) se left me hai means
                // the target cannot be made, like i=4 and j=2, means ye wala
                // 'R' ka target position idx 2 par hai and ye currently idx 4
                // par khada hai, toh ye wala 'R' apne correct posn par kabhi
                // nai pahuch payega, since R can only go to right side ie bade
                // wale index par jaa sakta hai bas, ie R can go to idx 5,6,...
                // lekin peche nai aa payega,

                // and this R had to get to idx 2, which is impossible in such
                // case return false since start se target nai bana payenge apan
                if (j < i) {
                    // means i wala char ka target posn left me hai lekin ye
                    // sirf rt jaa skta hai(since start[i]='R), hence it wont be
                    // able to reach target posn, ie target cant be made, hence
                    // in such case return false
                    return false;
                } else {
                    // we here means i<=j, ie either i th wala char already at
                    // correct posn(i==j) or i can be shifted to the right side
                    // to get to target posn(since j>i)
                    // and i th wala char can go right only here(since
                    // start[i]='R')
                    // hence current wala char can go to its correct target
                    // posn, in such case, move j to the target posn of next
                    // characetr
                    j++;
                    // j++ to move ahead of current character
                    while (j < n && target[j] == '_')
                        j++;
                    // this is to move j to the target posn of next character in
                    // line
                }
            } else {
                // same thing as above but for left

                // means current wala bas left jaa sakta hai
                // agar iska target me posn(j) iss posn(i) se right me hai means
                // the target cannot be made, like i=2 and j=4, means ye wala
                // 'L' ka target position idx 4 par hai and ye currently idx 2
                // par khada hai, toh ye wala 'L' apne correct posn par kabhi
                // nai pahuch payega, since L can only go to left side ie chhote
                // wale index par jaa sakta hai bas, ie L can go to idx 1,0
                // lekin aage nai jaa payega,(is indexes 3,4,5.. nai jaa payega)

                // and this L had to get to idx 4, which is impossible in such
                // case return false since start se target nai bana payenge apan
                if (i < j) {
                    // means i wala char ka target posn right me hai lekin ye
                    // sirf left jaa skta hai(since start[i]='L'), hence it wont
                    // be able to reach target posn, ie target cant be made,
                    // hence in such case return false
                    return false;
                } else {
                    // we here means i>=j, ie either i th wala char already at
                    // correct posn(i==j) or i can be shifted to the left side
                    // to get to target posn(since i>j)
                    // and i th wala char can go left only here(since
                    // start[i]='L')
                    // hence current wala char can go to its correct target
                    // posn, in such case, move j to the target posn of next
                    // characetr
                    j++;
                    // j++ to move ahead of current character
                    while (j < n && target[j] == '_')
                        j++;
                    // this is to move j to the target posn of next character in
                    // line
                }
            }
        }

        // ab agar kahi nai banna tha start se target toh upar se hi false
        // return ho jata, we here means target can be made, in such case return
        // true

        return true;
    }
};