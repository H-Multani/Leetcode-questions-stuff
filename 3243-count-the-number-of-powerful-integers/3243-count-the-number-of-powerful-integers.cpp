class Solution {
public:
    long long solve(string& str, string& ipsuffix, int limit) {
        // agar suffix ka length string ke length se chhota hai toh bana nai
        // sakte kuch bhi return 0
        if (str.size() < ipsuffix.size())
            return 0;

        long long ans = 0;

        // suffix ki location par already kya string pada hai vo nikalo(edge
        // case ke liye)
        string trailstr = str.substr(str.size() - ipsuffix.size());

        // remaining apan kitne positions par pasand ke char rakh sakte hai??
        int len = str.size() - ipsuffix.size();

        // ab har posn par iterate karke add karte jayenge kitne values yaha
        // daal kar powerful no banega
        for (int i = 0; i < len; i++) {
            // current i th posn of string me konse konse digits dal sakte hai

            // kitne digits le sakte hai cnt
            int dgt = str[i] - '0';
            // itne digits apan daal sakte hai current posn par,

            // agar maan lo dgt=5, means we can use 0,1,2,3,4 in this posn

            // lekin agar ye<limit hua toh
            if (dgt <= limit) {
                // we here means limit>=5, in such case pan current location par
                // 0,1,2,3,4 rakh sakte hai, aur phir current par 5 rakhne ke
                // liye aage kitne rakh payenge xplore karna padega, like if
                // string like ="_ _ _ 1", and str is "5 1 0 0" and agar current
                // posn par 5 rakh diya toh string becomes "5 _ _ 1", beech me
                // sirf limited values rakh payenge uske liye aage waale posn
                // par jaana padega

                // phir bhi yaha dgt jitne values toh rakh sakte hai without
                // taking tension for aage wale spaces, like if str is "5000"
                // and agar apan i=0 me 0,1,2,3,4 rakh rhe hai toh aage wale
                // posns par kuch bhi rakhenge tb bhi overall value <str hi
                // aayega

                // and in each posn we can put limit+1(=d let) digits, toh
                // Permutation and Combination ke hisaab se ttl possible values
                // is dgt*(d*d*d..(for each expty space aage waali))

                // vahi karo

                // essentially apan count karre hai abhi the values which start
                // frm 0,1,2,3,4
                ans += dgt * pow(limit + 1, len - i - 1);

                // ab cnt krne ke baad current location par 5 rakh kar aage
                // jitne banenge vo count karenge next iteration me

                // essentially yaha bas 0,1,2,3,4 wale cases count kiye h, 5
                // wala aage iterations me cnt hoga
            } else {
                // we here means current par digit>limit hai, toh yaha par jitne
                // possible digits hai saare ek baar me count kar sakte hai,
                // like if str is "7000" and limit is 5, toh har place par
                // 0,1,2,3,4,5 sab rakh sakte hai wo tension, toh uper wale case
                // ke opposite yaha ek baar me sab count kar lenge, aage jaane
                // ka need hi nai

                // ek baar me add kardo
                ans += pow(limit + 1, len - i);
                // cnt kar liye hai toh loop aage badhane ka need nai, infact
                // aagr kuch karne ka need nai hai, yehi se return krdo, edge
                // case yaha par phasega hi nai
                return ans;
            }
        }

        // edge case, agar already present string is greater than the suffix
        // string, toh apan 1 string aur bana sakte hai which will be the last
        // one toh in such case ans++ hoga
        if (trailstr >= ipsuffix)
            ans++;
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        // solve funcn bana liya, which will return ki 0 se val tak kitne
        // powerful integers aayenge

        // phir same funcn 2 baar call kar diya once for start-1 and once for
        // finish, toh no of powerful integers bw start and finish will be no of
        // powerful integers frm 0 to finish - no of powerful integers frm 0 to
        // start-1

        string st = to_string(start - 1);
        string end = to_string(finish);

        return solve(end, s, limit) - solve(st, s, limit);
    }
};