class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        // 2^n subset banenge, bits will go frm 0 to n-1
        int subsets = 1 << n;
        vector<vector<int>> ans;
        // ab loop karo
        for (int num = 0; num < subsets; num++) {
            // curr num wale bande par iterate karenge, jo bit set hoga, vahi
            // wala nums me daal lenge

            vector<int> temp;

            // iterate over the number frm 0 to i th bits
            for (int i = 0; i < n; i++) {
                // 1<<i, apan ko current i th bit frm rt side ka value 1 karke
                // dega

                // maan lo num=12-> 1100 (binary), means current subset me
                // i=2,i=3 wale bande hone chahiye

                // maan lo i=3, toh we get 1000 (binary) iska bitwise AND
                // karenge num se toh i=3 rd bit frm rt side milega, ie AND of
                // 1100 and 1000, we get 1000, which is a non 0 number, means
                // i=3 rd bit set hai right se(jo ki hai bhi)
                if (num & (1 << i)) {
                    // means i th banda lena hai lelo
                    temp.push_back(nums[i]);
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};