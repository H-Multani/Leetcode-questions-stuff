
void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n=s.size();

        // segment tree build wala logic likh lo upar hi
        // easy to understand code hai , not too hard


        // existing 1s kitne hai, ye seedhe seedhe ans me count honge
        int activecnt=count(s.begin(),s.end(),'1');

        // ab 0s ke blocks nikalne hai, we need idx of block ka start and block ka end

        vector<int> blockst;
        vector<int> blockend;

        // iterate krke bhar do
        for(int i=0;i<n;){
            if(s[i]=='0'){
                int start=i;
                // yehi se loop build karlo

                while(i<n && s[i]=='0'){
                    i++;
                }

                // we here means block end ho chuka hai start and end bhar do
                blockst.push_back(start);
                blockend.push_back(i-1);
            }
            else{
                // we here means current banda is not 0 ka block aage badho
                i++;
            }
        }

        int m=blockend.size();
        // if there is only 1 block of 0s like s="110000011", iss case me ans will be count of 1s since koi operation nai laga paaye

        if(blockend.size()<2){
            // means 1 hi block hai, iss case me har query ka ans will be no of 1s, bana kar bhejdo
            return  vector<int>(q.size(),activecnt);
        }

        // blocks nikal lo
        vector<int> blocksize(m);

        for(int i=0;i<m;i++){
            blocksize[i]=blockend[i]-blockst[i]+1;
        }

        // blocks ke sizes mil chuke hai, ie 0s wale continous blocks 

        // apna kaam pairsum se hai toh vo nikal lo, pairsums me m-1 pairsums niklenge, dimaag chalao samajh aa jaega, adjacent elements m ke pairs banane hai toh m-1 pairs banenge
        vector<int> pairsum(m-1);

        // pairsum bhar do
        for(int i=0;i<m-1;i++){
            pairsum[i]=blocksize[i]+blocksize[i+1];
        }


        // ab iss pairsum par baar baar iterate karennge for best pair sum for each query, toh iska segtree bana do

        // funcn takes array, we have vector, array bana kar bhejna
        int *st=constructST(pairsum.data(),m-1);

        // ab ans banana hai iterate thru all the queries
        vector<int> ans;

        for(auto it:q){
            int l=it[0];
            int r=it[1];

            // iss range ke first block ka idx nikal lo
            int low=lower_bound(blockend.begin(),blockend.end(),l)-blockend.begin();
            // iss range ke last block ka idx nikal lo
            int hi=upper_bound(blockst.begin(),blockst.end(),r)-blockst.begin()-1;

            // ab dono blocks hai apne paas start and end wale, now we just need max pair sum

            int maxans=0;

            if(low<hi){
                // since we need atleast 2 blocks

                // possible hai ki first block cut hua ho l se, toh effective first block nikal lenge
                int firstlen=blockend[low]- max(blockst[low],l)+1;
                // possible hai ki last block cut hua ho r se, toh effective last block nikal lenge
                int lastlen=min(blockend[hi],r)- blockst[hi]+1;


                // if low-hi==2 means exactly 2 blocks yehi se ans bhejdo
                if(hi-low==1){
                    // exactly 2 blocks dono ka sum bhej do
                    maxans=firstlen+lastlen;
                }
                else{
                    // we here means beech ke blocks bhi hai

                    // toh left se first 2 blocks ka alag sum nikalo (since possible ki block cut hua ho toh segtree cant be used)
                    int pair1=firstlen+blocksize[low+1];
                    // toh right se last 2 blocks ka alag sum nikalo (since possible ki block cut hua ho toh segtree cant be used)
                    int pair2=lastlen+blocksize[hi-1];

                    // beech walo me best pairsum seedha segtree se nikal lo
                    int beechwalokasum=RMQ(st,m-1,low+1,hi-2);
                    // m-2 is size of segtree, low+1 is kaha se search karna, hi-2 is kaha tak me search karna , essentially range [low+1,hi-2]

                    // teeno ka jo bhi maxm hai daaldo ans me
                    maxans=max({pair1,pair2,beechwalokasum});
                }
            }

            // ans me daal do ye maxans
            ans.push_back(maxans+activecnt);

        }


        return ans;

    }
};