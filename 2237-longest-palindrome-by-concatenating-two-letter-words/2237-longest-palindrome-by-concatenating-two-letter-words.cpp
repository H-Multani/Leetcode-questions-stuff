class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // hints se samajh aa gaya

        // for each "ab" we need a "ba" to put on other side, toh agar 5 "ab"
        // hai toh usko use krne ke liye 5 "ba"  bhi hona chahiye so that
        // palindrome me laga paaye, toh sbse pehle saare "ab","ba","xy" types
        // ke strings ka freq nikal lo

        // these will make palindrome like=> ___ab_________ba___
        // these cant be put in bw of the palindrome for obvious reasons

        // problem arises when strings like "aa" or "cc" come up, since ye beech
        // me bhi lag sakte hai palindrome ke(like that odd freq wala char)

        // so these have 2 posns 1st-> __aa__________aa__ like above case,
        // 2nd-> ____________aa____________

        // toh beech wala lag sakta h, hence if "aa" comes 7 times, toh 7 me se
        // 6 toh 1st posn type ag jayenge 3 on each side, and 7 th wala beech me
        // lagega like 2nd posn

        // toh ye "aa" type walo ka freq alag store karo, inn par alag kaam
        // hoga, counting karte vaaste,

        // make map that stores freq for "au" type characters
        unordered_map<string, int> mp1;
        // make map that stores freq for "xx" type characters
        unordered_map<string, int> mp2;

        // mp1 and mp2 ko bhar do
        for (auto it : words) {
            if (it[0] == it[1]) {
                // means it is "xx" type char, mp2 me dalo
                mp2[it]++;
            } else {
                // means it is "ds" type char, mp1 me dalo
                mp1[it]++;
            }
        }

        // ab count karenge inn me se kitne elements lagenge palindrome banane
        // ke liye, keep in mind element count krre h apan
        int cnt = 0;

        // sbse pehle "xx" type walo ka count karo

        // this is incase "xx" ka freq odd ho, agar odd h toh freq-1 karke count
        // kar lenge, and oddpresent ko true kar lenge, so that end me ye odd
        // wala bhi count kar paaye
        bool oddpresent = false;

        for (auto it : mp2) {
            int freq = it.second;

            if (freq % 2 == 1) {
                // means "dd" ka freq odd hai like 5,7,23 etc, toh freq-1
                // karenge and count kar lenge, since 5 "dd" hai toh isme se 4
                // "dd" can be placed like __dd_______dd__

                // toh place kardo
                cnt += (freq - 1);

                // and since ye odd tha freq toh matlab beech me banda baitha
                // sakte hai apan palindrome ke, toh oddpresent ko true krdo
                oddpresent = true;
            } else {
                // we here means freq is even, ie "ff" ka freq even h like
                // 4,8,12 etc, toh ye 8 "ff" equally split ho jayenge like
                // ___ff_______ff___ (these are 2 "ff" split)

                // toh saare hi use me aa jayenge cnt me add krdo
                cnt += freq;
            }
        }

        // ab if oddpresent=true, means koi ek "rr" ka freq odd h, means usko
        // beech me daal sakte hai apan like __________xx__________

        // toh ab maan lo ki 2 elements the "ee" and "gg" dono ka freq odd, toh
        // dono me se ek dalega beech me bas, since we cant split the string to
        // accomodate the "gg" wala pair

        // toh out of all the elements with even freq, bas ek hi beech me
        // aayega, if "dd" has freq=5 toh 4 toh pehle used h, 5 th wala bacha
        // bas, similarly "tt" has freq=9 toh isme se 8 to pehle used, 9 th wala
        // bacha bas, toh dono me se koi bhi daal do count 1 hi hoga jo bhi hai

        if (oddpresent) {
            // means beech me apan ek element daal sakte hai,laga do element
            // count krlo
            cnt++;
        }

        // cout << cnt << endl;

        // ab saare apan ne "ff" type ke elements count krliye hai, ab "ag" wale
        // par jao
        int cnt2 = 0;
        for (auto it : mp1) {
            // curr string is
            string curr = it.first;

            // if curr="ab" toh iske corresponding ek "ba" hona chahiye
            string rev = curr;
            reverse(rev.begin(), rev.end());

            // cout<<"curr= "<<curr<<" "<<" rev= "<<rev<<endl;

            // agar ye "ba" is present in map means apan pairs bana sakte hai
            // like __ab_______ba__, so that palindrome bane
            if (mp1.find(rev) == mp1.end()) {
                // means "ab" ke liye "ba" nai mila, continue to next pair
                continue;
            }

            // we here means mil gaya pair, toh agar "ab" ka freq=5 hai, and
            // "ba" ka freq=8, toh apan bas 5 pairs bana payenge, since bache 3
            // "ba" ke liye apan ke paas "ab" nai hai

            // toh jo bhi minm freq hai utne elements*2 count krlo, since "ab"
            // ka freq=5 and "ba" ka freq=5 le rahe hai apan, toh total 10
            // elements le rahe hai apan, tabhi count krlo

            cnt2 += (2 * min(it.second, mp1[rev]));

            // minm freq wala elements counted twice, since 5 "ab" ke saath 5
            // "ba" le rahe hai

            // also "ba" ko map se alag kardo, nai toh aage wale iteration me
            // "ba" aayega phir vo "ab" dhundega, which will make the same
            // element counted 2 times, jo nai karna h
            // mp1.erase(rev);

            // instead of alag karna, ho jaane do add, 2 baar add hoga na ek
            // element, bas na, cnt2 me lelo inn saare sums ko, end me cnt2/=2
            // kar dena, sab vapas sahi ho jaega

            // toh "ab" ka 5 element count hona tha which will be counted 2
            // times= 10 elements(5 times in "ab" wala case("ab" ke liye "ba"
            // dhundna) and 5 times in "ba" wala case("ba" le liye "ab"
            // dhundna))

            // end me cnt2/2 kar denge toh 10 vapas 5 par aa jayega GG
        }

        cnt2 /= 2;

        // cout<<"cnt2= "<<cnt2<<endl;

        // ab cnt2 contains the correct number of elements, cnt me add krdo
        cnt += cnt2;

        // for (auto it : mp1)
        //     cout << it.first << " " << it.second << endl;

        // ab apan ke paas saare element ke count aa chuke h, itne element
        // lagenge for biggest palindrome, each element has 2 characters, toh
        // overall length of palindrome will be 2*cnt which will be ans
        return 2 * cnt;
    }
};