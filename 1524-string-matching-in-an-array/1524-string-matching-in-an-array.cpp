class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // ezpz, har string lo, check karo kya vo baaki words me aa rha hai ki
        // nai, agar kahi bhi aa rha hai, toh ans me daal do, nai toh mat dalo

        // and constraints kamm hai toh brute force bhi chalega
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            // curr string is
            string curr = words[i];
            int curr_n = curr.size();
            // ab words array me baaki ke saare strings me jao, jo ki current
            // string nai hai
            bool curris_ans = false;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // means ye new word hai, check karo if ye new word ke andar
                    // kahi current string aa rha hai kya ??

                    // curr_n ke length ka saara substrings nikal lo, ek ek se
                    // compare karao, agar kahi same mil gaya toh ans me daal
                    // dena

                    // agar word ka size hi curr_n se kam hai toh ans ban hi nai
                    // sakta, continue to next word
                    if(words[j].size()<curr_n) continue;
                    for (int k = 0; k < (words[j].size()) - curr_n+1; k++) {
                        // currn size ka substring starting at k
                        if (words[j].substr(k, curr_n) == curr) {
                            // means curr word iss word[j] ka substring hai,
                            // means ye ek answer hai, ans true kardo
                            curris_ans = true;
                            break;
                        }
                    }
                }
            }

            if (curris_ans)
                ans.push_back(curr);
        }

        return ans;
    }
};