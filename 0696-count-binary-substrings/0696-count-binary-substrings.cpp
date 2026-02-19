class Solution {
public:
    int countBinarySubstrings(string s) {
        // ek array bhar do which will store like {a,b,c,d,...} where a,c,...
        // are consecutive 1 counts, and b,d,... are cons. 0's counts, toh array
        // like {43,56,32,87} means overall string me
        // 42 0's haiin line then 56 1s , then 32 0s in line, then 87 1s in line
        // or
        // 42 1's haiin line then 56 0s , then 32 1s in line, then 87 0s in line
        // either way ans will be same

        int n = s.size();
        vector<int> vals;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                // means consecutive count chalra hai, current wale ko count
                // karke aage badhao
                cnt++;
            } else {
                // we here means jo consecutive 0's ka count chalra tha vo ruk
                // kar ab consecutive 1's ka count le rahe apan

                // or

                // jo consecutive 1's ka count chalra tha vo ruk
                // kar ab consecutive 0's ka count le rahe apan

                // either way switch kar rahe apan, toh abhi tak jo count bana
                // hai vector me daal do and arr[i] wale bande ke conscutive
                // count karna chalu kardo

                // first cnt ko daal do vector me
                vals.push_back(cnt);

                // ab cnt ko 1 kardo to count arr[i] wala element, ab iss arr[i]
                // jitne kitne elements hai consecutively count karo
                cnt = 1;
            }
        }

        // loop ended lekin cnt me ho sakta hai values ho last wale consecutive
        // elements ki, toh vals me daal do
        vals.push_back(cnt);

        // ab vals has nos like
        // {0_consecutive_cnt,1_consecutive_cnt,0_consecutive_cnt,1_consecutive_cnt,0_consecutive_cnt,1_consecutive_cnt....}

        // in this ans will be min{0 cnt,adjacent 1 cnt} ie min(arr[i] and
        // arr[i-1]), can also use min(arr[i] and arr[i+1]), dono same ans
        // denge, but dono me se koi ek use karna dono nai, nai toh duplicate
        // values milengi
        int ans = 0;
        n = vals.size();
        for (int i = 1; i < n; i++) {
            ans += min(vals[i],vals[i-1]);
        }

        return ans;
    }
};