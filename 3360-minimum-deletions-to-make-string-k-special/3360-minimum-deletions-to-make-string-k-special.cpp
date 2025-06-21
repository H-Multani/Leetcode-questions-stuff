class Solution {
public:
    int minimumDeletions(string word, int k) {
        // looks simple enough

        // minm freq wala banda nikalo, +k karo, jitno ki freq iske upar hai,
        // unn se char alag karne padenge, kar dena then ans me cnt krlena
        // this doesnt work, hint dekhna pada

        unordered_map<char, int> mpp;
        for (auto it : word) {
            mpp[it]++;
        }

        // int minm = INT_MAX;

        // for (auto it : mpp) {
        //     if (it.second < minm) {
        //         minm = it.second;
        //     }
        // }

        // iske upar jitno ki freq hogi, sab se char remove honge cnt krlo

        // for (auto it : mpp) {
        //     if (it.second > minplusk) {
        //         // iss se char remove karne padenge, so that k wali range me
        //         aa
        //         // jaaye

        //         // need to remove it.second-minm characters so that k wali
        //         range
        //         // me ho current banda with the minm freq character, ie curr
        //         // bande ka freq aur minm freq me k se zyada ka difference na
        //         ho

        //         // toh itne char remove kardo current bande se and cnt krlo
        //         cnt += it.second - minm;
        //     }
        // }

        // ye nai chalega since eg 3 me ye, a ko alag karne ka sochega instead
        // of removing 1 B, and getting ans, toh another soln is har bande ko
        // minm leke dekh lo

        // like ye dekho ki agar current bande ko minm freq leke chalre hai toh
        // kitne characters delete karne padenge

        int ans = INT_MAX;

        // iterate over all freq of characters

        // mpp ka max size=26, since 26 char with sabka freq
        for (auto curr : mpp) {
            // current bande ka freq
            int freq = curr.second;

            // maan kar chalo ki ye freq minm hai, toh iske chalte kitne char ko
            // remove karna hoga baaki se

            // since current banda minm hai toh isse toh char remove nai kar
            // sakte

            // mod wala logic nai leke chalre since mod leke chalenge toh minm
            // and maxm ka definition invalid ho jaega, kya faayeda minm choosr
            // krne ka agar minm se bhi remove karoge toh, tbhi curr wale ko
            // minm dekh kar rakhenge and decide karenge ki iske minm hone se
            // baaki char kaise alag honge
            int cnt = 0;
            for (auto it : mpp) {
                // curr bande ka freq agar freq+k se bada hai toh characters
                // remove karne padenge
                if (it.second > freq + k) {
                    // means char remove karne padenge curr bande se, remove
                    // it.second-freq-k characters, to reach the under k
                    // difference range
                    cnt += it.second - freq - k;
                }
                // ya toh agar freq of curr char<minm freq
                else if (it.second < freq) {
                    // means new wale character ka freq aur chhota mila hai,
                    // lekin apan minm waale se toh remove nai kar sakte
                    // characters, toh current bande se saare characters remove
                    // kardo, saare occurences alag kardo so that current banda
                    // minm ban jaaye

                    // in such case cnt me curr bande ka freq add hoga bss
                    cnt += it.second;
                    // since iss bande ke saare characters alag karne hai, not
                    // literally but figuratively, cnt karlenge ki itne remove
                    // karne padenge, since aage baaki elements ko bhi minm dekh
                    // kar chalna hai
                }
            }

            // agar cnt ans se chhota hai toh update krdo
            ans=min(ans,cnt);
        }

        return ans;
    }
};