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
        // node bana liya, ab originally iske saare children ko null banao,
        // since new node hai, kya pata ike aage bhi nodes lage
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
            // current char ko insert karne ke liye proper index will be ch-'a'
            int idx = x - 'a';

            // check if the child already exists?
            // agar pehle se iss char par(iss prefix pr) pohoch chuke honge toh
            // iss idx par ek node pehle se hoga

            // incase node nai hai(ie nullptr hai idx par) means, apan pehli
            // baar bana rahe hai current char ke liye node

            if (crawler->children[x - 'a'] == nullptr) {
                // agar current char ke liye koi node nai hai(tabhi nullptr pr
                // hai), bana lo node and store kar lo current node(crawler
                // wala) ke children ke idx par insted of nullptr
                crawler->children[x - 'a'] = getnewTrieNode();
            }

            // now we have new node for current index(character)
            // ab ye new character as prefix ban gaya, increment prefix count of
            // the child node(idx wala child node)
            crawler->children[idx]->countprefix += 1;

            // ab naya node bana liya hai(curr char ke liye), aage wale prefix
            // iss node ke andar se hi banenge, toh visit the node we have made
            // changes to just now

            // basically, crawler ko aage badhao
            crawler = crawler->children[idx];
        }
    }

    int getScore(string& word, trieNode* root) {
        // gets sum of score of all possible prefixes of 'word'
        trieNode* crawler = root;
        int score = 0;
        for (char ch : word) {
            // current char ka index
            int idx = ch - 'a';
            // crawler ko current character ke index pr bhejo(initially crawler
            // root par hai, toh index tk bhejna padega)
            crawler = crawler->children[idx];
            // ab crawler curr char ke index pr hai, iska(current character ka)
            // prefix score add karo to ans since ye countprefix is count where
            // curr(and previous) character as prefix kitne strings me aaye the
            score += crawler->countprefix;
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
            // har word ka ttl score nikalo
            ans[i] = getScore(words[i], root);
        }

        return ans;
    }
};