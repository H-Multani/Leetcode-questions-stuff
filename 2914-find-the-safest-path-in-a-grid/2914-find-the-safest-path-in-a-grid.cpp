class Solution {
public:
    int n;
    bool solve2(int i,int j,vector<vector<bool>>& vis,int x,vector<vector<int>>& dist){
        if(i==n-1 && j==n-1 ){
            if(dist[i][j]>=x){
            // means ye safeness factor le sakte hai return true
            return true;
            }
            // means ye safeness factor nai le sakte
            else return false;
        }
        
        // we here means safeness factor kaafi hai, aage explore karo

        // current ko visited mark kardo
        vis[i][j]=true;
        
        bool ans=false;
        // explore down
        if(i+1<n && dist[i+1][j]>=x && !vis[i+1][j]){
            // explore
            ans=ans|solve2(i+1,j,vis,x,dist);
        }
        // explore up
        if(i-1>=0 && dist[i-1][j]>=x  && !vis[i-1][j]){
            // explore
            ans=ans|solve2(i-1,j,vis,x,dist);
        }
        // explore right
        if(j+1<n && dist[i][j+1]>=x  && !vis[i][j+1]){
            // explore
            ans=ans|solve2(i,j+1,vis,x,dist);
        }
        // explore left
        if(j-1>=0 && dist[i][j-1]>=x  && !vis[i][j-1]){
            // explore
            ans=ans|solve2(i,j-1,vis,x,dist);
        }

        return ans;
    }

    bool solve(int x,vector<vector<int>>& dist){
        // start frm (0,0), and agar (n-1,n-1) tak pahuch gaye means path valid hai return true

        // visited array lelo ek baar baar same jagah visit nai karna
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(dist[0][0]<x) return false;
        return solve2(0,0,vis,x,dist);
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // bfs use karo for filling up distances from thieves, layer by layer
        // har thief ka distances mark hote jaenge, and koi agar cell already
        // visited hai means uske nearest wale thief se already marked hai vo,
        // no need to visit again

        // this is essentially multi source BFS, since usually ek souce se bfs
        // karte the, yaha apan saare sources se ek common bfs chalenge for
        // filling distance of cells from thiefs

        // fir apan binary search on values karenge to get best path, usme bhi
        // andar dfs chal denge

        n = grid.size();

        // q bana lo gor bfs
        queue<pair<int, int>> q;
        // visited array lelo and dist array lelo
        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // iterate thru all the thiefs and q me dalte jao
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // current bande ko visited bhi mark karna, and iska level
                    // bhi set kar dena
                    q.push({i, j});
                    vis[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }

        // bfs chala do
        // levels ke liye ek counter lelo
        int lvl = 1;
        while (!q.empty()) {
            // currently kitne bande hai current level par
            int m = q.size();

            // ye saare m bande honge current lvl par, update the dist and inse
            // aage jitne aane hai q me daalte jana

            while (m--) {
                // curent banda nikalo
                auto [x,y] = q.front();
                q.pop();

                // current bande ka level already set hai aage explore karne ka
                // dekho

                // agar adjacets wala unvisited hai toh hi karna explore,
                // otherwise dont explore since already visited means pichle
                // iteration me closer wale thief se kar liye honge vo area
                // count, no need to do that again

                // if area is valid and unvisited tabhi visited mark karna and q me daal dena

                // explore down
                if(x+1<n && !vis[x+1][y]){
                    // means unvisited hai explore karlo
                    vis[x+1][y]=true;

                    // distance update kardo
                    dist[x+1][y]=lvl;
                    // aage explore karne ke liye q me daal do
                    q.push({x+1,y});
                }
                // explore up
                if(x-1>=0 && !vis[x-1][y]){
                    // means unvisited hai explore karlo
                    vis[x-1][y]=true;

                    // distance update kardo
                    dist[x-1][y]=lvl;
                    // aage explore karne ke liye q me daal do
                    q.push({x-1,y});
                }
                // explore right
                if(y+1<n && !vis[x][y+1]){
                    // means unvisited hai explore karlo
                    vis[x][y+1]=true;

                    // distance update kardo
                    dist[x][y+1]=lvl;
                    // aage explore karne ke liye q me daal do
                    q.push({x,y+1});
                }
                // explore left
                if(y-1>=0 && !vis[x][y-1]){
                    // means unvisited hai explore karlo
                    vis[x][y-1]=true;

                    // distance update kardo
                    dist[x][y-1]=lvl;
                    // aage explore karne ke liye q me daal do
                    q.push({x,y-1});
                }
            }

            // current level khatam hua and all have been marked, level aage badhao
            lvl++;
        }


        // means we are halfway done


        // ab ye distance array se ans nikalenge using binary search on ans

        // worst ans can be 0, best ans can be when koi na ko ie n+1, lekin we know atleast 1 thief is there, hence best ans can be n
        int l=0,r=n;
        int ans=-1;
        while(l<=r){
            // mid nikalo
            int mid=l+(r-l)/2;

            // kya mid jitna safeness factor par path niklega

            if(solve(mid,dist)){
                // means mid jitna safeness factor can be used , update ans
                ans=mid;

                // search right for better ans
                l=mid+1;
            }
            else{
                // search for valid ans
                r=mid-1;
            }
        }

        // ans bhej dena
        return ans;  
    }
};