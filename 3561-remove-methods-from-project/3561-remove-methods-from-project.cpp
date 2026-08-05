#define vi vector<int>
class DSU {
    vi parent, sizee;
    int components;

public:
    vector<int> ans;
    DSU(int nodes) {
        // jitne nodes hai utne parent ke locations banao
        parent.resize(nodes);
        // jitne nodes hai utne parent ke locations banao, and since initialyy
        // all nodes are unconnected, hence sabka size 1 hai
        sizee.resize(nodes, 1);

        // iota funcn basically 0 se chalu karke increasing values bhar raha hai
        // parent array me its the exact same thing as int curr=0; for(int
        // i=0;i<parent.size();i++){
        //     parent[i]=curr;
        //     curr++;
        // }
        // basically makes parent array like {0,1,2,3,4,5,6....}
        // we do this since originally, saare nodes khud ke parent hai, ie 1 is
        // parent of itself,2 is parent of itself....
        iota(parent.begin(), parent.end(), 0);

        // since intially there are no edges, all nodes are separate components,
        // jaise jaise add karte jaenge edges ko components kam hote
        // jaenge(since joined edges will be in common graph)
        components = nodes;
        ans.clear();
    }

    // finds super parent of current node u
    int parentt(int u) {
        // if u ka parent u khud hai, means we have reached super parent, return
        // u(since its the super parent)
        if (parent[u] == u)
            return u;

        // find u ke parent ka parent
        // parent[u]=> u ka parent
        // parentt(parent[u])=> (u ka parent) ka parent
        // set parent[u] to u ke parent ka parent
        // and return parent[u]
        // logic of how this is useful in nb
        return parent[u] = parentt(parent[u]);
    }

    // joins node u and v
    void unionSets(int u, int v) {
        int super_parent_of_u = parentt(u), super_parent_of_v = parentt(v);
        if (super_parent_of_u == super_parent_of_v)
            return;
        if (sizee[super_parent_of_u] < sizee[super_parent_of_v])
            swap(super_parent_of_u, super_parent_of_v);

        parent[super_parent_of_v] = super_parent_of_u;
        sizee[super_parent_of_u] += sizee[super_parent_of_v];

        components--;
    }
};

class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // before everything we will make adj list and DSU se connect kar dena
        // will be useful later

        // sabse pehle toh k wale node se BFS chal lenge and suspicious nodes
        // nikal lenge

        // toh ye nodes ho gaye removal waale suspicious nodes

        // ab baaki nodes ko bhi connect kar denge, if they connect to
        // suspicious wale nodes, that specific suspicious node cant be removed,
        // in which case koi node cant be removed pure scene me

        // agar ek non sus node bhi connect hua kisi sus node se toh koi bhi
        // node remove nai hoga essentially(examples dekho) and explained below
        // too

        // suspicious mark karne ke liye we will use a boolean array

        // sabse pehle adj list banado
        vector<vector<int>> adj(n, vector<int>());
        DSU* dsu = new DSU(n);
        for (auto it : invocations) {
            // it[0] invoked it[1], toh directed edge banao
            adj[it[0]].push_back(it[1]);
            // inko dsu me bhi connect kardo
            dsu->unionSets(it[0], it[1]);
        }

        // ab k se BFS chal lo and jitne nodes directly connected hai unko
        // suspicious mark kardo

        vector<bool> sus(n + 1, false);
        vector<bool> vis(n + 1, false);

        queue<int> q;
        q.push(k);
        vis[k] = true;
        sus[k] = true;

        while (!q.empty()) {
            // current banda nikalo
            int curr = q.front();
            q.pop();

            // iss bande ke neighbours par jao and unvisited hai toh mark it sus
            for (auto it : adj[curr]) {
                if (!vis[it]) {
                    sus[it] = true;
                    vis[it] = true;
                    // push for exploration
                    q.push(it);
                }
            }
        }

        // now we have list of suspicious nodes

        // and bache hue nodes non suspicious hai, but since pura graph is
        // connected by DSU as well, hence

        // agar koi bhi non sus node is directly or in directly connected to sus
        // node we will know since dono ke parents same honge

        // agar EK(1) bhi non sus node conencted mila sus node se toh koi node
        // remove nai hoga in which case we will send full array

        // aisa kyu??
        // in this case non sus node ko remove nai kar sakte, lekin since vo sus
        // node se connected hai toh sus node ko bhi remove nai kar sakte, since
        // sus node ko remove nai kar sakte hence uske pure sus node ke tree me
        // se kisi ko bhi remove nai kar payenge, in this case we dont remove
        // any node and send list of all nodes

        // iterate over the non sus nodes, node ka super parent nikalo and k
        // wale node ka super parent nikalo, if these super parents are same
        // meaning non sus node is also connected, is case me yehi se full array
        // send kar dena

        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                // iss nod ka super parent
                int sp1 = dsu->parentt(i);
                // ka ka super parent
                int sp2 = dsu->parentt(k);

                if (sp1 == sp2) {
                    // means non sus node connected to sus node, koi remove nai
                    // hoga, send full array
                    vector<int> ans;
                    for (int i = 0; i < n; i++)
                        ans.push_back(i);
                    return ans;
                }
            }
        }

        // we here means koi non sus node isnt connected to sus node, in this
        // case sus nodes ko remove kar denge and no sus nodes ko arr me daal
        // kar bhej denge
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};