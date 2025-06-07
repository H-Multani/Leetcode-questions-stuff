struct trieNode {
    trieNode* children[10];
    // 10 since 10 characters hai apne paas
};

class Solution {
public:
    // initialize the new node
    trieNode* getnewTrieNode() {
        // initializes a new node in the trie
        trieNode* newNode = new trieNode();
        // node bana liya, ab originally iske saare children ko null banao,
        // since new node hai, kya pata ike aage bhi nodes lage
        for (int i = 0; i < 10; i++) {
            newNode->children[i] = nullptr;
        }

        // return the initialized node
        return newNode;
    }

    // insert stuff inside the tree
    void insert(string& word, trieNode* root) {
        trieNode* crawler = root;

        // one by one saare character ko insert karo
        for (auto x : word) {
            // current char ko insert karne ke liye proper index will be ch-'a'
            int idx = x - '0';

            // check if the child already exists?
            // agar pehle se iss char par(iss prefix pr) pohoch chuke honge toh
            // iss idx par ek node pehle se hoga

            // incase node nai hai(ie nullptr hai idx par) means, apan pehli
            // baar bana rahe hai current char ke liye node

            if (crawler->children[x - '0'] == nullptr) {
                // agar current char ke liye koi node nai hai(tabhi nullptr pr
                // hai), bana lo node and store kar lo current node(crawler
                // wala) ke children ke idx par insted of nullptr
                crawler->children[x - '0'] = getnewTrieNode();
            }

            // ab naya node bana liya hai(curr char ke liye), aage wale prefix
            // iss node ke andar se hi banenge, toh visit the node we have made
            // changes to just now

            // basically, crawler ko aage badhao
            crawler = crawler->children[idx];
        }
    }

    vector<int> ans;
    void dfs(trieNode* root, int& temp) {
        // crawler lelo
        trieNode* crawler = root;

        // temp jitna bana hai push kardo, since aage exploration karke badi
        // strings hi banengi,toh like current agar 1 par hai toh 1 ko ans me
        // daal do, then explore for 10,11,12,13 etc

        // dont worry about anything, trust the dfs, 1 ke baad 10,11,12,,,,19
        // tak jaane ke baad hi 2 wala logic chalu hoga
        if (temp != 0)
            ans.push_back(temp);
        // ab iterate over the children
        for (auto i = 0; i < 10; i++) {
            // agar ye wala child null nai hai, toh iss idx ko string me daal
            // kar aagr explore karo

            if (crawler->children[i] != nullptr) {
                // add
                temp = temp * 10;
                temp += i;
                // explore
                dfs(crawler->children[i], temp);
                // explore time, aage wale node ke liye root will be the current
                // child node

                // undo
                // last digit alag karo temp se
                temp /= 10;
            }
        }

        // end me temp ko ans me daal do
    }
    vector<int> lexicalOrder(int n) {
        // ab apne paas basic tries ka code hai logic insertion ka, abb isme bas
        // numbers daal kar iterate karna hai

        // trie root banao
        trieNode* root = getnewTrieNode();

        // ab root bana diya trie ka, toh ab insertion karenge
        for (int i = 1; i <= n; i++) {
            // current number ka string banao
            string curr = to_string(i);

            // ab iss string ko trie me insert krdo
            insert(curr, root);
        }

        // ab ek vector banao jisme ans store karenge
        // ans vector bana liya hai

        // ab ek baar DFS chal do, saare possible strings bana kar ans me add
        // karte jao
        int temp = 0;
        dfs(root, temp);

        // string wala array bana kar kar diya, ab direct number bana kar try
        // karo

        // sabse aage wala 0 ko kaise alag karu bc, best idea, funcn me hi edge
        // case laga do

        return ans;
    }
};