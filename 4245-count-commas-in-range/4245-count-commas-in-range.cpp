class Solution {
public:
    int countCommas(int n) {

        // range count karlo, 10^5 tak jaa sakta hai,

        // 1,000 se leke 999,999 tak me 1 comma hi lagega

        // range nikal lo

        int ans = 0;

        // 1000 se chhota hai n toh koi comma nai lagega return 0
        if (n < 1000)
            return 0;

        // 1000 se leke 999999 tak 1 comma lagega har number me, karlo count,

        // 1 comma per number, 1 count increase

        // ab agar iske upar hua toh 1,000,000 tak hi jayega, isme bhi 2
        // comma lagega, 2 commas bass 1,000,000 par lagenge which is 10^6, jo
        // range hi nai hai

        // toh ans ke liye bas n and 1000 ke beech jitne elements hai count
        // karlo

        ans += (n - 1000 + 1);

        return ans;
    }
};