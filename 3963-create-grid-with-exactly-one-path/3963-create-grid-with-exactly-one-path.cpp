class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // koi bhi de sakte hai na why not give the easiest one, top row and
        // right most column normal rakho baakki sab obstacle rakh dena

        vector<string> ans(m);
        // start me saare obstacle rakh denge, 
        string col="";
        for(int i=0;i<n;i++){
            col+='#';
        }
        for(int i=0;i<m;i++){
            ans[i]=col;
        }

        // ab first row ke saare bande . kardo
        for(int i=0;i<n;i++){
            // first row har col ke bande . bana denge
            ans[0][i]='.';
        }
        // similarly last wale column ke saare bande . bana denge
        for(int i=0;i<m;i++){
            // first row har col ke bande . bana denge
            ans[i][n-1]='.';
        }

        // essentially for 3x4 grid we are making
        // ....
        // ###.
        // ###.
        // has only 1 valid path daudega ye


        return ans; 
    }
};