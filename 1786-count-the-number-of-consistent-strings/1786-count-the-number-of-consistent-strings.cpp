class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> allmpp;
        for (auto it : allowed) {
            allmpp[it]++;
        }
        int ans = 0;
        for (auto it : words) {
            unordered_map<char, int> currmpp;
            for (auto ch : it) {
                currmpp[ch]++;
            }
            bool isconsistent = true;
            for (auto ch : currmpp) {
                if (allmpp.find(ch.first) == allmpp.end()) {
                    // means current char not in allowed char wala map, this
                    // string is not consistent
                    isconsistent=false;
                }
            }

            if(isconsistent) ans++;

        }
        return ans;
    }
};