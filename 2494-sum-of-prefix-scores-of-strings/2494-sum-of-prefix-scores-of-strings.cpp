struct trieNode {
    int countprefix = 0;
    trieNode* children[26];
    // 26 since 26 characters hai apne paas
};

class Solution {
public:
    trieNode* getnewTrieNode() {
        // initializes a new node in the trie
        trieNode* newNode = new trieNode();
        // node bana liya, ab originally iske saare children ko null banao
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        // ab new node hai toh prefix cnt bhi 0 se chalu hoga
        newNode->countprefix = 0;
        // return the initialized node
        return newNode;
    }

    void insert(string& word, trieNode* root) {
        trieNode* crawler = root;

        // one by one saare character ko insert karo
        for (auto x : word) {
            int idx = x - 'a';
            if (crawler->children[x - 'a'] == nullptr) {
                // agar current char ke liye koi node nai hai(tabhi nullptr pr
                // hai), bana lo node and store kar lo insted of nullptr
                crawler->children[x - 'a'] = getnewTrieNode();
            }

            // now we have new node for current index(character)
            // ab ye new character as prefix ban gaya, increment prefix count of
            // the child node
            crawler->children[idx]->countprefix+=1;

            // crawler ko aage badhao
            crawler=crawler->children[idx];
        }
    }

    int getScore(string &word,trieNode* root){
        trieNode* crawler=root;
        int score=0;
        for(char ch:word){
            // current char ka inded
            int idx=ch-'a';
            // crawler ko current character ke index pr bhejo
            crawler=crawler->children[idx];
            // ab crawler curr char ke index pr hai, iska prefix score add karo to ans
            score+=crawler->countprefix;
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        // rootnode bana lo
        trieNode* root = getnewTrieNode();
        // insert all words in the trie
        for (auto currword : words) {
            insert(currword, root);
        }

        vector<int> ans(n);
        // ans[i]=sum of score of prefixes of words[i]
        for (int i = 0; i < n; i++) {
            ans[i] = getScore(words[i], root);
        }

        return ans;
    }
};