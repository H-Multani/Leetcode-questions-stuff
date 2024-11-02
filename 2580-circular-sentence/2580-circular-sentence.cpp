class Solution {
public:
    bool isCircularSentence(string sentence) {
        // saare words vector me laga do ek
        vector<string> sent;
        string curr = "";
        for (auto it : sentence) {
            if (it != ' ') {
                curr += it;
            } else {
                sent.push_back(curr);
                curr = "";
            }
        }
        sent.push_back(curr);

        int n = sent.size();
        for (int i = 1; i < n; i++) {
            // previous word ka last word ka length
            string prev = sent[i - 1];
            int previdx = prev.size() - 1;

            // jo condn hai chk karvate chalo
            // ie chk if prev word ka last char same as current word ka first
            // char
            // agar nai h means circular nai h sentence, return false
            if (sent[i - 1][previdx] != sent[i][0])
                return false;
        }

        // one last time, check if last word ka last char same as first word ka
        // first char, agar nai h toh return false

        // these are i/p sentence ka first and last character, since constraints
        // me h, no trailing and leading spaces present
        if (sentence[0]!=sentence.back()) return false;

        return true;
    }
};