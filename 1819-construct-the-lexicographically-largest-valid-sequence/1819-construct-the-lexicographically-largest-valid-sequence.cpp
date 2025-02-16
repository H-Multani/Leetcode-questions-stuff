class Solution {
public:
    bool solve(int i, int n, vector<int>& ans, vector<bool>& used) {
        if (i >= ans.size()) {
            // means array is filled, return true
            return true;
            // pakka ans kaise??, since we were filling largest numbers first
        }

        if (ans[i] != -1) {
            // means ye posn already filled hai, move to next index
            return solve(i + 1, n, ans, used);
        }

        // we here means yaha element bharna hai, loop laga kar try kardo saare
        // values
        for (int nos = n; nos >= 1; nos--) {
            // agar ye number already used hai toh mat use karo, since 2 se
            // zyada baar nai use krna h koi bhi number ko, and since already
            // used hai toh this will be 3rd time (since jab 1st milega saath me
            // 2nd bhi laga denge apan )
            if (used[nos]) {
                // means ye no already used, continue to next number
                continue;
            }

            // we here means not used number hai, try krlo

            // backtracking step
            // TRY

            // nos value ka first instance daal diya
            used[nos] = true;
            ans[i] = nos;

            // ab ye i th banda mil gaya hai, j th ke liye 2 condns
            // EXPLORE
            if (nos == 1) {
                // means number 1 tha, j ka need nai h, explore next idx
                // directly
                if (solve(i + 1, n, ans, used)) {
                    // we here means aage explore krne se true aaya hai, means
                    // yehi apna answer hai, return true frm here, since maxm
                    // rakh rahe hai, iske aage wale elements chhote hi honge
                    // toh yaha se mila answer will be lexicographic maxm, hence
                    return true;
                }
            } else {
                // means 2 to n ka case hai, j th banda milega
                int j = ans[i] + i;
                // since need |j-i|=ans[i]

                // ab iss idx ke problems hai
                if (j < ans.size() && ans[j] == -1) {
                    // ie j should be a valid idx, and yaha par koi dusra number
                    // ni hona chahiye

                    // agar yaha hai, means j valid hai, values rakh do and aage
                    // explore karo

                    // nos value ka 2nd instance daal diya
                    ans[j] = nos;
                    // yaha used me change nai akrenge, since nos wala number
                    // already used hai, the used array was for the possible
                    // numbers we can use

                    // explore aage wale idx
                    if (solve(i + 1, n, ans, used)) {
                        // we here means aage explore krne se ans true aaya hai,
                        // means yehi apna maxm ans hai, return true frm here
                        return true;
                    }

                    // we here means explore krne se ans nai mila, toh j ko
                    // vapas revert krdo to original posn
                    ans[j] = -1;
                }
            }

            // we here means iss posn par current number(nos) nai rakh sakte
            // apan, since explore krne par har jagah false aa raha hai, toh
            // move onto the next nos value that can be put in this index

            // UNDO

            // backrtacking step:undo all changes and backtrack
            used[nos] = false;
            ans[i] = -1;
        }

        // we here means iss idx par koi bhi value rakhne se ans nai aa raha ,
        // nai toh upar se hi true return ho jata,in such case, return false,
        // since kuch nai mila yaha explore krke
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);

        vector<bool> used(n + 1, false);

        solve(0, n, ans, used);

        return ans;
    }
};