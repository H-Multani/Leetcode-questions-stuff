class Solution {
public:
    typedef long long ll;
    ll n;
    vector<vector<ll>> memo;
    ll solve(ll i, ll trend, vector<int>& nums) {
        // base case
        if (i >= n) {
            // yaha ya toh ans bana hoga kuch ya nai bana hoga

            if (trend == 3) {
                // agar apan trend 3 par pahuch chuke the toh means trionic mil
                // chuka tha

                // iss case me return 0 kardo , since trend 3 tak pahuch chuke
                // the apan,trionic bana chuke the
                return 0;
            } else {
                // we here means next karte karte trend 1,2 lete chale gaye
                // trend 3 mila hi nahi, iss case me trionic pair is invalid,
                // since trend 3 aaya hi nahi, in such case return minm value so
                // that ans yaha wala aaye hi na kabhi
                return LLONG_MIN / 2;

                // /2 kyu??-> since worst case me dekho curr me add hora hai
                // aage se aane wala soln, toh agar vo worst case wala element
                // LLONG_MIN hua toh usme LLONG_MIN add karna will be out of
                // bound, toh usse bachne ke liye LLONG_MIN/2 bhej do so that
                // overflow nai hoye sinnce worst case me curr=LLONG_MIN/2 , and same was returned here toh ghum fir kar LLONG_MIN banega which is usable

            }
        }

        // agar memo me hai ans toh behej do
        if(memo[i][trend]!=LLONG_MIN) return memo[i][trend];

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        // agar trend 0 chalra means yaha se trend 1 chalu kar sakte
        if (trend == 0) {
            // means 2 options hai,

            // ya yaha se start karlo trend 1 ya yaha se start mat kro trend 1

            // skip kardo, aage dekho, toh aage i+1, trend same=0 hi rhega
            skip = solve(i + 1, trend, nums);
        }

        // last case: i am at trend 3 and yaha par stop kardo, since ho sakta
        // aage subarray smaller bane

        if (trend == 3) {
            // yaha take karke finish at this element
            take = nums[i];
        }

        // ab dekhte ki trend 1 ya 2 par ya hoga
        if (i + 1 < n) {
            // means current and next le sakte
            ll curr = nums[i];
            ll next = nums[i + 1];

            // yaha trend 0 hai, start trend 1 from here, take karliya
            if (trend == 0 && next > curr) {
                // means trend 1 chala sakte
                // also, take krre hai toh current element add karna take wale
                // case me

                take = max(take, curr + solve(i + 1, 1, nums));
                // aage trend 1 bhej do
            } else if (trend == 1) {
                // apan trend 1 par hai, kya apan trend 1 ko increase kar
                // sakte??
                if (next > curr) {
                    // kar sakte extend, karlo
                    take = max(take, curr + solve(i + 1, 1, nums));
                    // aage trend 1 bhej do
                } else if (next < curr) {
                    // means trend 1 nai chala sakte yaha lekin trend 2 chala
                    // sakte hai toh take karlo aur aage trend 2 chalu kardo

                    take = max(take, curr + solve(i + 1, 2, nums));
                    // aage trend 2 bhej do
                }
            } else if (trend == 2) {
                // means trend 2 par hai

                // same cases,
                // 1->kya trend 2 extend kar sakte
                // 2->kya trend 3 chala de
                if (next < curr) {
                    // kar sakte extend, karlo
                    take = max(take, curr + solve(i + 1, 2, nums));
                    // aage trend 2 bhej do
                } else if (next > curr) {
                    // means trend 2 nai chala sakte yaha lekin trend 3 chala
                    // sakte hai toh take karlo aur aage trend 3 chalu kardo

                    take = max(take, curr + solve(i + 1, 3, nums));
                    // aage trend 3 bhej do
                }
            } else if (trend == 3 && next > curr) {
                // last case trend 3 chalra hai

                // yaha case bana ki agar further increase karne ka man hai th
                // check karlo yehi and aage badha do
                take = max(take, curr + solve(i + 1, 3, nums));
                // aagr trend 3 bhej do

                // yaha trend 3 par 2 case banne the, ek case jisme trend 3 aage
                // badha rahe apan, ek case jisme yehi rol rahe subarray ko, ye
                // second wala case upar likh liye hai pehle hi
            }
        }

        // ab take nottake me se maxm sum jaha aaya lelo
        // update before sending ans
        return memo[i][trend]=max(take, skip);
    }
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        // TLE memo bana do

        // we change i and trend, i can be 0 to n-1, trend can be 0,1,2,3 thats it, vahi bana do

        memo.assign(n+1,vector<ll>(4,LLONG_MIN));

        return solve(0, 0, nums);
        // we send (i,trend) trend 0 is starting trend, trend 1 is nums[l...p]
        // increasing,trend 2 is nums[p...q] decreasing,trend 3 is nums[q...r]
        // increasing


        // i is starting index which is 0
    }
};