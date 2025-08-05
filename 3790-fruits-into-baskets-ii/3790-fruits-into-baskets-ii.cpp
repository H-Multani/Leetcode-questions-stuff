class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // constraints too small brute force it

        // vector laga lo store karne vaaste ki konsa wala basket occupied ho gya hai
        int n=baskets.size();
        vector<bool> vis(n,false);

        for(auto it:fruits){
            for(int i=0;i<n;i++){
                if(!vis[i] && baskets[i]>=it){
                    // means iss basket me dal sakte hai daal do
                    vis[i]=true;
                    break;
                }
            }
        }

        // ab jitne false hai utne basket unoccupied hai count krlo
        int cnt=0;
        for(auto it:vis){
            if(!it){
                cnt++;
            }
        }

        return cnt;
    }
};