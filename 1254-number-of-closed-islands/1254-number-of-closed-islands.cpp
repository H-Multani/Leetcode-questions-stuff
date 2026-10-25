#define vi vector<int>
class DSU {
    vi parent, sizee;

public:
    int components;
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

    void update(){
        for(int i=0;i<parent.size();i++){
            parentt(i);
        }
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // DSU lagega, sab join kar denge and baad me component count kar lenge
        int m = grid.size();
        int n = grid[0].size();

        // m*n size ka DSU bana denge and index ke liye grid[i][j] will be at
        // index i*n +j since to get to i th row and j th column we skipped over
        // i rows of n elements each and then current row me j elements skip
        // kiye hai

        DSU* dsu = new DSU(m * n + 1);

        // 1s ko nai chhedenge apan  toh all 1's are their separate component,
        // jo apan end me alag kar denge total component cnt se

        // toh 1s ka count lelo since each 1 will be separate component and 0s
        // ka cluster will be 1 component

        // toh ans will be total components- no of 1s

        // ok toh ek cheez aur karni hai ki closed island hona chahiye, ie 0s
        // should be surrounded by 1s, toh agar edge par 0s hai toh vo wala
        // island count nai hona chahiye

        // toh aisa kardo ki ek dummy node lelo maan lo m*n idx wala, and edge
        // par jitne 0s hai sabko iss dummy node se jod do

        // isse saare ke saare edge wale components ek dummy node se jud jayenge
        // ek component bana lenge saare, toh like in eg1 we had 4 components 0s
        // wale lekin isme se 2 components edge par the , toh ye 2 component
        // common node se jud jayenge toh ab ye 1 component ban jayega kaat peet
        // kar jitne bhi the, usko end me component cnt se -1 karke bhej denge

        // like maan lo currently we had 15 components of 1s, ek m*n wala
        // component, 5 components of 0s ka cluster and usme se 3 components are
        // on edge, toh ye saare uss m*n wale node se judd jayenge, isse ye
        // hoga ki 3 cluster of 0s are connected to m*n wala banda leading to
        // all becoming 1 big component jo end me component.cnt se -1 karke alag
        // kar denge, and agar koi bhi edge par cluster nai hua 0s ka tab bhi -1
        // krke m*n wala banda vaise bhi alag ho jayega,

        // so itll be like m*n wala component ya akele niklega(if edges par 0s
        // cluster nai h toh) ya big component ban kar niklega(0s ke cluster
        // edge wale nikal kar )


        // ek loop chala kar pehle saare edge wale 0s ko m*n wale se connect karlo
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((j==0 || i==0 || i==m-1 || j==n-1 )&& grid[i][j]==0){
                    // current ka idx is i*n+j
                    // jisse connect karna uska idx is m*n
                    dsu->unionSets(i*n+j,m*n);
                }
            }
        }

        // count lelo 1 ka
        int cnt = 0;

        for (auto i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // agar 1 hai toh cnt karlo bass
                if (grid[i][j] == 1) {
                    cnt++;
                    continue;
                } else {
                    // we at 0 , aaju baaju dekh lo mile koi aur 0 toh dono ke
                    // parents same kardo

                    // check up
                    if (i > 0 && grid[i - 1][j] == 0) {
                        // means ye bhi 0 hai, join kardo dono ko

                        // current banda is [i][j] at idx i*n+j
                        int idx = i * n + j;
                        // upar banda is [i-1][j] at idx (i-1)*n+j
                        int idx2 = (i - 1) * n + j;
                        dsu->unionSets(idx, idx2);
                    }
                    // check down
                    if (i < m - 1 && grid[i + 1][j] == 0) {
                        // means ye bhi 0 hai, join kardo dono ko

                        // current banda is [i][j] at idx i*n+j
                        int idx = (i)*n + j;
                        // neeche banda is [i+1][j] at idx (i+1)*n+j
                        int idx2 = (i + 1) * n + j;
                        dsu->unionSets(idx, idx2);
                    }
                    // check left
                    if (j > 0 && grid[i][j - 1] == 0) {
                        // means ye bhi 0 hai, join kardo dono ko

                        // current banda is [i][j] at idx i*n+j
                        int idx = i * n + j;
                        // upar banda is [i][j-1] at idx (i)*n+(j-1)
                        int idx2 = i * n + (j - 1);
                        dsu->unionSets(idx, idx2);
                    }
                    // check rt
                    if (j < n - 1 && grid[i][j + 1] == 0) {
                        // means ye bhi 0 hai, join kardo dono ko

                        // current banda is [i][j] at idx i*n+j
                        int idx = i * n + j;
                        // upar banda is [i][j+1] at idx (i)*n+(j+1)
                        int idx2 = i * n + (j + 1);
                        dsu->unionSets(idx, idx2);
                    }
                }
            }
        }

        // update kardo saare components ko
        // dsu->update();

        // aakhri me ans banane ke liye total components me se 1 wale components ka cnt alag kar dena and edge wala bhi alag kar dena 
        return dsu->components - cnt-1;
    }
};