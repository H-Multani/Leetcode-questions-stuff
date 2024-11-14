class Solution {
public:
    // checks agar har bande ko at max mid jitne produce denge toh kya all
    // products consumed
    bool isvalid(int n, int val, vector<int>& quantities) {
        int shopsfilled = 0;
        for (auto it : quantities) {
            // current type has 'it' no of products, har shop ko val jitne
            // products do
            if (it % val == 0) {
                // means har shop ko val jitne products milenge
                shopsfilled += it / val;
            } else {
                // means har shop ko val jitne products milenge except one shop,
                // aakhri wali shop ko <val products milenge, lekin phir bhi ye
                // shop filled me count karegi, since we can give at max one
                // type of item to each shop
                shopsfilled += (it / val) + 1;
            }

            // if at any point shops filled>n, means zyada shops bhar di hai,
            // product not distributed, in such case return false
            if (shopsfilled > n)
                return false;
        }

        // we here means saara product(and items) finish ho chuke hai,(even if
        // with some shops left with 0 product which is also valid)
        // since no product left hence we can fill all shops with har shop
        // getting at max val jitne products
        // hence return true, since no product left
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // binary search chala do
        // left=1, since minm 1 toh lagaenge har shop me at max
        int left = 1, rt = *max_element(quantities.begin(), quantities.end());
        // rt=max element since maan lo at best apan ne maxm element wala saara
        // product ek bande ko de diya
        int ans = -1;

        while (left <= rt) {
            // mid nikal lo
            int mid = left + (rt - left) / 2;

            // chk if agar har store ko mid(or less) jitne product de sakte hai
            // kya
            // eg mid=5, chk if har store ko 5(or less) product de agar toh kya
            // saare products distribute ho jaenge??

            // like in eg1, if mid=5,
            // distribute 11 like 5,5,1(since ek store ko ek product type hi de
            // sakte hai ) , ttl stores done=3
            // distribute 6 like 5,1(since ek store ko ek product type hi de
            // sakte hai) ttl stores done=2 overall stores filled=3+2=5,
            // stores filled like {5,5,1,5,1,0}(0 filled wala bhi valid hai accd
            // to question)
            // now all stores are filled no problem, and no product remaining
            // out, so this mid is a possible ans, since possible hai mid jitne
            // parts karke fill karna in such case maxm value of profuct
            // recieved by any store=5,
            // ab isko minimize karna hai toh lets try with mid=2
            // mid=2
            // distribute 11 like 2,2,2,2,2,1(since ek store ko ek product type
            // hi de sakte hai ) , ttl stores done=6 stores filled like
            // {2,2,2,2,2,1} but abhi toh product 6 bacha hai for distribution,
            // and already stores have been filled, that means all product not
            // distributed, this is not a possible ans for our question, hence
            // increase mid value and try again,
            // yehi upar wala karna hai basically

            if (isvalid(n, mid, quantities)) {
                // means ye wala mid value lenge toh all product will be
                // distributed no problem,in such case apan har shop ko at max
                // mid jitne product de rahe hai, so this mid is a possible
                // answer, toh update kardo
                ans = mid;

                // ab iss ans ko minimize karvana hai check left side
                rt = mid - 1;
            } else {
                // means ye wala mid value lenge toh all products not
                // distributed,since product not distributed hence ye wala mid
                // is not a possible ans, mid increase karke phir check karo,mid
                // increased by going right side
                // hence go right
                left = mid + 1;
            }
        }

        return ans;
    }
};