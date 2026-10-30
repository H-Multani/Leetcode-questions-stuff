using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<long long, long long>;
using ppii = pair<long long, pii>;
using vpii = vector<pii>;
using vppii = vector<ppii>;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // dijkstras hi chala do chal jana chahiye with node ka count leke
        // chalenge consecutive wale ka

        // adj list bana do
        vector<vector<pair<int, int>>> adj(n);

        // bhar do adj list ko
        for (auto it : edges) {
            // it[0] to it[1] ka path hai and wt hai it[2]
            adj[it[0]].push_back({it[1], it[2]});
            // adj[it[1]].push_back({it[0], it[2]});
            // did both of these since undirected hai graph
        }

        // pq banao which will store minm dist and state
        // so its like <dist,<node,count>>, so we use ppii
        priority_queue<ppii, vppii, greater<ppii>> pq;

        // minm dist wala vector banano. ab isme me mai sirf dist nai store
        // karunga, mererko <dist,currcnt> wala state store karna padega(since
        // ho sakta hai same dist ke liye 2 alag currcnt aaye, toh vo 2 alag
        // state banenge to explore) hence
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        // LLONG_MAX denotes ki we have not visited that node yet
        // since cnt can be 1,2,3,....k, toh k+1 tak ka array lelo

        // node 0 se start karre hai toh uska dist will be 0,and since vo first
        // time aara toh cnt bhi 1 rahega. mark that
        dist[0][1] = 0;

        // ab iska state pq me push kar dena
        // pq me jayega 3 things, dist of current node frm start(which is 0),
        // node konsa hai (also 0), and uske jitne consecutive kitne mile apan
        // ko(which is 1 since ye node wala label 1st time milra)
        pq.push({0, {0, 1}});

        // ab BFS wala loop chala do
        while (!pq.empty()) {
            // current node and state nikal lo
            int currdist = pq.top().first;
            int currnode = pq.top().second.first;
            int currcnt = pq.top().second.second;

            // pop frm pq
            pq.pop();

            // current state is [currnode][currcnt], iss par distance should be
            // dist[currnode][currcnt]

            // stale state dekhlo, agar currdist not same as
            // dist[currnode][currcnt] means ki dist apan update kar diye hai
            // already, ie ye query pehle push ki thi jab dist zyada
            // tha(currdist tha) and iske aane tak dist update ho gaya toh ye
            // query ko aage process krne ka need nai

            // since iss query ka dist (ie currdist) is more than
            // dist[currnode][currcnt](jo pehle already mil chuka hai currnode
            // par aane ke liye) toh explore karne par chhota dist toh aane se
            // raha kabhi bhi, toh why waste resources and explore
            if (dist[currnode][currcnt] != currdist) {
                continue;
            }

            // neighbours par jao ab
            for (auto it : adj[currnode]) {
                // neighbour node is
                int nbrnode = it.first;
                int nbrdist = it.second;

                // sabse pehle dekho ki yaha jana chahihye bhi ki nahi, cnt
                // ko use karo and lables ko compare karlo

                // currnode and nbrnode ke lables agar same hai, and agar
                // line se k bande aa chuke hai toh yaha explore karne ka
                // need nai hai

                // currcnt is ki labels[currnode] ke kitne instances aaye
                // hai consecutively , since apan ka limit is k, toh curr
                // node par tabhi jana agar consecutive me k bande se kamm
                // aaye hai

                // toh agar labels[currnode]==labels[nbrnode] means
                // consecutive me ek banda aur judega toh currcnt+1 ho
                // jayega, and agar ye k ke upar gaya means path is
                // invalid(since we only need consecutive k values), uss
                // case me we cannot explore further

                // toh ek kaam karo nbrnode par jaane ka new cnt nikal lo
                int newcnt;
                // labels check karo
                if (labels[currnode] == labels[nbrnode]) {
                    // means same label hai toh newcnt will be currcnt+1, since
                    // same label chalra abhi tak
                    newcnt = currcnt + 1;
                } else {
                    // we here means labels same nai hai, iss case me new cnt
                    // chalu hoga vapas 1 se
                    newcnt = 1;
                }

                // ab agar ye cnt>k hua toh aage explore karne ka need nai hai
                // apan ko since we only need at most k consecutive bande
                if (newcnt > k)
                    continue;

                // curr node se nbr node par jaa rahe hai with dist
                // currdist+nbrdist, lekin agar nbr par already lesser dist par
                // pahuch chuke hai toh yaha se jaane ka koi sense nai hai(since
                // bigger dist not needed)

                // new wala dist nikal lo
                int newdist = currdist + nbrdist;

                // aage jayenge toh state padega <nbrnode,newcnt> toh iss state
                // ka jo already dist hai usse smaller dist hua tabhi explore
                // karenge

                // ie agar nbrnode par newcnt(jitna consecutive count) leke
                // pehle pahuch chuke hai with distance 14(for example) toh
                // newdist=16 se waha fir kyu jayenge, same state par already
                // agar 14 dist se pahuche hai toh current newdist=16 par jaane
                // ka kya fayeda, better ans toh 14 wale raste se milna hai minm
                // dist wala toh 16 wale ko explore hi kyu kare

                // toh compare newdist with present dist of state

                if (newdist < dist[nbrnode][newcnt]) {
                    // we here means new wala dist to get to this state is
                    // smaller, iss case me update kar denge

                    // since this new dist is smaller, hence update kardo state
                    // par
                    dist[nbrnode][newcnt] = newdist;

                    // ab since yaha se minm dist mila hai toh aage yehi se
                    // explore karo

                    // for that pq me push kardo
                    // pq me aage dist will be newdist
                    // pq me aage node will be nbrnode
                    // pq me aage cnt will be newcnt
                    pq.push({newdist, {nbrnode, newcnt}});
                }
            }
        }

        // we here means sab ho chuka hai ab, and apna minm dist is in dist[n-1]

        // lekin dist[n-1] par toh boht saare states ke liye nikale hai apan ne,
        // toh saare states par traverse karo and minm dist nikal lo
        long long ans = LLONG_MAX;

        // k states ke liye dist nikale the apan dist, toh ka tak ka loop, cnt
        // can be 1,2,3,....k
        for (int i = 1; i < k + 1; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        // agar ans is still LLONG_MAX
        if(ans==LLONG_MAX){
            // means nai pahuch paaye node tak,return -1
            return -1;
        }

        return ans;
    }
};