class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // num1 ko lelo x ke liye
        long long x = num1;
        // ab x^num1 will be smallest ie 0

        // ab iss value me total set bit same as num2 hone chahiye, ie
        // no of set bits in num2 and x is same

        // agar kam set bits hai toh add karna padega, least significant bits me
        // se, zyada set bits hai toh again least significant bit se alag karna
        // padega

        if (__builtin_popcount(num1) == __builtin_popcount(num2)) {
            // num1 is answer, since if x=num1, toh num1^x will be smallest ie 0
            return num1;
        }

        // means ya apne paas extra bits hai, ya kam bits hai than needed,
        // in such case pehle toh nikalo ki kitne bits ko set/unset karna
        // hai
        int val = __builtin_popcount(x) - __builtin_popcount(num2);

        if (val < 0) {
            // means val jitne bits kam set hai, toh LSB se bits set karna
            // chalu karo
            val = abs(val);

            // val jitne unset bits ko set kar dena
            long long temp = 0;
            while (val > 0) {
                // if (x & (1 << temp) == 1) {
                //     // means temp wala bit already set hai, kuch mat karo,
                //     // move to the next LSB
                //     // ie left shift, to next LSB
                //     temp++;
                // } else {
                //     // means current bit unset hai, toh set kardo iss bit
                //     // ko, and val ko reduce kardo

                //     // (x>>temp) wala bit unset hai, toh we take OR with
                //     // (1<<temp), to set the required bit

                //     // eg x=110110, and bech wala 0 ko set karna hai, toh
                //     // 1<<3, we get 1000, ab OR kardo,toh we get, x=111110

                //     x = x | (1 << temp);

                //     // also we do val-- here, indicating ki apan ko val
                //     // jitne bits set karne the, usme se 1 kar liya hai set
                //     val--;
                // }

                // complicated code, easy bana rha, mik ne btaya
                if(!(x & (1 << temp))){
                    x = x | (1 << temp);
                    val--;
                }
                temp++;
                // move to the next bit in line
            }
        } else {
            // means val>0 hai, ie extra set bits hai apne paas, unset karna
            // padega unko, again here apan LSB se unset karege bits ko,
            // since agar MSB se unset kiya toh XOR karne ke baad both bada
            // value banega, which we dont want

            // hence LSB se unset karo bits ko
            long long temp = 0;
            while (val > 0) {
                // if (x & (1 << temp) == 0) {
                //     // means temp wala bit already unset hai, kuch mat karo,
                //     // move to the next LSB
                //     // ie left shift, to next LSB
                //     temp++;
                // } else {
                //     // means current bit set hai, toh unset kardo iss bit
                //     // ko, and val ko reduce kardo

                //     // (x>>temp) wala bit unset hai, toh we take OR with
                //     // (1<<temp), to set the required bit

                //     // eg x=101001, and bech wala 1 ko unset karna hai, toh
                //     // 1<<3, we get 1000, ab negate kardo,toh we get,
                //     // 110111, iska AND lelo x ke saath we get, x=100001
                //     x = x & (~(1 << temp));

                //     // also we do val-- here, indicating ki apan ko val
                //     // jitne bits set karne the, usme se 1 kar liya hai set
                //     val--;
                // }


                if(x & (1 << temp)){
                    x = x & (~(1 << temp));
                    val--;
                }
                temp++;
            }
        }

        return x;
    }
};