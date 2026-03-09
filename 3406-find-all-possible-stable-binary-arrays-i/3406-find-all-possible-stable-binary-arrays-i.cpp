class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][2];
    int solve(int onesleft, int zerosleft, bool prevWasOne, int limit) {
        // base case
        if (onesleft == 0 && zerosleft == 0) {
            // means apana ne saare 1s and 0s use kar liye hai return frm here

            // since 1 subarray mil gaya hence return 1
            return 1;
        }

        // memo me hai ans toh yehi se bhejdo
        if(dp[onesleft][zerosleft][prevWasOne]!=-1) return dp[onesleft][zerosleft][prevWasOne];

        // we here means nai mila hai array

        // ans nikal lo yaha se aage nikalne wala
        int ans = 0;

        if (prevWasOne) {
            // means pichla wala 1 tha, means apan ab 0s bharenge bass array me,
            // since we cannot put 1s here if pehle bhi 1 bhare the, since max
            // to max wwe can have limit 1's and limit 0's consecutively

            // toh yaha apan 0s bharenge, since pehl1 1's bhar diye the

            // toh ab yaha apan ke pass options hai kitne 0s bharne hai yaha

            // if we have zerosleft=5 and limit=3, means apan yaha bhi maxm 3 0s
            // de sakte hai,similarly if we have zerosleft=5 and limit=8, then
            // yaha apan bass 5 0s rakh sakte hai since thats all which is
            // available for use

            // overall min(zerosleft,limit) jitne rakh sakte apan

            for (int i = 1; i <= min(zerosleft, limit); i++) {
                // means apan i 0s rakhenge

                // toh i jitne 0s rakh kar explore karo kitne ans ban sakte hai
                // and result me add karo

                // ab yaha apan i jitne 0s use kar liye hai toh aage explore
                // karne me onecnt same jayega, zerosleft-i jayega since
                // remaining we have (zerosleft-i) itne 0s left

                // also since ye wala 0 lagaya tha toh aage apan false bhejenge
                // for prevWasOne
                ans =
                    (ans + solve(onesleft, zerosleft - i, false, limit)) % mod;
            }
        } else {
            // we here means pichla wala 0 tha , means apan ab yaha 1's
            // bharenge, all same logic as above, but 0s ki jagah 1s bhar rahe
            // ab

            // toh min(onesleft,limit) jitne 1s laga sakte yaha
            for (int i = 1; i <= min(limit, onesleft); i++) {

                // ans me add kardo

                // since yaha apan i jitne 1s bhar rahe hai hence aage
                // exploration ke liye (onescnt-i) jayega, since 0s use nai hue
                // toh zerosleft same jayega aage

                // also since yaha 1s bhar rahe toh aage exploration ke time
                // true bhej dena for prevWasOne

                ans = (ans + solve(onesleft - i, zerosleft, true, limit)) % mod;
            }
        }

        // memo me update before sending ans
        dp[onesleft][zerosleft][prevWasOne]=ans;

        // jo bhi ans bana bhej do
        return ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        // ye obviously TLE dega, toh memoize karlo

        // onesleft can be 200, zerosleft can be 200, prevWasOne can be true or
        // false(2 values), toh 3D dp lelo, of size 201,201,2 , dp me initially
        // -1 bhardo

        memset(dp,-1,sizeof(dp));

        // one se start karke ans nikalo
        int startwithone = solve(one, zero, false, limit);
        // 0 se start karke ans nikalo
        int startwithzero = solve(one, zero, true, limit);

        // ab dono case se jo ans nikle add karke bhej do
        return (startwithone + startwithzero) % mod;
    }
};