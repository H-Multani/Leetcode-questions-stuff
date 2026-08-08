class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // ok toh logic is fairly simple

        // 2 pointers use karenge one for word1 one for word2

        // ye dono pointers se hi match karaenge

        // for each posn/idx in word1 we check if it matches corresponding char
        // in word2, agar match karra hai toh ans me laga kar aage badho

        // agar match nai karra hai toh, for this char in word1 we have 2
        // choices,

        // choice 1-> yaha char ko change karke word2 wale ke jaisa bana denge,
        // lekin ye karne se aage ye operation nai kar payenge kabhi bhi, toh
        // agar ye operation yaha kiya toh check karna padega ki word2 ke bache
        // hue characters aage word1 me sequence me milenge ki nai

        // like suppose use kar liya operation yaha, ab word2 me remaining chars
        // are "bc" and word1 remaining is "cbdc", toh yaha apan word1 me
        // sequence me chale toh bina problem ke "bc" nikal sakte hai without
        // needing operation (since b ke baad c aara hai word1 me utha lo)

        // choice 2-> yaha par operation nai karo, since operation karne se koi
        // fayeda nai hone wala ans nai banne wala, in which case word1 ke ptr
        // ko aage badha do and word2 ke ptr se match karane ka try karo

        // toh ye karne ke liye we need 1 important thing

        // how do we check ki word2 ke remaining characters word1 ke remaining
        // part me sequence me milenge

        // like word2="bc", word1="cbfc", yaha par word1 me b ke baad c aara
        // dikhra, toh word2 can be made using sequence of characters of word1

        // ye karne ke liye vector lelo, which stores ki word1 me current idx se
        // end tak me kitne characters word2 se match karenge in order

        // like rtHandMatch[i]=3 means idx i se leke end tak me word2 ke last ke
        // 3 characters match kar rahe , and can be found as is without
        // operation to be done
        int m = word1.size();
        int n = word2.size();

        vector<int> rtHandMatch(m+1, 0);

        // pehle ye array bhar do, compare karne ke liye left to right nai
        // karenge, since baar baar right hand wale me dhundna will be too TLE

        // toh we iterate right to left
        int i = m - 1, j = n - 1;
        // counter lelo which counts ki kitne characters match karre
        int cnt = 0;
        while (i >= 0) {

            if (j>=0 && word1[i] == word2[j]) {
                // means 1 character match kar gaya,

                // array me +1 upadate kardo, if array me pehle se suppose 2
                // chars match krre the toh ye 3rd ban gaua, store kardo array
                // me

                cnt++;

                // since dono chars match kar gaye, means ab agle word2 ke char
                // ko match kara sakte

                // update both idx
                // i--;
                j--;
            } else {
                // we here means match nai kiya ith and j th character

                // j th char ko match karane ka try karenge bass since we need
                // count ki how many characters of remaining word2 can be found
                // in sequence in remaining word1

                // toh j wala char check karaenge, dont change that

                // i th idx aage badha do in attempt to match
                // i--;
            }

            rtHandMatch[i]=cnt;
            i--;
        }

        // ab we have array which tells us ki current idx par remaining word1
        // can make rtHandMatch[i] characters of word2 in sequence

        // ans bana do

        vector<int> ans;
        i = 0, j = 0;

        // booleans indicating ki oepration hua hai ki nai
        bool operation = false;
        while (i < m && j < n) {
            // agar current chars dono ke match karre hai exactly, toh means
            // yaha koi operation karne ka need nai seedha seedha utha lo
            if (word1[i] == word2[j]) {
                // current idx ko ans me daal do and dono idx aage badha do
                ans.push_back(i);
                i++;
                j++;
            } else {
                // we here means i th and j th character do not match

                // yaha we have 2 choices,

                // choice 1 is to make operation here,
                // choice 1 is to not make operation

                // agar operation pehle se hua rakha hai toh 2nd time nai kar
                // sakte, in this case we have only 1 option ki i ko aage badha
                // do
                if (operation) {
                    // means operation is done already

                    // i ko aage badha sakte bas
                    i++;
                } else {
                    // we here means operation laga sakte hai yaha par

                    // ab agar operation yaha laga diya toh we need how many
                    // remaining characters to match in word2
                    int rem = n - j - 1;

                    // check karo ki current idx se end tak me itne rem jitne
                    // characters order me mil pbhi payenge word1 me ki nai??

                    // that is rtHandMatch[i+1]

                    // i+1 since current wale ko toh change karre na , toh aage se measure karenge

                    if (rtHandMatch[i+1] >= rem) {
                        // means jitne chars match karane the, in word2, utne
                        // match ho jayenge directly without taking operations

                        // means yaha operation laga sakte

                        // laga lo

                        // ans me daal do i ko and aage badho
                        ans.push_back(i);
                        i++;
                        // since j wala char bhi match kar liye hai hence usko
                        // bhi aage badha do
                        j++;

                        // operation ho chuka hai toh mark kardo
                        operation=true;
                    } else {
                        // we here means yaha operation karenge toh aage ke
                        // characters match nai ho payenge,

                        // in this case we only have 1 option

                        // i ko aage badha do and aage wale se match karna ka
                        // try karo
                        i++;
                    }
                }
            }
        }

        // edge case if ans size ka nai bana means nai bana sakte ans return empty array
        if(ans.size()!=n) return {};

        // ans bhej do end me
        return ans;
    }
};