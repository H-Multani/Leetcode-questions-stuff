#define ll long long
#define vec std::vector<long long>

class DSU {

public:
    vec parent, sizee;
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

    // update function bana do ek, which will keep the parent array updated
    void update(){
        for(int i=0;i<parent.size();i++){
            parent[i]=find(parent[i]);
        }

        return;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        // ek set lelo which will store konsa tower down hai
        unordered_set<int> down;

        // dsu bana do c+1 size ka since we need 1 based indexing
        DSU grid(c+1) ;

        // ab connect kardo connections me iterate karke
        for (auto it : connections) {
            grid.unionSets(it[0], it[1]);
        }

        // saare connections done and saare grids made now

        // abb apan ek map with set lenge which will store ki har grid par konsa
        // element hai like ig towers 2,4,5,1 are on grid 2, then map me key
        // will be 2, value will be {1,2,4,5} isse apan [1,x] wali queries ke
        // liye smallest id jaldi nikal payenge

        unordered_map<int,set<int>> towers;

        // update kardo sabke super parents
        grid.update();

        // iterate over dsu.parent

        // start frm 1 since 0 wala tower akela hai not needed
        for(int i=1;i<grid.parent.size();i++){
            // current tower is i

            // current tower konse grid ka hai ye uska parent batayega

            // super parent nikal lo best
            int parentt=grid.parent[i];

            // iss parent ke set me current tower ke id ko daal do
            towers[parentt].insert(i);
        }

        // ab apna kaam mostly done hai query par iterate karo bass

        vector<int> ans;
        for(auto it:queries){
            // agar type 2 hai toh
            if(it[0]==2){
                // means x wala tower down karo
                int x=it[1];

                // sabse pehle ye tower konse grid me hai vo niklo
                int parentt=grid.parent[x];

                // map me se iss bande ko remove krdo
                towers[parentt].erase(x);

                // kaam khatam
            }
            else{
                // print parents of each 
                // for(int i=1;i<grid.parent.size();i++){
                //     cout<<i<<" ka parent "<<grid.parent[i]<<endl;
                // }
                // cout<<endl;

                // we here means type 1 hai
                int x=it[1];

                // pehle iss x ka parent nikalo
                int parentt=grid.parent[x];

                // ab check karo if ye availale hai ki nai map me
                if(towers[parentt].find(x)==towers[parentt].end()){
                    // means nai hai, in such case smallest id nikal lo

                    // agar set empty hai toh -1 ans me daal do
                    if(towers[parentt].size()==0){
                        ans.push_back(-1);
                        continue;
                    }
                    int id=*towers[parentt].begin();

                    // iss wali id ko ans me daal do
                    ans.push_back(id);
                }
                else{
                    // we here means ki tower is available, in such case khud hi manage kar lega tower
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};