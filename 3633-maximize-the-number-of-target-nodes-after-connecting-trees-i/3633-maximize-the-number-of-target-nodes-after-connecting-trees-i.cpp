class Solution {
public:
    // ek DFS funcn banao jo dono tree ke liye chal jaaye
    int dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, int k) {
        // agar k has reached 0 means apan ko jitni edges chalna tha chal chuke
        // hai, return 1, to count the current node we have reached
        if (k <= 0)
            return 1;

        // we here means aage chal sakte hai abhi

        // toh sbse pehle current node ko count karlo and visited mark krdo
        vis[node] = true;
        int ans = 1;
        // ans=1 since we need to count current node too since ye node bhi
        // accessible hai from the actual start(since k>0)

        // ab iss node ke unvisited neighbours par jaa kar exlore karo ki kya
        // ans nikal payega, jo bhi h ans me add kar dena
        for (auto nbr : adj[node]) {
            // if unvisited hai toh explore karo
            if (!vis[nbr]) {
                // explore karte time, new node and k-1 bhejna, since current
                // node se nbr wale node par jaane ke liye 1 edge lag gai hogi,
                // toh aage wale node ke paas bas k-1 edges hai for exploration
                ans += dfs(nbr, vis, adj, k - 1);
            }
        }

        // visited bande ko vapas unvisited kardo
        vis[node] = false;

        // ans ans return krdo

        // this ans will be how many nodes can be reached after crossing at max
        // k edges
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // edge case, if k==0 hai toh the maxm no of elements we can reach is the node itself, toh ans will be array full of 1's
        if(k==0){
            vector<int> ans(n,1);
            return ans;
        }

        // dono ka adj list banao
        vector<vector<int>> adj1(n + 1);
        vector<vector<int>> adj2(m + 1);

        // fill the adj lists
        for (auto it : edges1) {
            // undirected edge hai daal do
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto it : edges2) {
            // undirected edge hai daal do
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        // ab vector banao which will store ki tree1 ke har node se k max edges
        // chal kar kitne nodes aayenge
        vector<int> ans(n, 0);
        // har node ko source leke nikalo ki current node se chalu karenge toh k
        // edges ke baad kitne nodes aa payenge
        for (auto i = 0; i < n; i++) {
            // current i ko src leke k edges aake tak jao aur cnt karo kitne
            // nodes aayenge at max

            // visited array bana lo so that circle me na ghumte raho
            vector<bool> vis(n, false);

            // DFS chala do
            ans[i] = dfs(i, vis, adj1, k);
            // send 4 things, the starting nodem,visited array, adj list, k(the
            // no of edges we need to walk for)
        }



        // same cheez karo tree2 ke saath, nodes ka dist nikalo, but this time
        // store nai karna sabka, since we need only maxm ka nodes reached,
        // reason being, tree1 ke har node ko 1 edge laga kar tree2 se join krna
        // h such that nodes visited will be maxm, toh obviously, har baar apan
        // tree 2 ke uss node ko chunenge which will give maxm nodes reached
        // after k-1 edges (since 1 edge lagega to join the tree1 node to the
        // tree2 node)

        // for eg in eg1, tree1 ke har node ko tree2 ke 0 th node se jodenge,
        // since k-1=1 edges paar kar ke, node 0 will help us reach 4
        // nodes(which are 0,1,2,3 in tree2), thats the maxm no of nodes we can
        // reach after k-1 edges starting frm node 0(tree2) (node 4 bhi same 4
        // return krega toh dono me se koi bhi le sakte)

        // toh bss maxm nodes reached nikal lo, since path nai dena hai bas node
        // ka cnt dena hai
        int maxm = 0;
        for (auto i = 0; i < m; i++) {
            // current i ko src leke k edges aake tak jao aur cnt karo kitne
            // nodes aayenge at max

            // visited array bana lo so that circle me na ghumte raho
            vector<bool> vis(m, false);

            // DFS chala do
            maxm = max(maxm, dfs(i, vis, adj2, k - 1));
            // send 4 things, the starting nodem,visited array, adj list, k(the
            // no of edges we need to walk for)
        }

        // ab tree1 ke har node ko iss wale node se jodenge (the node that
        // returns maxm nodes reached after k-1 steps)

        // toh eg1 me dekhe toh, 
        // node 0(tree1) connected to node 0(tree2) will
        // increase the no of nodes reached from 5 to 5+4=9, since 5 nodes are
        // reached in tree1 itself, and when we connect to node 0(tree2), we can
        // access total 4 more nodes, which we added

        // node 1(tree1) connected to node 0(tree2) will
        // increase the no of nodes reached from 3 to 3+4=7, since 3 nodes are
        // reached in tree1 itself, and when we connect to node 0(tree2), we can
        // access total 4 more nodes, which we added

        // node 4(tree1) connected to node 0(tree2) will
        // increase the no of nodes reached from 4 to 4+4=8, since 4 nodes are
        // reached in tree1 itself, and when we connect to node 0(tree2), we can
        // access total 4 more nodes, which we added

        // all these asnwers match the reqd ans, so we just update it

        for(auto i=0;i<n;i++){
            ans[i]+=maxm;
        }


        // for (auto it : ans)
        //     cout << it << " ";
        // cout << endl;

        return ans;
    }
};