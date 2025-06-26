class Solution {
public:
    int longestSubsequence(string s, int k) {
        // greedy bana kar dekho

        // start frm last wala banda, and store ki curr bande ke right me kitne
        // 0s hai aur, which will be useful
        int n = s.size();
        vector<int> zero(n, 0);

        if (s[0] == '0')
            zero[0]++;
        for (int i = 1; i < n; i++) {
            zero[i] += zero[i - 1];
            if (s[i] == '0')
                zero[i]++;
        }

        // zero[i]= 4 means i ke left side me 4 0's hai which can be taken
        // directly

        // minm ans will be all the 0's clubbed together
        int ans = zero[n - 1];

        // isse better hi ans dhundna hai, start making frm right side

        // 1 aayega toh lene ka sochenge
        int tempans = 0;

        int value = 0;
        for (int i = n - 1; i >= 0; i--) {
            // agar current wala 0 hai toh include krlo
            if (s[i] == '0')
                tempans++;
            else {
                // means 1 hai, current wale bit ko include karenge toh vlue
                // kitne se badhegi?

                // 2^(n-i-1) se badhegi

                // agar le sakte hai toh lelo
                if(value+pow(2,n-i-1)<=k){
                    // means le sakte hai, value update krdo
                    value+=pow(2,n-i-1);

                    // ans++ karenge
                    tempans++;
                }
                else{
                    // means current 1 ko add karne se big value milegi, nai lena h

                    // yaha se jitne 0s mil sakte hai add karo and then return the ans
                    tempans+=zero[i];
                    break;
                }
            }
        }

        return max(ans,tempans);
    }
};