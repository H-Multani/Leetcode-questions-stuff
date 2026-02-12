class Solution {
public:
    int longestBalanced(string s) {
        // too small constraints, brute force kar sakte

        // lowercase english chars only toh map le sakte freq wala without
        // problems

        // ek ans lelo which will store biggest substring length
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // map lelo yehi since andar fir se i to j ke liye baar baar kon
            // banaye map and checking, toh bahar bana liya, andar bass include
            // karke check karenge if freq are all same
            unordered_map<char, int> mpp;

            for (int j = i; j < n; j++) {
                // current char ko include karo map me
                mpp[s[j]]++;

                int freq = -1;


                // ek valid boolean lelo so that galat wale substrings ko
                // consider na kare apan for ans
                bool valid = true;

                // iterate over the map and check if freq of all characters are
                // same

                for (auto it : mpp) {
                    // it.second is freq
                    if (freq == -1) {
                        // means first element hai uska freq store kardo freq
                        // me, isko aage baaki se compare karenge
                        freq = it.second;
                        continue;
                    }

                    if (it.second != freq) {
                        // means [i...j] wale substring me chars have different
                        // frequencies , ie this substring isnt valid
                        valid = false;
                        break;
                    }

                }


                // agar substring valid hai toh ans ka length update karlo
                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};