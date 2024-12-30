class Solution {
public:
    int lo, hi;
    int MOD = 1000000007;
    int solve(int currlen, int zero, int one, vector<int>& memo) {
        // base case
        // agar curr string ka length>high, kuch nai bana sakte ab iske aage,
        // rturn kardo
        if (currlen > hi)
            return 0;

        // agar curr length in between low and high, means this is a possible
        // intermediate answer, count incremenet karke aage check karo, since
        // aage aur answers ho sakte hai
        int currans = 0;
        if (currlen >= lo && currlen <= hi)
            currans++;

        // agar memo me ans hai toh yehi se bhej do
        if(memo[currlen]!=-1) return memo[currlen];

        // 2 options
        // zero add kardo curr string me, toh kitne answers milegne
        int addzero = solve(currlen + zero, zero, one, memo);
        // one add kardo curr string me, to kitne answers milenge
        int addone = solve(currlen + one, zero, one, memo);

        // return ans total jo milega, ie
        // agar curr string me 0's add karenge toh kitne ans milenge +
        // agar curr string me 1's add karenge toh kitne ans milenge +
        // current wala answer ko add karna mat bhulna(currlen ko range me hai)

        // memo me bhi update kar dena
        memo[currlen]=(addzero + addone + currans)%MOD;
        return (addzero + addone + currans)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        lo = low, hi = high;
        // empty string bhejo, zero and ones se banate jao string take nottake
        // karke, ban jaaye toh lo and hi ke range me ho string ka length toh
        // ans me +1 karte jana, hi se upar gaye toh return kar dena bas aur kya

        // instead of actually creating the string, bas length leke chalo string
        // ki, since ek baar me 'zero' ya 'one' hi add hoga string ke length me

        // tle dera, memoize kardo, here only length of string change, which
        // goes to maxm of high, iska memo bana do bss
        vector<int> memo(high + 1, -1);
        return solve(0, zero, one, memo);
        // 0-> length of initial string
    }
};