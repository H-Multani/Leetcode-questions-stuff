class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // sabse pehle saaare possible pairs ka sum bana kar vector me daalo
        vector<long long> pairsum;

        // for weights={1,2,3}, pairs will be [1,2],[2,3] iska pair sum will be
        // 3,5, yehi pair sum daalo
        for (int i = 1; i < weights.size(); i++) {
            pairsum.push_back(weights[i] + weights[i - 1]);
        }

        // ab pairsum ko sort kardo
        sort(pairsum.begin(), pairsum.end());

        // ab k partitions ke liye apan ko k-1 pairs uthaane padenge, toh maxm
        // sum ke liye end se k-1 pairs utha lo, and minm ke liye start se k-1
        // pairs utha lo

        // ab un pairs ka bhi sum hoga maxm and minm score banane ke liye, toh
        // saath me sum karte jayenge
        long long maxm=0,minm=0;

        // minm ke liye 0 se k-1 pairs uthao
        for(int i=0;i<k-1;i++){
            minm+=pairsum[i];
        }
        // maxm ke liye pairsum.size-1 se k-1 pairs uthao, peeche
        for(int i=0;i<k-1;i++){
            maxm+=pairsum[pairsum.size()-i-1];
        }

        return maxm-minm;
    }
};