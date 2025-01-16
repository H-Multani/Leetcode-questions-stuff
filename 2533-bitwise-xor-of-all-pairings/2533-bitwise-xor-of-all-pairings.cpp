class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // brute force tle de diya, ab batter soln nikalte hai

        // agar sirf ek number ke set bit ko dekhe, toh all in all, vo bit baaki
        // saare elements ke saath XOR hora hai

        // bsaically, har element of nums1, is being XOR with har element of
        // nums2, ye toh pair ke liye ho gaya, lekin phir vahi pair wale
        // elements khud me XOR hore hai ek doosre ke saath

        // toh instead of doing XOR of each pair, phir uss saare pairs ko XOR
        // karna, apan kya kar sakte hai ki, count the number of set bits in
        // each position, of both nums1 and nums2 ke elements, ie har bit par 1
        // kitne baar aayega in the end for XOR

        // isse end me answer ke liye pata chal jaayega ki kitne set bits
        // lagenge ans ke liye,

        // for eg in the end the 5 th bit has freq 5, means saare pairs bana kar
        // XOR karenge and operation karenge toh iss bit par 5 baar 1 aayega, jo
        // ki XOR ho kar 1 milega end me, in such case ans ke 5 th bit ko set
        // kar denge apan,

        // similarly, agar freq 4 mila, toh matlab iss posn par 1 aaayega 4
        // baar, toh 4 1's ek dusre ke saath XOR hoke 0 bana dnege, toh iss
        // position par apan 0 set kar denge answer me, yehi karo bass

        // and constraint ke hisaab se freq ke liye 32 size ka array kaafi
        // rahega, since for eg element is 12->1100, toh do +1 in idx 2 and 3,
        // of the freq vector

        vector<long long> freq(64, 0);

        // ab dono arrays me har element par iterate krdo

        long n = nums1.size(), m = nums2.size();

        // each element of nums 1 will come in m pairs , toh nums1 ke liye koi
        // bhi bit hoga, vo total m baar aayega, like of nums1={4} ,
        // nums2={1,2}, toh pairs will be {4,1},{4,2}, toh ye nums1 ke 4 ka set
        // bit 2 baar aaya, ue nums2.size(), jitne times aaya, toh ye count me
        // consider karna hai, sirf 4 ke bit ko ek baar freq me consider karke
        // khatam nai karna hai

        // we iterate over nums1, iska har element, nums2.size(), ie m jitne
        // times aayega, toh freq me +m add karna not +1
        for (auto it : nums1) {
            // current element me jitne set bits hai, freq me daal do
            long long setbits = __builtin_popcount(it);

            // itne bits ka location nikalo aur freq me update kardo
            long long temp = 0;
            while (setbits > 0) {
                if (it & (1 << temp)) {
                    // means ye wala bit set hai, toh freq me update kardo ki
                    // yeh temp location wala bit kitne baar set rahega
                    freq[temp]+=m;
                    setbits--;
                }
                // move to the next bit, to be checked
                temp++;
            }
        }

        // do same thing as above too but for nums2 ke elements
        // we iterate over nums2, iska har element, nums1.size(), ie n jitne
        // times aayega, toh freq me +n add karna not +1
        for (auto it : nums2) {
            // current element me jitne set bits hai, freq me daal do
            long long setbits = __builtin_popcount(it);

            // itne bits ka location nikalo aur freq me update kardo
            long long temp = 0;
            while (setbits > 0) {
                if (it & (1 << temp)) {
                    // means ye wala bit set hai, toh freq me update kardo ki
                    // yeh temp location wala bit kitne baar set rahega
                    freq[temp]+=n;
                    setbits--;
                }
                // move to the next bit, to be checked
                temp++;
            }
        }

        // ab freq me apne paas set bits ke count hai , ki har bit kitne baar
        // set hoga, now if i th bit is set(made 1) 6 times, means 6 baar iss
        // bit par XOR ke liye 6 1's aayenge, toh saare 1's will cancel each
        // other out, leaving this bit to have a 0 in the end

        // similarly for if set bit freq is 9, means iss bit par XOR ke liye 9
        // 1's aayenge, toh saare khud me hi XOR ho kar end me 1 chhorenge in
        // the end, yehi karna hai apan ko

        long long ans = 0;

        for (auto i = 0; i < 32; i++) {
            // current bit ka freq kya hai
            long long val = freq[i];

            // agar val is even means even 1's aayenge for XOR, all will cancel
            // out, leaving 0 fot this bit, toh yaha toh kuch nai h karne ke
            // liye

            // similarly, val is odd, means odd 1's aayenge for XOR, leaving
            // remaining 1 in the end, toh yehi bit set kardo
            if (val % 2 == 1) {
                // ans ka i th bit set kardo
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};