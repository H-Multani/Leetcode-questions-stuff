class Solution {
public:
    int n;
    vector<vector<int>> memo;
    bool solve(int i, int cnt, string& s) {

        // agar cnt<0 means closing brackets zyada hai open brackets se, string
        // isnt valid, return false
        if (cnt < 0)
            return false;
        // base case, agar end par pahuch gaye toh
        if (i == n) {
            // agar cnt is 0 means string is valid, return true, otherwise false
            if (cnt == 0)
                return memo[i][cnt]=true;
            return memo[i][cnt]=false;
        }

        // memo me hai toh bhej do ans
        if(memo[i][cnt]!=-1) return memo[i][cnt];

        bool ans = false;
        // agar '(' hai toh aage badha do cnt +1 karke, since open bracket se
        // cnt badhega
        if (s[i] == '(')
            return memo[i][cnt]=solve(i + 1, cnt + 1, s);
        // agar ')' hai toh aage badha do cnt -1 karke, since close bracket se
        // cnt kam hoga
        if (s[i] == ')')
            return memo[i][cnt]=solve(i + 1, cnt - 1, s);

        // we here means star hai
        // yaha 3 cases honge

        // case 1, replace * with open bracket, for that cnt badha kar bhejo
        ans = ans | solve(i + 1, cnt + 1, s);
        // case 2, replace * with close bracket, for that cnt kam kar ke bhejo,
        // isse cnt can become -ve, ye case alag se handle kiya upar
        ans = ans | solve(i + 1, cnt - 1, s);
        // case 3, replace * with empty string,iss case me i aage badhega bass, cnt remains same since koi bracket nikala ya add nai kiya
        ans = ans | solve(i + 1, cnt, s);

        return memo[i][cnt]=ans;
    }
    bool checkValidString(string s) {
        // DP use karlo, check if current * par '(', ')' , '' me se konsa laga
        // sakte, take nottake type banega but with 3 cases banenge one for each
        // option

        // and me agar ek bhi valid aaya toh ans is true

        // stack lagane ka need nai hai yaha as such, since stack me bas ek hi
        // char push karre, better to keep a counter, this will keep count of
        // open brackets ie (

        // open brackets will make the count higher
        // close brackets will make the count lower
        // star brackets will make the count lower/higher/same based on
        // condition

        n = s.size();

        // TLE dega, DP banana padega, 2 things change here, i and cnt, i can be upto n and cnt can be n+1 too, when saare are open brackets
        memo.resize(n+1,vector<int>(n+1,-1));

        // start at idx 0, initial count 0, string s
        return solve(0, 0, s);
    }
};