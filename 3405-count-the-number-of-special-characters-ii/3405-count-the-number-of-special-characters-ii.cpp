class Solution {
public:
    int numberOfSpecialChars(string word) {

        // every lowercase appears before the first uppercase, means last smol
        // ka idx< first big ka idx

        // 2 arrays lelo, first will store the last index of small character and
        // second array will store first index of capital character

        vector<int> lastsmol(26, -1);
        vector<int> firstbig(26, -1);

        for (int i = 0; i < word.size(); i++) {
            if (word[i] <= 'z' && word[i] >= 'a') {
                // smol me update karo

                // current character ka last idx mila hai update karo
                lastsmol[word[i] - 'a'] = i;
            } else {
                // big me update karo

                // current character ka bigg wala index mila hai, update only if
                // iske pehle same character ka koi idx nai aaya hai

                // like if 'A' came earlier at idx 4, then comes again at idx 8
                // then we need to store only idx 4 since that is the first
                // occurence of uppercase character

                if (firstbig[word[i] - 'A'] == -1) {
                    // means current wala idx is actually the first occurence,
                    // update kardo
                    firstbig[word[i] - 'A'] = i;
                }
            }
        }

        // ab iterate over both arrays and find best ans

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            // edge case, lowercase char hai hi nahi, in which case we skip
            // currrent character
            if(lastsmol[i]==-1) continue;
            // edge case, uppercase char hai hi nahi, in which case we skip
            // currrent character
            if(firstbig[i]==-1) continue;

            // current character ka last lowercase occurence is at lastsmol[i]
            // current character ka first uppercase occurence is at firstbig[i]

            // ab agar ye last lower wale ka idx< first upper ka idx, means its
            // special character in which case count karlo

            if (lastsmol[i] < firstbig[i])
                ans++;
        }

        return ans;
    }
};