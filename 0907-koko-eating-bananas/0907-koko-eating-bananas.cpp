class Solution {
public:
    bool check(vector<int>& pile, long long currspeed, long long h) {
        long long hrcnt = 0;

        for (auto it : pile) {
            if (it % currspeed == 0) {
                hrcnt +=(it/currspeed);
            }
            else{
                hrcnt +=(it/currspeed);
                hrcnt++;
            }
        }

        if(hrcnt>h) return false;

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        // sort(piles.begin(), piles.end());

        long long low = 1, high = *max_element(piles.begin(),piles.end()), ans;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};