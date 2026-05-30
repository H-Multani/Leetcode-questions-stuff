class Solution {
public:
    vector<int> segtree;
    int n = 50000;
    void construct() { segtree.resize(4 * n, 0); }

    int findmax(int start, int end, int i, int l, int r) {
        // l and r ka range [start,end] ke bahar hoga toh invalid hai
        if (l > end || r < start) {
            // out of range node hai return kar jao
            return 0;
            // invalid 0 bhej diye, since max gap 0 is for invalid
        }

        // agar exact range ke andar hai toh i ka value lena padega
        if (l >= start && r <= end) {
            return segtree[i];
        }

        // means overlap hai partial, toh left wale side ka ans nikalna padega
        // and right wale part ka ans nikalna padega

        int mid=l+(r-l)/2;

        // return max jo left side se mila and jo right side se mila usme se
        return max(findmax(start,end,2*i+1,l,mid),findmax(start,end,2*i+2,mid+1,r));

        // left ka idx is 2*i+1
        // left ke liye search l to mid

        // rt ka idx is 2*i+2
        // rt ke liye search mid+1 to r
    }

    // ye update segtree ka code almost always same rehta hai question ke liye
    void update(int idx, int val, int i, int l, int r) {

        // agar leaf node par hai toh update kardo bas
        if (l == r) {
            // leaf par aa gaye hai update the tree
            segtree[i] = val;
            return;
        }

        // ab mid nikalo
        int mid = l + (r - l) / 2;

        // kaha jana hai
        if (idx <= mid) {
            // means apan ko left me update karna hai, left jao
            update(idx, val, 2 * i + 1, l, mid);

            // left child ka index is 2*i+1
        } else {
            // means apan ko right me update karna hai, right jao
            update(idx, val, 2 * i + 2, mid + 1, r);

            // right child ka index is 2*i+2
        }

        // now we have returned from the recursion

        // update the segment tree

        // current range [l,r] ka best gap will be left range ka best gap+right
        // range ka best gap
        segtree[i] = max(segtree[2 * i + 1], segtree[2 * i + 2]);

        return;
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        // construct karlo segtree ko
        construct();

        // set for storing obstacles
        set<int> st;
        // starting obstacle 0
        st.insert(0);

        // vector lelo for ans
        vector<bool> ans;

        // process all queries
        for (auto q : queries) {
            if (q[0] == 1) {
                // type 1 query
                int x = q[1];

                // pehle ye nikalo ye obstacle konse 2 elements ke beeech me
                // fasega

                // upper bound se nikal lo
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? (*it) : -1;
                // agar valid hi nai hai means current ke right me kuch obstacle
                // nai hai in which case we store -1

                // no such check on prev since it always exists
                int pre = *prev(it);

                // now we have 2 obstacles nxt and pre which are basically ki x
                // ke aaju and baju me konsa obstacles hai so that space update
                // kar paye

                // pehle dist update karo between pre and x

                // node dalega x, and
                // x ke left me new gap ban gaya of size x-pre
                // starting node is 0
                // root ka range is 0 to n-1
                update(x, x - pre, 0, 0, n - 1);

                // ab right side dekho
                // right me node is nxt
                // right me new gap banega of size nxt-x
                // starting node is 0
                // root ka range is 0 to n-1
                update(nxt, nxt - x, 0, 0, n - 1);

                // ab segtree updated, set me insert kardo obstacle ko
                st.insert(x);

            } else {
                // query of type 2

                int x = q[1];

                int sz = q[2];

                // [0,x] me sz jitna gap dhudna hai

                // x ka nearest aage wala iterator nikalo
                auto it = st.upper_bound(x);
                // just previous wala nikalo
                int pre = *prev(it);

                // now find the max gap between 0 to prev
                // start searching frm root node 0
                // root node ka range 0 to n-1
                int maxgap = findmax(0, pre, 0, 0, n - 1);

                // ab ho sakta hai ki best gap is actually between pre and x, in
                // which case best ans le lenge
                int best = max(maxgap, x - pre);

                // ans me bhej dena bas
                // agar gap>=sz hua means dal jayega else no, in which case
                // return false
                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};