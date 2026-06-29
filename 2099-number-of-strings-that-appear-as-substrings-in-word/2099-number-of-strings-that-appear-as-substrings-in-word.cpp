class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // substr leke check kar lenge

        int ans = 0;

        for (auto it : patterns) {
            // current pattern ka size is
            int n = it.size();

            // word me har n size ka substring nikal kar dekho and compare karao
            bool found = false;
            if(n>word.size()) continue;
            for (int i = 0; i < word.size() - n + 1; i++) {
                if (word.substr(i, n) == it)
                    found = true;
            }

            if (found)
                ans++;
        }

        return ans;
    }
};