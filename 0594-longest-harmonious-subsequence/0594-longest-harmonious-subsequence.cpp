class Solution {
public:
    int findLHS(vector<int>& nums) {
        // pehle sort kardo
        sort(nums.begin(), nums.end());
        // har value ka biggest idx store karlo map me ek
        unordered_map<int, int> mpp;
        // storing biggest idx since apan ko biggest subsequence banana hai

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        // ab har idx i se chalu karke ans dhundenge
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            // current banda is nums[i]

            // iske liye maxm valid value we can take(such that nums[i] is minm)
            // is nums[i]+1 since we need maxm-minm==1

            int val = nums[i] + 1;

            // agar ye value map me hai means uska idx nikalo
            int idx = -1;
            if (mpp.find(val) != mpp.end())
                idx = mpp[val];

            // agar idx!=-1, means current i th bande se start hone wala maxm
            // subsequence will be frm i to idx

            // since only then maxm-minm==1

            // so if its like [1,1,2,2], mpp[1]=1, mpp[2]=3

            // at i=0, nums[i]=1, isko agar minm maan na hai toh maxm posisble
            // is nums[i]+1=2, 2 ka maxm idx is mpp[2]=3, means current i ke
            // liye idx i=0 se idx 3 tak ke saare elements le sakta hu mai and
            // itll be valid since minm=1, maxm=2, beech me we have 3-0+1
            // elements which will be included for the maxm subsequence size thing

            // update ans
            if(idx!=-1) ans=max(ans,idx-i+1);
        }

        return ans;
    }
};