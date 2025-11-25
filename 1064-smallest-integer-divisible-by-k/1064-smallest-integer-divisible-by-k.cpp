class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int len = 1;
        int val = 1;

        // soo the number is legitt getting to bigg to handle, lekin ek kaam ka
        // item ye hai ki long division jab karte hai apan toh end me remainder
        // bass kaam ka hota hai, fir end me uss number me agar 1 add karna hai
        // toh bass uss remainder ko *10 +1 kardo, same hoga like if we have 111
        // and divide by k=7 we get remainder 6, ab isme 1 add karenge toh ye
        // 1111 ban jayega, then remainder 6 me 1 becomes 61, toh ab 61%7=5, toh
        // end me apne kaam bas end ka modulo aa raha hai thats all not the
        // whole value, toh sirf modulo ko save karenge and count rakh lenge
        // length ka thats all

        // set to store remainders, agar koi bhi remainder repeat hua means
        // kitne bhi 1 laga lo repeat hi hota rahega, in such case return -1
        set<int> r;
        // worst case me it stores k values for k different remainders
        // S.C-> O(k)

        // worst case me ye loop k baar chalega for k different remainders
        // T.C-> O(k)
        while (true) {
            // current val check karo if it can be the ans
            if (val % k == 0) {
                return len;
            }

            // we here means remainder bachega kuch, in such case remainder
            // check karo agar pehle mila hai toh , agar pehle mila hai toh we
            // cant do anything since kitne bhi 1 add karlo end me repeat hi
            // hoga, in such case return -1
            int rem = val % k;

            if (r.find(rem) != r.end()) {
                // means ye remainder mila hai return -1
                return -1;
            }

            // we here means new remainder mila hai new wala, ab isme ek 1 add
            // kardo , if rem==2, then it becomes 21, if rem=32, then it becomes
            // 321

            // we only save this remainder since bass iska kaam rahega, aur ko 1
            // add kiya hai usko length me count kar lena
            val = (rem * 10) + 1;
            len++;
        }

        // we here means nai banne wala return -1
        // realistically we will never reach here since milega toh andar se hi
        // return kar dega, ya andar se hi -1 bhej dega
        return -1;
    }
};