class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // ezpz tareeka, 2 ke power wale saare numbers nikal lo, then current n
        // ka digits ka freq nikalo and compare karo, if koi bhi valid power of
        // 2 ka same freq map hua as n, means that no can be made by rearranging
        // digits of n, toh yes return krdenge, else no

        // store karlo saare power of 2 waale numbers ko
        vector<string> power_of2 = {
            "1",          "2",         "4",         "8",         "16",
            "32",         "64",        "128",       "256",       "512",
            "1024",       "2048",      "4096",      "8192",      "16384",
            "32768",      "65536",     "131072",    "262144",    "524288",
            "1048576",    "2097152",   "4194304",   "8388608",   "16777216",
            "33554432",   "67108864",  "134217728", "268435456", "536870912",
            "1073741824", "2147483648"};
        // 10^9 ke range me itne hi numbers hai which are powers of 2

        // ab freq nikalo n ki
        unordered_map<char, int> mpp;
        while (n > 0) {
            mpp[(n % 10) + '0']++;

            n /= 10;
        }

        // // map ko print krdo zara
        // for(auto it:mpp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        // ab loop karo powerof2 wale par
        for (auto curr : power_of2) {
            // curr wale bande ka freq array nikalo
            unordered_map<char, int> temp;

            for (auto ch : curr) {
                temp[ch]++;
            }

            // agar curr wale bande ka map same as n ka map, means n ke digits
            // can be rearranged to form curr wala banda which is a power of 2,
            // toh in such case return true
            if (temp == mpp)
                return true;
        }

        // we here means koi bhi nai mil paya which can be a power of 2 in such
        // case return false
        return false;
    }
};