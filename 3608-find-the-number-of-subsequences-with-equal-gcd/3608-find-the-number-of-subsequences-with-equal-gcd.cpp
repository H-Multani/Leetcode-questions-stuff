class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    vector<vector<vector<int>>> memo;
    int solve(int i, int seq1, int seq2, vector<int>& nums) {
        // agar n tak pahuch gaye hai toh compare karke bhej dena 1
        if (i == n) {
            // compare karo if seq1==seq2, return 1 since we here means 1
            // successfull pair mila hai
            if (seq1 == seq2 && seq1 != 0)
                return 1;
            else
                return 0;
        }

        // memo me hai toh bhej do
        if (memo[i][seq1][seq2] != -1)
            return memo[i][seq1][seq2];

        // we here means current bande ko bhejna padega seq1, seq2 ya dono me
        // nai

        // teeno side se aane wale ans club kar dena
        int ans = 0;

        // seq1 me bhej kar dekho
        if (seq1 == 0) {
            // first element hai yehi bhej do as GCD, aage is se hi compare
            // karenge
            ans = (ans + solve(i + 1, nums[i], seq2, nums)) % mod;
        } else {
            // gcd lelo seq1 and current element ka since vo gcd aage jayega
            // baaki seq1 ke elements ke sath include hone ke liye
            ans = (ans + solve(i + 1, __gcd(seq1, nums[i]), seq2, nums)) % mod;
        }

        // seq2 me bhej kar dekho
        if (seq2 == 0) {
            // first element hai yehi bhej do as GCD, aage is se hi compare
            // karenge
            ans = (ans + solve(i + 1, seq1, nums[i], nums)) % mod;
        } else {
            // gcd lelo seq1 and current element ka since vo gcd aage jayega
            // baaki seq1 ke elements ke sath include hone ke liye
            ans = (ans + solve(i + 1, seq1, __gcd(seq2, nums[i]), nums)) % mod;
        }

        // dono me hi nai daalo
        ans = (ans + solve(i + 1, seq1, seq2, nums)) % mod;

        return memo[i][seq1][seq2] = ans % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        // dp hai toh take skip leke chal sakte hai, lets try that

        // count return kardena

        // initially -1 bhejenge and elements ka gcd nikalte jayenge and return
        // kar denge

        n = nums.size();

        // we know ki TLE fatega, memo laga do

        // 3 things change here, idx i,seq1,seq2, both of which will be 200 at
        // best
        memo.resize(n, vector<vector<int>>(201, vector<int>(201, -1)));

        return solve(0, 0, 0, nums);
        // start frm idx 0, initially seq1 and seq2 ke elements ka gcd is 0,
        // accordingly change karte rehna

        // pehle -1 rkha tha lekin usse memo me dikkat aari
    }
};