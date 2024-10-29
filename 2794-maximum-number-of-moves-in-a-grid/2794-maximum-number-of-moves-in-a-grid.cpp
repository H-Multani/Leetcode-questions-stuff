class Solution {
    int maxdepth;
    int m,n;
    void solve(int i,int j, vector<vector<int>> &grid, int currdepth,vector<vector<int>> &memo){
        maxdepth=max(maxdepth,currdepth);
        if(i>=grid.size() || j>=grid[0].size()) return;
        if(memo[i][j]!=-1) return;

        memo[i][j]=currdepth;

        if( i-1>=0 && j+1<n && grid[i][j]<grid[i-1][j+1]){
            solve(i-1,j+1,grid,currdepth+1,memo);
        }
        if(j+1<n && grid[i][j]<grid[i][j+1]){
            solve(i,j+1,grid,currdepth+1,memo);
        }
        if( i+1<m && j+1<n &&  grid[i][j]<grid[i+1][j+1]){
            solve(i+1,j+1,grid,currdepth+1,memo);
        }
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        maxdepth=0;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        for(auto i=0;i<m;i++){
            solve(i,0,grid,0,memo);
        }

        return maxdepth;
    }
};