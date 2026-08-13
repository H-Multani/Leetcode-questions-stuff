class Solution {
public:
    struct node {
        // prefix wale char se start hone wale biggest substring ka length
        int pre = 0;
        // suffix wale char se start hone wale biggest substring ka length
        int suf = 0;
        // overall node ka max length of substring
        int maxans = 0;
        // prefix wala char konsa hai
        char left = 0;
        // suffix wala char konsa hai
        char rt = 0;
    };

    int n;
    vector<node> segtree;

    void build(int i, int l, int r, string& s) {
        // agar leaf node par hai toh
        if (l == r) {
            // yaha prefix wala biggest substring is 1
            // yaha suffix wala biggest substring is 1
            // yaha maxm ans is 1
            // left wala char is s[l]
            // rt wala char is s[l]
            // laga do yehi se
            segtree[i] = {1, 1, 1, s[l], s[l]};
            // return kardo yehi se
            return;
        }

        // we here means beech ke kisi node me hai apan

        // left nd rt wala subtree banao
        // mid nikal lo
        int mid = l + (r - l) / 2;

        // l to mid build kardo
        // and left subtree me segtree bharega 2n+1 me
        build(2 * i + 1, l, mid, s);
        // mid+1 to r build kardo
        // and rt subtree me segtree bharega 2n+2 me
        build(2 * i + 2, mid + 1, r, s);

        // ab dono side build ho gaye means dono nodes ban chuke neeche wale

        // in dono ko merge kardo current node ke liye, and update current node
        // in segtree

        // segtree me left wala banda is at 2i+1, of size mid-l+1(since left
        // node l to mid tak ke liye tha)

        // segtree me rt wala banda is at 2i+2, of size r-mid(since rt
        // node mid+1 to r tak ke liye tha)
        segtree[i] =
            merge(segtree[2 * i + 1], segtree[2 * i + 2], mid - l + 1, r - mid);

        // bass kaam khatam niklo yaha se
    }

    void update(int i, int l, int r, int pos, char ch) {
        // agar leaf par hai toh update kardo
        if (l == r) {
            // yaha character ch dalega dono pre and suffix ke chars me
            segtree[i] = {1, 1, 1, ch, ch};
            // return kardo yehi se
            return;
        }

        // we here means node par nai pahuche hai

        // mid nikalo
        int mid = l + (r - l) / 2;

        // agar pos left me hai toh left me jaa kar update kardo
        if (pos <= mid) {
            // left me update kardo
            // left is 2i+1
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            // rt me update kardo
            // rt is 2i+2
            update(2 * i + 2, mid + 1, r, pos, ch);
        }

        // updated segtrees ko merge kar dena
        segtree[i] =
            merge(segtree[2 * i + 1], segtree[2 * i + 2], mid - l + 1, r - mid);

        // kaam khatam return frm here
        return;
    }

    // merge ka logic likh do
    node merge(const node& l, const node& r, int leftlen, int rtlen) {
        // merged node banao
        node ans;

        // left wale node ka left most char is merged node ka left most
        // character, common sense
        ans.left = l.left;
        // same with rt most char
        ans.rt = r.rt;

        // ab suppose leftnode is like "aaab" and rtnode "cbbbd"
        // merged node is aaabcbbbd
        // toh left node ka prefix will be 3, toh merge ke baad bhi prefix 3 hi
        // rahega, toh ans ka prefix is same as left ka prefix
        ans.pre = l.pre;
        // edge case
        // ab suppose leftnode is like "aaa" and rtnode "abbbd"
        // merged node is aaaabbbd
        // ab ye formula kaam nai karega since ab pre ka value 3 nai 4 hai
        // toh ye case tab hoga jab left ka pre is same as left ka length , like
        // in above eg, left ka length i 3, and left ke pre is also 3

        // also jab left node ke rightmost char same as right node ke leftmost
        // char(like in above eg)

        // ye dono condn jab hongi tab ans ka pre banega left ka length+(rt node
        // ke pre ka size) in above eg this is ans.pre=3(from left ka
        // length)+1(rt node ka pre ka value)
        // isko eg par laga kar dekhna itll make sense
        if (l.pre == leftlen && l.rt == r.left) {
            ans.pre = l.pre + r.pre;
        }

        // same cheez rt side se, suffix ke sath
        // ie conditions will be
        // rt ka suffix same length as rt ka length and
        // left node ka rt most char is same as rt node ka leftmost char
        ans.suf = r.suf;
        if (r.suf == rtlen && l.rt == r.left) {
            ans.suf = l.suf + r.suf;
        }

        // dono node se jo max len hai vo current node e liye ans ban sakti
        // update
        ans.maxans = max(l.maxans, r.maxans);
        // merge ke baad bhi ban sakta, lekin uske liye left node ka rt char
        // must be same as rt node ka left char, tab best ans can be left ka
        // suffix+rt ka prefix
        if (l.rt == r.left) {
            ans.maxans = max(ans.maxans, l.suf + r.pre);
        }

        // ban gaya node return kardo
        return ans;
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        // seems like an easy problem actually of segment trees

        // toh node bana denge, and node me we will store 5 things
        // prefix wala char konsa hai
        // suffix wala char konsa hai
        // prefix wale char se start hone wala longest substring ka length
        // suffix wale char se start hone wala longest substring ka length
        // overall node ka range ka max length of substring

        // ye cheez boht kaam aayegi merge karne me nodes ko in seg tree

        // tree ka size 4*n banega as usual
        n = s.size();
        segtree.assign(4 * n, node());

        // segtree ko build kardo
        // idx 0 in segtree denotes for range 0 to n-1
        // segtree me index 0 se input dena start karega
        // string se
        build(0, 0, n - 1, s);

        // build karne ke baad queries par iterate kardo

        int k = queryCharacters.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            // current character konsa update karna and kaha update karna
            char ch = queryCharacters[i];
            int pos = queryIndices[i];

            // segtree par starting frm idx 0
            // ye 0 idx denotes range 0 to n-1
            // konse posn par konsa char update karna bhej diya
            update(0, 0, n - 1, pos, ch);

            // ab update ke baad segtree me top wale node par(idx 0) maxlen will
            // have best length of ans we can make as substrnig
            ans[i] = segtree[0].maxans;
        }

        return ans;
    }
};