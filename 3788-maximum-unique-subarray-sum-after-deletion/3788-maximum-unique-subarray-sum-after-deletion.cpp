class Solution {
public:
    int maxSum(vector<int>& nums) {
        // jitne elements duplicate hore hai sab delete kar denge first of all

        // then maxm subarray sum laga denge seedhe seeedha since values can be
        // -ve as well, simple kadanes

        // no need for kadanes, saare -ve elements bhi alag kar denge, so that
        // remaining subarray me saare elements +Ve rahe

        // toh +Ve unique elements ka sum nikal lo
        set<int> st;
        for (auto it : nums) {
            if (it > 0)
                st.insert(it);
        }

        int sm = 0;
        // iterate over the set to get sum of all +Ve unique elements
        for (auto it : st) {
            sm += it;
        }

        if(sm!=0) return sm;
        // agar sm==0 h means saare elements -ve hai, get biggest -ve element in
        // 1 subarray and send that as ans
        sm=INT_MIN;
        for(auto it:nums){
            sm=max(sm,it);
        }

        return sm;
    }
};