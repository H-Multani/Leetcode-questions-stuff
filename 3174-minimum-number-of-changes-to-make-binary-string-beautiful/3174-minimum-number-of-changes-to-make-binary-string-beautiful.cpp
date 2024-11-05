class Solution {
public:
    int minChanges(string s) {
        // hints se dekha thoda
        // kitne bhi chahe substrings bana sakte hai as long as even length lo
        // toh easiest way is even length ka smallest substring bana do aur usme
        // chk karo kya usme flip required hai

        // toh har 2 size ke substring ko chk karo, if sahi hai(ie both 0 or
        // both 1) toh kuch nai karo, otherwise 1 operation(flip) karke sahi kar
        // do

        // har 2 size ka substring will be current char and uska adjacent char,
        // here we will take current char and uske aage wala adjacent character

        int n = s.size();

        int ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            // the substring of size 2 is s[i] and s[i+1] wale characters

            // chk if the substring is valid or not
            if (s[i] != s[i + 1]) {
                // we here means substring like "01" or "10", not valid

                // same nai hai dono characters, ie substring not valid, flip
                // required, kar do flip koi bhi 1 character ko
                ans++;
            }

            // i+2 to move directly to the next substring
            
        }

        return ans;
    }
};