class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size()!=m*n) return ans;
        int curr_row_idx=0;
        vector<int> temp;
        for(auto it:original){
            if(curr_row_idx<n){
                temp.push_back(it);
                curr_row_idx++;
            }
            else if(curr_row_idx==n){
                // curr row filled, push to ans
                ans.push_back(temp);
                // clear the temp for elements of next row, and reset the column counter
                temp.clear();
                curr_row_idx=0;

                // now add current element to new row
                temp.push_back(it);
                curr_row_idx++;
            }
        }
        ans.push_back(temp);

        return ans;

    }
};