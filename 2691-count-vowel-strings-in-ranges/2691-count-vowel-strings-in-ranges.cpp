class Solution {
public:
    bool isvowel(string s) {
        int n = s.size();
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' ||
             s[0] == 'u') &&
            (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' ||
             s[n - 1] == 'o' || s[n - 1] == 'u'))
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> wordvowel;
        // stores 1 when current element starts and ends with vowel
        for (auto it : words) {
            if (isvowel(it))
                wordvowel.push_back(1);
            else
                wordvowel.push_back(0);
        }

        // ab bass prefix sum karke nikal lo
        vector<int> prefix(n, 0);
        // prefix[i]=4 means 0 se i tak 4 words hai that starts and ends with
        // vowels, as reqd

        // pehla wala bhar do
        if (wordvowel[0] == 1)
            prefix[0] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + wordvowel[i];
        }

        for (auto it : prefix) {
            cout << it << " ";
        }
        cout << endl;

        // ab queries par iterate karo aur ans banao
        vector<int> ans;
        for (auto it : queries) {
            int start = it[0];
            int end = it[1];

            // start se end tak kitne vowels wale words hai nikalo, its
            // prefix[end]-prefix[start]

            // since prefix[end]=>0 se end tak kitne words start and end with
            // vowel
            // since prefix[start]=>0 se start tak kitne words start and end
            // with vowel

            // toh difference => the no of words that start and end
            // with vowels frm idx start to end, yehi chahiye hai apan ko, daal
            // do ans me

            // edge case, agar same hai start and end toh bass 1 bhejdo agar uss
            // id wala element valid hai toh, otherwise send 0
            if(start==end){
                ans.push_back(wordvowel[end]);
                continue;
            }


            if (start != 0)
                ans.push_back(prefix[end] - prefix[start-1]);
            else
                ans.push_back(prefix[end]);
        }

        return ans;
    }
};