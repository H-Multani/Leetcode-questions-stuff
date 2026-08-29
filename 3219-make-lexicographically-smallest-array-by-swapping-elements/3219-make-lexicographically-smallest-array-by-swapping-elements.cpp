class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int grpno = 0;
        unordered_map<int, int> numtogrp;

        numtogrp[vec[0]] = grpno;

        unordered_map<int, list<int>> grptolist;
        // list since, push back, popback, pushfront, popfront O(1) me hoyega

        grptolist[grpno].push_back(vec[0]);

        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                grpno++;
            }

            numtogrp[vec[i]] = grpno;
            grptolist[grpno].push_back(vec[i]);
        }


        // build the ans- merge the groups
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int num=nums[i];

            int grp=numtogrp[num];

            // smallest available number in this grp
            ans[i]=*(grptolist[grp].begin());
            // use hogaya toh delete kardo used element ko
            grptolist[grp].pop_front();

        }

        return ans;
    }
};