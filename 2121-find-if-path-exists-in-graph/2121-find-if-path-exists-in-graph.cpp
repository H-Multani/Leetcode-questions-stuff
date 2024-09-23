class Solution {
public:
//referecne taken frm graph/9.cpp
    bool ans;
    void DFS(int src,vector<vector<int>> &adj,vector<bool> &vis, int dest){
        // src ko visited kar do
        vis[src]=true;
        // agar src dest tak pohoch jaaye, set ans as true
        if(src==dest){ ans=true; return;}

        // search the neighbours
        for(auto x:adj[src]){
            if(!vis[x]){
                if(x==dest){ ans = true; return;}
                // current neighbor not visited, visit it
                DFS(x,adj,vis,dest);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        ans=false;
        // approach:src se chalu krke dfs laga do
        // agar dest tak pahuch gaye toh return true, else return false
        // make adjacency list
        // unordered_map<int,vector<int>> adj;
        vector<vector<int>> adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(source==destination) return true;
        // vector<bool> visisted(adj.size(),false);
        vector<bool> visited(n,false);
        // for(auto it:adj){
        //     visited[it]=false;
        // }

        // ab dfs chala do, starting with 'source' as the original src
        DFS(source,adj,visited,destination);

        return ans;

    }
};