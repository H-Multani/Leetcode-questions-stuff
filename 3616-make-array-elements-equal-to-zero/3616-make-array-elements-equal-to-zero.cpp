class Solution {
public:
    int n;
    bool solve(int i, vector<int> nums, int startdir) {
        // loop karte jao and 0 count karte jao

        int zerocnt = 0;

        while (i >= 0 && i < n) {
            // iss direction me chalo
            i += startdir;

            // check if valid
            if(i>=n || i<0) break;

            // agar new position par 0 hai toh skip karke aur aadge badho
            if (nums[i] == 0)
                continue;

            // we here means positive value hai, decrement by 1
            nums[i]--;

            // direction reverse kardo 
            startdir*=-1;
        }

        zerocnt=count(nums.begin(),nums.end(),0);

        return zerocnt==n;
    }
    int countValidSelections(vector<int>& nums) {
        // har 0 se chalu karo explore karo ans ko
        n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // yaha se start karke left and right jao check if can be made
                // valid

                // ek baari left me jao, -1 bta rha hai ki left direction me
                // jana hai
                bool ans1 = solve(i, nums, -1);
                // ek baari right me jao
                bool ans2 = solve(i, nums, 1);

                if (ans1)
                    ans++;
                if (ans2)
                    ans++;
            }
        }

        return ans;
    }
};