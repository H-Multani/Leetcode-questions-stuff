class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});

        while (--numRows) {
            vector<int> temp;
            vector<int> prev = ans.back();
            temp.push_back(1);

            for (int i = 0; i < prev.size(); i++) {

                if (i == prev.size() - 1) {
                    temp.push_back(1);
                    continue;
                }
                temp.push_back(prev[i] + prev[i + 1]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};