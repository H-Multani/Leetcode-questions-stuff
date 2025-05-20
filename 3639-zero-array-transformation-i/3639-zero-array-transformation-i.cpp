class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // prefix sum wala h simple,yaha vo O(1) query process karne wala method
        // lagega

        // vo method laga lenge, then overall prefix array banaenge(which will
        // have +ve values) phir usko subtract karenge nums se each element with
        // corr element of nums, and if nums wala banda add hone ke baad bhi ttl
        // sum +ve bacha means zero array nai ban sakta return false

        // so like for eg2: prefix array after processing all queries will be
        // {1,1,0,-1}, inko ab prefix sum banaenge to we will get ttl sums as
        // {1,2,2,1}, iske har element jo subtract karenge with corr element of
        // nums so welll get {4-1,3-2,2-2,1-1}->{3,1,0,0}, since there are +ve
        // elements remaining means zero array cant be made, hence ans is false

        // the logic here is apan saare maxm subtracting nikal rahe hai, for
        // eg2, prefix[1]=2, matlab idx 1 me at max -2 kiya jaa sakta hai after
        // processing all queries, ye -2 jab apan karenge nums[1] me toh we will
        // get 3-2=1, which agae ye 0 ya -ve hota toh no problem, but its
        // positive, so that means saare queries chalane ke baad bhi the
        // smallest we gan get at idx 1 is value 1, means zero array cant be
        // made

        // yehi logic lagayenge

        // make prefix array of n+1 size, since for query [i,j], we will do
        // prefix[i]++ and prefix[j+1]--, since [i to j] tak me +1 karna hai
        // apan ko, toh j+1 th bande me jaa kar -1 karenge toh i to j wala +1 me
        // bharega, try run krlo itll make sense
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (auto it : queries) {
            prefix[it[0]]++;
            prefix[it[1] + 1]--;
        }

        // ab queries process krli hai, ab prefix sum nikalo filling the prefix
        // array
        for (int i = 1; i < n + 1; i++) {
            prefix[i] += prefix[i - 1];
        }

        // ab prefix array ban gaya hai, isko compare karo ab nums se
        for (int i = 0; i < n; i++) {
            // the maxm we can subtract from nums[i] after processing all
            // queries is prefix[i], toh dono me se agar nums[i] is bigger means
            // saare subtractions krne ke baad bhi +ve value bachegi meaning
            // nums cant be made zero array return false
            if (nums[i] > prefix[i]) {
                // we here means nums[i] me se saare queries chala kar elements
                // alag karne par bhi +ve value bachegi, means zero array cant
                // be made
                return false;
            }
        }

        return true;
    }
};