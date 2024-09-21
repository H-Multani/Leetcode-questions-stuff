class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> arr;
        for(auto i=1;i<=n;i++){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end());

        vector<int> ans;
        for(auto it:arr){
            auto val=stoi(it);
            ans.push_back(val);
        }
        return ans;
    }
};