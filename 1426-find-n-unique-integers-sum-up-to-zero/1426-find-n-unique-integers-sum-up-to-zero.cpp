class Solution {
public:
    vector<int> sumZero(int n) {
        // if n is even, adhe +1,+2.., bache adhe -1,-2..

        // if n is odd, adhe +1,+2.., bache adhe -1,-2.., beech wala 0

        vector<int> ans;
        if (n % 2 == 0) {
            // adhe odd adhe even
            for (int i = 1; i <= n / 2; i++) {
                ans.push_back(i);
                ans.push_back(-i);
            }
        } else {
            // adhe odd adhe even
            for (int i = 1; i <= n / 2; i++) {
                ans.push_back(i);
                ans.push_back(-i);
            }
            // beech wala 0 bhi add kar dena
            ans.push_back(0);
        }

        return ans;
    }
};