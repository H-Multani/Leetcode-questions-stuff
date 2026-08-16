class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // since score se kaam nai hai and mod 3 karre se kaam hai toh means
        // scores are useless and remainders are useful

        // remainder 0,1,2 wale ka counts lelo
        int c0 = 0;
        int c2 = 0;
        int c1 = 0;

        for (auto it : stones) {
            if (it % 3 == 0)
                c0++;
            if (it % 3 == 1)
                c1++;
            if (it % 3 == 2)
                c2++;
        }

        // ab yaha questn says ki agar kabhi bhi sum %3==0 hua toh banda looses
        // and if bob survives till end(no stones remaining), then he wins

        // toh clearly slice koi bhi 0 remainder dene wala stone nai legi
        // otherwise haar jayegi

        // toh alice has 2 choices, take remainder 1 wala stone, or take
        // remainder 2 wala stone

        // ye 2 choice ke hisab se ans banaenge apan

        // also iske alava remainder 0 wale stones will just be used to pass
        // chance, since sppose sum%3=1 chalra abhi and alice ka turn, toh alice
        // can take remainder 0 wala here, so new sum%3=1 hi abhi bhi for bob,
        // and bob can do the same thing, this goes over and over till 0s end,

        // yaha 2 cases banenge, 0s even the ya odd the

        // if 0s even the, then saare 0s khatam hone ke baad koi position me
        // change nai milega, if c0=6, and A ka turn, then
        //  A take 0,B take 0, A take 0,B take 0, A take 0,B take 0,
        // ab vapas A ka turn, toh kuch change nai hua state me

        // if 0s odd the, then saare 0s khatam hone ke baad position me
        // change milega, if c0=5, and A ka turn, then
        //  A take 0,B take 0, A take 0,B take 0, A take 0
        // ab vapas B ka turn, toh kuch change hua state me

        // yehi case ke hisab se bifurcation karo pehle toh

        if (c0 % 2 == 0) {
            // ab yaha 2 cases padenge for alice(a) and bob(b)

            // alice takes remainder 1 wala
            // a takes 1, b can take 1 only since if b takes remainder 2 wala
            // then overall sum=(+1+2)->(+3)%3==0, means b loose,
            // toh a takes 1,b takes 1
            // now overall sum=(+2)%3, toh a can take only 2 remainder
            // wala banda since if a takes remainder 1, then sum->(+2+1)%3==0,
            // means a looses, toh
            // toh a takes 1,b takes 1, a takes 2,
            // ab same logic as above continues
            // toh a takes 1,b takes 1, a takes 2,b takes 1, a takes 2,b takes
            // 1, a takes 2,b takes 1, a takes 2,b takes 1, a takes 2,b takes
            // 1,....

            // notice how a takes 1 start me, uske baad a always takes 2, and b
            // hamesha takes 1 frm start

            // means iss pattern me agar kabhi bhi 1's khatam ho gaye, then b
            // will loose, and since 0s even hai toh lene ke baad bhi b still
            // looses since itll go like
            // a takes 1, b take 1, a take 2, b take 1, a take 2, b take 0,
            // ab a will also take 0, since agar 2 le liye yaha toh b ab 2s le
            // payega, vo karna hi nai, and even no of 0s ke baad vapas b ka
            // turn hoga,and since b has no 1's , b looses

            // toh iss case me if c2>=c1, then alice wins

            // iska alternate case is when
            // alice takes remainder 2 wala in start

            // pura upar wala case reverse hoga, jaha 2 ka cnt matter karta tha,
            // waha ab 1 ka count matter karega

            // so, overall
            // toh iss case me if c1>=c2, then alice wins

            // yaha edge case ye ki eg2 me dekho,a takes 2, lekin since stone
            // end, hence a lost, toh is case ke liye remainder 1 wale bande bhi
            // hone chahiye, so that a doesnt lose due to elements not being
            // present

            // ie c1>=1
            // same case ko reverse kar sakte ie stones = [1]
            // iss case me c2>=1 hona chahiye

            // toh overall, c1>=1 and c2>=1

            // and iske upar
            // if c2>=c1, alice win
            // if c1>=c2, alice win
            // jo bhi case hoga alice accordingly khel legi and jet jayegi

            // agar ye cases nai hue toh alice loose
            // hence
            return (c1 >= 1 && c2 >= 1) && (c2 >= c1 || c1 >= c2);
            // (c1>=1 && c2>=1), ye upar samjha diya
            // c2>=c1, for case 1, when a takes remainder 1 wala
            // c1>=c2, for case 2, when a takes remainder 2 wala
        }

        // we here means odd wala case hai

        // ab odd wale case me state switch ho jayega, which can give an
        // advantage to person in stitch, ye upar samjhaya hai ki odd me kaise
        // state switch hoga

        // toh apan ek hi 0 remainder wala count karte chalenge, since logically
        // socho, aage patterns honge jab a only takes 1s and b only takes 2s

        // iss case me suppose 1s end, toh a takes 0, then b ko jhak maar kar 1
        // lena padega, and since available nai hai 1s toh b ko bhi 0 wala lena
        // padega, toh ye dono fir 0s lete jayenge transfer karte jayenge

        // aise me if 0s were even, the end me vapas a phas gaya, vo case upar
        // handle kiye

        // yaha 0s are odd, means end me b phasega, since ab b ko chahiye 1, and
        // vo khatam hai, hence

        // yaha apan 0s ke full count use nai karenge sirf 1 count use karenge
        // to signify ki order change hui hai

        // yaha ab fir se alice ke paas 2 cases

        // case 1
        // alice takes 1 in start
        // a takes 1, b takes 1, a takes 2, b takes 1, a takes 2,....

        // yaha kaam aayega ki a always takes 2 after taking one 1 wala

        // suppose c1=4, c2=1
        // a takes 1, c1=3, c2=1
        // b takes 1, c1=2, c2=1
        // a takes 2, c1=2, c2=0
        // b takes 1, c1=1, c2=0
        // ab a needs 2 or 0 to be still valid, 2 nai hai, toh a can only take 0
        // remainder wala,a takes that
        // b now needs 2, jo ki nai hai, toh b takes 1
        // remainder becomes 0, bob loose

        // toh if c1=4 and c2=1 then a wins
        // now agar we increase c1 more, then a still wins
        // toh if c1=5,6,7,... and c2=1 then a wins
        // means c1>c2, a wins

        // toh lets see similar case now
        // suppose c1=4, c2=2, still c1>c2
        // a takes 1, c1=3, c2=2
        // b takes 1, c1=2, c2=2
        // a takes 2, c1=2, c2=1
        // b takes 1, c1=1, c2=2
        // a takes 2, c1=1, c2=0
        // b takes 1, c1=0, c2=0
        // ab a needs 2 or 0 to be valid, 2 hai nai, toh a can only take 0
        // remainder wala, a takes that
        // ab dekho sum is still valid(%3!=0), lekin saare elements khatam ho
        // gaye, notice how c1=0,c2=0,c0=0, toh aise case me toh hamesha bob hi
        // jeetna tha na(since quesnt bola ki element khatam toh bob win)
        // means c1=4,c2=2 me a loose

        // toh overall c1=4,5,6...,c2=1 me a wins
        // and c1=4,c2=2, me a looses
        // toh overall if c1-c2>=3, then a wins overall, otherwise b wins


        // ab iska just opposite case
        // case 2
        // alice takes 2 in start

        // iss case me pura ulta hoga, means here
        // overall if c2-c1>=3, then a wins overall, otherwise b wins

        // toh ye 2 cases hai for a to win
        // c1-c2>=3, a takes 1 in start
        // c2-c1>=3, a takes 2 in start

        // dono merge kar denge
        // abs(c2-c1)>=3, then a wins, iske alava kuch bhi hua toh b wins
        return abs(c1-c2)>=3;
    }
};