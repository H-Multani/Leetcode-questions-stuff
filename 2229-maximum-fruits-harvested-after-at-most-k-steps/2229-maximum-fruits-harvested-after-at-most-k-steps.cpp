class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        // prefix sum nikalo fruits ka, and lower bound and uper bound lagane ke
        // liye we need positions vector toh 2 vectors bana lo
        vector<int> pre(n);
        vector<int> posn(n);

        for (int i = 0; i < n; i++) {
            posn[i] = fruits[i][0];

            // ab prefix sum update karo
            if (i == 0) {
                pre[i] = fruits[i][1];
            } else {
                pre[i] = pre[i - 1] + fruits[i][1];
            }
        }

        // ab dono arrays filled hai

        int ans = 0;

        // kitna distance chalega(left ya right doesnt matter) uska loop chalao
        for (int d = 0; d <= k / 2; d++) {
            // d steps chala hai

            // case 1: moved d steps to the left side

            // remaining steps
            int remain = k - (2 * d);
            // startpos se d steps left me gaya hai, toh new posn
            int i = startPos - d;
            // phir yaha se hoke aane ke baad ab right me jayega, startpos se
            // remaining steps right side me, 2d bcz left jane me d steps lage
            // and then left se vapas startPos aane me d steps lage ttl 2d steps
            // , jitne remaining hai utne steps right me jaa payega bass
            int j = startPos + remain;

            // ab i and j mil gaya hai, i and j are points on x axis jiss par
            // maxm jaa payenge left and right side me
            // ab indexes nikalo ki left me jaane par konsa idx tak ke fruits le
            // payenge apan same with right side
            // index nikalo left wala, ki left me posn i tak jaane me kitne
            // fruits ko andar karna hai
            int left = lower_bound(begin(posn), end(posn), i) - posn.begin();
            // similarly right side ka nikalo idx, ki rt side me j tkk jaane me
            // kitne fruits ko andar kiya
            int rt = upper_bound(begin(posn), end(posn), j) - posn.begin() - 1;

            // ab iss left se rt ke beech me actual me kitne fruits honge nikal
            // lo prefix sum wale array se
            int ttl;

            // invalid case left>right ho jaaye toh nai karna kuch
            if (left <= rt) {

                if (left > 0) {
                    ttl = pre[rt] - pre[left - 1];
                } else
                    ttl = pre[rt];

                // itne max fruits nikle hai ans update kardo
                ans = max(ans, ttl);
            }


            // case 1 done, ab case 2

            // case 2: moved d steps to right side
            remain=k-(2*d);
            i=startPos-remain;
            j=startPos+d;

            left = lower_bound(begin(posn), end(posn), i) - posn.begin();
            rt = upper_bound(begin(posn), end(posn), j) - posn.begin() - 1;
            
            // chk same thing as above
            if (left <= rt) {

                if (left > 0) {
                    ttl = pre[rt] - pre[left - 1];
                } else
                    ttl = pre[rt];

                // itne max fruits nikle hai ans update kardo
                ans = max(ans, ttl);
            }

        }

        // ans bhj do
        return ans;
    }
};