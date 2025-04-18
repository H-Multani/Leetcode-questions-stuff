class Solution {
public:
    string dostuff(string s) {
        // yaha par ip string ka encoding krna hai bss, vahi kardo
        string ans = "";
        if (s.size() == 1) {
            ans += "1";
            ans += s[0];
            return ans;
        }

        // we here means size>1 hai, freq nikalte chalo count lgate chalo,
        // values banate chalo
        int n = s.size();
        int cnt = 1;
        // cnt=1 since first char of series ko cnt krna padega
        for (int i = 1; i < n; i++) {
            // agar curent and prev char same hai toh cnt increase krdo
            if (s[i] == s[i - 1])
                cnt++;
            else {
                // we here means new char ka counting chalu hora hai yaha se,
                // jiska counting chal raha tha abhi takk usko add kardo ans me

                // encoding ke hisaab se first count daalo
                ans += to_string(cnt);
                // then char daalo jo aa raha tha
                ans += s[i - 1];

                // cnt ko restart krdo 1 se to count new region now, and to
                // include current i th banda in new region
                cnt = 1;
            }
        }

        // ek last baar count ko add kardo alongwith the n-1 th char in s
        ans += to_string(cnt);
        ans += s[n - 1];

        return ans;
    }
    string countAndSay(int n) {
        // recursive call krdo, and ek helper funcn bana lo which will make the
        // run-length coding

        // base case, if n==1 toh return 1;
        if (n == 1)
            return "1";

        // n ke liye ans nikalne ke liye n-1 ke ans ka zarurat

        // toh n-1 me jaa kar string nikalo jo bhi hai firstly
        // string n_minus1 = countAndSay(n - 1);

        // ab iss string ka encoding karo and return kardo, jaisa questn bola
        // hai

        // 1 line soln, instead of saving the n_minus1 and then sending to
        // another funcn, uss funcn me as parameter hi bhej do lol
        return dostuff(countAndSay(n-1));
    }
};