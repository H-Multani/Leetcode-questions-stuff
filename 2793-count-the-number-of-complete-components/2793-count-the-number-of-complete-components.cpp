
using vi = vector<int>;
class DSU {

public:
    vi parent, sizee;
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
    void unionSets(int u, int v) {
        // nodes u and v diye hai, dono ke super parents nikalo

        int super_parent_of_u = parentt(u), super_parent_of_v = parentt(v);

        // if dono ke super parents common hai, means ye nodes already
        // indirectly connected hai, no need to connect these again(why?, dsu
        // bolta hai ki bas unconnected components ko apan connect kar sakte
        // hai, but here u and v are indirectly connected, since dono ka super
        // parent common hai, hence edge not formed here, return)
        if (super_parent_of_u == super_parent_of_v)
            return;

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

        // chhote wale parent ka size add kar do bade wale parent ke size me ,
        // since both nodes(u and v) are joined now, and they have a common
        // parent now, tabhi chhote wale parent(jo pehle khud super parent tha,
        // aur ab nai rha, tbhi size ad krva rhe, since ho skta ki ye(super
        // parent of v) khud 2,3,4 nodes ka parent ho , and ab in saare child
        // nodes ke super parent badlenge toh size update karna pdega na) ka
        // size ab bade wale parent me add karna padega

        // super_parent_of_v wala node khud pehle size[super_parent_of_v]->itne
        // nodes ka super parent tha, ab nai raha toh inn saare childeren nodes
        // ka parent ab super_parent_of_u ban chuka hai, toh jitne new children
        // add hue hai, update karvana padega na super_parent_of_v ke size me,
        // thats why
        sizee[super_parent_of_u] += sizee[super_parent_of_v];

        // now u and v are connected components, hence ek component overall me
        // se kam ho jaega
        components--;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // okay simplr DSU se toh nai hona, but DSU can be helpful here

        // n nodes ka DSU bana do
        DSU dsu(n);

        // ab bass saare edges par iterate karke join karte jao

        for (auto it : edges) {
            dsu.unionSets(it[0], it[1]);
        }

        // ab saare connected components ke common parents honge, toh sabka size
        // common hoga

        // hint 2 and 3 dekho, now we need to store ki current component me
        // kitne edges hai

        // ye map me store karlo
        unordered_map<int, int> mpp;
        // stores ki current component me kitne edges hai
        // mpp[4]=9 means ki 4 value ke super parent waale component me 9
        // edges hai ab iss 4 parent wale component me kitne elements hai ?? its
        // sizee[4]

        // or we can also say that the component with super parent as node 4 has
        // 9 edges in it, so the component has 9 edges in it, and the no of
        // nodes in the component is sizee[4], in this we apply the hint3 check,
        // and update out count accordingly

        // simple really

        // so iterate the edges once again to fill the parent and edgecnt map
        for (auto it : edges) {
            // it[0] and it[1] ke beech me edge hai toh dono ka super parent
            // common hoga since they are already connected(prev loop)

            // toh dono se koi bhi ek leke uske super parent ke against
            // edgecnt+1 kardo
            mpp[dsu.parent[it[0]]]++;
        }

        // ab iss super parent waale map par iterate karenge and hint3 wala chk
        // lagayenge, and update karenge count ko accordingly
        int ans = 0;

        for (auto it : mpp) {
            // current component ka super parent kon h
            int parent = it.first;

            // iss super parent ke component me kitne edges hai
            int edgecnt = it.second;

            // iss super parent ke component me kitne nodes hai?
            int nodecnt = dsu.sizee[parent];

            // now if this component is complete connected, means each node is
            // connected to each other node of the component

            // ie if nodecnt=4,means node 0 is connected to nodes 1,2,3 and
            // node 1 is connected to nodes 2,3, and node 2 is connected to node
            // 3, basically all nodes connected to each other by direct edge

            // so for nodecnt=4, we need atleast 4*(4-1)/2=6 edges
            // so for nodecnt=5, we need atleast 5*(5-1)/2=10 edges
            // so for nodecnt=6, we need atleast 6*(6-1)/2=15 edges to connect
            // each node to the rest of the nodes thereby making the component
            // complete connected

            // toh yehi logic agar baith raha ha already means component is
            // already connected, in such case ans++
            if (nodecnt * (nodecnt - 1) / 2 == edgecnt)
                ans++;
        }

        // also note that the components with 0 edges are also valid complete
        // components toh unko consider karne ke liye we subtract the mpp.size
        // from dsu.components

        // since dsu.components will give the total no of components in the
        // graph(in eg1 this is 3 components) and mpp.size will give the no of
        // components with >1 nodes in it(in eg1 this is 2), toh remaining
        // components all have only 1 node in them, but since they are also
        // valid hence we have to count them too

        // for example in eg1, node 5 is a valid component and has to be counted

        // so to ans we add dsu.components-mpp.size();
        ans += dsu.components - mpp.size();

        return ans;
    }
};