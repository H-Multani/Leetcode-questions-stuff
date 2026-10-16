class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    vector<ll> sqSumSegTree;
    vector<ll> SumSegTree;
    vector<ll> lazyTree;
    int n;

    void lazyaddition(int i,int l,int r,int val){
        // current node ke kitne child nodes
        int len=(r-l+1);

        // sqSumSegTree update kardo math forumula se
        sqSumSegTree[i]+=2*val*SumSegTree[i]+len*val*val;

        SumSegTree[i]+=(len*val);

    }

    void updaterange(int st, int end, int i, int l, int r, int val) {
        // agar current node par lazy se kuch add karna tha toh krdo
        if (lazyTree[i] != 0) {
            lazyaddition(i,l,r,lazyTree[i]);
            // idx i par l to r me lazyTree[i] add kar dena

            // leaf node nai hai abhi toh left and rt child par lazy propogate kar dena vo neeche wale nodes par apne aap samay se addn karega
            if(l!=r){
                // left node at 2i+1
                lazyTree[2*i+1]+=lazyTree[i];
                // rt node at 2i+2
                lazyTree[2*i+2]+=lazyTree[i];
            }

            // current node par kuch pending nai hai all updated toh 0 kardo lazytree me
            lazyTree[i]=0;
        }

        // out of range hua toh no need to take anything
        if(l>end || r<st || l>r){
            return;
        }

        // completely within range
        if(l>=st && r<=end){
            // pura node le lenge
            lazyaddition(i,l,r,val);
            // i idx par hai l to r range hai aur iss range me val add krna hai

            // child ko inform kardo ki add karunga baad me 
            if(l!=r){
                // left node at 2i+1
                lazyTree[2*i+1]+=val;
                // rt node at 2i+2
                lazyTree[2*i+2]+=val;
            }

            // pura node le liye nikal lo
            return;
        }

        // means left or rt jana padega

        int mid=l+(r-l)/2;

        // l to mid range update kardo
        updaterange(st,end,2*i+1,l,mid,val);
        
        // mid+1 to r range update kardo
        updaterange(st,end,2*i+2,mid+1,r,val);

        // sum seg tree update kardo
        SumSegTree[i]=SumSegTree[2*i+1]+SumSegTree[2*i+2];
        // square sum seg tree update kardo
        sqSumSegTree[i]=sqSumSegTree[2*i+1]+sqSumSegTree[2*i+2];

    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        // 4n ka size dedo segtrees me
        sqSumSegTree.assign(4 * n, 0);
        SumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);

        // vector lelo last seen jo rakhega har element ka
        vector<ll> lastseenidx(100001, -1);

        ll ans = 0;

        // loop chalao
        for (int i = 0; i < n; i++) {
            // current bande ka last idx kaha mila tha, waha ke aage se latest
            // idx i tak +1 hoga since distinct element mila hai
            int st = lastseenidx[nums[i]] + 1;
            int end = i;

            // range update kardo
            updaterange(st, end, 0, 0, n - 1, 1);
            // st se end me +1 karna hai
            // root ka idx is 0
            // root represent range of 0 to n-1,
            // usme val add karni hai +1

            // ans me daal do
            ans = (ans + sqSumSegTree[0]) % mod;

            // last seen idx ko update kardo aage wale ke liye
            lastseenidx[nums[i]] = i;
        }

        return ans;
    }
};