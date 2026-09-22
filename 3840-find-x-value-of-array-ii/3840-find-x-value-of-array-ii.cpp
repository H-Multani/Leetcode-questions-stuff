struct node {
    // node ka cnt array hoga, stores ki 0,1,2,3,4 remainder wale kitne log hai
    // apne paas
    int cnt[5] = {0};

    // ek product hoga, jo store karega range ka product%k

    // since prod store karo ya %k karke store karo ek hi cheez hai, aage %k
    // alag se nai karna padega mereko basss
    int prod = 0;
};

// ek class bana denge segtree ke liye
class segmentTree {
public:
    int n;
    int k;
    // vector hoga segtree ka 4n size ka
    vector<node> segtree;

    // constructor bana lo
    segmentTree(vector<int>& nums, int k) {
        this->k = k;
        this->n = nums.size();

        // segtree ko resisze kardo
        segtree.resize(4 * n, node());
        // build karlo segtree ko
        build(0, 0, n - 1, nums);
        // segtree ka root is idx 0,
        // this idx 0 represents range 0 to n-1
    }

    void build(int i, int l, int r, vector<int>& nums) {
        // base case
        if (l == r) {
            // leaf node bana dena, idx is i in segtree, which represents l to
            // r, ie l, ie 1 element only, and nums[l] bhej dena
            leafnode(i, nums[l]);

            // bhej do
            return;
        }

        // we here means left and rt side ko banana padega
        int mid = l + (r - l) / 2;
        // left idx is 2i+1,denoting l to mid ka range
        build(2 * i + 1, l, mid, nums);
        // rt idx is 2i+2,denoting mid+1 to r ka range
        build(2 * i + 2, mid + 1, r, nums);

        // left and rt banne ke baad current node ko banayenge, left and rt node
        // bhej dena
        segtree[i] = merge(segtree[2 * i + 1], segtree[2 * i + 2]);
    }

    void leafnode(int i, int val) {
        // segtree ka i th node me val dalega bass

        // iss node ke saare count ko 0 se initialize kardo
        for (int x = 0; x < k; x++) {
            segtree[i].cnt[x] = 0;
        }

        // current value ka remainder kya aayega,
        int r = val % k;

        // segtree me update kardo, ki r remainder wala 1 banda hai current i th
        // node me
        segtree[i].cnt[r]++;

        // prod bhi update kar dena, prod is simply val%k;
        segtree[i].prod = r;
    }

    // update funcn likh lo

    void update(int idx, int val) {
        // segtree me update kardo

        // segtree ka idx 0, denoting range 0 to n-1, isme idx par val dalna hai
        segtreupdate(0, 0, n - 1, idx, val);
    }

    void segtreupdate(int i, int l, int r, int idx, int val) {
        // agar leaf node par hai toh kardo update
        if (l == r) {
            // leafnode wla funcn bula kar update kardo

            // iss node par i par val daalna hai, since here i==idx
            leafnode(i, val);
            return;
        }

        // mid nikal lo
        int mid = l + (r - l) / 2;

        // jiss idx ko dhund rahe hai left me hai toh left jao
        if (idx <= mid) {
            // left me i is 2i+1,range is l to mid
            segtreupdate(2 * i + 1, l, mid, idx, val);
        } else {
            // rt side jana hai update vaaste

            // rt me i is 2i+2,range is mid+1 to r
            segtreupdate(2 * i + 2, mid+1, r, idx, val);
        }

        // nodes update karne ke baad merge kar dena parent node ko
        // left and rt banne ke baad current node ko banayenge, left and rt node
        // bhej dena
        segtree[i] = merge(segtree[2 * i + 1], segtree[2 * i+ 2]);

        // kaam khatam
    }

