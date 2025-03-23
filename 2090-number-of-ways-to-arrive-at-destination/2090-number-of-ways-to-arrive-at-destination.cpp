
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<long long, long long>;
using vpii = vector<pii>;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int M=1e9+7;

        // first make adj list
        vector<vector<pair<int, int>>> adj(n);
        // stores ki curent node ke kitne neighbours hai kitne dist par

        for (auto it : roads) {
            // it[0]->it[1] at time it[2]
            adj[it[0]].push_back({it[1], it[2]});
            // it[1]->it[0] at time it[2]
            adj[it[1]].push_back({it[0], it[2]});
            // did both of these since undirected hai graph
        }

        // ab pq banao which will store <the minm dist to get to the reqd node
        // frm curr node, the reqd node >

        priority_queue<pii, vpii, greater<pii>> pq;
        // store the distance first, the node later since we need minm distance

        // ab minm dist vector banao, for this question apan ke liye dist same
        // as time hai, since time minimize karna hai
        vector<long long> time(n, LLONG_MAX);
        // LLONG_MAX indicate ki abhi tak vo node access nai kiya hai
        // make vector for keeping count of no of paths frm src to reqd node
        vector<long long> cnt(n, 0);
        // initially there are 0 paths to get to each node

        // apan source is 0 and destination is n-1 th node

        // source par aane ka 1 way hai only(starting frm there), update that
        cnt[0] = 1;
        // similarly dist to get frm src to src is 0, toh vo dist vector me
        // update kardo
        time[0] = 0;
        // our source is 0

        // source ka dist frm src is 0 , and node is also 0 toh vo pq me push
        // kardo
        pq.push({0, 0});

        // ab BFS wala while chalao
        while (!pq.empty()) {
            // curr node and dist nikalo

            // curr node par pahuchne ka minm dist is currdist
            long long currtime = pq.top().first;
            long long currnode = pq.top().second;

            // pop frm pq
            pq.pop();

            // yaha vo already smaller wala nai karenge, since possible hai ki
            // new path mil jaaye

            // directly go to neighbours

            for (auto nbr : adj[currnode]) {
                long long nbrnode = nbr.first;
                long long nbrtime = nbr.second;

                // currnode se nbr node tak pahuch sakte hai with time
                // nbrtime+currtime, lekin agar nbr par already lesser time me
                // pahuch chuke hai toh yaha se jaane ka koi sense nai h(since
                // we will get bigger time which is not needed )
                if (nbrtime + currtime < time[nbrnode]) {
                    // we here means new path wala time is smaller

                    // toh yehi path pakad lo

                    // minm time update karo pehle toh
                    time[nbrnode] = nbrtime + currtime;

                    // ab new time ko pq me push kardo with nbr node for further
                    // paths
                    pq.push({time[nbrnode], nbrnode});

                    // ab iss neighour me pahuchne ka ne path mil gaya through
                    // currnode, toh agar currnode par 4 ways se pahuch sakte
                    // the, toh ab iss nbr node me bhi same 4 path se pahuch
                    // payenge apan , toh vahi update kardo

                    // basically, currnode se ab nbrnode par same path se pahuch
                    // payenge jis se currnode par pahuche the,

                    // if currnode par minm dst me (src se) pahuchne ke 5 paths
                    // the, toh ab same 5 paths se currnode se hoke apan nbrnode
                    // par aa sakte hai, toh vahi 5 path ka count laga denge nbr
                    // ke count me, since yehi 5 path se minm dist aayega , none
                    // otherwise
                    cnt[nbrnode] = cnt[currnode];
                } else if (nbrtime + currtime == time[nbrnode]) {
                    // we here means iss node par aane ka new path mila hai apan
                    // ko currnode ke through

                    // ie iss nbr node par apan pehle bhi kisi aur node se aaye
                    // honge minm dist leke, ab same minm dist waala new path se
                    // aa rahe hai, toh vo paths iss nbr node ke pathcnt me add
                    // honge

                    // since currnode se ab aa rahe hai toh agar
                    // currnode par jaane ke 3 paths the minm dist wale, toh ab
                    // vo 3 path can be used to reach nbrnode too, that too minm
                    // dist ke saath, toh vo paths seedhe seedhe pathcnt me add
                    // kar denge apan

                    // cnt add karte time modulo M le lena
                    cnt[nbrnode]=(cnt[nbrnode]+cnt[currnode])%M;
                }
            }
        }

        // now we have all path cnts frm src to all destinations
        // cnt[n-1] will give is the no of paths frm 0 to n-1 th node
        return cnt[n-1];
    }
};