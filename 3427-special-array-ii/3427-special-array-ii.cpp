class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        // prefix sum types karna hai simple simple

        // har index ke liye, parity nikal lo, and vector me store karlo
        // like for eg1-> parity table is {_,0,0,0,1}
        // yaha at idx=2, value=0, means yee idx 2 tak apan ko abhi tak 0
        // violating idx mile hai, ie idx 2 tak aane me 0 baar mereko parity me
        // error dikha hai

        // like for eg2-> parity table is {_,0,1,1}
        // yaha at idx=2, value=1, means yee idx 2 tak apan ko abhi tak 1
        // violating idx mile hai(at idx 1 and 2 in nums), ie idx 2 tak aane me
        // 1 baar mereko parity me error dikha hai

        // yaha at idx=3, value=1, means
        // yee idx 3 tak apan ko abhi tak 1 violating idx mile hai, ie idx 3 tak
        // aane me 1 baar mereko parity me error dikha hai(at idx 1 and 2 in
        // nums)

        int n = nums.size();
        vector<int> parity(n, 0);
        // parity[0]=0 since idx 0 ke liye idx -1 toh hai nai apne paas, hence 0
        // rakh diya waha over queries
        int temp = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                // means violation hora yaha, violation cnt increase krdo
                temp++;
            }
            parity[i] = temp;
        }

        // ab zara socho we have query start=4,end=7 and uss part ka parity
        // array like {...,3(idx=4),3,3,3(idx=7),...}
        // we can see ki idx 4 se idx 7 tak me parity ka value change
        // nai hua hai means idx 4 se leke 7 tak me saare elements ka parity in
        // order hai, in such case query ka output will be true, since ye
        // subarray special hai

        // for eg if array like {2,2,3,4,5,6,7,9}, parity array be like
        // {0,1,1,1,1,1,1,2}, ab let query be start=1 to end=5
        // toh parity[start]=1, parity[end]=1, ab dono parities ke value same
        // hai means ye wala subarray (ie frm idx 1 to 5) will be a special
        // subarray, hence iss query ka ans=true
        // cross checking, subarray frm idx 1 to 5 is {2,3,4,5,6}, this is
        // clearly a special, toh matlab the logic works

        // ab this works since parity[start] is ki 0 se start idx tak me kitne
        // violations mile hai, and parity[end] is ki 0 se end idx tak me kitne
        // violations mile hai
        // hence agar dono ka value same hai means start idx se end idx ke beech
        // me koi violation nai mila hai apan ko,yehi core logic hai

        // ab queries par iterate kardo
        vector<bool> ans;
        for (auto it : queries) {
            int start = it[0];
            int end = it[1];

            // ab parity array me start ka value and end ka value check karo,
            // agar same hai means array is special, in such case return true
            // else false

            // edge case, if start==end, means reqd subarray me 1 element hai,
            // in such case also subarray is special, in such case return true

            if ((parity[start] == parity[end]) || start == end)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};