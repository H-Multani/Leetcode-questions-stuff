class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for (auto it : nums1) {
            mpp[it]++;
        }
        int ans = INT_MAX;
        for (auto it : nums2) {
            auto temp = mpp.find(it);
            // if 'it'(element of 1st array) not present in 2nd array, chek next
            // element in the 2nd array

            // if temp=mpp.end() means that it(the element of 1st array) wasnt
            // found in 2nd array
            if (temp != mpp.end()) {
                // the first value that is found(ie it(element of 2nd array) is
                // present in 1st array) is the minm value that is common(since
                // both arrays are in dorted order)
                // so we just set that value as answer and break out of the
                // loop(since we only needed the smallest element)
                ans = it;
                break;
            }
        }
        if (ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};