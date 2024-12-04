class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // 2 pointer approach laga rah mai

        int i = 0, j = 0;
        // i for str1
        // j for str2

        int n = str1.size();

        for (i = 0; i < n; i++) {
            if (j < str2.size() && str1[i] == str2[j]) {
                // means subsequence ka ye character mil chuka hai, no need to
                // get any operations on this character

                // ie str2 banane ke liye ye character directly use kar lenge,
                // isko transform krne ka need nai padega, toh dono i and j ptrs
                // aage badha do, since j th wala char ke liye corresponding i
                // th wala char mik chuka h, move to next char in str2
                j++;
                // no i++ since i++ for loop krke de rah hai

                // ye i th char used hai already, continue to next character in
                // str1
                continue;
            }

            // if current i th char is 'a' and j th char is 'b', then this j th
            // char can be made by transforming the i th char to +1(accd to
            // question), yehi karna hai
            // toh 1 condn if str1[i]+1==str2[j]
            // ishi condn ka edge case, if str1[i]=='z' and str2[j]=='a', edge
            // case hai to be considered
            if (j < str2.size() && (str1[i] + 1 == str2[j] ||
                                    (str1[i] == 'z' && str2[j] == 'a'))) {
                // we here means
                // str2 banane ke liye ye(i th) character use kar lenge,
                // isko transform krna ka need padega,lekin use kar sakte no
                // worries

                // transform ke baad j th char will be settled, ie iss
                // j th char ke liye current i th char(after transform) chal
                // jaega, hence move onto the next j th character in line
                j++;

                // also move to the next i th character, since current i th char
                // already used for current j th character(before the j++)
            }
        }

        // agar saare j wale characters settle nai ho paaye means str2 cant be
        // made subsequence of str1 after atmost 1 operation, in such case
        // return false
        if (j < str2.size())
            return false;

        return true;
    }
};