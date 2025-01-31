using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;

class DSU {
    vi parent;
    int components;

public:
    vi sizee;
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
    int largestIsland(vector<vector<int>>& grid) {
        // grid of nXn will be single array of size n*n, vahi use karenge DSU ke
        // liye

        // and (i,j) will become (i*n+j) for index purposes

        int n = grid.size();
        DSU dsu(n * n);

        // ab saare already made islands ke components bana do, like current
        // island ke saare (i,j) will have common component, common parent

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // iske 4 directions me jo bhi 1 hai, vo iske component ke
                    // honge, DSU se join krdo

                    // chk for i-1 th banda
                    if (i > 0 && grid[i - 1][j] == 1) {
                        // DSU se join krdo (i,j) and (i-1,j) ko
                        // (i,j)=i*n+j
                        // (i-1,j)=(i-1)*n+j
                        dsu.unionSets(i * n + j, (i - 1) * n + j);
                    }
                    // chk for i+1 th banda
                    if (i < n - 1 && grid[i + 1][j] == 1) {
                        // DSU se join krdo (i,j) and (i+1,j) ko
                        // (i,j)=i*n+j
                        // (i+1,j)=(i+1)*n+j
                        dsu.unionSets(i * n + j, (i + 1) * n + j);
                    }

                    // chk for j-1 th banda
                    if (j > 0 && grid[i][j - 1] == 1) {
                        // DSU se join krdo (i,j) and (i,j-1) ko
                        // (i,j)=i*n+j
                        // (i,j-1)=(i)*n+j-1
                        dsu.unionSets(i * n + j, i * n + (j - 1));
                    }
                    // chk for j+1 th banda
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        // DSU se join krdo (i,j) and (i,j+1) ko
                        // (i,j)=i*n+j
                        // (i,j+1)=(i)*n+j+1
                        dsu.unionSets(i * n + j, i * n + (j + 1));
                    }
                }
            }
        }

        // ab saare components ban gaye hai, islands ban gaye hai

        // ab har 0 ko 1 karke chk karo maxm ans kya nikal rha hai

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    // iss 0 ko 1 karne se kya ans aayega

                    int currans = 0;

                    // curr bande ko 1 bnaya hai toh uske liye island size
                    // increase by 1
                    currans++;

                    // ab set banayenge, components dhundenge
                    set<int> islands;

                    // 4 directions me search karo islands ke liye

                    // search (i-1,j)
                    if (i > 0 && grid[i - 1][j] == 1) {
                        // means curr bande ke neeche ek island hai, uss island
                        // se ye connected hua hai ab se, toh vo island ka size
                        // to be considered for ans of current case

                        // toh parent ko set me daal do, since island ke har
                        // bande ka common parent hoga, and uss parent ka size
                        // will be ki kitne bande hai island me

                        // toh neeche wale bande ke island ko include karne ke
                        // liye, uska parent set me daal do, baad me ek saath
                        // saare parents par iterate karenge overall size ke
                        // liye

                        // toh (i-1,j) ke parent nikalo, and insert krdo
                        islands.insert(dsu.parentt((i - 1) * n + j));
                    }
                    // search (i+1,j)
                    if (i < n - 1 && grid[i + 1][j] == 1) {
                        // means curr bande ke upar ek island hai, uss island
                        // se ye connected hua hai ab se, toh vo island ka size
                        // to be considered for ans of current case

                        // toh parent ko set me daal do, since island ke har
                        // bande ka common parent hoga, and uss parent ka size
                        // will be ki kitne bande hai island me

                        // toh uppar wale bande ke island ko include karne ke
                        // liye, uska parent set me daal do, baad me ek saath
                        // saare parents par iterate karenge overall size ke
                        // liye

                        // toh (i+1,j) ke parent nikalo, and insert krdo
                        islands.insert(dsu.parentt((i + 1) * n + j));
                    }

                    // search (i,j-1)
                    if (j > 0 && grid[i][j - 1] == 1) {
                        // means curr bande ke left ek island hai, uss island
                        // se ye connected hua hai ab se, toh vo island ka size
                        // to be considered for ans of current case

                        // toh parent ko set me daal do, since island ke har
                        // bande ka common parent hoga, and uss parent ka size
                        // will be ki kitne bande hai island me

                        // toh left wale bande ke island ko include karne ke
                        // liye, uska parent set me daal do, baad me ek saath
                        // saare parents par iterate karenge overall size ke
                        // liye

                        // toh (i,j-1) ke parent nikalo, and insert krdo
                        islands.insert(dsu.parentt(i * n + j - 1));
                    }
                    // search (i,j+1)
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        // means curr bande ke right me ek island hai, uss
                        // island se ye connected hua hai ab se, toh vo island
                        // ka size to be considered for ans of current case

                        // toh parent ko set me daal do, since island ke har
                        // bande ka common parent hoga, and uss parent ka size
                        // will be ki kitne bande hai island me

                        // toh right wale bande ke island ko include karne ke
                        // liye, uska parent set me daal do, baad me ek saath
                        // saare parents par iterate karenge overall size ke
                        // liye

                        // toh (i,j+1) ke parent nikalo, and insert krdo
                        islands.insert(dsu.parentt(i * n + j + 1));
                    }

                    // ab apne paas 4 directions ke respective islands ke
                    // parents aa gaye hai, ye saare islands will be joined when
                    // curr banda becomes 1, toh overall size of this new island
                    // will be sum of sizes of individual islands in the set
                    // +1(for counting current banda)

                    // yehi kardo, currsum ke liye saare parents ke sizes add
                    // kardo
                    for (auto it : islands) {
                        currans += dsu.sizee[it];
                    }

                    // now we have maxm island size if current banda becomes 1,
                    // update ans
                    ans = max(ans, currans);
                }
            }
        }

        // ab ans vaaste 2 options hai, ya toh 0 hoga kahi na kahi, in such case
        // ans!=0, ans is returned, no worries

        // case 2: pure grid me 0 nai hai, insuch case ans will be n*n, eg 3 dekh lo
        if(ans==0) return n*n;

        return ans;
    }
};