    // ab merge ka logic likhna hai ye main hai
    node merge(node& left, node& rt) {
        node ans;

        // left node and rt node ke prod hai apne paas, vo merged ke liye
        // nikalna is easy

        ans.prod = (left.prod * rt.prod) % k;
        // %k kar dena since prod me % karke store karre hai, useful here later

        // ab count nikalna hai
        // maan lo current is {3,3,2,2}, isme left is {3,3} and rt is {2,2}, k=5
        // maan lo

        // toh left node me
        // prod=(3*3)%k=> 4
        // ab yaha subarrays ka prod nikalte nikalte %k karke dekhna hai and cnt
        // lagana hai

        // subarrays here is {3},{3,3}
        // {3}-> 3%k=3, toh cnt[3]=1
        // {3,3}->3*3-> 9%k=4, toh cnt[4]=1
        // cnt=>{0,0,0,1,1}

        // toh rt node me
        // prod=(2*2)%k=> 4
        // ab yaha subarrays ka prod nikalte nikalte %k karke dekhna hai and cnt
        // lagana hai

        // subarrays here is {2},{2,2}
        // {2}-> 2%k=2, toh cnt[1]=1
        // {2,2}->2*2-> 4%k=4, toh cnt[4]=1
        // cnt=>{0,0,1,0,1}

        // merge ke liye array is {3,3,2,2}
        // subarrays will be {3},{3,3},{3,3,2},{3,3,2,2}
        // merge ke prod is simple-> 3*3*2*2-> left.prod*rt.prod

        // cnt me sochna padega
        // subarrays is
        // {3}-> 3%k=3, toh cnt[3]=1
        // {3,3}->3*3-> 9%k=4, toh cnt[4]=1
        // {3,3,2}->3*3*2-> 18%k=3, toh cnt[3]+=1
        // {3,3,2,2}->3*3*2*2-> 36%k=1, toh cnt[1]=1
        // cnt=>{0,1,0,2,1}

        // ab yaha notice karo, upar wale 2 subarrays ka which is {3},{3,3}, ye
        // seedha seedha left wale se same, direct use karlo

        // toh cnt me left wale ka cnt and current node ka cnt same rahega at
        // this point
        for (int x = 0; x < k; x++) {
            ans.cnt[x] = left.cnt[x];
        }

        // ab merge ka scene

        // baaki 2 subarrays ko dekho
        // {3,3,2}-> (3*3*2)%k-> (3*3)%k * (2)%k -> here (3*3)%k is simple
        // left.prod
        // toh overall becomes (left.prod*(2%k))%k, this is new remainder

        // ab right me dhundo ki {2} wale subarray ka kya remainder tha,it was 1

        // and new remainder we know is (for {3,3,2}) is 3 (frm line 159)
        // toh that means ki merged wale ke liye right side se jo subarrays
        // pehle remainder 1 de rahe the, ab same subarrays remainder 3 denge,
        // ye 2 toh sirf example hai irl toh multiple elements ka prod hoga na
        // waha%k par jo 1 deta tha, ab change hone ke baad 3 dega

        // toh ab apan merged cnt me idx 3 par +1 count karenge

        // and maan lo agar rt side me remainder 1 dene wale 10 cnt the, then
        // merged me same 1 remainder dene wale 3 denge toh ab idx 3 me +10
        // count karenge

        // -----------------------------------
        // SIMILARLY for {2,2}
        // ab right me dhundo ki {2,2} wale subarray ka kya remainder tha,it was
        // 4

        // and new remainder we know is (for {3,3,2,2}) is 1 (frm line 160)
        // toh that means ki merged wale ke liye right side se jo subarrays
        // pehle remainder 4 de rahe the, ab same subarrays remainder 1 denge,
        // ye {2,2} toh sirf example hai irl toh multiple elements ka prod hoga na
        // waha%k par jo 4 deta tha, ab change hone ke baad 1 dega

        // toh ab apan merged cnt me idx 1 par +1 count karenge

        // and maan lo agar rt side me remainder 4 dene wale 10 cnt the, then
        // merged me same 4 remainder dene wale 1 denge toh ab idx 1 me +10
        // count karenge

        // yehi logic laga rahe
        for(int x=0;x<k;x++){
            // new remainder nikal lo

            // jo subarray(right node me) pehle remainder x dete the ab vo newrem denge

            // x toh remainder hai na toh x%k karne se same hi aayega why bother

            // this is (left.prod*(2%k))%k wala logic
            int newrem=(left.prod*(x))%k;

            // ab jo right node me x remainder dete the, vo same subarrays merged me newrem denge, toh cnt add kardo
            ans.cnt[newrem]+=rt.cnt[x];
        }

        // merged node done,return
        return ans;
    }

    // query method query karega and node nikal kar layega

    node query(int start,int end){
        // start to end me dhundna hai

        // range is start to end, root is at idx 0, represents 0 to n-1
        return segtreequery(start,end,0,0,n-1);
    }

    node segtreequery(int st,int end,int i,int l,int r){
        if(l>=st && r<=end){
            // current node covers full range, pura bhej do
            return segtree[i];
        }

        // left and rt side dono side jaa kar dekho
        int mid=l+(r-l)/2;

        if(end<=mid){
            // means completely left side se ans milega

            // left ka idx is 2i+1, represent l to mid
            return segtreequery(st,end,2*i+1,l,mid);
        }
        if(st>mid){
            // means completely rt side se ans milega

            // rt ka idx is 2i+2, represent mid+1 to r
            return segtreequery(st,end,2*i+2,mid+1,r);
        }

        // we here means left se kuch aayega, rt se kuch aayega

        // left se kya aayega
        node left=segtreequery(st,end,2*i+1,l,mid);
        // rt se kya aayega
        node rt=segtreequery(st,end,2*i+2,mid+1,r);

        // merge kardo dono nodes ko, and return the ans

        return merge(left,rt);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        int n = nums.size();

        // nums ks segtree bana do
        segmentTree segtree(nums, k);

        //  ek result wala array lelo query ke ans isme store karenge
        vector<int> ans;

        // har query par iterate karenge
        for (auto q : queries) {
            // konsa idx hai
            int idx = q[0];
            // isme konsa val daalna hai
            int val = q[1];
            // kaha tak remove karna hai,
            int start = q[2];
            // 0 to start-1 tak remove karenge
            // ans nikalna hai konse X ke liye
            int x = q[3];

            // segtree me update daal do
            segtree.update(idx, val);
            // ab start to n-1 jitna me dhudna hai x ke liye ans, ye node
            // bhejega
            node ansnode = segtree.query(start, n - 1);

            // ab iss ans wale node ke count array ka x wale remainder ka freq
            // hoga, wahi dena hai
            ans.push_back(ansnode.cnt[x]);
        }

        return ans;
    }
};