class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // very similar to lc 3169 ka AC wala soln, bss there we were merging 1
        // set of ranges here we merge 2 set of ranges(one for x axis and oter
        // for y axis)

        // sabse pehle toh ranges bana lo x and y ki separate, so that we see
        // similarity in ranges
        vector<vector<int>> x, y;

        for (auto it : rectangles) {
            // we got it={x1,y1,x2,y2}, ye coordinates hai diagonals ke ie
            // (x1,y1),(x2,y2) isse rectangle banega with corners
            // (x1,y1),(x1,y2),(x2,y1),(x2,y2)

            // now with these corners we get to know ki x axis me current
            // rectangle will cover the range x1 to x2, similarly in y axis we
            // will cover y1 to y2

            // toh yehi ranges thi jo apan ko chahiye thi, laga do
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }

        // ab jaise lc 3169 me krte the, similarly sort karo ranges ko so that
        // saari aas paas ki ranges ek saath aa jaaye
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        // ab combined range waale vectors banao
        vector<vector<int>> combinedx, combinedy;

        // ab ek loop chala kar x ke saare ranges merge karo, like we did in lc
        // 3169
        int currstart = x[0][0], currend = x[0][1];

        for (int i = 1; i < x.size(); i++) {
            // lc 3169 me sirf > le rahe the, yaha >= le rahe hai since 3
            // rectangles ke beech se nikalna hai line which could be at x=4
            // line or similar

            // agar current range ka start>=currend hai means ki iss
            // posn(currend waale x cood) se line nikali jaa sakti hai, ie
            // yaha par line banane ka jagah hai, toh ye ek separate range ho
            // gaya ab, toh separate range ki tarah count karlo
            if (x[i][0] >= currend) {
                // we here means yaha se line nikali jaa sakti hai

                // combined range till here is {currstart,currend}, ye range
                // push kardo combinedx wale vector me to indicate ki iss
                // currend tak jitni combined ranges aani thi aa chuki hai
                combinedx.push_back({currstart, currend});

                // new range ke liye i th range ka start will become new
                // currstart and i th range ka end will become new currend
                currstart = x[i][0];
                currend = x[i][1];
            } else {
                // we here means ki current(i th) range bhi kisi aur range se
                // overlap karri hai, ie rectangles overlap karre hai (like the
                // red and yellow rectangles in eg1)

                // toh uske liye currend update kardo
                currend = max(currend, x[i][1]);

                // max lene ka vahi reason hai ki biggest wala range rakhna hai
                // combined wala
            }
        }

        // ab x wala range {currstart,currend} ek baari final combined me daaldo
        combinedx.push_back({currstart, currend});

        // now do the exact same thing but for y axis

        currstart = y[0][0];
        currend = y[0][1];
        for (int i = 1; i < y.size(); i++) {
            if (y[i][0] >= currend) {
                combinedy.push_back({currstart, currend});
                currstart = y[i][0];
                currend = y[i][1];
            } else {
                currend = max(currend, y[i][1]);
            }
        }
        combinedy.push_back({currstart, currend});

        // ab apne pass combined ranges hai
        // notice that each range me atleast 1 rectangle lie karta hai, toh
        // basically we can easily draw lines bw these sections, if 4 ranges hai
        // we can draw 3 lines to split into 4 sections with >=1 ractangle in
        // each section which is needed

        // foe eg
        // toh combinedy in eg1 is like {(0,2),(2,4),(4,5)}, ie we have 3
        // ranges, jisme rectangles pure fitt aayenge, toh inn 3 ranges ke beech
        // se 2 cuts maar sakte hai to get ans in such case return true
        // lekin same cheez combinedx me dekho, combinedx is like {(0,5)}, ie
        // all rectangles are combined into same range,ab iske beech se apan 2
        // cuts nai maar sakte hai

        // so essentially , agar combined x/y ka ranges ka size>=3 hua toh apan
        // horizontal/vertical cuts maar sakte hai, in such case ans is true

        // kaise??, combinedy={(0,2),(2,4),(4,5)}, here 1st cut goes frm y=2,
        // and second cut goes frm y=4, toh 3 sections ban sakte hai

        // now if this was like {(0,2),(2,4),(4,7),(7,10)}, toh yaha 3 cuts maar
        // sakte hai, lekin apan kahi bhi 2 cuts maarenge toh bhi valid sections
        // rahengee, since each section me atleast 1 rectangle hoga, toh iss
        // case me bhi return true

        // but if this was like {(0,2),(2,4)}, toh yaha 1 cut maar
        // sakte hai, toh only 2 sections banenge, but we need 3 sections, toh
        // 2nd cut nai padne ke vajah se ans will be false

        // toh all in all agar combined me >=3 ranges hai, means we can cut them
        // into 3 sections, otherwise not

        // toh all in all agar combined x/y me se jisme bhi>=3 size rahega, usme
        // apan 2 cuts laga kar 3 sections me divide kar payenge hence making
        // soln possible, return true
        if (combinedx.size() >= 3 || combinedy.size() >= 3)
            return true;

        // else we cant make the cuts be it horizontally or vertically, in such
        // case return false
        return false;
    }
};