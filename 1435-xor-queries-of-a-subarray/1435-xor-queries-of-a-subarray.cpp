class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            int temp=0;
            for(int i=start;i<=end;i++){
                temp=temp^arr[i];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};