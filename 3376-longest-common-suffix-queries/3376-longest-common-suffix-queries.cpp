class Solution {
public:
    struct trienode {
        // storing idx of the smallest element of wordsContainer jo ki current
        // node tak prefix store kar raha
        int idx;

        // trienode ke pointer ka array, used to making the tree
        trienode* children[26];


        // MLE aara hai destructor bana do so that faltu resources chalti na rahe
        ~trienode(){
            // 26 childredn banaye the close karo sabko
            for(int i=0;i<26;i++){
                delete children[i];
            }
        }
    };

    // ek funcn jo ki trienode bana kar dega
    trienode* getnode(int i) {
        trienode* temp = new trienode();

        // iss new node ka index i set kardo
        temp->idx = i;

        // ans iske children empty bana do sab
        for (int j = 0; j < 26; j++) {
            // temp ke children ke i th node par kuch node nai hai null set
            // kardo
            temp->children[j] = nullptr;
        }

        // ab return kardo node ko
        return temp;
    }

    void insertvals(trienode* root, int i, vector<string>& wordsContainer) {

        // word nikal lo
        string word = wordsContainer[i];
        int n = word.size();

        // reverse se insert karte jao, since trie me suffix both wierd and
        // hard, toh reverse karke prefix kardo
        for (int j = n - 1; j >= 0; j--) {
            // character is
            char ch = word[j];
            // iss char ka trie ke liye idx will be
            int chidx = ch - 'a';

            // kya root ke children me ye idx par null hai?, agar hai null toh
            // banana padega node
            if (root->children[chidx] == nullptr) {
                // new node bana do and since iss par first time aaye hai toh
                // wordsContainer wale word ka actual idx hi jayega which is i
                root->children[chidx] = getnode(i);
            }

            // ab we here means node ban chuka hai(ya already bana hua hai)

            // jo bhi case hai root ko aage badha do, so that aage wale
            // characters insert kar paaye
            root = root->children[chidx];

            // ab possible ki pehle koi string already dal chuka ho jiska kuch
            // idx ho already, toh uss idx wale se compare karana padega current
            // word ke length ko since question says agar common prefix nikal
            // raha toh smaller length to be considered

            // now we check if already present wale string ka size is smaller ya
            // fir current wale ka size is smaller, jo smaller hoga vahi leke
            // chalenge apan since question asks that

            // already present wala string is (root->idx) wala string of
            // wordsContainer, since jab previous kisi string ka insertion karre
            // honge apan tab ke time ye idx setup kiya gaya hoga, toh abhi tak
            // that was the best ans, for this node tak suffix ke liye, but
            // current wala string also reaches the same place, toh possible hai
            // ki current string is a better ans since ho sakta current ka size
            // kam, toh kara lo check iska length
            if (wordsContainer[root->idx].length() > n) {
                // means we need to update root ka idx
                root->idx = i;
            }
        }
    }

    // ab search wala function banao
    int search(trienode* root, string word) {
        // initially root ka idx will be best ans, since kuch match nai karega
        // toh empty suffix match karega
        int ans = root->idx;

        int n = word.length();

        // checking bhi reverse karenge since insertion ulta kiya

        for (int i = n - 1; i >= 0; i--) {
            int chidx = word[i] - 'a';

            // root me dekho ki ye idx hai ki nai hai, agar nai hai means we
            // have reached end of suffix,

            root = root->children[chidx];

            if (root == nullptr) {
                // we here means end tak pahuch chuke hai suffix ke, jitna ans
                // idx mila hai abhi tak vahi bhej do
                return ans;
            }

            // we here means abhi common suffix nikal raha hai, in such case
            // update ans, and current ans will be root ka idx since jaha tak
            // pahuche hai waha tak ka best ans wala idx is already stored in
            // root ka node
            ans = root->idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        // simple trie lagega bass

        int m = wordsContainer.size();
        int n = wordsQuery.size();

        // result vector bana do
        vector<int> ans(n);

        // trie banane ke liye root node bana lo

        trienode* root = getnode(0);

        // ab trie bhar do wordsContainer ke elements se
        for (int i = 0; i < m; i++) {
            // idx store karte chalenge, initially set this to root ka index
            int idx = root->idx;
            // agar current index wale element ka length is smaller than root ka
            // idx wale ka length, means we need to update the root ka index,
            // since jab kuch common nai milega tab ye empty string common
            // milega which will be root ka idx wala element, toh keep that in
            // updated always
            if (wordsContainer[idx].size() > wordsContainer[i].size()) {
                // means we need to update string idx for empty wala case, toh
                // update kardo
                root->idx = i;

                // ab sbse chhota length of string is present at this idx i
            }
            insertvals(root, i, wordsContainer);
        }

        // ab trie me insert kar diya hai pura, ab simply har query par jao and
        // traverse karke ans nikal lo and update kardo

        for (int i = 0; i < n; i++) {
            // root se search karo current query ko and best idx nikal lo
            ans[i] = search(root, wordsQuery[i]);
        }

        // kaam hone ke baad delete the root, so that MLE na aaye
        delete root;

        return ans;
    }
};