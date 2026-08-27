class Solution {
public:
    // initially ans is empty string
    string ans = "";

    bool solve(string& curr, vector<int>& freq, string& target, int i,
               bool greater) {
        // base case if i out of bound ho jaaye
        if (i == target.size()) {
            // kya yaha aake jo current banaya apan ne vo greater hai?
            if (greater) {
                // hai greater, mark as ans and return true
                ans = curr;
                return true;
            }
            // we here means nai hai greater
            return false;
        }

        // current index par characters rkhne ka try karo

        // idea is agar greater ban gaya hai already to yaha ab smallese sequence me characters daalo do that just greater than target bane
        for (char ch = 'a'; ch <= 'z'; ch++) {
            // agar freq hi nai hai toh continue karlo
            if (freq[ch - 'a'] == 0)
                continue;

            // agar abhi tak matching karate jaa rahe hai and abhi tak ka string
            // greater nai hua hai, toh apan current character ko nai le sakte
            // if it is smaller than target[i], since if target[i]=g and humne
            // yaha agar b laga diya toh curr will be smaller than target which
            // we dont want, hence in such case continue too
            if (greater == false && ch < target[i]) {
                continue;
            }

            // we here means current character rakh sakte hai

            // DO
            // current char daal do
            curr.push_back(ch);
            // ek char used hai freq update karo
            freq[ch - 'a']--;

            // EXPLORE

            // kya current character rakhne se greater ban gaya target se?, for
            // that we check if ch>target[i], if true then greater ban gaya hai
            // yehi par 

            // also check ki kahi pehle se greater toh nai tha?
            bool isgreat=greater || (ch>target[i])  ;
            // in dono cases me se ek me bhi true hai means greater ban chuka hai
            
            // current character rakhne se aage solution banega kya
            // current par greater bana ki nai target se bhej dena
            if (solve(curr, freq, target, i + 1, isgreat)){
                // we here means current character rakhne se aage se true aayega, means ans is found, in such case return true yehi se
                return true;
                // since aage check karne ka need naii
            }

            // we here means true nai aaya

            // UNDO kardo
            // curr se pop kardo and freq badha do
            curr.pop_back();
            freq[ch-'a']++;

        }

        // sab khatm hone ke baad bhi nai mila toh false bhej dena
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        // ok toh logic is simple. apan permutation direct nai nikal sakte, and
        // since we need just greter wala, hence apan characters target se match
        // karenge jaha tk match ho, jaha match nai hua, waha bigger character
        // daal kar bana denge string

        // itll make sense trust me, simple do, explore, undo banana hai

        // current character daal sakte ki nai dekh lena

        // firstly we need freq array of s
        vector<int> freq(26, 0);

        for (auto it : s) {
            freq[it - 'a']++;
        }

        string curr = "";

        // funcn bula lo, isme we send current string jo bani abhi tak matching
        // kara kar, send freq array,target bhej denge and target ke konse index
        // se match karana hai start me vo bhej denge(0 at start), and boolean
        // bhej denge to denote ki curr string target se greater ban rhi ki nai
        solve(curr, freq, target, 0, false);

        // ans update hua hoga bhej do

        return ans;
    }
};