class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto it:nums){
            vector<int> temp;

            while(it>0){
                temp.push_back(it%10);
                it/=10;
            }

            reverse(temp.begin(),temp.end());

            ans.insert(ans.end(),temp.begin(),temp.end());
        }

        return ans;
    }
};