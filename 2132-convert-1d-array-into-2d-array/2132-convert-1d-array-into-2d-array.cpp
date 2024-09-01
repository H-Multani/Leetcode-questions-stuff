class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size()!=m*n) return ans;
        int curr_column=0;
        vector<int> temp;
        for(auto it:original){
            if(curr_column<n){
                temp.push_back(it);
                curr_column++;
            }
            else if(curr_column==n){
                // curr row filled, push to ans
                ans.push_back(temp);
                // clear the temp for elements of next row, and reset the column counter
                temp.clear();
                curr_column=0;

                // now add current element to new row
                temp.push_back(it);
                curr_column++;
            }
        }
        ans.push_back(temp);

        return ans;

    }
};