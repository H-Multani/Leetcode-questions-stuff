class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> indexes(k, 0);
        // 'indexes' list ke index denotes ki konsi list par hai currently
        // unn indexes pr jo value hai, that denotes ki uss list ke konse index
        // pr jana hai like if indxes is like {1,3,2}, means list number 0 ke
        // index no 1 pr jana hai means list number 1 ke index no 3 pr jana hai
        // means list number 2 ke index no 2 pr jana hai... and so on

        vector<int> ans = {-1000000, 1000000};
        // is ans range

        while (true) {
            // minm element
            int minm = INT_MAX;
            // maxm element
            int maxm = INT_MIN;
            // minm element nums array ke konse list me hai, vo index(nums array
            // ke liye)
            int minmelement_index = 0;

            // indexes pr iterate krke minm and maxm banda nikalo
            for (auto i = 0; i < k; i++) {
                // nums ki konsi list pr jana hai
                int numsidx = i;
                // iss list pr jaane ke baad ab iss list me konse index pr jana
                // hai
                int idx_inside_curr_list = indexes[i];
                // the element at that posn in nums is
                int element = nums[numsidx][idx_inside_curr_list];

                // update and get the minm and maxm values
                // for minm
                if (element < minm) {
                    minm = element;
                    // iss minm element ka index update kar do, since we need
                    // this index
                    minmelement_index = numsidx;
                    // ie we need ki ye minm element konse list me hai nums
                    // ke,vo list ka index store kar lo, since aage iss list pr
                    // vapas aa kar index aage badhana padega
                }
                // for maxm
                // maxm apan bas comparison ke liye rakh rahe hai, maxm value ko
                // aage ya peeche nai karenge apan, toh uska bas element ka
                // value kaafi hai
                maxm = max(maxm, element);
            }

            // now we have minm and maxm of current range,
            // ab minm and maxm element se range update kar sakte hai, range
            // will be (minm,maxm), chk with current range we have and update
            if (maxm - minm < ans[1] - ans[0]) {
                // means current wali range smaller hai, update kar do
                ans[1] = maxm;
                ans[0] = minm;
            }

            // no need to check for a<c wala , since agar smaller milega
            // firstly, toh sabse smallest values wala range hi milega by
            // default, since elements sorted hai har list me

            // range update karne ke baad, ab iss range ko chhota karna hai,
            // minm ko aage badha kar
            // toh minm wala element konse list se mila vaha par jao, and index
            // +1 kar do, so that ye same minm value ab apan ko next time na
            // mile

            // minm element wale list par gaye, and uss pr jo index pr khade the
            // usse 1 aage aa gaye
            int newindex = indexes[minmelement_index] + 1;
            // chk if ye index pr jane se uss list ke put of bound toh nai
            // hore??
            if (newindex >= nums[minmelement_index].size()) {
                // if this runned means ki iss index ko aage badhane se out of
                // bound hora hai, toh aage nai badha sakte, and in this
                // scenario, ab aur range bhi decrease nai kar sakte hai, since
                // minm aage nai badh raha, hence in such case, jo range mila
                // hai vahi minm hai ab, break out of the loop
                break;
            }

            // we here means ki index update karne se out of bound nai hora hai,
            // ie minm aage badha paa rahe hai apan, toh badha do
            indexes[minmelement_index]=newindex;
            // or we can simply do indexes[minmelement_index]++;
            // by this work apan ne minm ko bhi aage badha diya hai
        }

        // we out o loop means jo range milna tha mil gaya, return the ans
        return ans;
    }
};