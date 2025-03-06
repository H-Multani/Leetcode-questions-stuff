class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        unordered_map<int,int> mpp;

        for(auto it:grid){
            for(auto it2:it){
                mpp[it2]++;
            }
        }
        int twice;
        for(auto it:mpp){
            if(it.second>1){
                twice=it.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(twice);
        int ans2;
        for(auto i=1;i<=n*n;i++){
            if(mpp.find(i)==mpp.end()){
                ans2=i;
            }
        }
        ans.push_back(ans2);
        return ans;
    }
};