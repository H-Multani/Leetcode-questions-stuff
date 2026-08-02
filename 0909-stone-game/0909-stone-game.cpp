class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // ok toh logic samajhna, alice can choose initially frm start or end,
        // and ye pata hai ki even no of elements honge, means idx 0 to n-1, and
        // n-1 will be odd(n is even so n-1 is odd)

        // also since sum of all elements is odd meaning kabhi bhi tie wala
        // scene nai aa sakta, chahe KOI bhi type se bifurcation karo

        // toh alice can choose idx 0(even wala) ya n-1(odd wala)

        // suppose we have 6 elements like
        // a b c d e f at indexes
        // 0 1 2 3 4 5

        // alice can choose idx 0(even), toh bob has 2 choices now  1 or 5 (both
        // odd choice), fir bob inme se koi bhi choose kare, alice can choose 4
        // or 2 (both even choice)

        // since if bob choose 1 alice can choose 2 simply
        // since if bob choose 5 alice can choose 4 simply

        // toh suppose bob chose 1 and then alice chose 2 (not 5)

        // now bob has option for idx 3 or 5
        // if bob take 3, alice take 4
        // if bob take 5, alice take 4

        // ye cases bigger arr par same chalenge

        // and iss pure ko alice reverse kar sakti by initially choosing odd
        // indexes, so that even wale bob hamesha le jaaye

        // toh overall alice has control over ki either she can take all even
        // index wale bande ya all odd index wale bande, and leave bob for the
        // rest

        // aise case me alice will always choose vo side jiska sum maxm aara
        // hamesha, if odd indexes walo ka sum bigger hai, alice choose karegi
        // odd wale lene ka frm start, so that bob ke paas sirf even index wala
        // choice bache

        // toh essentially bob ke paas koi choice nai hai except take whats
        // given(even idx wale), since alice sare odd wale pehle hi leke baith
        // jayegi

        // keep in mind alice can choose even wala too at any time(since bob 2
        // me se koi 1 odd wala lega, toh alice has option for even idx as well
        // as odd index now), lekin since she plays optimally, hence vo bob ko
        // chance hi nai degi odd wale side par aane ka, she will always take
        // the odd wala banda so bob has to take even wala banda(since he has no
        // choice as shown in example above)

        // for ex arr=[1,2,499,3], now alice knows ki even idx se sum maxm
        // aayega, toh even idx wala alice legi, so alice takes 1, bob has to
        // choose between 2 and 3 now,

        // bob choose 3, alice choose 499, she wins
        // bob choose 2, alice choose 499, she wins

        // toh since alice can control from start ki konse walo ka sum maxm
        // hoga, she will choose that path frm start(be it odd idx wala path ya
        // even idx wala path)

        // meaning alice hamesha jeetegi chahe array kuch bhi ho, hence

        return true;
    }
};