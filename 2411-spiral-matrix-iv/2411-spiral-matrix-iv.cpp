/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // spiral matrix 2 ka code likh denge pura, but instead of counter we use
        // element frm head of linked list, and bharne ke baad head ko aage badha denge,
        // and incase head =null ho jaaye in that case -1 store karvaa denge simple

        vector<vector<int>> ans(m,vector<int>(n));
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        int dir = 0;
        while (left <= right && top <= bottom) {
            if (dir == 0) {
                // going towards right side
                // row fixed to top, move columns
                // top fixed, start frm left, go upto right
                for (int i = left; i <= right; i++) {
                    // jo pehle print kar rahe the, ab uss jagah me value bharna hai
                    // ans.push_back(matrix[top][i]);

                    if(head!=nullptr){
                        ans[top][i] = head->val;
                        // head aage badha do bharne ke baad
                        head=head->next;
                    }
                    else{
                        // means list ke end par pohoch chuke hai, -1 daald o value
                        ans[top][i] =-1;
                    }
                }
                // iss row ka kaam ho gaya, inc top
                top++;
            }
            if (dir == 1) {
                // going down , starting frm top
                // column fixed to right, move rows
                // right fixed, start frm top, go upto bottom
                // int starting=0;
                // cout << "starting is " << starting << endl;
                for (int i = top; i <= bottom; i++) {
                    // ans.push_back(matrix[i][right]);
                    if(head!=nullptr){
                        ans[i][right] = head->val;
                        // head aage badha do bharne ke baad
                        head=head->next;
                    }
                    else{
                        // means list ke end par pohoch chuke hai, -1 daald o value
                        ans[i][right] =-1;
                    }
                }
                // iss column ka kaam ho gaya, dec right
                right--;
            }
            if (dir == 2) {
                // going towards left side, starting frm rt side
                // row fixed to bottom, move columns
                // bottom  fixed, start frm right, go upto left

                for (int i = right; i >= left; i--) {
                    // ans.push_back(matrix[bottom][i]);
                    if(head!=nullptr){
                        ans[bottom][i] = head->val;
                        head=head->next;
                    }
                    else{
                        ans[bottom][i] =-1;
                    }
                }
                // iss row ka kaam ho gaya, dec bottom to move to next row
                bottom--;
            }
            if (dir == 3) {
                // going up, starting frm bottom
                // column fixed to left, move rows
                // left fixed, start frm bottom, go upto top

                for (int i = bottom; i >= top; i--) {
                    // ans.push_back(matrix[i][left]);
                    if(head!=nullptr){
                        ans[i][left] =head->val;
                        head=head->next;
                    }
                    else{
                        ans[i][left] =-1;

                    }
                }
                // iss column ka kaam ho gaya, inc left
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};