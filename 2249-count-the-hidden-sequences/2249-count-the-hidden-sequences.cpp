class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // initial banda 0 maan kar pehle nikalo already kya values aani hai,
        // minm and maxm,phir uss hisaab se apan calculate karenge accd to how
        // many minm is >=lower and how many maxm<=upper

        // initial banda kuch bhi maan lo (0 ya aur koi value), end me minm and
        // maxm ka difference same hi aana hai har baar, toh apan ez rakhne ke
        // liye first banda 0 le rahe hai

        // agar maan lo minm and maxm ka diff is 4 (minm=4 and maxm=8), and
        // lower and upper ka diff is 5 (lower=5 upper=10), toh apan iss range
        // me apne sequences bana sakte hai

        // iss range(5 to 10) me apan 2 sequences rakh payenge, which will be 5
        // to 9(minm=5, maxm=9, diff=4 maintined) and 6 to 10(minm=6, maxm=10,
        // diff=4 maintained)

        // ye minm and maxm apan set karke baaki wala sequence bana sakte hai ,
        // lekin apan ko bas count karne bola hai, toh bas count karo

        // given range was 5 to 10(5 size ki) and apan ki range banri thi 4 to
        // 8(4 size ki), toh ab kitne tareeko se apan 5 size ke dabbe me 4 size
        // ke dabbe ko rakh sakte hai???

        // ye 5 size ka dabba means sequence banane ke baad maxm and minm
        // iss upper and lower ke range me rahe asia banana hai apan ko

        // for above eg it basically means 5 size ka dabba hai(lower=5,
        // upper=10), toh apan kitne sequences bana sakte hai such that saari
        // values iss range me rahe, ab agar minm and maxm range me rahega tb hi
        // toh beech ke range me rahenge, thats why apan bas minm and maxm leke
        // chal rahe

        // toh basically ab ye [minm,maxm] ka range ho gaya hai, iss range ko
        // apan ko [lower,upper] ke range me rakhna hai, and count karna hai
        // kitne possible pairs of [minm,maxm] can be put inside this
        // [lower,upper] range,

        // its the diff bw the sizes +1, toh 5 ke area me 4 ke dabbe ko rakhne
        // ke 2 ways(mentioned above), yehi krna hai bas
        // btw ye formula nai hai koi, ye bas trial and error se socha maine 2-3
        // egs par toh common pattern dikh gaya lol

        // initial banda 0 leke array banao using prefix sum, infact array
        // banane ka need hi nai, direct ek ek element nikalte jao and maxm and
        // minm update karte jao
        long long maxm = 0, minm = 0;
        long long curr = 0;

        for (auto it : differences) {
            curr += it;

            // ye curr apna new element hai, maxm and minm update karo
            maxm = max(maxm, curr);
            minm = min(minm, curr);
        }

        // ab maxm and minm ka diff nikalo
        int diff = maxm - minm;

        // agar ye diff se chhota range hai [lower,upper] ka toh return 0 since
        // no possible sequence can be made
        if (diff > upper - lower)
            return 0;

        int range = upper - lower;

        // ab apna possible sequences ka cnt will be diff bw the ranges of
        // [lower,upper] and [minm,maxm] +1

        return range - diff + 1;
    }
};