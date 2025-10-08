class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p,
                                long long success) {
        // dono me se ek array ko sort kardo, usme binary search chalayenge apan
        sort(p.begin(), p.end());
        int n = p.size();

        // ab potion par apan binary search chalayenge and count karenge ki
        // kitne potions will be valid with current spell

        // binary search since minm valid potion milne ke baad aane wale saare
        // potions will be valid automatically 

        vector<int> ans;
        // iterate over the spells
        for (auto curr : s) {
            // we need curr*(value frm potions)>=success

            // ie value frm potions>=success/curr

            long long val = success / curr;

            // agar success/curr not prefectly divisible, toh val ko val+1
            // kardo, since lower bound me agar integer only value denge in such
            // case toh chhote wale ans bhi count kar lega which is not valid
            if (success % curr != 0)
                val++;

            // binary search through p and find smallest banda such that its
            // value>=val

            // ie lower_bound nikal lo, since lower bound gives first instance
            // with value>=required

            int idx = lower_bound(p.begin(), p.end(), val) - p.begin();

            // iss idx se leke end tak saare values can be used with curr to
            // make overall product>=success

            // count karlo kitne elements hai
            int cnt = n - idx;

            // ans me daal do
            ans.push_back(cnt);
        }

        return ans;
    }
};