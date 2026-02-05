class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            // jo likha hai kardo
            if (nums[i] > 0) {
                // right me nums[i] jitne steps chalo and update kardo value

                int idx = (i + nums[i]) % n;
                // mod n since circular array

                ans[i] = nums[idx];
            } else if (nums[i] < 0) {
                // left me abs(nums[i]) steps chalo and update value

                int idx = ((i + nums[i]) % n + n) % n;
                // apana abs(nums[i]) nai le rahe since we have to go left
                // anyway, toh abs() leke fir usko subtracct karu is preety
                // useless, and the rest ((..)%n+n)%n thing se +ve valid index
                // mil jaega apan ko which can be used to access elements at
                // nums array, thats all
                ans[i]=nums[idx];
            }
            else{
                ans[i]=nums[i];
            }
        }

        return ans;
    }
};