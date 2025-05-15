class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        // toh basically 0101/1010 wala pattern banana hai idx ke saath and unn
        // idx ke corresponding wale words ko ek vector me daal kar return krna
        // h

        // toh ke kaam karo 0101.. wala pattern banao pehle toh, then 10101....
        // wala pattern banao, then jo maxm size ka aayega uske idx utha lena
        // words se

        int n = words.size();

        // to store 010101... pattern wale idx
        vector<int> zero;
        // to store 10101.... pattern wale idx
        vector<int> one;

        // first element daal do
        for (int i = 0; i < n; i++) {
            if (groups[i] == 0) {
                zero.push_back(i);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (groups[i] == 1) {
                one.push_back(i);
                break;
            }
        }

        // agar dono me se koi ka bhi size agar 0 hai means saare elements same
        // hai return first word, like if one.size()==0 means groups array me
        // iterate krne par ek bhi 1 nai mila, ie saare 0 bhare pade h groups
        // array me, toh maxm alternationg aubsequence banega of size 1(since 0
        // ke baad koi 1 nai mil rha) toh words[0] return kr denge

        if (zero.size() == 0 || one.size() == 0)
            return {words[0]};

        // we here means 0101 wala pattern ban sakta hai bana do

        // 010101 wala pattern banao pehle toh
        for (int i = zero[0] + 1; i < n; i++) {
            // agar last wala banda 0 hai toh 1 dhundo and vice versa
            // mil jaaye toh daal dena seedha
            if (groups[i] != groups[zero[zero.size() - 1]]) {
                // we here means zero array me last wala banda current bande ke
                // same nai hai ie if last banda (groups[zero[zero.size -1]]) is
                // 0 curr banda is 1 and vice versa, means alternating
                // subsequence ban sakta hai add krdo idx ko zero wale array me

                // index daal do zero array me
                zero.push_back(i);
                // p.s. all this zero[zero.size -1] is since zero array stores
                // indexes of elements, zero array ka last wala index nikal kar
                // groups array me uss idx par jayenge toh 0 ya 1 milega
            }
        }

        // ab apan ke paas 01010.. wala pattern banane wala indexes mil chuke
        // hai, toh if zero array={2,4,6,8,14} means inn idx par jayenge toh
        // 0,1,0,1 wala pattern banega ie 0 at idx 2, 1 at idx 4,0 at idx 6,1 at
        // idx 8,0 at idx 14, etc

        // toh alternating wala subsequence ban gaya hai 0101.. wale pattern ka,
        // ab same cheez 10101.. wale pattern ka banao
        for (int i = one[0] + 1; i < n; i++) {
            if (groups[i] != groups[one[one.size() - 1]]) {
                one.push_back(i);
            }
        }

        // ab dono me se jo bada pattern bana rha hai vo lenge
        vector<string> ans;

        if (zero.size() > one.size()) {
            // means 0101.. wala pattern bada ban rha hai toh vahi banao

            // ab ye jo idx store kiye hai inn saare idx par jao words wale
            // array me jo strings hai ans me daal do

            for(auto idx:zero) ans.push_back(words[idx]);
        }
        else{
            // means 10101.. wala pattern bada banra h vahi bana do

            for(auto idx:one) ans.push_back(words[idx]);
        }

        return ans;
    }
};