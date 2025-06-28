class Solution {
public:
    static bool comp(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second < p2.second)
            return true;
        return false;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // max heap bana kar elements daal do, k elements nikal lo aur ek temp
        // ans me daal do
        // pq me pair daal dena, value and index
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // top k wale elements nikal kar daal do
        vector<pair<int, int>> tempans;
        while (k--) {
            tempans.push_back(pq.top());
            pq.pop();
        }

        vector<int> ans;

        // sort kardo tempans ko, index ke accd
        sort(tempans.begin(), tempans.end(), comp);

        // ans me daal do ab elements sorted order me(sorted accd to index),
        // since subsequence me elements order me chahiye hote hai

        for(auto it:tempans){
            ans.push_back(it.first);
        }

        return ans;
    }
};