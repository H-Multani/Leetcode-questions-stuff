class Solution {
public:
    int n;
    bool solve(int idx, string pattern, string& ans, vector<bool>& used) {
        // base case,
        if (idx >= ans.size()) {
            // means ans ban chuka hai, return krdo yehi se
            cout<<ans<<endl;
            return true;
        }

        // ab current i dhundna h and uske liye apan ko i+1 wala banda dhundna
        // hai,but i+1 yaha se access nai krskte, toh i-1 se khelenge

        // start frm 1, upto n, since 1 se chalu krre hai toh jo ans milega vahi
        // smallest possible ans hoga
        if (idx == 0) {
            // idx 0 ke liye alag loop chalega, baaki ke liye alag thoda, since
            // idx 0 se i-1 nai le skte
            for (int number = 1; number <= n; number++) {
                
                // i==0 hai, yaha koi used unused ka scene nai hai

                // TRY
                used[number] = true;
                ans[idx] = (char)('0' + number);

                // EXPLORE
                if (solve(idx + 1, pattern, ans, used)) {
                    // agar yaha se kuch answer mil gaya hai true, toh yehi
                    // se true return krdo
                    return true;
                }

                // UNDO
                used[number] = false;
                ans[idx] = 'a';
                // }
            }
        } else {
            // for idx=2 onwards, idx-1 th wale bande se khelna hai apan ko ab
            for (int number = 1; number <= n; number++) {
                // current banda agar unused hai toh use krlo

                // conditions apply, pattern follow hona chahiye idx and idx-1
                // th element me
                if (!used[number]) {
                    // ye number unused hai, pattern follow krra h toh hi explore
                    // krna bss
                    if ((ans[idx - 1] > (char)(number + '0') &&
                         pattern[idx - 1] == 'D') ||
                        (ans[idx - 1] < (char)(number + '0') &&
                         pattern[idx - 1] == 'I')) {
                        // we here means i valid number hai idx th posn ke liye
                        // , use and explore further

                        // TRY
                        used[number] = true;
                        ans[idx] = (char)(number + '0');

                        // EXPLORE
                        if (solve(idx + 1, pattern, ans, used)) {
                            // we here means aage explore krne se answer mil
                            // gaya hai, ans mil gaya h toh aage chk krne ka
                            // need hi nai, yehi se return krdo
                            return true;
                        }

                        // we here means explore krne se answer nai mila, in
                        // such case, UNDO the changes for other characters
                        // UNDO
                        used[number] = false;
                        ans[idx] = 'a';
                    }
                }
            }
        }

        // we here means kahi bhi explore krke ans nai mil paya, in such case
        // return false, since nothing can be done now
        return false;
    }
    string smallestNumber(string pattern) {
        // optimal soln, simple backtracking, TRY, EXPLORE,UNDO
        n = pattern.size() + 1;

        // initially ans ko n size ka string bana do with char a as placeholder
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += 'a';

        // used vector banao
        vector<bool> used(n + 1, false);
        // n+1 since for n=4 we need nos 1,2,3,4, thoda kaam kam karna padega
        // bss

        // send the index starting, the pattern, the ans string, used bhi bhj do
        solve(0, pattern, ans, used);

        return ans;
    }
};