class Solution {
public:
    unordered_map<int, vector<int>> adj;
    // stores har node ke subtree ka size
    vector<int> ans;
    // stores current char konse node par dikha tha last time, size 26 obviously
    vector<int> last;

    void dfs(int curr, string& s, vector<int>& parent) {
        // current node ka char is
        int c = s[curr] - 'a';

        // nearest ancestor will be the last time we saw this character
        int nearancestor = last[c];

        // ab aage iske children par explore karna hai apan ko, toh aagr
        // children ke liye current wala node will become ancestor toh last of
        // current character me curr node daal denge

        // since aage childrens ke liye current node will become nearest
        // ancestor hence last wala array me currnode daal denhe
        last[c] = curr;
        // ab childresn par iterate karo

        for (int child : adj[curr]) {
            // dfs explore karlo child par
            dfs(child, s, parent);
        }

        // ab explore karke vapas aa gaye hai apan log

        // toh yaha par current node ke liye nearest ancestor jo tha vapas
        // update kardo
        last[c] = nearancestor;

        // ab yaha karenge operation for current banda

        // questoion ke hisab se agar ancestor hua toh current node ka new
        // parent will be that ancestor

        // wahi update kard

        // edge case, if curr node is root, it has no ancestor
        if (curr != 0) {
            // old parent of curr node was parent[curr]
            int newparent = parent[curr];
            // update se pehle make sure ki ancestor hai bhi
            if (nearancestor != -1) {
                // new parent will be
                newparent = nearancestor;
            }

            // curr node ke parent ko update kardo aur kya ab
            parent[curr]=newparent;

            // ab ye new wale parent ka size update karna padega since ek proper new connection banaya hai apan ne

            // toh new parent me jitne nodes already the, usme ab ye curr node ke subtree wale nodes direct add honge since parent wale se curr node join hora hai toh curr node ke sath uske jitne subtree wale nodes hai vo bhi add honge

            // kardo update ans wale array me

            // new wale parent ke size(ans[newparent]) me curr node ka size(ans[curr]) add hoga 
            ans[newparent]+=ans[curr];
        }


    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        // adj list bhar do, vector bhi rakh sakte aisehi map liya hai yaha
        int n = parent.size();

        // bhar do adj list
        for (int i = 0; i < n; i++) {
            // parent[i] is parent of node i
            // toh parent[i] ke child me i daal denge
            adj[parent[i]].push_back(i);
        }

        // initially all nodes ka size is 1(ie themselves only)
        ans.resize(n, 1);
        // last array me 26 size ka hoga and -1 hoga since koi char nai mila
        // abhi tak
        last.resize(26, -1);

        // simple DFS call karenge explore karenge
        dfs(0, s, parent);
        // node 0 se start karre hai and s,parent bhej diye

        // ab dfs ke baad apna ans bhar chuka hoga
        return ans;
    }
};