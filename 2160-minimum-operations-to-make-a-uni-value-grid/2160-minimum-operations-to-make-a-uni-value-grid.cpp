class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // let y be a no in the grid, if for all y , we have y%x as the same
        // value, means uni-value grid can be made, othereise not

        // since agar maan lo ek y1%x=4 aaya aur dusra y2%x=3 aaya toh ye y1 and
        // y2 can never be same, no matter how many x are removed or added
        int val = grid[0][0] % x;

        // ab problem ye hai ki +x ya -x karke nos toh change kar sakte hai, but
        // we need to get to uni-value grid in minm no of operations

        // toh minm operations ke liye, i think the best option would be ki
        // saari values ko mid ke around banaye

        // see eg1, apan kya kar sakte hai ki saare values ko 2 bana de, lekin
        // usme 6 operations lagenge, lekin agar apan mid value le(4 ya 6) toh
        // uss case me 4 operations me uni-value grid mil raha hai, which is
        // minm, vahi karna hai basically apan ko

        // toh mid ke liye pehle grid ko sort kardo
        // sort(grid.begin(), grid.end());

        // ab grid sorted hai lekin grid ke andar ke vectors sorted nai hai, toh
        // apan ko saare vectors sort nai karne hai , bass mid wala sort karna
        // hai

        // m rows
        int m = grid.size();
        // n columns
        int n = grid[0].size();
        // sort(grid[m / 2].begin(), grid[m / 2].end());

        // ab mid value nikal lo
        // push all values into a vector, sort the vector
        vector<int> temp;
        for(auto it:grid){
            for(auto it2:it) temp.push_back(it2);
        }

        sort(temp.begin(),temp.end());
        int mid=temp[(m*n)/2];

        cout << mid << endl;

        // ab count lelo
        int cnt = 0;

        // ab grid par iterate karo, and count the no of operations reqd to
        // convert each number to mid

        for (auto it : grid) {
            for (auto it2 : it) {

                // current number is it2
                // if it2%x is not same for other numbers, we cant make the grid
                // uni-value in such case return -1, to do this we have val
                // stored, val is grid[0][0]%x. id val==it2%x, means grid can be
                // made uni-value, other wise not
                if (val != it2 % x)
                    return -1;

                // ab it2 ko mid tak lana hai by +x or -x, toh this steps can be
                // counted easily

                // abs(it2-mid), will give +ve value always, to handle cases like
                // it2<mid

                // now this value abs(it2-mid) will be exactly divisible by x,
                // since both it2 and mid give same remainder when divided by
                // x,means we can add/subtract in it2 to get to x, since the
                // value is exactly divisible by x so value/x will give how many
                // times we need to add/subtract x to get it2 to mid
                cnt+=abs(it2-mid)/x;
            }
        }

        return cnt;
    }
};