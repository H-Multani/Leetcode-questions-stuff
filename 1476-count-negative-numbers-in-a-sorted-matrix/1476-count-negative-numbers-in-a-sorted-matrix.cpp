class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;

        for(auto it:grid){
            for(auto it2:it){
                if(it2<0) ans++;
            }
        }

        return ans;
    }
};