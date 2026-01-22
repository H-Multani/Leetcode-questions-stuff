class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // choice nahi hai, minm sum wala pair hi alag karna hai, toh its easier
        // than i thought

        int ans = 0;

        while (true) {
            // loop laga kar check karo if vector is in order
            bool inorder = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    inorder = false;
                    break;
                }
            }

            // agar order me hai toh break frm this loop
            if (inorder)
                break;

            // we here means nai hai order me
            int sum = INT_MAX, idx = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] + nums[i + 1] < sum) {
                    sum = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            // iss nums[i] is replaced by nums[i]+nums[i+1]=>sum
            nums[idx] = sum;
            // and nums[i+1] is removed
            nums.erase(nums.begin() + idx + 1);

            // 1 baar operation kiya count karo
            ans++;
        }

        return ans;
    }
};