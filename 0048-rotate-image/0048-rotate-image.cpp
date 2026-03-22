class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // isme same logic as lc 1886

        // rotate matlab [i][j] becomes [j][n-i-1]

        // first row becomes last column
        // second row becomes last 2nd column...
        // i th row becomes last se i th column(ie n-i-1 th column)

        // first column becomes first row
        // second column becomes second row
        // third column becomes third row...
        // j th column becomes j th row


        // laga do yehi logic

        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=matrix[i][j];
            }
        }

        matrix=ans;
    }
};