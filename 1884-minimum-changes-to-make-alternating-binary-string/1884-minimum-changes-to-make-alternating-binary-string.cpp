class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // ab iss n size ka string can either be 01010101 or 101010101 depending
        // on type, toh dono type me check karlo, ki current type par laane me
        // kitne operations lagenge, jisme kam operations lage, vahi hoga ans

        // type 1 is 01010101.., isme even idx par 0 hai odd idx par 1 hai
        int type1 = 0;
        // type 2 is 10101010.., isme odd idx par 0 hai even idx par 1 hai
        int type2 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // means even hai index

                // agar s[i]==0 means type 1 ke hisab se already order me hai,
                // no steps reqd
                // agar s[i]==0 means type 2 ke hisab se ek operation lagega
                // yaha
                if (s[i] == '0') {
                    // means type 2 me convert karne ke liye 1 operation
                    // lagega,include in type 2 then
                    type2++;
                }
                // agar s[i]==1 means type 2 ke hisab se already order me hai,
                // no steps reqd
                // agar s[i]==1 means type 1 ke hisab se ek operation lagega
                // yaha
                else {
                    // we here means s[i]==1 , type 1 ke hisab me operation
                    // lagega yaha, include in type 1 then
                    type1++;
                }
            }
            else{
                // means odd hai index
                if (s[i] == '1') {
                    // means type 2 me convert karne ke liye 1 operation
                    // lagega,include in type 2 then
                    type2++;
                }
                else {
                    // we here means s[i]==0 , type 1 ke hisab me operation
                    // lagega yaha, include in type 1 then
                    type1++;
                }

            }
        }



        // ab dono me se jis bhi type me convert karne me kam time lagega vahi bhej do as ans
        return min(type1,type2);
    }
};