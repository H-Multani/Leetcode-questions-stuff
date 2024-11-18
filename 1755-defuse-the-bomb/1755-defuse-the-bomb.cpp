class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // brute force krlo, constraints boht km h
        vector<int> ans(code.size(), 0);

        if (k == 0) {
            return ans;
        }

        if (k > 0) {
            // iterate krke har posn ke liye sum nikalo and store in ans vector
            int n = code.size();

            for (int i = 0; i < n; i++) {
                // for ans[i]

                // sum of next k elements
                long long currsum = 0;
                for (int j = i + 1; j <= i + k; j++) {
                    currsum += code[j % n];
                }

                ans[i] = currsum;
            }
        } else {
            int n = code.size();
            for (int i = 0; i < n; i++) {
                // for ans[i]

                // sum of prev k elements
                long long currsum = 0;
                for (int j = i - 1; j >= i + k; j--) {
                    currsum += code[((j % n) + n) % n];
                }

                // -ve index ko +ve banane ka technique
                // i is -ve, to make +ve index we do
                // ((i%n)+n)%n
                // eg with idx -1 we want to reach index n-1 really, the above
                // formula does that for us, similarly for -2 we reach index
                // n-2, which is actually what we need for the k<0 wala case

                ans[i] = currsum;
            }
        }

        return ans;
    }
};