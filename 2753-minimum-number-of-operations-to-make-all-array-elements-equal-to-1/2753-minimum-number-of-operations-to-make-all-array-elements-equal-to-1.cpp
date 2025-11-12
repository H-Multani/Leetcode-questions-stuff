class Solution {
public:
    int minOperations(vector<int>& nums) {
        // first and foremost saare elements ka overall GCD lelo ek, agar vo 1
        // aata hai kahi se means something can be done, otherwise we send -1
        int overall = nums[0];
        int one = 0;
        for (auto it : nums) {
            overall = __gcd(overall, it);
            if (it == 1)
                one++;
        }

        // agr ye overall 1 hua means it can be achieved, otherwise send -1
        if (overall != 1)
            return -1;

        // okay toh apan array me once again overall calculate karte chalte
        // hai start se, and jaha bhi overall==1 hua means uss point ke alava
        // saare jitne elements hai sab 1-1 operation me set ho jaenge

        // like if values are {2,6,3,4}, then gcd(2,6)=2 replace 6 with 2(1
        // operation), then gcd{2,3}=1, replace 3 with 1 (1 operation), ab array
        // is like {2,2,1,4}, then ab iss 1 se baaki saare n-1 elements can be
        // made 1, toh ttl operations+=n-1=3, overall operations=3+1+1=5, which
        // is not correct since instead of whole array, chhote subaaray me
        // operation kare toh bhi same ans niklega kam steps me eg taking
        // gcd(3,4)=1, uske baad n-1=4-1=3 steps+1(3,4 ka gcd wala step)=4 steps
        // me kaam khatam

        // toh it doesnt matter for efficient approach since constraint too
        // small, simple subarray logic se ho jaega

        int ans = INT_MAX;

        // ok toh edge case ye hai ki agar pehle se boht elements 1 hai toh unko
        // change nai karna padega apan ko toh ek onecount le lenge jisko
        // overall ans me se subtract kar denge and agar onecnt==n hua toh means
        // 0 steps reqd

        int n = nums.size();
        if (one == n)
            return 0;

        // also agar onecnt>0 hua toh bhi ye neeche wala kaam karne ka need nai
        // hai, since ek 1 can be used to make rest elements 1, toh agar
        // onecnt=3,n=7, then 7-3=4 elements bache each will take 1 step to
        // become 1
        if(one>0) return n-one;

        for (int i = 0; i < n; i++) {

            // overall lelo
            int overall = nums[i];
            for (int j = i; j < n; j++) {
                // overall update karo
                overall = gcd(overall, nums[j]);

                // now we have subarray [i,j] agar overall=1 hai toh j-i jitne
                // steps lage to get this overall to 1(kaise??, ek testcase
                // subarry leke dekh le bhai j-i jitne hi lagenge steps ), iske
                // baad baaki saare elements ko ek ek operation me 1 karna
                // padega which will take n-1 steps toh add kardo
                if (overall == 1) {
                    // means steps nikal sakte hai yaha se. since the first time
                    // we here will be the best time since smallest subarray
                    // liya hoga toh stpes calculate karke break kar dena so
                    // that better options can be explored faster

                    int steps = (j - i) + (n - 1);
                    ans = min(ans, steps);
                }
            }
        }

        return ans - one;
    }
};