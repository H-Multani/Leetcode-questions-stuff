class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        // jo likha hai vahi karlo

        string ans = "";

        for (auto it : words) {

            // score nikalo
            int ttl = 0;

            for (auto ch : it) {
                ttl += (weights[ch - 'a']);
            }

            // ttl ka modulo karlo 26 se

            ttl = ttl % 26;

            // ab agar ttl=0, we add 'z' to the ans
            // agar ttl=1, we add 'y' to the ans
            // agar ttl=2, we add 'x' to the ans
            // ...
            // agar ttl=i, we add ('z'- i) th character to the ans
            
            ans=ans+((char)('z'-ttl));
        }

        return ans;
    }
};