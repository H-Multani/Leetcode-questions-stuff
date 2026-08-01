class Solution {
public:
    int n;
    bool solve(int i, int j, long long sum1, long long sum2, vector<int>& nums,
               int turn) {
        // agar j<i aa gaya hai meaning sab khatam ho chuka hai, return kardo jo
        // bhi ans aaya
        if (j < i)
            return sum1 >= sum2;

        // if turn==0 means player 1 ka turn h explore karlo
        bool ans = false;
        if (turn == 0) {
            // player 1 can take i wala banda or j wala banda dono case chal lo
            // jo best utha lo

            // agla turn player 2 ka

            // yaha we do OR, since player 1 kisi bhi path se jeete chalega
            ans = ans | solve(i + 1, j, sum1 + nums[i], sum2, nums, 1);
            ans = ans | solve(i, j - 1, sum1 + nums[j], sum2, nums, 1);
            return ans;
        } else {
            // yaha we do AND, since if ans is true means player 1 jeetega,

            // which we dont want, we want player 2 to win here, toh AND
            // karenge, so that player 2 ke liye agar koi winning ka path
            // hai(dono me se ek bhi ans is false) then vo false carry forward
            // ho, since in this case player 2 will win,

            // we do this since both players play optimally, toh yaha OR lene se
            // player 2 bhi aise khelra such that player 1 jeet jaaye which
            // doesnt happen irl, hence here we use AND
            ans =(solve(i + 1, j, sum1, nums[i] + sum2, nums, 0) &&
                         solve(i, j - 1, sum1, nums[j] + sum2, nums, 0));
            // means turn==1, ie player 2 ka turn h, same logic dekhlo iska bhi
            return ans;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        // recursively check karlo agar kahi bhi true aaya toh return true else
        // false
        n = nums.size();

        // turn bhi save karlo kiska turn chalra hai
        return solve(0, n - 1, 0, 0, nums, 0);
    }
};