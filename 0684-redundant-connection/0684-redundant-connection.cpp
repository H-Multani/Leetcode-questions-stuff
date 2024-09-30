using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
class DSU {
    vi parent, sizee;

public:
    int components;
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
    bool unionSets(int u, int v) {
        // nodes u and v diye hai, dono ke super parents nikalo

        int super_parent_of_u = parentt(u), super_parent_of_v = parentt(v);

        // if dono ke super parents common hai, means ye nodes already
        // indirectly connected hai, no need to connect these again(why?, dsu
        // bolta hai ki bas unconnected components ko apan connect kar sakte
        // hai, but here u and v are indirectly connected, since dono ka super
        // parent common hai, hence edge not formed here, edge is formed but
        // since indirectly connected hai already toh direct u to v ka edge
        // banane ka need nai hai also no need to change any component size
        // since dono abhi bhi common component me hi hai, return)
        if (super_parent_of_u == super_parent_of_v)
            return false;

        // by default we assume ki u wala node ka parent has bigger
        // size,(reduces some steps thats it)

        // and if we get ki u ke parent ka size kam hai, then swap u and v ke
        // parents, so that now, u wala parent has greater size
        if (sizee[super_parent_of_u] < sizee[super_parent_of_v])
            swap(super_parent_of_u, super_parent_of_v);
        // apan ne u and v ke parents ko change nai kiya hai haina, bas values
        // swap ki hai so that steps kam lage

        // now since u ke super parent ka size bada hai, hence vo(super parent
        // of u) phir se ek parent banega(super parent of v waale component ka),
        // for that

        // currently v ke super parent is a self parent, ie if
        // super_parent_of_v=2, means 2 ka parent 2 hi hai currently

        // set v ke super parent ka parent to u ka super parent
        // if if super_parent_of_v=2, ab ye 2 ke parent ko kar do
        // super_parent_of_u par

        // so now v wale components joined hai, and ab super_parent_of_v wala
        // self parent nai hai(ie it has a parent above itself)

        // eg dekh lo samajh aa jaega
        parent[super_parent_of_v] = super_parent_of_u;

        // chhote wale parent ka size add kar do bade wale parent ke size me
        // add, since both nodes(parents) are joined now
        sizee[super_parent_of_u] += sizee[super_parent_of_v];

        // now u and v are connected components, hence ek component overall me
        // se kam ho jaega
        components--;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // simple dsu approach

        vector<int> ans(2);
        // here we notice that no of nodes same as no of edges(usually 1 edge
        // less is reqd to connect same no of nodes)
        int nodes = edges.size();
        DSU dsu(nodes + 1);

        // NOTE: dsu me vertices are frm 0,1,2,...., but question me apan ko
        // 1,2,3... types vertices diye hai, toh iske vajah se error aa raha
        // hai, 2 options to sort this, either make dsu of n+1 size or send
        // nodes after decreasing node value by 1,

        // ie option 1=> either make dsu of size (nodes+1)(ive done this)
        // or option 2=>send nodes like (u-1,v-1), so that the vertex 1 becomes
        // 0 for the dsu, the vertex 3 becomes vertex 2 for the dsu and so on

        for (auto it : edges) {
            // current wali edge ko conect kar do
            int u = it[0], v = it[1];
            if (dsu.unionSets(u, v)) {
                // the funcn returns true means edges were not redundant and
                // needed to be joined to make the whole tree
            } else {
                // the funcn returned false means the edge was redundant, this
                // is a possible ans so update in ans
                // update directly since we need the ans that occurs last in the
                // input
                ans[0] = u;
                ans[1] = v;
            }
        }

        return ans;
    }
};