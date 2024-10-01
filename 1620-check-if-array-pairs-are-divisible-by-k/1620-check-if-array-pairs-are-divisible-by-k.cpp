class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainders;
        for (auto it : arr) {
            int rem = ((it % k) + k) % k;
            // for cases if arr[i] is negative, this is the way to get remainder
            // of -ve values
            remainders[rem]++;
        }

        if (remainders.find(0) != remainders.end() && remainders[0] % 2 != 0) {
            // 0 remainder wale odd values hai
            // saare 0 remainders waalo ke pairs nai ban paenge
            // hence in such case return false
            return false;
        }

        for (auto i = 0; i < arr.size(); i++) {
            // curr ka remainder= ((arr[i]%k)+k)%k
            // iska pair banane ke liye remainder needed= k- (curr ka remainder)
            // since pair tabhi banega if (arr[i]+arr[j])%k==0, aur ye tab hoga
            // if (arr[i]%k)+(arr[j]%k)==k, remainder 0 dene waalo ke liye case
            // alag banega bas
            int remainder_first_half = ((arr[i] % k) + k) % k;
            // incase arr[i] is negative this is the remainder, also works for +ve values
            int remainder_other_half = k - remainder_first_half;
            // cout << arr[i] % k << " " << remainder_pair_key << endl;

            // remainder 0 wala value hai agar(ie curr value ka remainder 0
            // hai), upar false nai aaya means aise 0 remainder wale even values
            // hai already, no need to check for this, direct continue karo
            if (remainder_first_half== 0)
                continue;

            // now we have 2 keys for the remainders map
            // first key is remainder_first_half and second key is remainder_other_half
            // agar dono key ka value same hua means arr[i] wale element ke liye
            // pair ban sakta hai, in such case move to chk pair for the next value
            // otherwise if value not same means arr[i] wale element ke liye
            // pair nai ban paega, in such case return false
            if (remainders[remainder_first_half] !=
                remainders[remainder_other_half]) {
                return false;
            }
        }

        return true;
    }
};