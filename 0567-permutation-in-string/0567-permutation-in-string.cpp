
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        // permutation me char ke freq doesnt change, use this
        unordered_map<char, int> s1_mpp;
        for (auto it : s1) {
            s1_mpp[it]++;
        }

        int n = s1.size();
        // apan ko s1 ke size ka substring chahiye s2 ke andar
        // so s1 ke size ka substrings leke chalo s2 me, agar mil jaaye, toh
        // return true, else if we reach end means apan ko substring nai mila
        // return false

        // chk upto s2.size -1 since n size ka har baari substring banaenge toh
        // last substring will start frm s2.size()-n wala index, hence whi tak
        // check kar rahe hai apan bas
        for (int i = 0; i <= s2.size() - n; i++) {
            string substring = s2.substr(i, n);
            // get substring starting at index i and of size n

            // substring ke saare values ek map me laga do, yehi freq directly
            // chk karenge apan

            unordered_map<char, int> substrmap;
            for (auto it : substring) {
                substrmap[it]++;
            }

            // check if both the substring wala map and s1 wala map are same, if
            // they are same, means dono me har character ka freq same mila hai,
            // ie we have found the reqd n size wala substring inside s2, in
            // such a case return true, else chec the next substring
            if (substrmap == s1_mpp) {
                // means all char and their all freq are same, means substring
                // is found inside s2, return true
                return true;
            }
        }

        // we here means no substring of size n and permutation of s1 was found
        // inside s2, in such case return false
        return false;
    }
};