class Solution {
public:
    // binary exponentiation wala power funcn(online nikala), pow ka faster
    // version with modulo capabilities
    long long pow(long long a, long long b, long long m) {
        long long ans = 1;
        while (b) {
            if (b & 1)
                ans = (ans * a) % m;
            b /= 2;
            a = (a * a) % m;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        // isme bhi pichle potd lc 3262 jaise p and c lagega

        // okay toh counting karte hai apan

        // theres 4 prime nos (2,3,5,7) which have to be placed at all the odd
        // indeces

        // and theres 5 even nos (0,2,4,6,8) which have to be placed at all the
        // even indices

        // duplication allowed hai toh seedha *4 hoga har place k liye

        // for n=7 we have  _ _ _ _ _ _ _
        // 1st posn, i=0,even idx, even values rakhni hai, 5 options
        // 2nd posn, i=1,odd idx, prime values rakhni hai, 4 options
        // 3rd posn, i=2,even idx, even values rakhni hai, 5 options
        // 4th posn, i=3,odd idx, prime values rakhni hai, 4 options
        // 5th posn, i=4,even idx, even values rakhni hai, 5 options
        // 6th posn, i=5,odd idx, prime values rakhni hai, 4 options
        // 7th posn, i=6,even idx, even values rakhni hai, 5 options
        // overall we have 5*4*5*4*5*4*5
        // for n=7 we have ans= pow(4,7/2)*pow(5,(7/2)+1)

        // toh basically bas *4, *5 karna hai n times

        // okay that gave a TLE, toh better option is pow funcn se nikal le
        // instead of looping

        // for n even, ans=pow(4,8/2)*pow(5,8/2)
        // for n odd, ans=pow(4,7/2)*pow(5,(7/2)+1)

        long long mod = 1e9 + 7;

        if (n & 1) {
            // means value is odd, bitwise logic h banta h terko, dry run krde,
            // used this since n goes 10^15, mod me samay lagega, whereas this
            // is O(1)

            // agar value odd h toh ans is
            return (pow(4, n / 2, mod) * pow(5, (n / 2) + 1, mod)) % (mod);
        }

        // agar n is eve, ans is 
        return (pow(4, (n / 2), mod) * pow(5, (n / 2), mod)) % (mod);
    }
};