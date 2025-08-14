class Solution {
public:
    string largestGoodInteger(string num) {
        // ez, saare size 3 ke substrings nikal kar chk krlo konsa biggest hai,
        // agar 3 values same hai contigous means its a possible ans, update kar
        // dena

        string ans = "";
        int n = num.size();

        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                // we here means current substring is possible ans

                // agar previous ans se better hai toh update kardo

                if (ans=="" || ans[0]<num[i]){
                    // means current wala number is better than previous ans, update ans
                    ans=num[i];
                    ans+=num[i+1];
                    ans+=num[i+2];

                }
            }
        }

        return ans;
    }
};