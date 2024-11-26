class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // hint 1 se help li

        // the champions should have an indegree 0

        // simple adj list banao pehle toh
        // then sabki indegree calculate karo
        // in the end map me saare elements ki indegree hogi apne paas, jiski
        // indegree 0 hai vo ans hai, incase multiple nodes ka indegree 0 hai,
        // in such case return -1;

        // ab socha jaaye toh adj list ka need bhi nai h, seedha edges me
        // iterate karte karte indegree calcualte karo mast

        // constraints too small, map ki jagah vector me store karlo indegree

        vector<int> indegree(n, 0);
        // initially sabki indegree 0 hai
        // indegree[i] means i th node ka indegree, eg indegree[2] means node 2
        // ka indegree, indexes go frm 0 to n-1, aur nodes bhi same 0 to n-1 jaa
        // rahe hai , toh indegree wala ka index hi uska node hai

        for (auto curredge : edges) {
            // curr edge is [u,v]
            // means there is directed edge frm u to v
            // ie u se v tak directed edge hai

            // toh v ki indegree increase kardo 1 se, since v par apan ab 1 more
            // node se jaa sakte hai, ie u
            indegree[curredge[1]]++;
        }

        // now we have all nodes ka indegree

        // first count ki 0 indegree wale kitne nodes hai
        int zero_indegree_cnt = 0;
        for (auto it : indegree) {
            if (it == 0)
                zero_indegree_cnt++;
        }

        // agar 0 indegree wale nodes 1 se zyada ya kam hai toh matlab ans nai
        // nikal sakta, in such case return -1
        if (zero_indegree_cnt != 1)
            return -1;

        // we here means 0 indegree wala 1 node hai bas, vo node ka value nikalo
        int ans=0;
        for(auto i=0;i<n;i++){
            if(indegree[i]==0){
                ans=i;
                break;
            }
        }

        return ans;
    }
};