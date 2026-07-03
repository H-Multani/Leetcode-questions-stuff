class Solution {
public:
    int n;
    long long k;

    // return true of path score<k and path is possible
    bool solve(int i, unordered_map<int, vector<pair<int, int>>>& mpp, int x) {

        // dijkstras laga lo

        // dijkstras ke liye pq lagta hai bana lo
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        // pq me we store <dist,node>

        // pehla wala node is at dist 0 laga do
        pq.push({0, 0});

        // results store karne ke liye vector lelo
        vector<long long> ans(n, -1);
        ans[0] = 0;

        // bfs chala do

        while (!pq.empty()) {
            // top nikalo
            auto curr = pq.top();
            pq.pop();

            // agar current wala node ka best distance is not current distance
            // then we dont need to process further here

            // basically lets say node 3 ke liye dist mila 100, updated and
            // pushed to pq, then better dist mila for same node 3 at dist 50,
            // then aage again better dist mila at 20, iss case me apan ke paas
            // 3 entries hai pq me for same node ke liye, toh vaisa kuch agar aa
            // jaaye toh skip kar dena, ki agar current node ka best distance is
            // not current node tak aane ka current distance then we dont need
            // to process this

            // current node tak aane ka best distance is ans[curr.second]
            // current node tak aane ka current distance is curr.first

            // agar ye dono same nai hai means apan ko aage better already mil chuka hai and updated hai, in such case we dont need to explore this path
            if(curr.first!=ans[curr.second]) continue;

            if (curr.second == n - 1) {
                // means we have reached the end point, path is possible

                // agar path length<=k hai tab chal jayega otherwise not
                if (curr.first <= k)
                    return true;

                // otherwise explore options
            }

            // we here means aage explore karo

            // cout<<"currently for node "<<curr.first<<" at dist
            // "<<curr.second<<endl;

            for (auto [nbr, cost] : mpp[curr.second]) {
                // explore tabhi karna agar aage wali edge ka weight>=x ho, and
                // neighbour par pehle se nai gaye ho YA new wale path se
                // better(smaller) ans mile

                // agar cost<x hai toh yaha se jana hi nai hai
                if (cost < x)
                    continue;

                if (ans[nbr] == -1 ||
                    (1LL * curr.first) + (1LL * cost) < ans[nbr]) {
                    // update ans of nbr

                    ans[nbr] = (1LL * curr.first) + (1LL * cost);
                    // cout<<"next node "<<nbr<<" at dist "<<ans[nbr]<<endl;

                    // pq me daal do nbr ko, new node and new dist

                    // remember pehle distance daalna hai fir node, since pq me
                    // order dist ke hisab se karna hai apan ko
                    pq.push({ans[nbr], nbr});
                }
            }
        }

        // we here means nai mila, in such case return false
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        // offline nodes ko consider hi nai karunga, baaki dijkstras laga dunga
        // easy, ek cheez yaha hai extra ki path ka total sum<=k ho, and agar
        // overall sum<=k hai toh uss case me path ka minm edge leke aana hai as
        // ans, toh uske liye, maxm edge nikal lenge edges wale me se hi, and
        // edges par binary search chala dunga
        this->k = k;
        n = online.size();

        // toh first of all we need to remove the offline edges

        unordered_map<int, vector<pair<int, int>>> mpp;
        long long r = 0;

        for (auto it : edges) {
            if (online[it[0]] && online[it[1]]) {
                // online ho dono nodes tabhi banana connection
                mpp[it[0]].push_back({it[1], it[2]});
                r = max(r, 1LL * it[2]);
            }
        }

        // overall ans nikal kar rakh lena
        long long ans = -1;

        long long l = 0;

        // r ka best value can be k since we know atleast 1 edge aayega hi, and
        // that edge can be at most k since k se zyada hua toh already invalid
        // ho jayega, minor optimization on range
        r = min(k, r);

        while (l <= r) {
            // mid nikalo
            long long mid = l + (r - l) / 2;

            // check if mid wale jitna minm edge leke chalenge toh ans aayega ya
            // nai

            // essentially check if we can go frm node 0 to n-1 with minm edge
            // length as mid

            // cout<<"mid is "<<mid<<endl;

            if (solve(0, mpp, mid)) {
                // means path is possible, and update kardo
                ans = mid;

                // ans possible hai toh right dhundo for better ans
                l = mid + 1;

            } else {
                // valid ans dhundo left me
                r = mid - 1;
            }
        }

        return ans;
    }
};