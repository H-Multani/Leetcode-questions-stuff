class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // common nikalo
        int n=tops.size();

        // ya toh tops[0] common hoga ya bottoms[0]
        // ek ek loop laga kar chk krlo

        bool istops0=true,isbottom0=true;
        for(int i=1;i<n;i++){
            if(tops[i]!=tops[0] && bottoms[i]!=tops[0]) istops0=false;
        }
        for(int i=1;i<n;i++){
            if(tops[i]!=bottoms[0] && bottoms[i]!=bottoms[0]) isbottom0=false;
        }

        // agar dono nai h toh return false
        if(!istops0 && !isbottom0 ) return -1;

        int common;

        if(istops0) common=tops[0];
        if(isbottom0) common=bottoms[0];
    
        int topscnt = 0, bottomcnt = 0;

        for (int i = 0; i < n; i++) {
            if (tops[i] == common)
                topscnt++;
            if (bottoms[i] == common)
                bottomcnt++;
        }

        // tops me topscnt jitne common bande hai, bache kitne swaps lagenge to
        // get bottom waale at top too= n-topscnt

        // similar for bottomcnt

        // toh ab inn swaps me jo minm h vahi ans h

        return min(n - topscnt, n - bottomcnt);
    }
};