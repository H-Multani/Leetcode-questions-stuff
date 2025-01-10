class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // words 2 me jitne bhi char aa rhe hai, sabke frequency lelo, store
        // kara do

        // har word (in words2) ka separate frequency rahega
        vector<vector<int>> freq;

        for (auto it : words2) {
            vector<int> temp(26, 0);
            for (auto it2 : it) {
                temp[it2 - 'a']++;
            }

            freq.push_back(temp);
        }

        // okay toh ye freq par baar baar iterate karne me boht samay lagra hai
        // toh ek universal freq array banaenge, jisme bataenge ki kam se ka har
        // char kitni baar hona chahiye to make sure ki vo word aa jaaye
        // like for wa wala testcase, we need {l:1,o:1} for words2[0] and
        // {e:1,o:1} for words2[1], and soo onn, toh agae overall freq banaenge
        // toh itll be like, {l:1,o:1,e:1}, ye freq minm chahiye honge answer
        // vaaste, yehi banao, baar baar iteration se bachenge isme
        vector<int> overall(26, 0);
        for (auto it : freq) {
            for (int i = 0; i < 26; i++) {
                overall[i] = max(overall[i], it[i]);
            }
        }

        // ab jiss bhi word me ye saari frequency rahengi(words1 ke), vo saare
        // words answer rahenge, toh un words ko daal dena bss
        vector<string> ans;

        for (auto it : words1) {
            // current word ka freq array banao
            vector<int> currfreq(26, 0);
            for (auto it2 : it) {
                currfreq[it2 - 'a']++;
            }

            // ab agar currfreq me character ki frequencies freq array ke har
            // word ke frequency barabar ya zyada hai toh current word answer
            // hai, else nai

            // basically, freq array me har word ka frequency hai(words2 array
            // ke)

            // this currfreq waali frequencies, should be barabar ya greater
            // than frequencies of each word of word2(wa wala testcase padh na
            // aa jaega samajh me)
            bool curr = true;

            for (int i = 0; i < 26; i++) {
                if (currfreq[i] < overall[i]) {
                    curr = false;
                    break;
                }
            }

            if (curr) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};