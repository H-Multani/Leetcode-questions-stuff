using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

// bc chal gaya waah pata nai kaise, mai toh simple socha tha ki weighted graph
// bana lunga, fir har char(src) to char(target) nikalta jaunga minm dist
// disjkstra se

// fir socha har baar dijkstra boht complexity kha jaega, fir socha 26 x 26
// combinations hi toh ho sakte hai since sab charcaters lowercase hai, toh har
// possible distance bana kar hi store kar deta ek baari me, isse recomputatuon
// time bachega kaafi, plus simple hi hai, har character ko start leke dijkstra
// chal do khatam , toh ye shortest path to all reachible nodes nikal kar de
// dega

// overall iss question me major work is adjacency list banana and solutions
// precompute karna, baaki source par iteration toh ek baar me ho gaya
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // NOTE-> here we treat 'a' as node 0, 'b' as node 1 and so onn

        // ek kaam karo weighed graph bana do directed, one thing, make sure ki
        // agar a->b tak ke liye 2-3 possible original->changed wale pairs hai
        // toh smallest wala lena, since we need smallest overall cost

        // 26x26 ka vector banao store the smallest distances between nodes
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        int n = original.size();

        // pehle toh dist[i][j] nikal lo ki node i to node j wala cost kitna
        // pdega, since multple entries ho sakti hai toh smallest cost wali
        // entry lena
        for (int i = 0; i < n; i++) {
            // basically dist[a][b]=min(dist[a][b],cost[a to b current wali])
            dist[original[i] - 'a'][changed[i] - 'a'] =
                min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        // ab iss par chal kar directed graph bana sakte hai apan, bana lo
        // adjacency lisst
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
        // node se start karke, reuse the distance wali list to store final
        // distances of each node to each other node
        dist.resize(26, vector<int>(26, -1));

        for (int i = 0; i < 26; i++) {
            // current banda ko start leke chalo

            // current bande ko source leke chalo dijkstra chala do, toh we will
            // get i th node se saare reachible nodes ka smallest distance(cost)

            // priority queue bana lo
            priority_queue<pii, vpii, greater<pii>> pq;
            // start from node i with dist=0, since node i ka node i se dist is
            // 0 only
            pq.push({0, i});

            // since 26 characters hai hence 26 nodes ka distance vector bana
            // diya, this stores ki node i se saare nodes ka kitn distance hai
            vi distemp(26, -1);

            // since node i ka node i se distance is 0 henc
            distemp[i] = 0;

            // BFS type chala do loop
            while (!pq.empty()) {
                int curr = pq.top().second;

                // node i se node curr tak ka distance/cost
                int currdist = pq.top().first;

                pq.pop();

                if (distemp[curr] < currdist) {
                    // means node i se iss node par pehle hi smaller dist se aa
                    // chuke, dont explore any more since useless hai
                    continue;
                }

                // we here means new wala distance is smaller

                // neighbours par explore karo
                for (auto [nbr, cost] : adj[curr]) {

                    // agar iss nbr par pehle nai aaye hai ya new dist kam hai,
                    // tabhi explore karna
                    if (distemp[nbr] == -1 || distemp[nbr] > currdist + cost) {
                        // means ya pehli baar aa rahe hai ya toh smaller dist
                        // mila hai

                        // update kardo
                        distemp[nbr] = currdist + cost;
                        // since node i se iss node nbr tak ab smaller distance
                        // me aaye hai which is currdist (distance of node i to
                        // node curr)+cost(distance of node curr to node nbr)

                        // explore karne ke liye pq me daal dena, since ho sakta
                        // hai iske neighbours ab even smaller dist chal le
                        pq.push({distemp[nbr], nbr});
                    }
                }
            }

            // ab ye node i se saare neighbours tak ke minm path distances(cost)
            // hai update kardo overall wale me
            for (int j = 0; j < 26; j++) {
                dist[i][j] = distemp[j];
            }

            // additional option, directly final dist array me bhi update kar
            // sakte lekn ab maine yaha alag bana diya hai toh bhi chalta GG
        }

        // now we have dist vector which stores
        // dist[i][j] means node i to node j ka minm cost overall (note that ye
        // bass cost hai path nahi)

        // ab apan ans bananyenge string par chal kar

        n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            // agar source[i] to target[i] ka dist is -1 means its not possible
            // to change character using any operations in such case return -1
            if (dist[source[i] - 'a'][target[i] - 'a'] == -1)
                return -1;

            // nahi toh ans me daal do
            ans += dist[source[i] - 'a'][target[i] - 'a'];

            // agar dist array nahi bharte pehle toh yaha par dijkstra chalna
            // padta toh samajh aa raha hoga ki dijkstra ki complexity se kaha
            // apan query ko O(1) me solve karre hai by precomputation
        }

        return ans;
    }
};
