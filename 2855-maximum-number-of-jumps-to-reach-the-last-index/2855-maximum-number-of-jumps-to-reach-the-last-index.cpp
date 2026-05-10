class Solution {
public:
    int n;
    vector<int> memo;

    int solve(int i, vector<int>& nums, int t) {
        // agar n-1 pahich gaye toh return 0, otherwise chalte chalo

        if (i >= n - 1) {
            // means end pahuch chuke hai, return 0
            return 0;
        }

        // memo me hai toh bhej do ans
        if(memo[i]!=-1) return memo[i];

        // we here means explore karna baaki hai abhi, i+1 se start karke valid
        // paths par jao and explore karo

        bool found = false;
        // agar koi bhi path nai mile toh found will remain false

        // ans lelo best wala
        int ans = -1;

        // explore karo

        for (int j = i + 1; j < n; j++) {
            if (abs(nums[j] - nums[i]) <= t) {
                // means valid hai
                // path mila ek explore karo
                found = true;
                // best ans nikalo iss path ka
                ans = max(ans, 1 + solve(j, nums, t));
            }
        }

        // agar koi path nai mila abhi tak toh ans will remain -1, in such case
        // return INT_MIN, since yaha se path clearly n-1 tak nai pahuchayega
        if(ans<0) return memo[i]=INT_MIN;

        // nai toh ans return kardo
        return memo[i]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        // dp laga sakte hai explore wala
        n = nums.size();

        // TLE phek diya, memo bana lo, only 1 thing changes here, which is idx i,utne ka hi memo bana lo

        memo.resize(n+1,-1);
        int ans=solve(0, nums, target);
        return (ans<0)? -1: ans;
        // start frm idx 0
    }
};