class Solution {
public:
    // dfs funcn for even edges wala
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj,
             vector<int>& marks, int mark) {
        vis[node] = true;
        // int ans = 0;

        // current wale bande ko mark krdo
        marks[node] = mark;

        // neighbpours ke paas jao, and opposite mark do, if current mark=1,
        // send 0, if current mark is=0 send 1
        for (auto nbr : adj[node]) {
            // if unvisited hai toh explore karo
            if (!vis[nbr]) {
                // neighbour par ek edge leke jaa rahe hai, mark change krke
                // daalo
                if (mark) {
                    // means current node ka mark is 1, toh nbr ka mark will be
                    // 0
                    dfs(nbr, vis, adj, marks, 0);
                } else {
                    // means current node ka mark is 0, toh nbr ka mark will be
                    // 1
                    dfs(nbr, vis, adj, marks, 1);
                }
            }
        }
        vis[node] = false;
        return;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
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

        vector<int> ans(n, 0);

        // use alternate marking wala logic, ek baar me count karlo
        vector<int> mark(n, -1);
        vector<bool> vis(n, false);
        // alternate 0,1 marking karo 1 DFS se

        // start marking frm 0
        dfs(0, vis, adj1, mark, 0);
        // first 0 is the starting node, last 0 is the mark we give to this node

        // after DFS has run apne paas marks hai saare, toh 0,1 count kar lenge
        // agar toh we will get ki konsa node overall kitne nodes ke pass jaa
        // sakta hai in tree1

        // 0sum and 1sum nikalo
        int zerosum = 0, onesum = 0;
        for (auto it : mark) {
            if (it)
                onesum++;
            else
                zerosum++;
        }

        // toh eg1 me dekhe agar toh mark={0,1,1,0,0}, toh that basically means
        // ki node 0 can reach ttl of zerocnt=3 nodes in tree1( which is true,
        // since node0 can reach nodes 0,3,4 after even no of edges)

        // vice versa for node 1, it can reach ttl onesum=2 nodes in tree1(
        // which is true)

        // tree1 ka ans bhar do
        for (auto i = 0; i < n; i++) {
            // agar i th node ko 1 mark kiya hai toh onesum add hoga , otherwise
            // zerosum add hoga
            if (mark[i] == 1)
                ans[i] += onesum;
            else
                ans[i] += zerosum;
        }

        // ab apne paas saare tree1 ke ans hai, same logic lagao tree2 ke liye,
        // bas yaha par apan since koi bhi node se jod sakte hai toh apan vo
        // node se jodenge jo maxm nodes reached de

        // for eg, in eg1 tree2 ka mark array will be like {0,1,1,1,0,1,1,0},
        // giving zerosum=3 and onesum=5, ie agar 1 wale se connect kiya toh 5
        // nodes access ho payenge, otherwise maxm 3 nodes access ho payenge
        // after even no of edges crossed

        // toh node 0 of tree1 which is curently at 3(nodes accessible), if we
        // connect it to node 0 of tree2, this will access marks2[0] ka ulta =1
        // mark wale nodes which are 5, (marks2[0] ka ulta since 1 edge lagega
        // to join tree1 and tree2, toh agar 0 of tree1 connected to 0 of tree2,
        // toh node 0 of tree1 can access nodes 1,2,3 of tree2 after even no of
        // steps which have mark 1, tabhi mark 1 wale ka count lenge)

        // making the total accessible nodes of node 0 to 3+5=8 which is correct

        // similarly, node 1 of tree1 ko bhi apan node 0 of tree2 se connect
        // karenge since that will give maxm no of accessible nodes, making node
        // 1 ka ans= 2+5=7, which is correct ans

        // toh essentially like lc 3372, waha maxm lere the, yaha bhi tree2 ka
        // maxm lenge

        // array bana do mark2
        vector<int> mark2(m, -1);
        vector<bool> vis2(m, false);
        // DFS chala do ab adj2 par
        dfs(0, vis2, adj2, mark2, 0);

        // ab 0cnt and 1cnt nikalo phir se
        zerosum = 0;
        onesum = 0;

        for (auto it : mark2) {
            if (it)
                onesum++;
            else
                zerosum++;
        }

        // toh lc 3372 types yaha bhi maxm nikalo dono me se, this maxm will be
        // how many maxm nodes we can reach in tree2 after each 2 steps

        int maxm = 0;
        maxm=max(onesum,zerosum);

        for (auto i = 0; i < n; i++) {
            ans[i] += maxm;
        }

        return ans;
    }
};