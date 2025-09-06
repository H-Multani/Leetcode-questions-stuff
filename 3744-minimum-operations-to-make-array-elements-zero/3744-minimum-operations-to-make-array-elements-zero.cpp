class Solution {
public:
    long long solve(long long l, long long r) {
        // starting with the smallest range first
        long long L = 1;

        // R baar baar change hoga toh loop me hi define kar denge

        // ye L,R range ho gai, and iske liye steps needed=1 (for starting
        // range)
        long long S = 1;

        long long ttl = 0;

        // loop tab tak chalao jab tak L<r hai, ie (L,R) ke range me elements
        // hai jiska nikalna hai
        while (L <= r) {
            long long R = (4 * L) - 1;

            // ab overlapping area nikalo between (L,R) and (l,r), beech ke area
            // ke har element ko S steps lagenge, count karlo

            // overlapping area
            long long start = max(L, l);
            long long end = min(R, r);

            // agar no overlapping area ie start>end, in such case no need to
            // count further, in such case get out of loop

            if (start <= end) {
                // we here means valid hai range


                // we here means area valid hai, kinte elements hai count karlo
                long long elements = end - start + 1;

                // har element ko S steps lagenge, toh vo total me add kardo
                ttl += (elements * S);
            }

            // agli wali range ke liye L,R and S chahiye rahega, ranges go like
            // (1,3),(4,15),(16,63),(64,255) and soo onn, toh L changes like
            // 1,4,16,64.. toh L=L*4 for next range

            // and next range me jayenge toh an agli range me har element ke
            // liye S+1 steps lagenga, toh update S too

            // update L
            L *= 4;
            // update S
            S++;
        }

        // return the step count
        return ttl;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        // iterate over all the queries
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];

            long long steps = solve(l, r);

            // isse current query ke steps aa gaye, toh result me add kardo

            // this is the no of steps agar ek ek karke/4 kare toh, lekin since
            // apan ek baar me 2 elements ko /4 kar rahe hai hence half steps
            // lagenge

            // so ttl to be added in ans is steps/2, lekin agar odd hua toh uss
            // case me 1 step extra lagega, toh to handle that we add
            // (steps+1)/2

            ans += (steps + 1) / 2;
        }
        return ans;
    }
};