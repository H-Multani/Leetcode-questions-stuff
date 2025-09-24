class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        // edge case, numerator 0 hai, return 0
        if (numerator == 0)
            return "0";

        // values can be -ve, uska edge case likho pehle toh

        // is numerator -ve
        bool num;
        if (numerator < 0)
            num = true;
        else
            num = false;
        // is denominator -ve
        bool den;
        if (denominator < 0)
            den = true;
        else
            den = false;

        // overall ans will be
        bool overall = num ^ den;
        // xor since dono me se ek -ve hua toh total bhi -ve hoga

        // 2 parts honge, ek decimal se pehle, ek decimal ke baad tak ka

        // decimal se pehle wala part string me daal do

        // ab apna kaam bas value se hai toh dono values ko +ve kardo
        long long n, d;
        n = llabs((long long)numerator);
        d = llabs((long long)denominator);

        string ans = "";
        ans = ans + to_string(n / d);

        // ab map lelo, this map will store the remainders and the indexes, hint
        // 3 dekho, jaha remainder repeat hona chalu honge wahi se string ko
        // pack karke ans me bhej denge

        // ab decimal ke baad wala ans banayenge apan
        string ans2 = "";

        unordered_map<long long, long long> mp;
        // this will store ki ans2 me konse idx par repeating hora hai

        long long remainder = n % d;
        long long quotient = remainder;

        // iss remainder ko daal do map me pehle since pehla remainder hai ye
        mp[remainder] = ans2.size();
        // iska vaalue=ans2.size since ye remainder tab hoga jab ans2 ke iss
        // wale idx se repeating chalu hogi(mik)

        while (remainder != 0) {
            // jaise normal long division karte the pen paper par
            // remainder aane par, jo bhi remainder hai *10 kardo tab tak
            // jab tak vo value>denominator na ho

            quotient = remainder;

            // i will keep track ki konsa wala 0 hai ye, since first wala *10 se
            // quotient me koi change nai hota, lekin subsequent *10 karne se
            // quotient me ek 0 badhta jayega
            long long i = 0;
            while (quotient < d) {
                // har 10 * ke liye ek 0 ans2 me daalna mat bhulna jaise long
                // division me karte the

                // edge case 0 daalne ka
                // pehla wala 0 toh aisehi milega bina quotient me 0 dale hue,
                // agar pehle 0 se nai hota hai kaam toh subsequent har *10 par
                // ek 0 daalna hai
                // ye basic hai long division method ka, isko hi implement kiya
                // hai bass
                if (i > 0)
                    ans2 += '0';
                quotient *= 10;

                // increase i as well
                i++;
            }
            // ab new wale quotient ka division karke ans me daal do
            long long val = quotient / d;

            ans2 = ans2 + to_string(val);

            // and remainder update kardo
            remainder = quotient % d;

            // kya ye remainder set me hai

            if (mp.find(remainder) == mp.end()) {
                // we here means set me nai hai, daal do set me remainder ko and
                // aage badho
                mp[remainder] = ans2.size();
            } else {
                // we here means map me hai remainder, means aage badhne par
                // sirf repetition milega, means yaha se repeating chalu hogi
                // ans2 ki all the way, in such case, brackets ke andar daal kar
                // ans bana kar bhej do

                // ab kuch toh part repeating hora hoga jo apan yaha hai , toh
                // nikal lo ki repeating part konsa hai
                string rep = ans2.substr(mp[remainder]);

                // cout << rep << " rep" << endl;

                // repeating wala item mil gaya hai, format me likho
                rep = '(' + rep + ')';

                // repeating wale item se pehle kuch non repeating part hoga,
                // agar hai toh nikal lo
                string nonrep = ans2.substr(0, mp[remainder]);
                // cout << nonrep << " nonrep" << endl;

                // toh overall decimal ke aage wala part hoga non repeating part
                // + repeating part

                // dont forget the sign
                if (overall)
                    ans = '-' + ans;

                return ans + '.' + nonrep + rep;
            }
        }

        // edge case, do not forget the sign
        if (overall)
            ans = '-' + ans;

        // agar ans2 is empty means perfect division hua hai in such case sirf
        // ans1 bhejo as ans
        if (ans2 == "")
            return ans;

        // we here means repeating digits ke bina hi division
        // ho gaya, in such case seedha seedha ans1+ans2 bhej do( with the
        // decimal in btw of course)
        return ans + '.' + ans2;
    }
};