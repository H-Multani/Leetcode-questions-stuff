class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        // har iteration check kar lo, at max we can have 60 iterations, laga lo
        // 60 tak ka loop
        for (int t = 0; t <= 60; t++) {
            // val nikal lo
            long long val = (long long)num1 - (long long)t * num2;

            // we need val=sum of t powers of 2

            // edge case agar val -ve gaya toh return -1
            if (val < 0)
                return -1;

            // val ka binary me no of 1's is how many bits we need in minm to
            // represent val in powers of 2
            // toh like if val=5, which is 101, we need 2 set bits minm to
            // represent 5, 2 se zyada bits me bhi kar sakte hai represent no
            // worries, lekin minm we need 2 bits

            // toh ab we need val to be sum of t powers of 2, meaning ki minm t
            // set bits required hone chahiye val me to make t a possible ans
            if (__builtin_popcountll(val) <= t) {
                // means ki apan ko val ko represent karne ke liye agar 3 bits
                // chahiye minm then t>=3, means t is a valid ans

                // like if val=6-> 110, need 2 set bits minm, and t=3 , toh that
                // means t is a valid ans, since 6 can be represented in t
                // bits(powers of 2) easily, since 6 ko minm 2 bits chahiye the,
                // ab isko zyada bits me karna easy hai, powers kam kardo,
                // instead of 4+2+0 we can do 2+2+2 (3 powers of 2) or
                // 1+1+1+1+1+1(6 powers of 2)

                // that means t is a valid ans, ek dikkat hai bas abhi

                // agar t>val hua toh???, if maan lo val=5->101, and t= 6, toh
                // bits wise valid hai, we needed 2 set bits minm, and apan ke
                // paas 6 tak ka range hai, means t should be valid, lekin val
                // can at max be made like 1+1+1+1+1 (ie 5 powers of 2), lekin
                // apan ko toh exactly 6 powers of 2 chahiye tha na, that means
                // its not valid, and can not make exact t powers of 2 since
                // bits hi nai hai itne, iska edge case lagana padega

                // toh we need to make sure t>val or t==val, tbhi valid hoga

                if (t <= val) {
                    // we here means t is absolutely a valid ans, and since we
                    // needed the smallest valid ans hence return frm here
                    return t;
                }
            }
        }

        // we here means ans nai mila, in such case return -1
        return -1;
    }
};