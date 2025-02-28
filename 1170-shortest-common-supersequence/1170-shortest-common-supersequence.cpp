class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // pura code khud se banao, recursion+memo wala likhna hai likh do lekin
        // abhi maine yaha nai likha hai

        int m = s1.size(), n = s2.size();

        // bottom up wala vector banao
        vector<vector<int>> memo(m + 1, vector<int>(n + 1));

        // memo[i][j] means shortest common supersequence of length i(of s1) and
        // j(of s2) respectively an iterate kardo
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < n+1; j++) {
                // bottom up waka logic likh do ab

                // agar dono me se ek bhi idx 0 par hai toh bache wale idx
                // seedhe string size me add kardo
                if (i == 0 || j == 0) {
                    // agar i=0 hua toh j add hoga and agar j=0 hua toh i add
                    // hoga
                    memo[i][j] = i + j;
                }
                // agar dono string ke idx me common char hai toh ek baar add
                // karo bass
                else if (s1[i-1] == s2[j-1]) {
                    // +1 to add the character once
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                    // then solve funcn me we used to visit the (i-1,j-1), since
                    // i and j par common char hai toh ek baar add karne ke baad
                    // dono idx ko aage badha dete the apan
                } else {
                    // yaha 2 cases hote the, ya toh s1 se character leke
                    // dalenge, ya s2 se char leke daalenge, dono case me 1 char
                    // dalega hi dalega, hence +1 karenge yaha par bhi
                    memo[i][j] = 1 + min(memo[i - 1][j], memo[i][j - 1]);
                    // ab 2 cases kaise hote the ki agar current char s1 se liya
                    // hai toh aage wale ke liye i-1 bhejenge, and agar current
                    // char s2 se liya hai toh j-1 bhejenge, and phir dono side
                    // se jo bhi minm string length aayega, usko consider
                    // karenge

                    // vahi kiya hai agar s1 se curr char liya h toh
                    // memo[i-1][j], and agar s2 se curr char liya hai toh
                    // memo[i][j-1]
                }
            }
        }

        // ab apne paas memo[m][n] me shortest common supersequence ka length
        // mil gaya hai, string bana do ans wala reverse iterate karke
        string ans = "";

        int i = m, j = n;
        // since apan i and j ko string end se chalu krre hai toh, characters
        // ulte dalenge, ie baad me aane wala pehle dalega, toh return krne se
        // pehle string ko reverse kardena

        while (i > 0 && j > 0) {
            //  ye chalega, yaha cases banao ab

            // agar dono idx par common character hai toh, since i start with m
            // so correct idx ke liye i-1 same with j
            if (s1[i - 1] == s2[j - 1]) {
                // means common character hai, toh ye common char ans me daal do
                // 1 baar and i and j ko peeche kardo
                ans += s1[i - 1];

                i--;
                j--;

                // yehi wala case hai jisme memo[i-1][j]==memo[i][j-1] bhi hoga
                // handled here
            }
            // else agar same character nai hai toh
            else {
                // 2 options hai, ya toh i ko aage badhao, ya j ko

                // isme se konsa lena hai???, uske liye ab memo ka kaam aayega

                if (memo[i - 1][j] > memo[i][j - 1]) {
                    // means s2 wale string se character lene me smaller
                    // supersequence aa rha hai, and we need the smallest
                    // supersequence we can get, hence s2 se leo character and j
                    // aage badha do
                    ans += s2[j - 1];
                    j--;

                    // we take char frm s2 since bottom up approach me dekho,
                    // memo[i][j] banane ke liye we needed memo[i-1][j] and
                    // memo[i][j-1] ka minm,to make the minm sized
                    // supersequence, yaha memo[i][j-1] wala lene se smaller
                    // size ka sequence mil rha hai memo[i][j] ke liye, hence
                    // wahi waale ka character daalo ans me
                } else {
                    // means s1 wale string se character lene me smaller
                    // supersequence aa rha hai, and we need the smallest
                    // supersequence we can get, hence s1 se leo character and i
                    // aage badha do
                    ans += s1[i - 1];
                    i--;
                }
            }
        }

        // we out of this loop, means i ya j me se koi na koi 0 pahuch gaya tha
        // , ie possible hai ki i se ya j se aur characters daalne ke liye ho

        // iss case me jitne bache characters hai seedhe seedhe ans me dalenge,
        // toh daal do
        while (i > 0) {
            ans += s1[i-1];
            i--;
        }
        while (j > 0) {
            ans += s2[j-1];
            j--;
        }

        // ab apna string ban chuka hai lekin reversed hai, since apan i=m se
        // start karke i=0 tak characters daal rahe the, ie ulte characters daal
        // rahe hai toh string bhi ulti hi baneggi na, same with j

        // toh string ko reverse kardo, phir return kardena
        reverse(ans.begin(),ans.end());

        return ans;
    }
};