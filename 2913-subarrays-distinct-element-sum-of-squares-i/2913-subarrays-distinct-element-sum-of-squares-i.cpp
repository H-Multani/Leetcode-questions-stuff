class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // part 1 is easy, toh yaha toh seedha subarrays par chal kar hi nikal sakte ans

        int ans=0;

        int n=nums.size();

        for(int i=0;i<n;i++){

            // ek unordered_map lelo which will store distinct cnt
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){

                // current nums[i] se leke nums[j] tak ke subarray ke liye

                // current bande ko map me include karlo
                mpp[nums[j]]++;

                // kitne distinct elements hai
                int cnt=mpp.size();

                // sum of squares of distint cnt add kardo ans me
                ans+=(cnt*cnt);
            }
        }

        return ans;
    }
};