class Solution {
public:
    int n;
    // dfs likh do
    void dfs(vector<int>& edges, int node, vector<int>& dist,
             vector<bool>& vis) {

        // current node ko visited mark krdo
        vis[node] = true;

        // har baar bas ek neighbour milega

        // toh for loop ka need nai h seedha wahi chal chalo

        // now to get to this curent node we have travelled dist[node] jitna
        // dist,
        int travelled = dist[node];

        // toh agar aage wale node par jana h toh already travelled dist+1 dist
        // lagega yehi lagaenge

        // agar aage wala node non visited hai toh chale jao update kardo
        // aage wala node is edges[node]
        int nbr = edges[node];
        if (nbr != -1 && !vis[nbr]) {
            // means aage wala node is not visited, update dist and explore
            dist[nbr] = travelled + 1;
            dfs(edges, nbr, dist, vis);
        }

        // explore krne ke baad jo curent node ko visited mark kiya tha usko
        // vapas unvisited mark karo(since by this, the same vis array can be
        // used for both node1 and node2)
        vis[node] = false;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        // 2 vector banao dist calculate karenge frm node1 to each node and
        // node2 to each node
        vector<int> dist1(n, INT_MAX);
        // dist1[4]=3 means node1 to node 4 ka path is of length 3
        vector<int> dist2(n, INT_MAX);

        // vector boolean rakh lo visited ke liye, since cycles present ho skti
        vector<bool> vis(n, false);

        // node1 se node1 ka dist=0 hoga vahi update krdo
        dist1[node1] = 0;
        // node2 se node2 ka dist=0 hoga vahi update krdo
        dist2[node2] = 0;

        // ab dfs call krdo 2 baari one to fill dist1, other to fill dist2
        dfs(edges, node1, dist1, vis);
        // edges,dist1,vis as normal jayenge, node1 se start krre hai apan toh
        // vo initial bhjemnge

        // same with node2
        dfs(edges, node2, dist2, vis);

        // no adjacency list since given h ki ek node ka bas ek neighbour hoga
        // at max

        // ab apne dist1 and dist2 bhar chuke hai

        // minm dist wala node
        int minmdistnode = -1;
        // minm dist wala node kitne dist par h
        int minmdisttillnow = INT_MAX;

        // ab dono ke dist ko compare karenge

        for (int i = 0; i < n; i++) {
            // node1 se i th node ka dist= dist1[i]
            // node2 se i th node ka dist= dist2[i]

            // ab questn bolra hai ki vo node nikalo such that, maxm dist bw
            // node1 to that node and node2 to that node is minimized

            // yaha that node is i th node

            // toh sbse pehle get maxm of (dist of node1 to i, dist of node2 to
            // i)
            int maxm = max(dist1[i], dist2[i]);

            // ab ye maxm dist ko minimize karna hai, and since minm bhejna h
            // toh agar ye maxm dist is smaller than current minmdistillnow
            // means ki abhi tak yehi minm dist mila hai, toh update kar denge
            // node ko and minm dist ko
            if (maxm < minmdisttillnow) {
                // matlab maxm dist smaller hai
                minmdisttillnow = maxm;
                minmdistnode = i;

                // ye sab bakchodi ka zarurat nai h since == wale case me idx
                // kyu update karenge apan i=0 se increment krre h, toh already
                // wala idx will be smaller than the i anyways, why bother

                // // agar dist small h toh
                // if (maxm < minmdisttillnow) {
                //     // seedha node and dist update kardo
                // } else {
                //     // means dist is same as maxm dist till now, toh iss case
                //     me
                //     // node with smallest idx chahiye, toh idx update karo
                //     bas minm lo minmdistnode = min(i,minmdistnode);
                // }
            }
        }

        // ab apn ke paas minm dist wala node h return krdo
        return minmdistnode;
    }
};