class Solution {
public:
    long long countCommas(long long n) {
        // again samr logic range count karlo

        long long ans = 0;

        if (n < 1000) {
            // we here means less than 4 digits, 0 commas,
            return 0;
        }
        // 1,000 to 999,999 jitne honge sab me 1 comma lagega, karlo count
        // commas count karlo

        // values cnt karlo
        long long cnt = min(n, 1LL * 999999) - 1000 + 1;

        // cnt<0 meaning ki n ka range hi nai hai utna , toh elements kaha se
        // milenge
        if (cnt < 0)
            return ans;

        // yaha each number will have 1 comma starting from 1000

        ans += (cnt);

        // min isliye since possible hai ki 999,999 ki range me hi n aa
        // jaaye, toh uss case me range tak lena bass

        cout << "999,999 ki range tak " << ans << endl;

        // ab agar 1,000,000 se leke 999,999,999 tak hai toh har value will have
        // 2 commas, karlo count

        // yaha har element ke 2 commas honge, karlo count
        cnt = min(1LL * 999999999, n) - 1000000 + 1;
        // cnt<0 meaning ki n ka range hi nai hai utna , toh elements kaha se
        // milenge
        if (cnt < 0)
            return ans;

        // count nikal liye ki kitne elements hai

        // har element ke 2 commas
        ans += (cnt * 2);
        cout << "999,999,999 ki range tak " << ans << endl;

        // ab agar 1,000,000,000 se leke 999,999,999,999 tak hai toh har value
        // will have 3 commas, karlo count
        // yaha har element ke 3 commas honge, karlo count
        cnt = min(1LL * 999999999999, n) - 1000000000 + 1;
        if (cnt < 0)
            return ans;

        // count nikal liye ki kitne elements hai

        // har element ke 3 commas
        ans += (cnt * 3);
        cout << "999,999,999,999 ki range tak " << ans << endl;

        // ab agar 1,000,000,000,000 se leke 999,999,999,999,999 tak hai toh har
        // value will have 4 commas, karlo count
        // yaha har element ke 4 commas honge, karlo count
        cnt = min(1LL * 999999999999999, n) - 1000000000000 + 1;
        if (cnt < 0)
            return ans;

        // count nikal liye ki kitne elements hai

        // har element ke 4 commas
        ans += (cnt * 4);
        cout << "999,999,999,999,999 ki range tak " << ans << endl;


        // ab agar 1,000,000,000,000,000 se leke 999,999,999,999,999,999 tak hai toh har
        // value will have 5 commas, karlo count
        // yaha har element ke 5 commas honge, karlo count
        cnt = min(1LL * 999999999999999999, n) - 1000000000000000 + 1;
        if (cnt < 0)
            return ans;

        // count nikal liye ki kitne elements hai

        // har element ke 5 commas
        ans += (cnt * 5);
        cout << "999,999,999,999,999,999 ki range tak " << ans << endl;

        return ans;
    }
};