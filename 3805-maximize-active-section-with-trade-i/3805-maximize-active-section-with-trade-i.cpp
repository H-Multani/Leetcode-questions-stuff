class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // count only bundles of 0s
        vector<int> arr;
        int cnt = 0;
        int onecnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                cnt++;
            else {
                // one aaya hai active section hai cnt karlo
                onecnt++;
                // count agar non 0 hai toh arr me push kardo
                if (cnt != 0) {
                    arr.push_back(cnt);
                }

                // reset cnt to 0
                cnt = 0;
            }
        }
        // count agar non 0 hai toh arr me push kardo
        if (cnt != 0) {
            arr.push_back(cnt);
        }

        // now we have half ans made already, which is cnt of 1s

        // question bolta ki 0s ke beech wale 1s ke bundle ko 0 bana do and fir
        // uss bade 0s ke contious block ko 1 bana do, toh beech wale 1s end me
        // 1s hi rahenge, and aaju baaju wale 0s ke block 1s ban jaenge

        // toh 100110001 becomes->100000001-> 111111111,

        // basically 2 adjacent blocks of 0s become 1s, and get added to ans

        // yaha augmentation already hai toh apan koi bhi 2 adjacent blocks le
        // sakte hai including start and end wale blocks, agar augmentation nai
        // hota toh ans ke liye first and last block use nai kar paate

        //  toh we just need maxm sum of 2 adjacent blocks of 0s, nikal kar add
        //  kardo
        int m = arr.size();
        int ans = onecnt;
        // jitne 1s already hai utne ans me include kardo yehi par

        // iterate through 0s ke blocks and get maxm sum of 2 adjacent blocks
        // and update ans
        for (int i = 1; i < m; i++) {
            // current and peeche wale ka pair check karo accha ans banega kya

            // banega toh update kardena,
            ans = max(ans, onecnt + (arr[i] + arr[i - 1]));
        }

        return ans;
    }
};