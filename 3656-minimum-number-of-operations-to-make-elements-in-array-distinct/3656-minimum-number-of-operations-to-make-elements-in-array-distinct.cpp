class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // map me cnt lelo,
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;

        if (n == 1)
            return 0;
        if (n == 2) {
            if (mpp.size() == 2)
                return 0;
            return 1;
        }

        if (mpp.size() == n) {
            return 0;
        }

        // cout << n << " " << mpp.size() << endl;
        // cout << "start " << endl;
        // for (auto it : mpp)
        //     cout << it.first << " " << it.second << endl;
        // cout << "start " << endl;

        // we here means n>=3
        int ans = 0;

        for (int i = 0; i < n - 2; i += 3) {
            ans++;
            // i th banda alag karo
            mpp[nums[i]]--;
            // i+1 th banda alag karo
            mpp[nums[i + 1]]--;
            // i+2 th banda alag karo
            mpp[nums[i + 2]]--;

            // agar abhi bhi map ke saare ka freq>1 hai toh aage badh jana
            // remove karne ke liye, nai toh yehi break kro
            bool found = true;
            for (auto it : mpp) {
                if (it.second > 1) {
                    found = false;
                    break;
                }
                // cout << it.first << " " << it.second << endl;
            }

            // agar yaha koi bhi element ka freq>1 mila means abhi aage jaa kar
            // aur elements alag karne hai nai toh yehi se ans return krdo
            if (found)
                return ans;
            // cout << "curr " << i << " " << ans << endl;
        }

        // we here means saare elemnts alag kar diye hai apan ne return ans+1,
        // to indicate ki aage wale elements remove kiye hai 1 step me
        return ans + 1;
    }
};