class Solution {
public:
    string res = "";
    bool issubseq(string& s, string& sub, int k){
        int i=0,j=0;
        int L=sub.length();
        int n=s.length();

        while(i<n && j<k*L){
            if(s[i]==sub[j%L]){
                // matching char mil gaya, next char par jao
                j++;
            }

            i++;
        }

        // agar j=k*l means saare char mil gaye, return true
        return j==k*L;
    }
    void backtrack(string& s, string& curr, vector<bool>& canuse,
                   vector<int>& reqfreq, int k, int maxlen) {
        // base case
        if (curr.length() > maxlen)
            return;
        // curr ka bigger length h res se toh update krdo
        // OR
        // curr ka same length hai res ke lekin lexicographichal bigger h curr
        // agar toh update krdo AND subsequence hona chahiye
        if ((curr.length() > res.length() ||
            (curr.length() == res.length() && curr > res)) && issubseq(s,curr,k)) {
            // update res
            res = curr;
        }

        // saare subsequence generate krne ka koshish karo
        for(int i=0;i<26;i++){
            // agar curr char ko nai use krskte toh mat karo, ya freq=0 hai toh mat use karo
            if(canuse[i]==false || reqfreq[i]==0) continue;

            // we here means curr char ko use kar sakte h
            char ch=i+'a';

            // normal backtracking

            // DO
            // curr char ko add karo curr string me
            curr.push_back(ch);
            // char used, freq kam karo
            reqfreq[i]--;
            // EXPLORE
            backtrack(s,curr,canuse,reqfreq,k,maxlen);

            // UNDO
            // jo char dala th remove karo
            curr.pop_back();
            // freq update kardo
            reqfreq[i]++;

        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();

        int freq[26] = {};

        for (auto it : s) {
            freq[it - 'a']++;
        }

        // konse char le sakte hai nikalo
        vector<bool> canbeused(26, false);
        // jo char le sakte hai uska har subsequence me at max kitne freq use
        // kar skte h
        vector<int> reqdfreq(26, 0);

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canbeused[i] = true;
                // atmost this can be used in a subsequence
                reqdfreq[i] = freq[i] / k;
            }
        }

        // maxm length possible of overall aubsequence
        int maxlen = n / k;

        // string curr leleo,whci will generate subsequence
        string curr;

        // backtrack krke saare subsequence nikalo
        backtrack(s, curr, canbeused, reqdfreq, k, maxlen);
        // backtracking me hi result update krdenge

        return res;
    }
};