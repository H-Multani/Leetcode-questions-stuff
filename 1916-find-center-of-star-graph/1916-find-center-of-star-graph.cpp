class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        for(auto it:edges){
            // count har edge se kitne nodes connected hai
            // it[0] connected to it[1], hence incremenet count
            // it[1] connected to it[0]
            mpp[it[0]]++;
            mpp[it[1]]++;
        }

        int nodecnt=mpp.size();

        for(auto it:mpp){
            if(it.second==nodecnt-1){
                // nodecnt-1 since current wale node ko count nai krna hai
                return it.first;
            }
        }
        return 0;
    }
};