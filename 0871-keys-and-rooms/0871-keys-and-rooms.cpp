class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto nbr:rooms[curr]){
                if(vis[nbr]==false){
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }

        for(auto it:vis){
            if(it==false) return false;
        }
        return true;
    }
};