class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // start and end index of each character store karne ke liye vector,
        // like har character start konse idx par hora and end konse idx par
        // hora

        // start valid hone ke liye initially -1
        vector<int> start(26, -1);
        // end toh sabka worst case me 0 hi banega
        vector<int> end(26, 0);

        // vector to check if current character wala substring is valid to be
        // taken or no, like if we choose ki char x ka substring banao, aur uss
        // substring me baaki characters aaye lekin fully cnt nai aaye, ie x
        // wale substring me 'a' is present lekin saare 'a' nai hai present, toh
        // vo x wala substring nai le sakte invalid hai vo, toh vai store karne
        // ke liye vector
        vector<bool> isvalid(26, true);

        // ans wala vector
        vector<string> ans;

        // iterate over s and start and end bhar do
        for (int i = 0; i < n; i++) {
            // current char ka idx is
            int idx = s[i] - 'a';

            // start me update kardo
            if (start[idx] == -1) {
                // means koi start idx nai bhara tha, bhar do
                start[idx] = i;
            }

            // end wala to normally update ho jayega
            end[idx] = i;
        }

        // ab har character par jao and dekho konse konse le sakte
        for (int c = 0; c < 26; c++) {
            // agar current character c ka start is -1 meaning ye character
            // doesnt exist in string, in which case continue to next character
            if (start[c] == -1)
                continue;

            // we here means character exist karta hai, ab iss par start to end
            // iterate karo, s wale indexes par iterate karenge

            for (int i = start[c]; i <= end[c]; i++) {
                // s me idx i par character is s[i],
                // iska index of character is s[i]-'a'
                // this character can be anything , toh agar current character
                // ko include karna hai range me toh iss character ke saare
                // occurences bhi iss(start[c] to end[c]) wale range me hone
                // chahiye

                // like suppose apan c=0-> 'a' wala ka subarray le rahe hai, and
                // range ke andar we find character 'x', tohh agar ye 'a' wala
                // range valid ho uske liye 'x' ke saare occurences iss 'a' ki
                // range me hone chahiye, to check that iss 'x' ka start nikalo

                // ab agar start of this character(x) is smaller than start of
                // current character('a'), means 'x' ke kuch occurences 'a' ki
                // range se bahar hai, meaning current wala 'a' wala subarray is
                // not valid, vahi check karre

                // here s[i]-'a' -> 'x' ka idx
                // c-> 'a' ka index
                if (start[s[i] - 'a'] < start[c]) {
                    // we here means current range is not valid
                    isvalid[c] = false;

                    // since valid hi nai hai range toh invalid mark karke move
                    // out of loop to next character
                    break;
                }

                // we here means 'x' ke saare occurences 'a' wali range me hai,
                // toh valid hai for now

                // lekin ab possible hai ki 'a' ka range jaha khatam hora, waha
                // 'x' ka range na khatam ho

                // if 'a' ka range ends at idx 5 and 'x' ka range ends at idx 8,
                // then apan current bande ki range ko badha kar 8 tak le jaa
                // sakte hai, since 5 tak toh valid tha hi, 8 tak le jaane me
                // pura valid ho jayega toh kya dikkat

                // toh "a" ka end range update kardo, to include 'x' ka range as
                // well
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }

        // ab saare valid and invalid waale character ke ranges update kar chuke
        // hai apan along with ki current character ka valid range konsa hai

        // last substring ka starting point store karlo
        int lastTakenStart = INT_MAX;

        // ab apan rt to left traverse karenge and ans banaenge
        for (int i = n - 1; i >= 0; i--) {
            // currently konse char ko dekhre s me, s[i]
            // uska index is s[i]-'a'

            int c = s[i] - 'a';

            // current char ka range valid bhi hai?, invalid hai toh aage badhao
            if (!isvalid[c]) {
                continue;
            }

            // we here means valid hai

            // check if current idx i is starting point for range of this
            // character, agar hai then check if iss character ka end idx is
            // lesser than last taken substring ke start ka, since agar hua that
            // means ki current wala substring non overlapping hai peeche wali
            // substring se, matlab ans me le sakte
            if (i == start[c] && end[c] < lastTakenStart) {
                // we here means, non overlapping hai substring, lelo ans me

                ans.push_back(s.substr(i,end[c]-i+1));
                // i se start karke length jitna substring lelo

                // current ka start update to lastTakenStart , since aage wale substring ke liye ye wala taken substring ka start will be considered
                lastTakenStart=i;
            }
        }

        return ans;
    }
};