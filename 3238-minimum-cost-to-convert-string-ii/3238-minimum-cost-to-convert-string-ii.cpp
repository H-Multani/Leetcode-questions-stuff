class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> psl;
    ll BIG_VAL = 1e10;

    // ad list yehi define karlo kahi send na karni pade, stores sting to string
    // with cost <string1,<string2,cost>> indicating s1 to s2 ka cost is cost
    unordered_map<string, vector<pair<string, ll>>> adj;

    // ek memo bana lo solve funcn ke liye
    vector<ll> memo;

    // src and target yehi store kar dena to avoid complicated parameter sending
    // bullshit
    string src, tgt;

    // ek set bana lo which will store valid lengths of substrings, bass itne
    // lengths ki substrings hi check karenge apan, baaki nai, since itne length
    // ki susbtrings hi hai original array me for change
    set<int> validlen;

    ll dijkstra(string& start, string& end) {

        // dijkstra ke liye pq bana do, which stores {cost to the-string from
        // currsrc, the-string}
        priority_queue<psl, vector<psl>, greater<psl>> pq;

        // result lelo which will store the distances/cost to different strings
        unordered_map<string, ll> result;

        // start ka cost is 0, since start to start string ka cost is 0
        result[start] = 0;

        // ab pq me daal do isko
        pq.push({0, start});

        // ab BFS loop chala do
        while (!pq.empty()) {
            // top nikalo
            ll currcost = pq.top().first;
            string str = pq.top().second;
            pq.pop();

            // agar apan end wale string tak aa chuke means best ans mil gaya
            // return frm here
            if (str == end)
                return currcost;

            // we here means aaege xplore karna hai

            for (auto [nbr, cost] : adj[str]) {
                // ab cost is the cost to get to node/string nbr from current
                // string str

                // agar yaha pehle kabhi nai gaye, ya fir yaha(nbr) tak jaane ka
                // new dist/cost is smaller, then only explore karlo
                if (!result.count(nbr) ||
                    currcost + cost < result[nbr]) {
                    // means new entry or better cost, update kardo
                    result[nbr] = currcost + cost;

                    // currcost +cost since
                    // currcost-> ttl cost to get from start string to current
                    // string(str) cost-> ttl cost to get from current
                    // string(str) to nbr string

                    // also push this to pq to further explore options
                    pq.push({result[nbr], nbr});
                }
            }
        }

        // ab agar result[end] kuch bana hai toh bhej do nai toh BIG_VALUE bhej dena
        if(result.count(end)){
            // means nikal hai kuch result
            return result[end];
        }

        return BIG_VAL;

    }

    ll solve(int i) {
        // base case
        if (i >= src.size())
            return 0;

        // agar memo me ans hai toh wahi se bhej do
        if (memo[i] != -1)
            return memo[i];

        // minm cost nikalo src and target ke i th char ko same karne ke liye

        ll ans = BIG_VAL;

        if (src[i] == tgt[i]) {
            // means current char is same, no need to check here, aage wla ans
            // dhundo
            ans = solve(i + 1);
        }

        // we here means ya toh i th char same nai hai(and badi substr dekhni
        // padegi), ya toh same char hai fir bhi badi substring check karni
        // padegi

        // like changes for substring can be like "abc"->"abx" isme same hai
        // characters lekin these same char are needed for substring check,
        // karlo

        // jitne valid lengths ke substrings bana sakte ho bana lo

        for (auto len : validlen) {
            // agar idx i se start karke len size ka substring nai le sakte toh
            // nikal jao yaha se
            if (i + len > src.size())
                break;

            // iss size ke substrings bana sakte ho, bana kar check karlo

            // substrings of length len starting len
            string newsrc = src.substr(i, len);
            string newtgt = tgt.substr(i, len);

            // agar ye newsrc adj me present hai means newsrc to newtgt bana
            // sakte hai kuch cost aayegi, in such case check dijkstra otherwise
            // explore other substrings of bigger sizes
            if (!adj.count(newsrc)) {
                // means nai hai adj list me, it ye newsrc se newtgt nai bana
                // sakte
                continue;
            }

            // ab iss src sub string se target sub string bana sakte hai
            // banane ka shortest path nikal lo using dijkstra

            ll cost = dijkstra(newsrc, newtgt);

            // ye cost nikal kar dega

            // agar ye cost not possible hui ie BIG_VAL, means nai bana sakte
            // newsrc to newtgt, in such case exolore bigger substrings starting
            // frm idx i
            if (cost == BIG_VAL)
                continue;

            // we here means cost valid hai, toh minm ans lelo
            ans = min(ans, cost + solve(i + len));
            // solve(i+len) since ek substring leli from idx i to i+len-1, ab
            // aage wali valid substring HAS to start from i+len, since question
            // ka condition 1 yehi bolta ki substrings disjoint honi
            // chahiye( btw condition 2 wala kaam dijksta already karra apne se)

            // hence apan i+len se chalu karte aage ka exploration since
            // disjoint substring leni hai question bola, basically i to i+len-1
            // ek substring lene ke baad agli substring i+len se le sakte, we
            // cannot change one substring and then uske part leke aage wali
            // change karna like "abcdef" me se "abc" changed to "mno" we got
            // "mnodef", ab isme next substring has to be from "def", we cant
            // take new substring from "nod" ya smth, since questn bolta ye nai
            // chalega
        }

        // bhej do ans, return se pehle memo update
        memo[i] = ans;
        return ans;
    }
    // hint taken frm mik
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        src = source;
        tgt = target;

        // dp memo bana do 10000+1 size ka, since itne tak hi indexes jaa sakte
        // apan ke
        memo.assign(10001, -1);

        // adj list bhardo
        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        // valid length array bhar do
        for (auto it : original) {
            validlen.insert(it.size());
        }

        // result nikal kar store karlo
        ll ans = solve(0);
        // since idx 0 se check karna chalu karenge source and target strings ko

        if (ans == BIG_VAL)
            return -1;

        return ans;
    }
};