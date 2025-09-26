class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort karlo, then use binary search to get third value of triangle

        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // ye 2 sides lelo i and j wala, sum nikal lo
                int sm = nums[i] + nums[j];

                // now we need third side with value<sm, since tabhi valid hoga
                // triangle

                // use binary search, find third slide that is strictly< than
                // this sum

                // lower bound se we will get first value>= sm, which means ki
                // iss ke just pehle wali value<sm hogi definitely

                // ie apna kaam hai idx-1 se
                int idx = lower_bound(nums.begin() + j, nums.end(), sm) -
                          nums.begin();

                // this idx is the first banda with value>=sm, iske just pehle
                // wale bande se ban sakta hai triplet, and iske peeche walo se
                // bhi ban sakta hai triplet

                // ie 0 se leke idx-1 (inclusive) wale bando se bana sakte hai
                // apan triplet yaha

                // triplet will be (nums[i],nums[j],nums[0 to idx-1]);

                // lekin isme i and j wale toh already used hai , toh possible
                // hai ki same index ki value hi 2 baar use kar rahe ho

                // its also possible ki same triplet 2 baar count karre , dikkat

                // iss duvidha se bachne ke liye apan bas j se leke idx-1 tak ke
                // triplets count karenge, this way the triplets will be (i,j,k)
                // in which i<j<k and k->(j,idx-1), iss way saare triplet only
                // counted once

                // those triplets will be (idx-1)-j jitne
                // count karlo

                if (idx - j - 1 > 0)
                    ans += (idx - j - 1);
            }
        }

        return ans;
    }
};