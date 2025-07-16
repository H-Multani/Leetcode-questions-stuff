class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // odd cnt lelo, even cnt lelo
        int odd = 0, even = 0;
        for (auto it : nums) {
            if (it % 2)
                odd++;
            else
                even++;
        }

        // ab alternating wala nikalo

        // initial previous parity chahiye rahegi
        int prev = nums[0] % 2;

        // ab idx=1 th bande se alternating parity chk karte jao, and cnt
        // increase karte jana agar mile toh

        // cnt lelo 1 se, since kuch bhi nai milega toh size 1 ka toh
        // subsequence rahega, or we can think of this as counting idx=0 wala
        // banda ka parity
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            // curr ka parity will be nums[i]%2;
            if (nums[i] % 2 != prev) {
                // means alternate hori hai parity, count karlo isko
                cnt++;
                // ab parity update kardo, if prev parity was 1, toh current
                // bande ka parity needed=0,and ye mil gaya toh current ka
                // parity=0, next wale ka parity needed=1, yehi alternatig
                // chahiye, toh prev parity update krdo
                prev = nums[i] % 2;
            }
        }

        // ab 3 ans hai apne paas, jo bhi maxm h bhj do
        return max({odd, even, cnt});
    }
};