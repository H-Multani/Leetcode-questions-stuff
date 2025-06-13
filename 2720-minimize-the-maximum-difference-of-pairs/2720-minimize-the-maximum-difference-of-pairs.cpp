class Solution {
public:
    int n;

    bool isvalid(vector<int>& nums, int mid, int p) {

        // nums me iterate krke dekhenge ki kitne pairs h with diff<mid

        int i=0;
        int cnt=0;

        // iterate over nums
        while(i<n-1){
            
            if(abs(nums[i]-nums[i+1])<=mid){
                cnt++;
                // i and i+1 ki pairing done, increase i by 2
                i+=2;
            }
            else{
                // i ko bas 1 se badhao, goto next element
                i+=1;
            }
        }

        // agar p se zyada pairs mile hai toh return true GG
        if(cnt>=p) return true;

        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0, r = nums[n - 1] - nums[0];

        // binary search lagao
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // p of pairs dhundo such that maxm diff bw pts is mid
            if (isvalid(nums, mid, p)) {
                // could be a possible ans, update ans
                ans = mid;

                // chhota ans dhundne ke liye left jao
                r = mid - 1;
            } else {
                // means ans nai mila hai, chk right side
                l = mid + 1;
            }
        }

        return ans;
    }
};