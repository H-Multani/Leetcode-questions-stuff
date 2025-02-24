class Solution {
    // adjacency list
    unordered_map<int, vector<int>> adj;

    // to store bob iss node par kiss time par aaya tha
    unordered_map<int, int> bobmap;

    // alice ki abhi tak ki maxm income
    int aliceincome;

    // the bool return is to make sure ki konse path se 0 tak pahuch rahe
    // hai,recursive call wala part dekho aa jaega samajh me
    bool DFSbob(int curr, int time, vector<bool>& vis) {
        // curr node par hai, true mark kardo, visited hai kyuki
        vis[curr] = true;

        // bob curr node par 'time' time par aaya tha map me daal do
        bobmap[curr] = time;

        // agar curr node 0 hai, means we reached target, kuch nai karo, return
        // frm here
        if (curr == 0)
            return true;

        // ab iss curr node ke saare neighbours par jao(jo unvisited hai)

        for (auto nbr : adj[curr]) {
            if (!vis[nbr]) {
                // agar neighbour unvisited hai, toh visit karlo
                // neighbour node bhejo, neighbr tak jane me time+1 lagega, laga
                // do
                if (DFSbob(nbr, time + 1, vis)) {
                    // agar iss neighbour se aage jaane me 0 node tak pahuche
                    // hai means ye path sahi hai, hence return true
                    return true;
                }
            }
        }

        // if we here means current node se kahi bhi 0 tak ka path nai mila,
        // means useless hai ye path, backrack kar jao

        // jo bobmap me time store karaya hai remove kardo, since ye path par
        // bob chalega hi nai, since ye path se 0 tak pahuch hi nai rahe hai
        // apan, toh store kyuu karna, which might cause errors, hence alag
        // kardo
        bobmap.erase(curr);
        // return false, since yaha se 0 tak nai jaa payenge
        return false;
    }

    void DFSalice(int curr, int time, int currincome, vector<bool>& vis,
                  vector<int>& amount) {
        // current node visited hai true mark kardo
        vis[curr] = true;

        // ab income change decide karo iss node ka
        if (bobmap.find(curr) == bobmap.end()) {
            // means ye node bobmap me hai hi nai, in this case amount seedha
            // seedha add hoga curr income me
            currincome += amount[curr];
        } else {
            // means bob yaha pahucha hai kisi time par
            if (bobmap[curr] < time) {
                // means bob yaha pehle pahucha tha, toh curr node unlocked hai
                // alice ke liye, hence no cost added/subtracted
            } else if (bobmap[curr] == time) {
                // means alice and bob iss node par saath me pahuche hai, jitna
                // bhi amount hai adha alice me count hoga adha bob me

                // toh alice ke currincome ke amount/2 add kardo(bob se apna
                // naata nai hai, toh kya karenge uska store karke)
                currincome += (amount[curr] / 2);
            } else {
                // means yaha node prr alice pehle pahuchi thi, in such case
                // again pura amount alice ko lena padega,
                currincome += amount[curr];
            }
        }

        // ab curr node ke liye bhi currincome me changes kar diye hai, ie iss
        // node par aayenge toh income me changes account kar liye hai

        // ab agar curr node leaf node hai toh
        // curr node is leaf node agar adj list me iss node ke liye 1 element
        // hai bss, since leaf node is only connected to 1 node

        // edge case, WA aa rha hai, source node ko hi leaf maan liya since uska
        // bhi adj[curr].size==1 nikla, bachne ke liye ek additional check, ki
        // curr node src node nai hona chahiye, ie curr!=0 hona chahiye
        if (adj[curr].size() == 1 && curr!=0) {
            // means curr node is leaf node, aage kuch nai hai check karne ke
            // liye, bass maxm income ko update kardo, and return frm here
            aliceincome = max(aliceincome, currincome);

            // yaha se return krne me wa aa raha hai, toh mat karo yaha se
            // return, mik ke vdo me hai logic why we done return frm here
            //  return;
        }

        // we here means apan leaf node par nai aaye hai abhi, in such case
        // unvisited neighbours par explore karo paths
        for (auto nbr : adj[curr]) {
            if (!vis[nbr]) {
                // agar neighbour unvisited hai toh, aage explore karo, since we
                // need all leaf tak ke paths

                // aage exploration ke liye, send neighbour as node,
                // time+1(since curr node par 'time' hai toh neighbour par
                // jayenge toh time+1 lagega),updated currincome, baaki vis and
                // amount same as always
                DFSalice(nbr, time + 1, currincome, vis, amount);
            }
        }

        // we here means saare explore kar liye hai path, ans jitne ans milne
        // the mil gaye hai, nothing left to do, return

        // jo node visited tha usko vapas unvisited kardo, useless hai since
        // tree hai, ek node par vapas thodi aayenge ab apan, who bother
        // vis[curr] = false;
        return;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size(); // n nodes hai 0 to n-1

        // alice ka income, isko maximize krna hai, toh min lelo
        aliceincome = INT_MIN;

        // adj list populate karo
        for (auto it : edges) {
            // undirected graph hai
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // dfs on bob for finding time to reach each node till 0, basically bob
        // ke 0 tak ke path me konse node par kitne time me jaa raha hai bob ye
        // banana h

        // send in DFS, bob kaha se start krra hai(start node),time of current
        // node(ie iss node par kitna time par pahuche, initially 0)
        // DFS hai toh vivited vector bhi bhejna hai(dont visit node 2nd time)
        vector<bool> visited(n, false);
        DFSbob(bob, 0, visited);
        // adj list used, globally defined, no need, destination needed, 0 hi
        // hai, no need to specify

        // ab bob ke pure path ka time pata hai, ki bob konse time par konse
        // node par rahega

        // ab DFS maro alice ke liye
        int currincome = 0;
        // visited saare false kardo
        visited.assign(n, false);
        // source bhejo jaha se chalu krna h(0),time bhejo starting wala(kiss
        // node par jitne time par aaye hai apan)(initially
        // 0),currentincome(initially 0), visited array(since DFS chala rhe ),
        // amount(since iska need hoga)
        DFSalice(0, 0, currincome, visited, amount);

        // ab maxm income bhejo
        return aliceincome;
    }
};