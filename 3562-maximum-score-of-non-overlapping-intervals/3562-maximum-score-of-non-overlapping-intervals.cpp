class Solution {
public:
    int n;
    vector<int> nextidx;
    // solve will return a node, node me ttl score rakhenge and indexes rakh lenge
    struct node{
        // initial score -1
        long long score=-1;
        // indexes store karenge
        vector<int> idx;

    };
    
    vector<vector<node>> memo;

    node solve(vector<vector<int>>& interval,int i,int k){
        // base case, agar i>n ya k==0 toh means aur node nai le sakte return empty node
        if(i>=n || k==0) return node();

        // memo me hai toh yehi se bhejdo
        if(memo[i][k].score!=-1){
            // means node ka ans nikal rakha hai
            return memo[i][k];
        }


        // we here means 2 options hai current idx ke liye take or skip

        // skip karke jo node niklega nikal lo
        node skip=solve(interval,i+1,k);
        // agle node par jao i+1 par, and k stays same since kuch nai liya

        // take current node
        // current wale ko le liya hai toh aage se kya aayega nikalo

        // aage apan i+1 par nai jayenge, current interval liya hai toh uske end ke baad wala valid interval par jana padega, which is nextidx[i], toh yehi wale par jao
        node temp=solve(interval,nextidx[i],k-1);
        // k-1 since 1 interval le liye 

        // curernt interval ka info nikal lo
        // current ka wt
        int wt=interval[i][2];
        // current ka og index
        int index=interval[i][3];
        // current ko lenge toh next idx konsa hoga
        int j=nextidx[i];


        node take;
        // take ka score will be temp ka score+ current interval ka score since taken hai current interval
        take.score=temp.score+interval[i][2];

        // current node ko liya hai toh node me idx wala array update kardo

        // temp se jitne idx aaye vo current me include karo
        take.idx=temp.idx;
        // ab isme current wale ka og idx daal do
        take.idx.push_back(index);
        // easily comparison karne ke liye idx ka sort kardo
        sort(take.idx.begin(),take.idx.end());

        // resultant node wahi hoga jiska score better
        node result;

        if(skip.score>take.score) result=skip;
        else if(skip.score<take.score) result=take;

        // we here means same score hai, iss case me smaller idx walo ko lena hai

        // we can directly compare vectors and values using <  or > in cpp
        else result=(skip.idx<take.idx)? skip:take;

        return memo[i][k]=result;
    }

    // binary search wala funcn
    int findnext(vector<vector<int>>& intervals,int r){
        int lo=0,hi=n-1;

        int ans=n;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // agar mid wale ka start>r hua means this node is possible ans rakh lo
            if(intervals[mid][0]>r){
                // ans update karo
                ans=mid;

                // check left for better ans
                hi=mid-1;
            }
            else{
                // check left for valid ans
                lo=mid+1;
            }
        }

        return ans;

    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        // original index store karlo since aage sort karenge intervals ko and
        // ans me og index needed
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // ab intervals ko sort kardo start ke hisab se
        sort(intervals.begin(), intervals.end());

        // ab nextidx naam ka vector bana lo which will be used to figure out
        // next possible area to jump to after taking current interval

        nextidx.resize(n);
        // preprocessing karre hai so that recursion ke beech me baar baar
        // binary search na lagana pade

        for (int i = 0; i < n; i++) {
            // current interval ka ending kaha hai

            int end = intervals[i][1];

            // ab iss ko lene ke baad next valid interval ka start>current wale
            // ka end

            // ye nikal lenge binary search se, since we can take any valid
            // interval but we need to maximize score hence apan nearest wala
            // interval lenge , fir usme take nottake chala kar score nikal
            // lenge

            // current wala interval ke liye next valid interval ka index nikal kar store kar lenge
            nextidx[i]=findnext(intervals,end);
        }

        // ho gayi preprocessing

        // ab solve funcn bula lo usme take nottake chala do ezpz

        // memo lagega, yaha 2 things change i and k, bana do utne ka vector and since we return node hence memo me node rakhenge
        memo.assign(n+1,vector<node>(5));


        // since maxm 4 intervals le sakte hence
        int k=4;
        // we start from idx 0 vahi bhej do
        return solve(intervals,0,k).idx;
        // solve will return node, which stores maxm score and indexes to take for that score, toh iss returned value ka indexes wala part bhejna h bas

    }
};