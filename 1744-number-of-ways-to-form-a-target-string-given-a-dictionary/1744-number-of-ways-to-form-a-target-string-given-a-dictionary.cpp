class Solution {
public:
    long long MOD = 1000000007;
    long long solve(int i, int j, vector<vector<int>>& freq, string& target,vector<vector<int>>& memo) {
        // base case
        // agar i reached the end of target
        if (i == target.size()) {
            // means apan ne target bana liya hai, this is a possible answer,
            // return 1 to indicate ki bana liya hai target ko successfully
            return 1;
        }
        if (j == freq.size()) {
            // means target banane se pehle hi indexes khatam ho gaye, in such
            // case target is not made, hence return 0
            return 0;
        }

        // agar memo me already hai toh yehi se return kardo ans
        if(memo[i][j]!=-1) return memo[i][j];

        // ab current idx is j, ie words array ke har word ke j th idx par
        // iterate karna hai apan ko ab, to search the character...

        // search the character target[i]
        char need = target[i];

        // ab 2 options hai apne paas,
        // option 1, search for the character in current index j, for that sabse
        // pehle dekho ki needed char hai bhi sahi current idx me ki nai , ie
        // chek if curr char ka freq >0 hai ki nai, aagr nai hai means reqd char
        // doesnt exist at this idx, in such case yaha take option nai chalega

        // so agar char doesnt exist in such cse freq[j][need-'a'] will give us
        // 0, and if not it will give us ki kitne baar needed char mila hai, for
        // eg if freq[j][need-'a']=4 means ki 4 options hai apne paas current
        // char lene ke j th idx me, hence instead of searching all 4 paths, we
        // only search 1 path, and usse jo ans aayega, multiply that by 4, to
        // get total paths, since apne paas 4 char the, koi bhi leke chalenge
        // toh same path 4 baar chalna padega, which give tle, hence instead of
        // that, apan 1 baar bas explore karke ans nikalenge and multiply that
        // by 4 to get total no paths
        // ab curent char target ka mil chuka hai toh search for the next
        // character, ie i+1, also current idx par dhund chuke toh bas ab aage
        // hi dhund skte hai, ie j+1 se aage wale idx par hi dhund sakte hai
        // apan answer, yehi kiya hai
        long long take =
            freq[j][need - 'a'] * solve(i + 1, j + 1, freq, target,memo);

        // option 2, dont search for needed character in current index j, since
        // ho sakta hai aage wale idx me mil jaaye target,to explore this path,
        // simply iterate in the next idx
        long long donttake = solve(i, j + 1, freq, target,memo);
        // i stay same since current idx me needed char nai dhunde, toh same
        // char aage wale idx(j+1) me dhundenge

        // ab return kardo ans
        // ans will be take + donttake
        // take->reqd char current idx par lene se kitne baar target bana sakte
        // hai
        // donttake->reqd char current idx par NAI lene se kitne baar target
        // bana sakte hai

        // ans can be large, mod karke bhejna
        // ans ko memo me update kardo
        memo[i][j]=(take + donttake) % MOD;
        return (take + donttake) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        // kitne length ka hai har word
        int n = words[0].size();

        // freqyency dictionary banao
        vector<vector<int>> freq(n, vector<int>(26, 0));
        // freq[i][0] batayega ki words array ke har word ke i th idx me 'a' ka
        // freq kya hai
        // freq[i][1] batayega ki words array ke har word ke i th idx me 'b' ka
        // freq kya hai...and so on,

        // populate kardo freq array ko

        for (int i = 0; i < words.size(); i++) {
            // current word ke saare freq update kardo
            for (auto j = 0; j < n; j++) {
                // j th idx par jao, so freq[j]
                // j th idx par current word me konsa char hai (ch -'a'), uski
                // freq increase kardo
                freq[j][words[i][j] - 'a']++;
            }
        }

        // now all freq is populated

        // solve kardo and ans return kardo
        // in solve function we send (i,j,freq array,target to be made)
        // here i iterates over the target string, and j iterates over the freq
        // array

        // tle dera, memoize karo, here only i and j change hore hai, toh 2D
        // memo bana lo
        // j->freq array, maxm n size
        // i->target string, maxm m size
        int m=target.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return solve(0, 0, freq, target,memo);
    }
};