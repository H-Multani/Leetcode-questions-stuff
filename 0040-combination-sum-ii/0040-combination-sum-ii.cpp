class Solution {
    vector<vector<int>> ans;
    // map<vector<int>, int> mpp;

public:
    void solve(int i, vector<int>& arr, int target, int currsum,
               vector<int>& temp) {
        if (currsum > target)
            return;

        if (currsum == target) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1])
                continue;

            // do
            temp.push_back(arr[j]);
            // explore
            solve(j+1, arr, target, currsum + arr[j], temp);
            // undo
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        // mpp.clear();
        // take not take approach used here
        // take or not take current element here
        vector<int> temp;

        // sorting the array before operating on it, bcoz otherwise ans aa raha
        // hai but not in the order they need
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, 0, temp);

        return ans;
    }
};