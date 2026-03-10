class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // t[zero+1][one+1][2] ka banana hai
        vector<vector<vector<int>>> t(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

        // base case likh dena before bottom up

        for (int i = 0; i <= min(zero, limit); i++) {
            t[i][0][0] = 1;
            // kyuki this is, agar apan ke pass i 0s available hai, and zero 1s
            // available hai and we start from 0

            // aisa hamesha 1 case rahega since hamesha string will be like
            // 000...i values, like 0,00,000,0000,....
            // toh aise cases hamesha ek hi honge, same logic with those cases
            // starting with 1
        }

        for (int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        // bottom up wala loop chala do using i and j, i will be for the 0s
        // count, and j will be for 1s count

        for (int i = 0; i <= zero; i++) {
            // i is for no of 0s
            for (int j = 0; j <= one; j++) {
                // edge case- agar i ya j dono me se koi bhi 0 hua toh continue
                // kar dena since aage apan i-1 and j-1 se khel rahe
                if (i == 0 || j == 0)
                    continue;

                // j is for no of 1s

                // yaha par pehle for loop likhte the ab formula likhenge

                // first wale for loop ko replace karne wala formula
                t[i][j][1] = (t[i][j - 1][0] + t[i][j - 1][1]) % mod;

                // isme ek subtraction aur karna jab valid ho tab
                if (j - 1 >= limit) {
                    t[i][j][1] =
                        (t[i][j][1] - t[i][j - limit - 1][0] + mod) % mod;
                    // we do +mod since -ve bhag sakta hai value, toh usko sahi
                    // range me laane ke liye karre ye
                }

                // second wale for loop ko replace karne wala formula
                t[i][j][0] = (t[i - 1][j][0] + t[i - 1][j][1]) % mod;

                // isme ek subtraction aur karna jab valid ho tab
                if (i - 1 >= limit) {
                    t[i][j][0] =
                        (t[i][j][0] - t[i - 1 - limit][j][1] + mod) % mod;
                    // we do +mod since -ve bhag sakta hai value, toh usko sahi
                    // range me laane ke liye karre ye
                }
            }
        }

        // end me ans will be
        // t[zero][one][0]-> kitne zero the, kitne 1 the, starting from 0
        // t[zero][one][1]-> kitne zero the, kitne 1 the, starting from 1
        return (t[zero][one][0] + t[zero][one][1]) % mod;
    }
};