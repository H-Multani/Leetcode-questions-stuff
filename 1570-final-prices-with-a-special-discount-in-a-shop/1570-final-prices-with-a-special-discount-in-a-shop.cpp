class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            int minm = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    minm = prices[j];
                    break;
                }
            }
            if (minm <= prices[i])
                prices[i] -= minm;
        }

        return prices;
    }
};