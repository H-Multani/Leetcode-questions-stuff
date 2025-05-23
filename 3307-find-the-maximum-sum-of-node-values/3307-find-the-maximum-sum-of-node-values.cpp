class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        // toh we have to apply the k wala operation on minm 2 nodes yeah

        // maan lo nodes [a,b] ko dekhe agar, toh a^k>a and b^k>b, toh matlab
        // a,b par operation lgana would be a good plan as it will increase the
        // sum

        // but (a,b) is not an edge so nai laga sakte direct operatn, but we can
        // indidrectly, woulddnt it change the beech wale element?, no look here
        // if edges were like (a,x),(x,y),(y,b), toh a and b are indirectly
        // connected, apply operation on these 3 edges we get
        // (a,x) becomes-> (a^k,x^k), toh x and a wala node have updated values,
        // so for aage wala edges jaha pehle x tha waha ab x^k rahega
        // (x^k,y) becomes-> (x^k^k,y^k)=>(x,y^k), toh x has regained its
        // original value but y becomes y^k.
        // (y^k,b) becomes-> (y^k^k,b^k)=>(y,b^k), toh that means y has regained
        // its original value but b becomes b^k

        // all in all path from a->x->y->b, after 3 operations becomes
        // a^k->x->y->b^k, which is the thing we wanted originally(only changes
        // to a and b by operation, nobody else)

        // toh by this logic apan koi bhi (a,b) nodes leke un par direct
        // operation laga kar values maximize kar sakte hai, condition being ki
        // 2 nodes at a time need mandatory, since the logic doesnt work in 1
        // node

        // toh even no of changes (even no of values where a^k>a hai) ke liye
        // toh kaam set hai apna, 2-2 ke pair leke lagate jao operation and GG

        // but for odd no of changes, what we can do is, find the element which
        // will give the least change in value like (a,b) lele agar toh if a^k>a
        // hai bass, toh we take b such that b^k doesnt remove from the overall
        // sum too much

        // like choose b such that b-(b^k) will be minm so that agar b wale node
        // me change kar bhi diya toh overall sum will not be changed much

        // maan lo array is {a,b,c}, and we have only a^k>a, no else(means baaki
        // elements par operation nai laga sakte sum will decrease),toh apan
        // array par iterate krke dekhenge ki konsa element h which will give
        // smallest change in overall sum

        // current overall sum=a+b+c, agar sirf a par operatn laga sakte toh
        // best sum would be =(a^k)+b+c

        // if we take (a,b), then sum becomes = (a^k)+(b^k)+c
        // if we take (a,c), then sum becomes = (a^k)+(c^k)+b

        // ab maan lo b-(b^k)<c-(c^k), meaning b me operation karne par chhota
        // change aayega overall sum me since b isnt going really far changing
        // frm b to b^k as comapared to c to c^k, since difference kam hai

        // toh in such case laga do (a,b) wala operation, hence the max sum
        // possible is (a^k)+(b^k)+c

        // but apan toh operation akrte gaye the na so we have the ideal
        // sum=(a^k)+b+c, lekin ye ideal sum feasible hi nai h, the maxm
        // feasible sum is (a^k)+(b^k)+c, the diff bw these sums is b-(b^k),
        // which is the element b that we took which gave minm change, toh sbse
        // simple plan h ki ye smallest wala banda ka change store karlo, ye
        // sbse kam nuksan krra hai overall sum me

        // toh ideal sum me se nuksan ko subtract kardo and the ans is reached,
        // ie ideal-nuksan= ((a^k)+b+c)-(b-(b^k)) => ((a^k)+(b^k)+c)

        // yehi approach laga do

        ll idealsum = 0;
        // to keep ideal sum

        // kitne elements par changes kiye count karlo, since even no of changes
        // is no problem, odd me dikkat ayegi
        ll changecnt = 0;

        // store the element which will give minm change (minm nuksan to overall
        // sum)

        // nuksan store karlo seedha since element store kroge then diff
        // nikaloge then subtract yada yada, too much
        ll nuksan = INT_MAX;

        for (auto it : nums) {
            // if it^k>it, toh change karke add kardo ideal sum me
            if ((it ^ k) > it) {
                // it^k karke ideal me dal do
                idealsum += (it ^ k);
                // changes kiya 1 element me toh cnt krlo
                changecnt++;
            } else {
                // we here means change karne par it^k<it banega, toh yaha
                // change nai karenge, original it hi add kardo ideal sum me
                idealsum += it;

                // lekin possible hai ki it wala banda give the minm
                // nuksan(incase of odd no of changes), toh nuksan nikal kar
                // minm nuksan store karlo
            }
            nuksan = min(nuksan,abs(1LL*(it - (it ^ k))));
        }

        // ab 2 cases hai , ya toh changes even hai, in which case the ideal sum
        // will be made, return it
        if (changecnt % 2 == 0) {
            return idealsum;
        }

        // we here means odd values the, but we have stored the minm nuksan
        // karane wala banda, toh best possible achievable sum will be diff bw
        // ideal sum and nuksan
        return idealsum - nuksan;
    }
};