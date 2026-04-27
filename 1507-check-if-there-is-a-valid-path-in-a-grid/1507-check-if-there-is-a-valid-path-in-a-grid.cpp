class Solution {
public:
    int m, n;
    void solve(int i, int j, vector<vector<int>>& grid,
               vector<vector<bool>>& vis) {
        if (i >= m || j >= n)
            return ;

        if (i == m - 1 && j == n - 1) {
            vis[i][j] = true;
            return;
        }

        // mark curent place visited
        vis[i][j] = true;

        // explore areas

        int val = grid[i][j];

        // 4 areas hai left right top bottom

        // check some stuff before leaving,
        // 1> index valid ho,
        // 2-> aage wala not visited ho, tabhi explore kar paoge
        // 3-> aage wala path visible ho, ie agar left jaa rahe, toh left wale
        // bande par path hona chahiye uss tak aane ka like left se aa rahe agar
        // toh street 1,3,5 bass valid and so onn

        // go left(i,j-1)
        // left sirf tabhi jaa sakte agar current wala left path de, ie current
        // wala is street 1,3, or 5
        if (val == 1 || val == 3 || val == 5) {
            // means yaha se left jaa sakte hai

            if (j > 0 && vis[i][j - 1] == false) {
                // means yaha explore kar sakte hai apan, since unexplored path
                // hai

                // explore sirf tabhi karna agar left wala banda ke paas right
                // se entry khuli ho, since yaha se elft jaenge, aage wale ke
                // liye apan right se aa rahe, toh right wala area khula hona
                // chahiye, otherwise not

                // right wala area open= street 1,4,6, toh inme se koi bhi
                // street hai toh jaa kar karlo explore
                if (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
                    grid[i][j - 1] == 6) {
                    // means yaha explore kar sakte, karlo
                    solve(i, j - 1, grid, vis);
                }
            }
        }

        // go right(i,j+1)
        // right sirf tabhi jaa sakte agar current wala right path de
        if (val == 1 || val == 4 || val == 6) {
            if (j < n-1 && vis[i][j + 1] == false) {
                if (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
                    grid[i][j + 1] == 5) {
                    solve(i, j + 1, grid, vis);
                }
            }
        }

        // go down(i+1,j)
        if(val==2 || val==3 || val==4){
            if(i<m-1 && vis[i+1][j]==false){
                if(grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6){
                    solve(i+1,j,grid,vis);
                }
            }
        }

        // go up(i-1,j)
        if(val==2 || val==5 || val==6){
            if(i>0 && vis[i-1][j]==false){
                if(grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4){
                    solve(i-1,j,grid,vis);
                }
            }
        }

        return;
        
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        // edge cases kaafi honge lekin doable hai, ek visited vector bana do,
        // so that unique paths hi explore kare apan, and usme se agar kabhi
        // m-1,n-1 pahuche then return true
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // start only from (0,0);
        solve(0, 0, grid, vis);

        return vis[m - 1][n - 1];
    }
};