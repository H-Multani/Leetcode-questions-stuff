class Solution {
public:
    vector<int> partitionLabels(string s) {
        // okay toh essentially, ek partition me ek hi char aa sakta hai, sabse
        // pehle sare characters ka very first and very last idx likh do

        // ki har char sabse pehle and sabse last me konse idx par aata hai in s

        // phir apan s par iterate karenge,like shown
        // for eg 2 b={3,6},c={1,9},d={7,7},e={0,8}
        // ab agar s par iterate kare apan toh
        // at i=0 we have e, e ka last idx is 8, toh current partition idx 8 tk
        // jayega, ab apan j=1 se 8 tak chalaenge, agar beech me koi aur char
        // mila jiska jiska last idx>8 hai toh ye wala partition expand hoga aur
        // j=1, c hai, c ka ending idx is 9, toh ye partition 8 par nai 9 par
        // khatam hoga, so that each char appears in only 1 part
        // j=2, me c hai, last char at idx 9, current ending is idx 9
        // j=3, me b hai, last char at idx 6, current ending is idx 9
        // j=4, me b hai, last char at idx 6, current ending is idx 9
        // j=5, me b hai, last char at idx 6, current ending is idx 9
        // j=6, me b hai, last char at idx 6, current ending is idx 9
        // j=7, me d hai, last char at idx 7, current ending is idx 9
        // j=8, me e hai, last char at idx 8, current ending is idx 9
        // j=9, me c hai, last char at idx 9, current ending is idx 9
        // toh ye wala partition me 9-0+1=10 char honge, ans me daal kar aage
        // badhenge starting frm i=10 now, repeat same process

        vector<pair<int, int>> idx(26, {INT_MAX, -1});

        for (int i = 0; i < s.size(); i++) {
            // current char ka first and last idx update karo
            int charidx = s[i] - 'a';
            idx[charidx].first = min(i, idx[charidx].first);
            idx[charidx].second = max(i, idx[charidx].second);
        }

        vector<int> ans;

        int n = s.size(), i = 0;
        // to keep track of where the new partition is starting frm
        int currstart = 0;

        // current partition ka end, for starting this will be s ke 1st char ka
        // ending
        int currend = idx[s[0] - 'a'].second;
        while (i < n) {
            // agar i currend par pahuch gaya hai means current wala partition
            // ban chuka hai
            if (i == currend) {
                // we here means current wala partition ban chuka hai, ab iss
                // partition ke size ko ans me dalo
                ans.push_back(currend - currstart + 1);

                // ab next partition ke liye start currstart frm i+1, and
                // currend frm i+1 th char ka end
                currstart = i + 1;
                // agar i+1 par char hai toh currend uss char ke last idx par
                // daal do
                if (i + 1 < n)
                    currend = idx[s[i + 1] - 'a'].second;
                else {
                    // we here means koi char nai hai aage break frm loop
                    break;
                }

                // start frm i+1 th char now
                i++;
                continue;
            }

            // we here means current partition abhi ban raha hai, toh agar
            // current char ke last idx se currend agar aage badhega toh badha
            // do, this is so that, current character(jo abhi wale partition me
            // hai) uska last instance bhi current partition me hi aa jaaye, so
            // that overall partition is valid
            currend=max(currend,idx[s[i]-'a'].second);

            // now move to the next char in current partition
            i++;
        }

        return ans;
    }
};