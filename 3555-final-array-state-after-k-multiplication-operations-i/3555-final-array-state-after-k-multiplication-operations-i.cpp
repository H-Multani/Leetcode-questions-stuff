class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto i = 0; i < nums.size(); i++) {
            pair<int, int> temp;
            temp.first = nums[i];
            temp.second = i;
            pq.push(temp);
        }

        while (k--) {
            int idx = pq.top().second;
            nums[idx] *= multiplier;
            pq.pop();

            pair<int, int> temp;
            temp.first = nums[idx];
            temp.second = idx;
            pq.push(temp);
        }

        return nums;
    }
};