class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<long long> pow10(n+1);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10LL)%mod;
        }

        // prefix sum me store karlo ki har index tak kitne characters non 0 the
        // and ek final string bana lenge which will consist of all non 0
        // characters, fir usme query ke hisab se operations karenge, trust me
        // itll make sense

        vector<int> pre(n + 1, 0);
        // pehle to prefix array bana lo
        // pre[i]=4 means idx 0 se leke idx i(i included) tak me 4 non 0 values
        // hai

        vector<long long> sm(n + 1, 0);
        // sum of digits ke liye bhi ek prefix array lelo

        // ek prefix sum lelo which will store ki current idx tak non 0
        // characters mila de toh konsa number banega
        vector<int> vals(n + 1, 0);
        // vals[i]=135 means idx 0 se leke i(inclusive) tak non 0 digits se
        // value banaenge toh 135 value banega

        // prefix ka idx 0 ke liye values bhardo
        pre[0] = ((s[0] - '0') == 0) ? 0 : 1;
        sm[0] = s[0] - '0';
        vals[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (((s[i] - '0') == 0) ? 0 : 1);
            sm[i] = sm[i - 1] + (s[i] - '0');

            // vals bhardo
            if (s[i] != '0') {
                vals[i] = ((1LL*vals[i - 1] * 10)%mod + (s[i] - '0')) % mod;

                // logic being suppose vals[i-1]=135, and current me we got 7
                // then vals[i] has to become vals[i]=1357, vahi kar raha
            } else {
                // means current wala char is 0, not to be included in vals toh
                // peeche wala jaisa same value banega yaha bhi
                vals[i] = vals[i - 1];
            }
        }

        // ab ans banayenge queries par iterate karke
        vector<int> ans;

        for (auto it : queries) {
            // start nikalo and end nikalo ki kitne idx tak lena hai
            int st = it[0];
            int end = it[1];

            // sum ke liye toh seedha nikal lo
            int sum;
            if (st == 0)
                sum = sm[end];
            else
                sum = sm[end] - sm[st - 1];

            // ab digits nikalne ki iss range me kitne digits hai,

            // we have overall string s1 which consists of only non 0 digits

            // iske help se nikalenge apan

            // substring nikal kar convert to int kar lenge mast

            // length of substring is
            long long len;
            if (st == 0)
                len = pre[end];
            else
                len = pre[end] - pre[st - 1];

            // substring ye vo kuch nai karenge

            // number nikalo idx end tak kitna bana hai which is vals[end], and
            // we need frm idx st starting, toh vals[st-1] nikalenge, since
            // vals[i] includes idx 0 to i, hence for [st,end], we need to get
            // vals[st-1]

            // now suppose vals[st-1]=12 and vals[end]=1234, toh we need beech
            // wale, which is 34, to get that we have a way

            // reqd=vals[end]-(vals[st-1]*10^k) where k is difference between no
            // of digits of both vals[end] and vals[st-1], essentially k=(digit
            // cnt vals[end])- (digit cnt vals[st-1])

            // which becomes k=4-2=2, toh 10^2 we multiply to vals[st-1] toh it becomes 1200, difference both we get 1234-1200=> 34, which is reqd, yehi kar lenge

            // for digits we can directly get it from pre[] wala array

            // k nikalo
            long long k;
            if(st==0){
                k=pre[end];
            }
            else{
                k=pre[end]-pre[st-1];
            }

            // ab power of 10 nikal lo and multiply that to vals[st-1], power of 10 ke liye hardcoded array par jao wahi se nikal lo
            long long x;
            if(st==0){
                // no need for anything, since vals[end] pura lena hai
                x=vals[end];
            }
            else{

                // now we simply do vals[end]-(vals[st-1]*10^k)
                // ab this can overflow in opposite incase vals[st-1] wala bigger value ban jaaye, uss case me we add mod since we know theres 2 ways for modding -ve values

                // first way is x%mod, 
                // second way is (x+mod)%mod, 
                // second way se overall +Ve aata hai ans, which is what we need
                x=(vals[end]-(vals[st-1]*pow10[k])%mod + mod)%mod;
            }


            // ans bana kar bhej do
            ans.push_back((x * sum) % mod);
        }

        return ans;
    }
};