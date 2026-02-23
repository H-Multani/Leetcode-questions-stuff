class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // binary code of length k is values from 0 to 2^k
        // lekin itne check karna ka need hi nahi hai apan ko alag alag

        // substring ka def bolta ki beech se element nikal nahi sakte , toh k
        // size ka substring banate jao(from s) set me daalte jao, agar end me
        // 2^k unique substrings bane toh means saare possisble binary
        // substrings ban gaye hai otherwise ans cannot be made, since 2^k se
        // zyada binary substrings possible hi nahi hai of length k, toh agar
        // ban gaye matlab s ke substrings se k length ke saare binary strings
        // bana sakte hai

        unordered_set<string> subs;

        // starting frm idx 0 saare substrings nikalo of k size each
        int n = s.size();
        for (int i = 0; i < n - k + 1; i++) {
            // substring nikalo of k size
            string substring = s.substr(i, k);

            // ab iss substring ko daal do set me
            subs.insert(substring);
        }

        // agar subs ka size is 2^k means all possible binary strings of length
        // k can be made out of string s, in such case return true

        // this works since k size ke total 2^k binary strings ban sakte hai, ab
        // apan agar k size ka har possible substring nikal kar rakh le from s
        // toh ye hoga ki apne paas k length ke 2^k unique substrings available
        // hai, that can only mean one thing ki string s can be used to make all
        // possible substrings of length k, sinnce maxm possible 2^k strings ban
        // sakte the of k size, aur apan ne same 2^k unique substrings bana diye
        // hai from all k length substrings of s, toh that means all possible
        // strings of length k can be made from substrings of s, in such case
        // return true

        // 2^k karne ka ez tareeka 1<<k, ie 1 leftshift k times,
        if (subs.size() == (1 << k))
            return true;

        // we here means subs me kam elements hai ie all possible binary strings
        // of k size cannot be made by substrings of s, in such case return
        // false
        return false;
    }
};