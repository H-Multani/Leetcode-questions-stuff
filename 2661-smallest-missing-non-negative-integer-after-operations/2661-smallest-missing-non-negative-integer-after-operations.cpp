class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int, int> mpp;

        // saare values par iterate karke mod karo val se and store ki konsa
        // wala mod kitni baar aara hai, will be sueful for mex
        for (auto it : nums) {
            // mod nikalo aur map me freq uncrease kardo

            // ts handles values of it<0
            int v = ((it % val) + val) % val;

            mpp[v]++;
        }

        // ab mex ke liye iterate karo

        int mex = 0;

        // agar iss mex%val ka count >0 hai in map means mex can be made by
        // applying some operations
        while (mpp[mex % val] > 0) {
            // we here means current wala mex can be made

            // toh current wale remainder se freq ek kam kardo, since 1 element
            // needed to get this current mex, toh we need to make sure ki same
            // element cannot be used multiple times, tabhi map se ek baari freq
            // alag karre
            mpp[mex % val]--;

            // ab mex aage badha do, since current value can be made toh mex nai
            // ho sakti, maybe aage wali value is mex
            mex++;
        }


        return mex;
    }
};