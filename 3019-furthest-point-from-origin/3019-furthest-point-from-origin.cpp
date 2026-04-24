class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // left count karlo ttl, right cnt karlo ttl, and space cnt krlo ttl

        int left = 0, rt = 0, space = 0;

        for (auto it : moves) {
            if (it == 'L')
                left++;
            else if (it == 'R')
                rt++;
            else
                space++;
        }

        // ab if left>right means left boht bari jaa rahe hai, toh usko hi
        // support kar lenge '_' wale se

        int ans = 0;

        if (left > rt) {
            // means left boht baari gaye hai overall me, toh saare '_' left
            // leke jaenge, just to get to best posn

            // chala do logic bhej do ans

            int cnt = 0;

            for (auto it : moves) {
                if (it == 'L' || it == '_') {
                    // move left
                    cnt--;
                } else {
                    // move right
                    cnt++;
                }
            }

            // sab simulate karne ke baad ans update kardo, since agar beech me
            // update karoge toh galat ans maxm ban sakta hai, since we need
            // overall posn at end of all steps
            ans=max(ans,abs(cnt));

        } else {
            // means right>=left, means overall apan right boht baari gaye hai,
            // har '_' ki baari me right chale jana fir
            int cnt = 0;

            for (auto it : moves) {
                if (it == 'R' || it == '_') {
                    // move right
                    cnt++;
                } else {
                    // move left
                    cnt--;
                }
            }
            ans=max(ans,abs(cnt));
        }

        return ans;
    }
};