class Solution {
public:
    void DFS(int src,vector<vector<int>> &adj,vector<bool> &vis){
        // src ko visited kar do
        vis[src]=true;

        // search the neighbours
        for(auto x:adj[src]){
            if(!vis[x]){
                // current neighbor not visited, visit it
                DFS(x,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj;
        int n=isConnected.size();
        adj.resize(n);
        // for(auto &it:isConnected){
            
        //         adj[it[0]].push_back(it[1]);
        //         adj[it[1]].push_back(it[0]);
            
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(adj.size(),false);

        int cnt=0;
        for(auto i=0;i<n;i++){
            if(visited[i]==false){
                DFS(i,adj,visited);
                cnt++;
            }
        }

        return cnt;

    }
};