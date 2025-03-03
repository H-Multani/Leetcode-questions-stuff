class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // 3 arrays bana lo phir ans bana kar bhej do, simple bohot
        vector<int> before, pvt, after;
        for (auto it : nums) {
            if (it < pivot)
                before.push_back(it);
            else if (it == pivot)
                pvt.push_back(it);
            else
                after.push_back(it);
        }

        before.insert(before.end(), pvt.begin(), pvt.end());
        before.insert(before.end(), after.begin(), after.end());
        return before;
    }
};