class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,pair<int,int>> mpp; // stores node and degree(in and out)
        if(n==1) return 1;
        for(auto it:trust){
            mpp[it[0]].second++;
            mpp[it[1]].first++;
            // if(mpp.find(it[1])==mpp.end()) mpp[it[1]]=0;
        }
        
        for(auto it:mpp){
            if(it.second.second==0 && it.second.first==n-1) return it.first;
        }

        return -1;
    }
};