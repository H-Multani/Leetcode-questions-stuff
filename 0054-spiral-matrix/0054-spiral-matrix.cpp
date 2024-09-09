class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int dir = 0;
        while (left <= right && top <= bottom) {
            if (dir == 0) {
                // going towards right side
                // row fixed to top, move columns
                // top fixed, start frm left, go upto right
                for (int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                // iss row ka kaam ho gaya, inc top
                top++;

            }
            if (dir == 1) {
                // going down , starting frm top
                // column fixed to right, move rows
                // right fixed, start frm top, go upto bottom
                for (int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                // iss column ka kaam ho gaya, dec right
                right--;

            }
            if (dir == 2) {
                // going towards left side, starting frm rt side
                // row fixed to bottom, move columns
                // bottom  fixed, start frm right, go upto left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                // iss row ka kaam ho gaya, dec bottom to move to next row
                bottom--;

            } 
            if(dir==3) {
                // going up, starting frm bottom
                // column fixed to left, move rows
                // left fixed, start frm bottom, go upto top
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                // iss column ka kaam ho gaya, inc left
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};