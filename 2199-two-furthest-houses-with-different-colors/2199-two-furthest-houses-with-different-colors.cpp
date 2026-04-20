class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int,vector<int>> mpp;

        for(auto i=0;i<colors.size();i++){
            mpp[colors[i]].push_back(i);
        }

        int ans=INT_MIN;

        for(auto i=0;i<colors.size();i++){
            
            // iterate over the map
            for(auto it:mpp){
                if(it.first==colors[i]) continue;

                // compare only first and last element
                ans=max({ans,abs(it.second[0]-i),abs(it.second.back()-i)});
            }
        }

        return ans;



        
    }
};