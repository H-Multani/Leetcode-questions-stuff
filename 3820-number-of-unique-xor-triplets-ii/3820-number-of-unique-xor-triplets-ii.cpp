class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // ek kaam karo n^2 me j and k se jitne ban rahe hai unique, daal do set
        // me, fir ek loop me i par chalna

        // integer can be 1500-> 10111011100
        // nearest power of 2 is 2048,

        // in any case, there can only be 2048 possible values since as we know
        // xor of any 3 nos in best case(biggest value) is nearest 2 ka power-1,
        // and most no of unique values which can be made is also 2048(0 to
        // 2047)

        // toh set zyada lamba nai hoga as such, but may cause TLE lets see

        // use unordered set, so that fetching efficient ho

        int n = nums.size();
        unordered_set<int> st;
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                st.insert(nums[j] ^ nums[k]);
            }
        }

        // ab iss set me iterate karke i wala loop chalao and ans banao new set
        // me
        unordered_set<int> st2;
        for (auto i = 0; i < n; i++) {
            for (auto it : st) {
                st2.insert(it ^ nums[i]);
            }
        }

        return st2.size();
    }
};