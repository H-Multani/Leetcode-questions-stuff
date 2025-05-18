class Solution {
public:
    int mod = 1e9 + 7;
    void fillcols(string& curr, int i, int m, vector<string>& possiblecols,
                  char prevchar) {
        // base case, if i reach m means apni string ban chuki h m size ki and
        // its valid toh seedha possiblecols me add krdo
        if (i == m) {
            possiblecols.push_back(curr);
            return;
        }

        // ab RGB par iterate karo , konsa char curr posn par laga sakte hai
        // lagao and explore karo
        for (auto ch : {'R', 'G', 'B'}) {
            // current char is ch

            // agar ch is same as prevchar, means adjacent char same ho jayega,
            // agar ye char le liya toh, toh continue to next character
            if (ch == prevchar)
                continue;

            // we here means this char can be put in this posn in the string,
            // hence daal kar explore karlo

            // remember that aage wale ke liye curr me character add krke bhejna
            // and i increase krke bhejna, also aage wale bande ke liye prevchar
            // will be this current character ch
            string s = curr;
            s += ch;
            fillcols(s, i + 1, m, possiblecols, ch);
        }
    }

    int solve(int prevstate, int remainingcols, vector<string>& possiblecols,vector<vector<int>>& memo) {
        // base case, agar remainingcols has reached 0 means ek possible valid
        // matrix ban chuka hai, since 0 columns remain to be filled, return 1
        // to indicate that 1 valid matrix is made
        if (remainingcols == 0)
            return 1;

        // agar memo me ans hai toh return frm here
        if(memo[prevstate][remainingcols]!=-1) return memo[prevstate][remainingcols]; 

        // ab previous par apan ne konsa column state dala hai nikalo
        string prev = possiblecols[prevstate];

        // ab apan agle column me bharne wale state ke liye explore karnenge,
        // and make sure its valid with prev wala column

        // agar hai valid toh explore kar lenge and waha se nikalne wale valid
        // matrix ke count ko add kar lenge apne ans me
        int ans = 0;
        for (int i = 0; i < possiblecols.size(); i++) {
            // check if current column can be put adjacent to previous wala
            // column

            // current wala column is
            string curr = possiblecols[i];
            if (curr == prev)
                continue;
            bool valid = true;
            for (int j = 0; j < prev.size(); j++) {
                if (curr[j] == prev[j]) {
                    // means characters adjacent aa rahe hai, ie this column
                    // cant be used with previous column, explore other options
                    valid = false;
                    break;
                }
            }

            if (valid) {
                // means current column can be used with previous column, lelo
                // and explore karo, for exploration, the i will become
                // prevstate and since apan ne ye column le liya hai toh
                // remainingcols-1 bhejna aage waale remainingcols ke liye
                ans = (ans + solve(i, remainingcols - 1, possiblecols,memo)) % mod;
            }
        }

        // memo update kar denga curr ke liye
        memo[prevstate][remainingcols]=ans;

        return ans % mod;
    }
    int colorTheGrid(int m, int n) {
        // sabse pehle saare valid possible m size ke strings banao comprising
        // of RGB, if m=4 then strings can be like "RGBR" etc, and its valid
        // since none of the adjacent char are same
        // this "RGBR" will go in column 1, then search again for column 2

        // aise saare possible valid strings nikalo and store kardo ek vector me
        vector<string> possiblecols;
        // this will store all possible valid columns of the m x n grid
        // recursively fill krdo isko
        string temp = "";
        fillcols(temp, 0, m, possiblecols, 'X');
        // isme apan 5 cheez bhej rhe h, m and possiblecols toh access ke kaam
        // karega, the 0 is the no. of chars we have in string, as well as the
        // empty string, the X is for adjacent character, since i th char vaaste
        // i-1 wala and i th char shouldnt be same, and apan RGB se bharenge toh
        // X koi ke similar nai hoga toh all R,G,B will be explored

        // now that we have explored all possible valid sequence of columns, ab
        // inko bas order me jamana h and count krna h

        // loop from 0 to possiblecols.size since col 0 par apan itne saare
        // strings rakh kar start kr skte h

        // also keep count of the possible ways we have encountered

        // solve funcn gave TLE, memoize krne ka try krte h
        // 2 cheez change hori prevstate and remainingcols, toh 2D memo banao
        vector<vector<int>> memo(possiblecols.size(), vector<int>(n, -1));
        // possiblecols.size since i wahi ka idx hai and n since remaining cols
        // at max n hoga
        int ans = 0;
        for (auto i = 0; i < possiblecols.size(); i++) {
            // column 0 par curr string i daal kar explore karo kitne possible
            // ways hai and add it to ans
            ans = (ans + solve(i, n - 1, possiblecols,memo)) % mod;

            // in solve funcn we sent curr state konsa hai, ie current konsa
            // banda liya hai column me daalne ke liye(i),ye i th banda wala
            // string will be previous state, and iske aage waale states banane
            // vaaste explore karenge

            // then we sent the no of columns that need to be filled, since we
            // filled the 0 th column with curr string i, toh baaki n-1 strings
            // ko bharne vaaste explore karna
        }

        return ans;
    }
};