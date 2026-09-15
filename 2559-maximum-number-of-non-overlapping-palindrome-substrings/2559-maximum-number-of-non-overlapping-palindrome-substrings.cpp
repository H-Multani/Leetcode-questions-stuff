class Solution {
public:
    int n;
    vector<vector<int>> memo;
    bool isplaindrome(string& s, int i, int j) {
        while (i < j) {
            // check if char is same
            if (s[i] != s[j]) {
                // not palindrome
                return false;
            }

            // we here means yaha tak hai palindrome, update pointers
            i++, j--;
        }

        // we here means palindrome hai
        return true;
    }
    int solve(string& s, int k, int i, int j) {

        // edge case agar range ke out hai toh return 0
        if (i >= n || j >= n)
            return 0;

        // memo me hai toh yehi se bhejdo
        if (memo[i][j] != -1)
            return memo[i][j];

        // case 1
        // kya i to j wala palindrome hai
        if (isplaindrome(s, i, j)) {
            // meaning ye hai palindrome

            // yaha apne paas 3 options hai

            // option 1-> current palindrome ko count karlo and age next k
            // length(or above) explore karo, agla banda will start from j+1, se
            // k characters, which is at idx j+k
            int take = 1 + solve(s, k, j + 1, j + k);

            // option 2-> k length se bada palindrome dhundo, current palindrome
            // ko nai lo, toh current palindrome not calculated, and next
            // palindrome +1 size ka hoga, toh i to j+1 solve explore karenge,
            // since yaha current palindrome ko nai liya hence koi count nai
            // lenge
            int grow = solve(s, k, i, j + 1);

            // option 3-> current palindrome ho skta hai ki aage slide ho jaaye
            // aur extra palindromes mile k size ke hi

            // toh third option is to slide the palindrome, ie instead of taking
            // (i,j) wala palindrome, we will search for palindrome in (i+1,j+1)
            // since ho sakta hai ki apan 2 palindrome ka jagah khaa rahe ho, ie
            // jaha palindrome could be (0,i) and (i+1,j+1), waha apan ne (i,j)
            // tak ka le liya toh ab na (0,i) ban paa raha na (i+1,j+1)

            // toh iss case me slide karke explore karo ki kitne ans aa rahe
            int slide = solve(s, k, i + 1, j + 1);

            // ab yehi 3 options hai apne paas, teeno me se jaha se bhi best aa
            // jaaye bhej dena
            return memo[i][j] = max({take, grow, slide});
        }

        // we here meaning ki current wala palindrome nai hai substring

        // toh yaha bass 2 options hi hai

        // option 2-> k length se bada palindrome dhundo, current substring
        // palindrome nai hai toh nai karenge count, and next palindrome +1
        // size ka hoga, toh i to j+1 solve explore karenge, since yaha current
        // palindrome nai hai hence koi count nai lenge
        int grow = solve(s, k, i, j + 1);

        // option 3-> current substring ho skta hai ki aage slide ho jaaye
        // aur extra palindromes mile k size ke hi

        // toh third option is to slide the substring, ie instead of taking
        // (i,j) wala substring(which is not palindrome anyway), we will search
        // for palindrome in (i+1,j+1) since ho sakta hai ki apan 2 palindrome
        // ka jagah khaa rahe ho current substring leke, ie jaha palindrome
        // could be (0,i) and (i+1,j+1), waha apan ne (i,j) tak ka substring  le
        // liya toh ab na (0,i) ban paa raha na (i+1,j+1)

        // toh ye khali substring ab 2 actual palindromes ka jagah khaa raha
        // hoga, toh explore (i+1,j+1) instead

        // toh iss case me slide karke explore karo ki kitne ans aa rahe
        int slide = solve(s, k, i + 1, j + 1);

        // yaha yehi 2 cases rahenge, jaha se best ans aaye bhej do

        return memo[i][j] = max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        n = s.size();

        // ok toh edge case me TLE fatt raha hai
        // k==1 hai meaning minm 1 length ka palindrome banana hai
        // iss case me toh jitna n hai utne hi palindrome banenge best case me,
        // since bigger size ka palindrome banne ke baad bhi overall palindromes
        // ka count chahiye na apan ko toh
        // toh ye case me best ans is n
        if(k==1) return n;

        // funcn recursively solve karke le aayega

        // TLE patkega pata hai, memo bana do

        // yaha 2 things change, i and j both can be 2000 tak ka, toh bana do
        // memo
        memo.assign(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1);

        // s,k toh jayega hi, fir starting substring has to be minm length k
        // which is idx 0 to k-1, wahi bheja hai
    }
};