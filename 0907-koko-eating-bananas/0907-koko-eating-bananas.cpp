class Solution {
public:
    bool check(vector<int>& pile, long long currspeed, long long h) {
        // no of hrs needed to finish all the piles
        long long hrcnt = 0;

        for (auto it : pile) {
            // current pile ko khatam karne me kitne hrs lagenge
            // utne hrs nikal kar hrcnt me add kardo
            // (see para 2 of questn to understand why we do this)
            if (it % currspeed == 0) {
                hrcnt += (it / currspeed);
            } else {
                hrcnt += (it / currspeed);
                hrcnt++;
            }
            // if yaha par hi agar hrs taken>h ho gaye, means h hrs me saari
            // piles khatam nai ho payengi, return false
            if (hrcnt > h)
                return false;
            // optional code hai ye wala, iske bina bhi chalega no worries
        }

        // if no of ttl hrs taken > h, means h hrs me saari piles khatam nai ho
        // payengi, in such case return false
        if (hrcnt > h)
            return false;

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // minm speed eats 1 banana per her, maxm speed eats (maxm element)
        // bananas per hr
        long long low = 1, high = *max_element(piles.begin(), piles.end()), ans;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // kya is mid speed se kha sakte hai?

            // is speed se khayenge toh kya h hrs me saare bananas khatam ho
            // paenge ?
            if (check(piles, mid, h)) {
                // means yes, iss speed se saare bananas khatam ho sakte hai
                // within h hrs, ab smaller speed chahiye that satisfies, go
                // left
                ans = mid;
                high = mid - 1;
            } else {
                // means iss speed se saare bananas khatm nai ho paenge within h
                // hrs, go right side to get higher eating speed
                low = mid + 1;
            }
        }
        return ans;
    }
};