class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> mpp;
        // to store freq of char, this will take max size of 26

        // set to store the strings already made, atmost 676 strings can be
        // made, size 3 palindromic strings, since _,_,_, 1 st and 3rd char has
        // to be same, and middle can be any character, toh 26*26, since 26(for
        // 1st and 3rd char) and 26(for 2nd char)
        set<string> st;

        vector<int> indexes(26, -1);

        // ab string par iterate kardo
        for (auto i = 0; i < s.size(); i++) {
            char it = s[i];
            // curr char ko include karo
            mpp[it]++;

            // agar freq>=2 hai toh baaki strings ban sakti hai
            if (mpp[it] >= 2) {
                // means palindromic strings can be made with this character

                string temp = "";
                // agar curr char ka freq 3 hai toh isse hi pehla string bana do
                if (mpp[it] >= 3) {
                    temp += it;
                    temp += it;
                    temp += it;

                    // string ban gaii, like "aaa" or "fff", set me daal do,
                    // since ho sakta hai yehi string aur 50 baar aaye aage wale
                    // iterations me, lekin count ek baar hi karna hai apan ko
                    st.insert(temp);
                    // temp khali kardo for new strings to be made
                    temp = "";
                }

                // ab baaki characters se jo string banne the vo bana do
                // like "aba", "cjc" etc

                // now iterate over the rest of the characters
                for (auto ch : mpp) {
                    // curr char already consider kar chuke hai, toh uske alava
                    // saare char nikalo
                    if (ch.first != it) {
                        // new char, temp me daalo, string banao, set me add
                        // karo

                        // agar new char ka most recent idx> most recent idx of
                        // it, tabhi consider karna else nai consider karna ,
                        // most outer wale for loop ke end me likha hai kyuu
                        if(indexes[ch.first-'a']<=indexes[it-'a']) continue;

                        // it ko temp me daalo pehle
                        temp += it;
                        // new char ko temp me daalo
                        temp += ch.first;
                        // temp complete karke size 3 palindrome banao, like
                        // it+newchar+it, like "aba" type thing
                        temp += it;

                        // abb iss new string ko set me push kardo, since it
                        // needs to be considered only once
                        st.insert(temp);

                        // revert temp to original
                        temp = "";
                    }
                }
            }
            // problem:eg 3 me, last wale "a" par pahuchenge toh map me "b" ke
            // saath saath "c" bhi hoga which will give 2 strings like "aba" and
            // "aca" lekin "aca" is not a valid answer, toh usse bachne ke liye,
            // we also store the most recent index jaha par curr char(it) mila
            // tha, and agar uss idx ke aage hai map ka char, toh banalo string,
            // nai toh nai banao, like for last wala "a" in eg3, previous "a" ka
            // idx is 4, and "b" ka recent idx is 5, and "c" ka recent idx is 2,
            // hence "c" nai lenge apan

            // and after all the calculation, "a" ka recent idx yaha update
            // kardnge, before moving to next char in s

            // now this idx becomes recent idx of curr character
            indexes[it - 'a'] = i;
        }

        // now all the strings made are stored on the set, set ka size will be
        // the no of unique strings that could be made, yehi ans hai, return
        // kardo
        return st.size();
    }
};