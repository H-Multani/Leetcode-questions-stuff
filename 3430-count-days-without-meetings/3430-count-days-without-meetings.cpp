class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // prefix sum wala MLE dera tha, toh lets try sorting wala part hi

        // taking lil help frm hints

        // combined meetings wala ek vector bana lo, jitni meetings overlap krri
        // hai, saari merge kardo ek me hi, so that seedha seedha ranges aye
        // apne pass, ki hnn inn ranges me meetings hai

        // first step is sorting the meetings, so that aas pass waali saari
        // meetings ek saath rahe
        sort(meetings.begin(), meetings.end());

        // phir inn ranges me iterate karke cnt bana lenge, lets try it

        vector<vector<int>> combined;

        // currstart and currend lelo as first meeting ka start and end

        int currstart = meetings[0][0];
        int currend = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            // agar new(i th) meeting ka start currend se bada hai means yaha
            // beech me area rahega with 0 meetings scheduled, in such case
            // [currstart,currend], ye wala combined meeting area combined array
            // me daal do, and ab 0 meeting wale area se aage jaa kar new
            // currstart will become current meeting ka start, and new currend
            // will become current meeting ka end
            if (meetings[i][0] > currend) {
                // current combined meeting daal do array me
                combined.push_back({currstart, currend});

                // ab new aage wali combined meeting ke liye starting will be
                // current meet ka start
                currstart = meetings[i][0];
                // also new meeting ka end will current meeting ka end
                currend = meetings[i][1];
            } else {
                // we here means ye wali meeting bhi overlap hogi kisi aur
                // peeche wali meet ke saath, toh currend aage badha do, since
                // combined meet me saari consider honge
                currend = max(currend, meetings[i][1]);

                // possible hai pehla meeting was [1,10], second was frm [3,7],
                // toh at first currend was 10, new meeting include karne ke
                // baad currend will still be 10, since 2nd meeting pehle khatam
                // hori hai, toh uss case ko consider karna padega, uske liye hi
                // maxm lere, ki iss maxm value tak meetings scheduled hai
            }
        }

        // now currstart and currend wala combined meet ek last baar add kardo
        // combined array me
        combined.push_back({currstart, currend});

        // ab apne paas combined meets hai, eg 2 ke hisaab se like
        // sorted meetings={[1,3],[2,4]}
        // combined meetings={[1,4]}, ie 1 se 4 tak meetings hai, isme
        // overlapping meetings bhi counted aur simgle wali bhi counted

        // ab iss par iterate karke count banate jao
        int cnt = 0;
        // day 1 se first meeting start tak kitne free days the count karliye
        cnt += combined[0][0] - 1;
        for (auto i = 1; i < combined.size(); i++) {
            // ab i-1 wale ka end se leke i wale ke start tak free days hai,
            // count karlo
            cnt += combined[i][0] - combined[i - 1][1] - 1;
        }

        // for(auto it:combined){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }

        // last meeting se end of days tak kitne free days hai count karlo
        cnt += days - combined[combined.size() - 1][1];

        return cnt;
    }
};