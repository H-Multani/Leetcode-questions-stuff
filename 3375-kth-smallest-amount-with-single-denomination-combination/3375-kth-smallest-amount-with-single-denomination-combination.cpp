class Solution {
public:
    typedef long long ll;
    ll countsmaller(ll mid, vector<int>& coins) {
        // correct wala ans bhejna hai apan ko
        ll ans = 0;

        int n = coins.size();

        // toh we need |a∪b∪c∪d....| ka value

        // for n coins we have 2^n-1 expressions, loop chala kar iterate karo

        // 2^n ke liye we can use left shift operator
        // 1<<n is same as 2^n

        for (int expression = 1; expression <= (1 << n) - 1; expression++) {
            // duplicates ke liye LCM nikalna padega leke chalo yehi se
            ll lcm = 0;

            // order bhi pata hona chahiye, if order is odd, then we add to ans,
            // else we subtract frm ans
            ll order = 0;
            // order tells us ki kitne coins use hue hai

            // current expression is
            // 1-> 001-> 1 set bit-> |a|-> add
            // 2-> 010-> 1 set bit-> |b|-> add
            // 3-> 011-> 2 set bit-> |a∩b|-> subtract
            // 4-> 100-> 1 set bit-> |c|-> add
            // 5-> 101-> 2 set bit-> |a∩c|-> subtract

            // and

            // |a|-> mid/coins[0]
            // |b|-> mid/coins[1]
            // |c|-> mid/coins[2]
            // ....
            //  |a∩b|-> mid/LCM(coins[0],coins[1])
            //  |a∩b∩c|-> mid/LCM(coins[0],coins[1],coins[2])
            //  and so onn

            // toh vo value banao ab

            // n bits hai na expression me, toh n ka loop
            for (int i = 0; i < n; i++) {
                // current bit set hai toh use karo, to check that

                // (1<<i) to get 1 to the required bit and then
                // & expression, so that expression ka vo specific bit check ho
                // jaaye ki set hai ya nai
                if (expression & (1 << i)) {
                    // means i th bit set hai

                    // since current bit set hai toh order me count karlo pehle
                    // toh
                    order++;

                    // then lcm update karo
                    if (lcm == 0) {
                        // in this case curent element ko LCM bana do
                        lcm = coins[i];
                    } else {
                        // we here means pehle lcm le chuke hai |a| ka, ab |b|
                        // ko include karna hai

                        // hence lcm will be
                        // a*b/LCM(a,b)
                        // a is lcm here toh use that and b is coins[i]
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            // ye loop khatam hone ke baas mere paas order hoga which tells ki
            // kitne coins use hue hai yaha
            // if order is odd, means we have to add to ans, else subtract frm
            // ans
            if (order % 2 == 1) {
                // means ans me add karna hai

                // this expression can be
                // |a|
                // |a∩b∩c|
                // |a∩b∩c∩d∩e|
                // .....

                // inn sabka formula is simply
                // mid/lcm

                // since we wanted to know ki mid se chhote ya same kitne
                // elements the

                // for 2-> 2,4,6,8,10,...., if mid=13, then mid/13=6 elements
                // hai smaler than or equal to 13

                // yehi toh count karna tha

                // ab ye ek coin ke liye, if we include multiple coins like 

                // 3-> 3,6,9

                // merge karenge toh 6(and its multiples) wala coin, is LCM(2,3) multiple times aayega toh vo alag karne ke liye we divide by LCM too

                ans+=(mid/lcm);
            }
            else{
                // we here means even hai, iss case me subtract karte the

                ans-=(mid/lcm);
            }
        }

        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        // first we use binary search on ans

        ll ans = -1;

        ll l = 1;
        ll r = (ll)(*max_element(coins.begin(), coins.end())) * k;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            // check if this mid wala can be k th smallest , ie mid se chhote k
            // elements hai kya

            if (countsmaller(mid, coins) >= k) {
                // means left side me k smaller elements hai

                // means this can be possible ans
                ans = mid;

                // check left for better ans
                r = mid - 1;
            } else {
                // we here means apan kth smallest se chhote hai, left check
                // karo for valid ans
                l = mid + 1;
            }
        }

        return ans;
    }
};