class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {

        // toh ek kar sakte ki current sum of squared diff nikal lo, and usko
        // minimize karne ka try karo one element at a time

        // toh eg2 me start sum is 16+16+16+9->57, isko kam karna hai apan ko

        // toh biggest element is 4-> contributes 16, ek step ka use karke 3
        // bana do usko, now it contributes 3, brings contribution down from 16
        // to 9, which brings overall down frm 57 to 50, yehi karte jayenge aur
        // kya

        // best case me k steps lagenge, dekhta if it works, gave TLE

        // toh we know ki 4 comes 3 times, toh uske liye 3 loop chalane se accha
        // ek baari me hi saare 4 ko 3 bana do

        // isse 3 loop ka kaam 1 loop me ho jayega , TLE nai fatega

        // lekin ye count rakhna padega na , uske liye unorderd_map lelo, unique
        // diff and uska freq rakh lega

        // and since ab pq me element ka kaam hai toh set use karlo so that
        // biggest wala end me hi mil jaaye

        set<long long> st;

        // we have overall k1+k2 steps toh k leke chal lo alag lene ka no need
        long long k = k1 + k2;
        int n = nums1.size();
        // current total bhi nikal lo, this is sum of squared difference
        long long ttl = 0;

        unordered_map<long long, int> mpp;

        for (int i = 0; i < n; i++) {
            long long diff = abs(nums1[i] - nums2[i]);
            ttl += (diff * diff);
            mpp[diff]++;
        }

        // pq me saare diff push nai karenge, sirf ek instance push karenge bass
        // utna kaafi hai
        for (auto it : mpp) {
            st.insert(it.first);
        }

        // yaha loop tab tak chalayenge jab tak saare steps use na hoye ho, OR
        // overall sum hasnt reached 0
        // cout<<"current ttl "<<ttl<<endl;
        while (k > 0 && ttl != 0) {
            // current biggest diff nikalo,
            long long tp = *st.rbegin();

            // ab iss top wale ke kitne instances
            int cnt = mpp[tp];

            // ek step kam karoge toh sum me change aayega (isquare)-(i-1 square
            // ka) like 16 to 9 ka diff aayega, ya 25 to 16 ka diff aayega

            long long change = (tp * tp) - ((tp - 1) * (tp - 1));
            // cout<<"changed "<<tp<<endl<<" to "<<tp-1<<endl;
            // cout<<"removed "<<change<<endl;

            // toh 1 step kam karne se change jitna badlega, and aise cnt jitne
            // change laga sakte apan

            // like if change is 16 to 9-> 7
            // 1 step me 7 ka change padega, and aise cnt=3 element hai , toh
            // sabke liye alag karne ka sense nai hai kuch , yehi se dekh lo
            // kitne remove kar sakte

            // agar cnt<=k hai meaning saare 4 ko 3 bana sakte apan no worries,
            // har 4 me ek step lagega kyuki
            if (cnt <= k) {
                // tp+1 ab set me nai rehna chahiye since its no longer the biggest element
                st.erase(prev(st.end()));
                // we here means saare tp ko tp-1 bana sakte apan, bana denge
                // tp se ek step kam karo
                tp--;

                // ab cnt jitne tp became tp-1, toh overall change hua
                // (cnt*change)

                // remove this change from overall sum
                ttl -= (cnt * change);

                // top wale element ko vapas pq me daal do, updated apne aap
                // settle ho jayega
                st.insert(tp);

                // and map me bhi update kardo

                // remove pichla wala element
                mpp.erase(tp + 1);

                // new wale ka freq daal do purane ke sath
                mpp[tp] += cnt;

                // k me se cnt jitne steps used, update k
                k -= cnt;
            } else {
                // we here means saare tp toh tp-1 nai ban payenge

                // lekin jitne ban payenge utne bana denge

                // we here means k<cnt pakka hai

                // toh k elements hi tp se tp-1 ja payenge

                // kitne ban payenge tp se tp-1

                int elementcnt = k;

                
                // ab har ek step me change jitne diff aayega, for elementcnt elements, overall diff will be change*elementcnt, remove this frm ttl
                ttl-=(change*elementcnt);

                // yaha par k steps exhaust ho jayenge , toh no need to even update anything else, since loop aage nai chalega

                // one more thing, since yaha saare k steps lag gaye hai, toh aage loop nai chalega vaise bhi, toh return ans frm here only
                return ttl;
            }
        }

        // dekha jaaye toh yaha tabhi pahuchega jab ttl==0, since uss case me hi else wala case nai chalega

        return ttl;
    }
};