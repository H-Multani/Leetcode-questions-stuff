class Solution {
public:
    int findFinalValue(vector<int>& nums, int og) {
        unordered_set<int> st;

        for(auto it:nums){
            st.insert(it);
        }

        while(st.find(og)!=st.end()){
            og*=2;
        }

        return og;
    }
};