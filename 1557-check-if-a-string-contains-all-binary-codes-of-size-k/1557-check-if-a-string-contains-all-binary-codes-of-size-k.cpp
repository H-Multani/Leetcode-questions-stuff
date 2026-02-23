class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // binary code of length k is values from 0 to 2^k
        // lekin itne check karna ka need hi nahi hai apan ko alag alag

        // substring ka def bolta ki beech se element nikal nahi sakte , toh k
        // size ka substring banate jao(from s) set me daalte jao, agar end me
        // 2^k unique substrings bane toh means saare possisble binary
        // substrings ban gaye hai otherwise ans cannot be made

        unordered_set<string> subs;

        // starting frm idx 0 saare substrings nikalo of k size each
        int n = s.size();
        for (int i = 0; i < n - k+1; i++) {
            // substring nikalo of k size
            string substring = s.substr(i, k);

            // ab iss substring ko daal do set me
            subs.insert(substring);
        }

        // agar subs ka size is 2^k means all possible binary strings of length
        // k can be made out of string s, in such case reurn true

        if (subs.size() >= (1 << k))
            return true;

        return false;
    }
};