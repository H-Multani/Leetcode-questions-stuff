class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        // columns ke hisab se dekh lo

        // agar first column sorted order me hai means strs bhi sorted order me
        // hai, no need to check further and no need to remove anything since if
        // strs is like "apple","grape","melon", toh dekho first column is
        // sorted , toh strs is also in sorted order already dekha jaaye toh
        // since a<g column me, and apple<grape lexicographically too toh it
        // makes sense, toh

        // NOTE-> instead of comparing whole strings we can just compare the
        // first characters since, agar order me raha toh first character
        // order me rahega tabhi toh aage ka string ordeer me rahega

        // if array was like {"qstad","hwfee","asdfr"}, ab first column isnt
        // sorted since q>h and therefore qstad>hwfee lexicographically as well,
        // toh agar final array ko lexicographic order me banana hai toh ye
        // first column alag karna hi padega so we are left with
        // {"stad","wfee","sdfr"}, same checking again this time we have w>s
        // which is wrong ans similarly wfee>sdfr which is also wrong isko bhi
        // alag karna padega column ko aage badho, similarly next column me t>f
        // aayega which will be wrong and hence removed now we are left with
        // {"ad","ee","ff"}, now the first column is in lexicographical order
        // and hence the strings are also in order toh yaha ke baad sab set hai
        // no need to check forward and remove columns since aage wale columns
        // remove karne ka no need since abhi hi order me aa gaya hai why check
        // forward , jitne columns remove kiya alag rehen do send ans

        // toh instead of updating all strings each time and checking first
        // column  we can just iterate on the columns, and jaha dikhe ki order
        // me hai sab kuch waha stop kar denge since yaha par bani strings sab
        // order me then why remove additional columns useless, nai hai toh aage
        // check krte chalenge

        // ek edge case ye banega ki agar column me check karte time same aaya
        // toh apan next column me check karenge to confirm if its actually in
        // lexicographical order otherwise continue, keep in mind jaha dikkat aa
        // rahi hai wahi check karna bass no need to recheck pehle wale bande
        // since vo toh already in position hai bass jisko check karna hai vahi
        // check karo

        // also apan order me check kar rahe hai since agar original string hi
        // order me hai toh why even remove nay columns, jaha par dikkat aa rahi
        // hai wahi se karo na remove columns ko

        int ans = 0;

        int n = strs.size();
        int m = strs[0].size();

        // array lelo which will store ki konse indexes me i and i-1 ko check
        // karna hai incase strs[i-1][col]==strs[i][col]
        set<int> idx;
        // check karte time agar same value aa gai of strs[i][col] and
        // strs[i-1][col] toh we need to check next row since ho sakta order
        // me ho ya na ho still
        bool chknextcol = false;

        // iterate over all columns
        for (int col = 0; col < m; col++) {
            // check current column
            // cout << "at col " << col << endl;

            // agar check karte time in order nahi mile toh remove karna hai
            // column ko boolean lelo which will store if we need to remove
            // column
            bool removecol = false;

            // pehle ye dekho ki kahi pehle ke koi bande ka checking karna toh
            // baaki nahi??
            // agar baaki hai toh pehle ye check karo

            if (idx.size() > 0) {

                // means pehle wale check karo on the idx reqd

                set<int> temp = idx;
                chknextcol = false;
                vector<int> remove;
                for (auto i : temp) {
                    // cout << "checking idx " << i << endl;
                    if (strs[i - 1][col] > strs[i][col]) {
                        // means iss column ko alag karna padega
                        removecol = true;
                        break;
                    } else if (strs[i - 1][col] == strs[i][col]) {
                        // means iss idx ke liye aur aage check karna padega
                        // rehen do isko set me aage check karenge
                        chknextcol = true;
                    } else {
                        // we here means sab order me hai iss idx ke liye remove
                        // frm set

                        // abhi alag mat karo since possible hai ki ye column hi
                        // remove na karna pade idx.erase(i);
                        remove.push_back(i);
                    }
                }

                if (removecol) {
                    ans++;
                    // move to next column
                    continue;
                }

                if (chknextcol) {
                    // we here means abhi bache hue hai bande checking ke liye
                    // aage wala column check karo

                    // isse pehle jitne bando me dikkat resolve ho gai hai unko
                    // toh remove kardo like pehel idx 3 and 7 me prblem thi
                    // agar, and abhi bass 7 me problem hai toh 3 kaa toh order
                    // set hai ma toh 3 ko set se remove kardo since uska toh
                    // set hai na plus this idx doesnt need to be checked
                    // further since ye currently in order hai and only idx 7
                    // need to be checked toh set se remove karo fir check again
                    for (auto it2 : remove) {
                        idx.erase(it2);
                    }
                    continue;
                }

                // otherwise we here means sab order me hai aage check karne ke
                // baad bhi toh why remove more columns return frm her
                return ans;
            }

            chknextcol = false;

            vector<int> remove;

            for (int i = 1; i < n; i++) {
                if (strs[i - 1][col] < strs[i][col]) {
                    // means order me hai aage badhao
                } else if (strs[i - 1][col] == strs[i][col]) {
                    // means same value mila hai to confirm correct order we
                    // need to check next column as well
                    chknextcol = true;

                    // vector me daal do ki i and i-1 th wale bande ko check
                    // karna hai

                    // yaha bhi similar abhi add mat karo since possible hai ki seedha seedha column ko hi uda de
                    // idx.insert(i);
                    remove.push_back(i);
                } else {
                    // we here means strs[i-1][col]>strs[i][col] means ye column
                    // order me nahi hai isko alag karna padega to make strs
                    // array in correct order
                    removecol = true;
                }
            }

            if (!removecol && !chknextcol) {
                // means we do not need to remove current column

                // and

                // we also dont have a case where characters are same toh
                // confirm karne ke liye aage wale cols me bhi check nai karna
                // padega

                // toh yaha par dekhe toh yaha par jitni strings banegi sab in
                // order rahengi then why remove more columns send ans frm here
                // only

                return ans;
            }

            // we here means ya toh column remove karna hai ya toh aage wala
            // column check karna padega confirm karne ke liye

            if (removecol) {
                // means column hi remove karna padega, ans me add kardo aur
                // aage badhao
                ans++;

                // also ye w
                continue;
            }

            // we here means column bhi remove nai karna hai, ie we just have to
            // check next column for correct order, aage badhao to the next
            // column

            // jin bando ko check karvana tha unko bhar do set me
            for(auto it2:remove) idx.insert(it2);
        }

        return ans;
    }
};