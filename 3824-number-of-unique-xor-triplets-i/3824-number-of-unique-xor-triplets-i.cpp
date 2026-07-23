class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) return 2;

        // we here means 3 hai ya aage, 3 se aage formula lagana padega for nearest power of n since utne hi unique values laga paoge

        // toh 2 ka power lete jao jab n cross karlo wahi se return kar dena

        // we do this since

        int ans=1;

        while(ans<=n){
            ans*=2;
        }

        return ans;
    }
};