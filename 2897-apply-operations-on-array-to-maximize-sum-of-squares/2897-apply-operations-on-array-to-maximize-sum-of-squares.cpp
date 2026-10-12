class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        // sinple hi toh hai, saare values ke 1 OR karte karte leke aa jao ek
        // element me mbss aur kya

        // end me yehi banda bachega bass with most no of set bits and hence max
        // square sum

        vector<int> cnt(32, 0);

        // nums par iterate karo
        for (auto it : nums) {
            // current bande ke har bit ko dekho
            for (int i = 0; i < 32; i++) {
                // current bit 1 hua toh
                if (it & (1 << i)) {
                    // we here means ye wala bit posn set hai

                    // toh cnt me iss bit posn par +1 kar dena
                    cnt[i]++;

                    // since saare elements OR karoge toh ye wala bit kisi ek
                    // number me 1 aayega to OR of all elements me ye bit 1 de
                    // dega

                    // apan saare bits count kar rhe hai, so that top ka ans banane ke liye saare bits sahi se use ho paye
                }
            }
        }

        // ab apan ko pata hai konse wale bits set dikhane hai, value bana akr
        // bhej do

        long long ans = 0;

        // sicne we can take onyl top ke k values, hence

        while (k--) {

            // current banda kon banega
            long long curr = 0;

            // bits wale array par iterate karlo, wahi se bits nikal kar value
            // banegi
            for (int i = 0; i < 32; i++) {
                // agar current posn par 1 bit set hai toh kardo current value
                // me set
                if (cnt[i] > 0) {
                    // set bit cnt se 1 cnt remove kardo
                    cnt[i]--;

                    // curr value me vo bit set kardo
                    curr=(curr | (1<<i) );
                }
            }

            // ab current wala ban chuka hai result me add kardo
            ans=(ans+(curr*curr))%mod;
        }

        return ans;
    }
};