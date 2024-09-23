class Solution {
public:
    vector<int> t;
    int solve(int idx, string& s, unordered_set<string>& st, int len) {
        if (idx >= len)
            return 0;

        // agar iss index pr pehle aa chuke hai toh iss index ke memoization
        // vector me value -1 nai honi chahiye
        // ie agar iss idx ke liye apan ans pehle nikal chuke hai toh t[idx] me
        // value -1 nai hogi, the -1 represents ki apan current index ke liye
        // ans nai nikale hai, in such case find the ans, otherwise seedha
        // return kar do yehi se ans

        // if memo vector ke current index(idx)
        // par aa chuke hai(ie val of t[idx]!=-1) means optimal soln already stored hai hamare paas,
        // toh seedhe retrieve kar do , no need to check for the same ans again.
        if(t[idx]!=-1){
            // means ans mil chuka h pehle iss idx ke liye, return kar do seedhe
            return t[idx];
        }

        // curr char ko skip kar diya, toh vo char ab extra me ho gaya
        // hence result will be 1+(baaki string me chk karo)
        int result = 1 + solve(idx + 1, s, st, len);

        // curr char ko agar skip nai kiya, toh substring dhundo dict me
        // starting j from i th index only
        for (auto j = idx; j < len; j++) {
            string curr = s.substr(idx, j - idx + 1);
            if (st.find(curr) != st.end()) {
                // means substring curr is present
                // ir curr substring is valid and is not extra
                // ab chk karo remaining substring me if there are any extra
                // characters remaining substring starts frm j+1 th character
                auto remainingans = solve(j + 1, s, st, len);

                // ab result ka minm nikalo, since
                // ho skta hai na ki remaining substring se zyada extra
                // characters aaye and skipped character wale part se kam extra
                // characters aaye, toh in this case we take the ans with minm
                // extra characters, since wahi ans nikalvana hai
                result = min(result, remainingans);
            }
        }

        // current wale index ke liye minm ans(optimal) is stored in result, ye
        // result ke value ko send kar do to the memoization vector t, so that
        // for current index baar baar same cheek check na karna pade
        t[idx] = result;

        // in the end return jo bhi extra characters aaye hai, ie result
        return result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        // tle aa raha memoize karna padega soln ko
        // maxm length of s can be 50 so 51 size ka array lelo, for easy access

        // in each index of t we store ki current wale index ke char ko agar
        // lenge/ nai lenge toh minm ans kya aayega

        // initialize all values of t by -1
        vector<int> temp(51, -1);
        t = temp;

        int len = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        return solve(0, s, st, len);
    }
};