class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // simple enough, saare words me se prefix nikalo pref ke size ka,jitne
        // prefix same as pref un sabke liye ans++
        int ans = 0;

        for (auto it : words) {
            if (it.size() < pref.size())
                continue;

            // find prefix of length pref.size(), from current word, agar this
            // prefix same as pref, means pref is a prefix to this word, ans+1
            // kardena
            if (it.substr(0, pref.size()) == pref)
                ans++;
        }

        return ans;
    }
};