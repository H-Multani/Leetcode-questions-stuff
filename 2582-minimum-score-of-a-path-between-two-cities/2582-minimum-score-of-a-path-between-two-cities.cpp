
#define ll long long
#define vec std::vector<long long>



class DSU {
    vec parent, sizee;

public:
    ll components;
    DSU(ll nodes) {
        parent.resize(nodes);
        sizee.resize(nodes, 1);
        iota(parent.begin(), parent.end(), 0);
        components = nodes;
    }

    ll find(ll u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    bool unionSets(ll u, ll v) {
        ll super_parent_of_u = find(u), super_parent_of_v = find(v);
        if (super_parent_of_u == super_parent_of_v)
            return false;
        if (sizee[super_parent_of_u] < sizee[super_parent_of_v])
            swap(super_parent_of_u, super_parent_of_v);

        parent[super_parent_of_v] = super_parent_of_u;
        sizee[super_parent_of_u] += sizee[super_parent_of_v];
        components--;
        return true;
    }
};



class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // ek kaam karlo, dsu se join kardo sab ko, fir parent nikal lena 1 and
        // n ka, jin jin nodes ka same parent hua, means vo path me jaa sakte
        // hai, fir roads par ek bari iterate maar kar dekh lena, agar dono
        // nodes me se koi bhi ek required parent wala hai means iska edge can
        // be used for minm score, utha lena

        // like suppose eg2 me all nodes have parent 1 after connection, and we
        // iterate through the roads vector now, we have ai and bi, agar dono me
        // se kisi ka bhi parent 1 hua means ye (ai ya b1) same group ke hai
        // jisme 1 to n ka path aayega, toh current wale distance_i ko use kar
        // sakte hai for getting minm score, for eg2,this will be 2 since minm
        // dist 2 aaya which will be considered for ans

        // all in all the edge doesnt even need to be in the actual path from 1
        // to n, bass same grp me ho toh vo edge ko consider kar sakte hai apan
        // in path for minm score

        DSU* dsu=new DSU(n+1);

        // dsu se conenct kardo sabko

        for(auto it:roads){
            dsu->unionSets(it[0],it[1]);
        }


        // ab bas check karna hai ki parent 1 and n ka parent kon hai
        int parent1=dsu->find(1);
        int parentn=dsu->find(n);

        // agar dono ke parents same nai hue means connected hi nai hao in which case return -1
        if(parent1!=parentn) return -1;


        // we here means parents common hai, ab iterate through roads, agar kahi bhi node ka parent same as parent1(or parentn) then that means conencted hai, means the edge can be considered for smallest score, bana lo

        int ans=INT_MAX;

        for(auto it:roads){
            if(dsu->find(it[0])==parent1 || dsu->find(it[1])==parent1){
                // means dono me se ek node is connected to node 1 and n, toh this edge can be considered for minm score, update kardo
                ans=min(ans,it[2]);
            }
        }

        return ans;

    }
};