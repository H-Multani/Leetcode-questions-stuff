class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // basically idx a se start karke strictly increasing subarray nikalna
        // hai of size 2k,
        // beech me ek point par bas ye strictly increasing na ho toh chalega
        // which is idx (a+k-1,b), in dono idx par agar strictly increasing na
        // ho toh bhi chalega

        int n = nums.size();

        int l = 0, r = (2 * k) - 1;

        // constraints too small, check each window of size 2*k, jaha valid mil
        // jaaye return krdo

        // sliding windo GG
        while (r < n) {
            // current wali window check karo if valid

            // chk of a valid subarray 1 can be made
            // chk frm idx [l,r-k], basically size=k wala window, since b=a+k,
            // r=l+k similar shii

            // just dry run karo apne aap clear hoga
            // the l+1 is so that nums[i-1] ko access kar paaye
            bool subarr1 = true;
            for (int i = l + 1; i <= r - k; i++) {
                if (nums[i - 1] >= nums[i]) {
                    // we here means current subarray not valid
                    subarr1 = false;
                }
            }
            // cout<<"comparing "<<l<<" "<<r-k<<" "<<subarr1<<endl;

            // chk of a valid subarray 1 can be made
            // k size ka window starting idx l+k until end 
            bool subarr2 = true;
            for (int i = l + k + 1; i <= r; i++) {
                if (nums[i - 1] >= nums[i]) {
                    // we here means current subarray not valid
                    subarr2 = false;
                }
            }

            // agar dono valid subarrays can be made then return true, ezpz
            if (subarr1 && subarr2)
                return true;

            // l and r ko aage badha do
            l++;
            r++;
        }

        return false;
    }
};