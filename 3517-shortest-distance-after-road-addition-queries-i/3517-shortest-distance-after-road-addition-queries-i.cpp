class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        // 0 to n-1 tak nodes ka adjacency list banao pehle toh
        // like 0->1->2.... so on
        vector<vector<int>> adj(n);
        for (auto i = 0; i < n - 1; i++) {
            // unidirectional link bw i and i+1
            adj[i].push_back(i + 1);
        }
        // after this we have made link of 0->1, 1->2,2->3 and so on

        // ans vector banao
        vector<int> ans;

        // har query ko iterate karo
        for (auto query : queries) {
            // current query->[a,b] indicates unidirectional join frm a to b,
            // adj list me add kardo new wale edge/join ko
            // as asked by the question
            adj[query[0]].push_back(query[1]);

            // ab bfs chala kar shortest path nikal lo
            // shortest path algo src=0 har baar
            // for more details abt this algo, see 12.cpp file, waha samajh lena
            int currans = INT_MAX;

            queue<int> q;

            // start frm 0, source is 0
            q.push(0);

            vector<int> distance(n, -1);
            // initially all nodes are at dist -1 frm 0(ie not connected to 0)
            distance[0] = 0;
            // 0 se chalu kar rhe hai, hence 0 ka dist 0 hoga frm 0

            // bfs chala do
            while (!q.empty()) {
                // current top wala value nikalo
                int currtop = q.front();
                q.pop();

                // iske neighbours me explore karo ab
                for (auto neighbor : adj[currtop]) {
                    // agar current neighbour ka dist -1 hai , means its not
                    // visited, visit it
                    if (distance[neighbor] == -1) {
                        // current neighbor tak ka dist frm src is current bande
                        // tak pahuchne me kitna distance laga +1
                        // basically
                        // distance(src->neighbour)=distance(src->currtop)+distance(currtop->neighbour)
                        // here distance(src->currtop)=distance[currtop]
                        // and distance(currtop->neighboue)=1, since currenttop
                        // se 1 dist par hai neighbbour
                        // overall being distance[currtop]+1
                        distance[neighbor] = distance[currtop] + 1;

                        // push neighbour to q, since there could be further
                        // levels to the graph
                        q.push(neighbor);
                        // aur levels explore karne pad skta h, hence explore
                        // karo
                    }
                }
            }

            // ab bfs chala diya hai, and apna ans is stored in
            // distance[n-1],since distance[n-1] is the minm distance frm node 0
            // to n-1, since apan shortest path algo src=0 se chala rahe the,
            // and apan ko n-1 th node tak ka minm distance chaiye tha which is
            // distance[n-1]
            currans = distance[n - 1];
            // push the ans to the vector
            ans.push_back(currans);
        }
        return ans;
    }
};