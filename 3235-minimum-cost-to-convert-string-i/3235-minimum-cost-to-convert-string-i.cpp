using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // ek kaam karo weighed graph bana do directed, one thing, make sure ki
        // agar a->b tak ke liye 2-3 possible original->changed wale pairs hai
        // toh smallest wala lena, since we need smallest overall cost

        // 26x26 ka vector banao store the smallest distances between nodes
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        int n = original.size();
        for (int i = 0; i < n; i++) {
            // basically dist[a][b]=min(dist[a][b],cost[a to b current wali])
            dist[original[i] - 'a'][changed[i] - 'a'] =
                min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        // NOTE-> here we treat 'a' as node 0, 'b' as node 1 and so onn

        // ab iss par chal kar directed graph bana sakte hai apan, bana lo
        vector<vector<pii>> adj(26);

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][j] != INT_MAX) {
                    // means node i to j ka direct path hai, utha lo
                    adj[i].push_back({j, dist[i][j]});
                }
            }
        }

        // ab apan ke paas, adjacency list hai, shortest path algo chala do har
        // node se start karke, reuse the distance wali list
        dist.resize(26, vector<int>(26, -1));

        for (int i = 0; i < 26; i++) {
            // current banda ko start leke chalo

            // current bande ko source leke chalo dijkstra chala do

            // priority queue bana lo
            priority_queue<pii,vpii,greater<pii>> pq;
            // start from node i with dist=0, since node i ka node i se dist is 0 only
            pq.push({0,i});
            vi distemp(26,-1);
            // since 26 characters hai hence 26 nodes
            distemp[i]=0;


            // BFS type chala do loop
            while(!pq.empty()){
                int currdist=pq.top().first;
                int curr=pq.top().second;

                pq.pop();

                if(distemp[curr]<currdist){
                    // means iss node par pehle hi smaller dist se aa chuke, dont explore any more
                    continue;
                }

                // neighbours par explore karo
                for(auto [nbr,cost]:adj[curr]){
                    
                    // agar iss nbr par pehle nai aaye hai ya new dist kam hai, tabhi explore karna
                    if(distemp[nbr]==-1 || distemp[nbr]>currdist+cost){
                        // means ya pehli baar aa rahe hai ya toh smaller dist mila hai

                        // update kardo
                        distemp[nbr]=currdist+cost;

                        // explore karne ke liye pq me daal dena
                    pq.push({distemp[nbr],nbr});
                    }
                    
                }
            }

            // ab ye node i se saare neighbours tak ke path distances hai update kardo overall wale me
            for(int j=0;j<26;j++){
                dist[i][j]=distemp[j];
            }
        }

        // ab apan ans bananyenge string par chal kar

        n=source.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            // agar source[i] to target[i] kuch nahi hai means not possible to change character using any operations in such case return -1
            if(dist[source[i]-'a'][target[i]-'a']==-1) return -1;

            // nahi toh ans me daal do
            ans+=dist[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};
