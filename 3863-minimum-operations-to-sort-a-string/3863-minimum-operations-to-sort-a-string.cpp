class Solution {
public:
    int minOperations(string s) {
        // ok toh 3-4 hi possible ans hai,

        // case 1-> agar already sorted hai toh 0 step lagega(includes size 1
        // wala)

        // case 2-> agar size 2 hai toh sort nai kar sakte kuch bhi karlo,
        // return -1, iklota case hai ye

        // case 3-> agar minm char start me hai, ya maxm char end me hai toh 1
        // step me ho jayega sorting, return 1 in such case

        // case 4-> ab bache kuche cases ke liye, ya ans 2 hoga ya 3 hoga,
        // isme agar minm and maxm char agar beech me hue toh 2 step me sort ho
        // jayega like maan lo string is [....az...], toh ek loop me 0 to n-2
        // tak sort ho jayega and bache ek step me idx 2 to n-1 sort kar denge ,
        // isse 2 step me ho jayega sorting

        // nai toh agar maan lo maxm is at idx 0 and minm is at idx n-1 , toh ek
        // operation me 0 to n-2 sort(maxm n-2 aa jayega), ek me 1 to n-1 sort
        // kar denge(maxm n-1 aa jayega and minm 1 aa jayega), ek me 0 to n-1
        // sort again(minm 0 par aa jayega ), iss specific case me hi 3 step
        // lagenge

        int n = s.size();
        if (n == 1)
            return 0;
        // check already sorted
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] > s[i]) {
                // means not sorted
                valid = false;
                break;
            }
        }

        if (valid)
            return 0;

        // case 2 check karte ab, we here means n=2 wala valid nai hai, no way
        // to save this btw, return -1
        if (n == 2)
            return -1;

        // case 3
        // min char and max char ka idx nikalo
        int minidx = 0, maxidx = 0;
        char minch = 'z' + 1, maxch = 'a' - 1;

        for (int i = 0; i < n; i++) {
            // minm sirf tab update karna jab new char mile
            if (s[i] < minch) {
                minidx = i;
                minch = s[i];
            }

            // maxm ke liye same char ka naya idx bhi mil jaaye toh bhi koi
            // dikkat nai
            if (s[i] >= maxch) {
                maxidx = i;
                maxch = s[i];
            }
        }

        // case 3
        if (minidx == 0 || maxidx == n - 1)
            return 1;

        // case 4
        // iss case me 3 step lagenge
        if (minidx == n - 1 && maxidx == 0)
            return 3;

        // bache kuche sare case me 2 step me done
        return 2;
    }
};