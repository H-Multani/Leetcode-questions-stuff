class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            // st.insert(it);
            mpp[it]++;
        }

        vector<int> ans;
        for(auto it:nums){
            if(mpp.find(it)!=mpp.end() && mpp[it]==2){
                ans.push_back(it);
                mpp.erase(it);
            }
        }

        return ans;
    }
};