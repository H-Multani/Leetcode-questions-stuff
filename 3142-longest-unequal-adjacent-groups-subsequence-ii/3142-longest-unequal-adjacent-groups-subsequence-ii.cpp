class Solution {
public:
    bool hamming(string s1,string s2){
        if(s1.size()!=s2.size()) return false;

        // means same size hai, ab hammign dist nikalo
        int dist=0;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) dist++;

            if(dist>1) return false;
        }
        if(dist==0) return false;

        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        // LIS

        int n = words.size();

        // 1 vector to store parents of each element, will store index ko parent
        // element
        vector<int> parent(n, -1);
        // -1 indicate ki iske koi parent nai h
        // parent[i]=5 means ki iss i th bande ka parent is at idx 5, ie
        // subsequence bnate time idx 5 wale element ke baad idx i wala element
        // aayega

        // ek vector to store LIS
        vector<int> dp(n, 1);
        // dp[i]=4 means ki idx i par khatam hone waale maxm LIS ka size is 4

        // ek value to store biggest LIS we found and ek variable to store the
        // index at which we found the bigger LIS
        int biggest = 0, biggestidx = -1;

        // ab LIS ka code likho
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // agar valid hai LIS me toh
                if (groups[j] != groups[i]) {
                    // groups are valid
                    // ab chk kro if dono ka hamming dist same h ki nai, ye
                    // funcn also checks if size of both strings is same or not
                    if (hamming(words[j], words[i])) {
                        // we here means hamming dist=1 hai, means j and i are
                        // valid for subsequence, toh i ke subsequence ke pehle
                        // ja ka subsequence daal denge
                        if (dp[j] + 1 > dp[i]) {
                            // means new wala subsequence is of bigger size,
                            // update krdo
                            dp[i] = dp[j] + 1;

                            // and since i ka subsequence me j wala char aa rha
                            // h toh parent me update krdo
                            parent[i] = j;
                            // ie subsequence banayege toh i th char ke just
                            // pehle j th char aayega

                            // ab since ye update hua h toh possible hai ki ye
                            // new wala dp[i] could store biggest subsequence
                            if (biggest < dp[i]) {
                                // means dp[i] par jo banra hai vo biggest
                                // subsequence h, toh value and idx update krdo
                                biggest = dp[i];
                                biggestidx = i;
                            }
                        }
                    }
                }
            }
        }

        // if(biggestidx==-1) means at max 1 size ka ans banega
        if(biggestidx==-1) return {words[0]};

        // ab apan ka kaam khatam, bas biggest subsequence wala banda hai apne
        // paas ab at idx biggestidx

        // ab iss idx par backtrack karke index ka array banao
        vector<int> resultidx;

        while (biggestidx != -1) {
            // current idx resultidx me daalo
            resultidx.push_back(biggestidx);
            // ab iss idx wale bande ke parent par jao jaisa LIS ka code h vaise
            biggestidx = parent[biggestidx];
        }

        // ab apan ke paas resultidx me saare result indexes hai lekin reverse
        // order me hai since backtracking krre the apan

        // toh reverse krdo index wale array ko
        reverse(resultidx.begin(), resultidx.end());

        // ab resultidx me saare vo index hai jo LIS bana rahe hai accd to given
        // condn, toh inn saare indexes wale words ko ek vector me daal do, toh
        // sbse bada valid ans banega return it
        vector<string> ans;
        for (auto it : resultidx)
            ans.push_back(words[it]);

        return ans;
    }
};