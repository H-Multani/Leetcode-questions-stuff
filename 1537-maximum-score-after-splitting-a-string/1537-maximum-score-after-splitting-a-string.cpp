class Solution {
public:
    int maxScore(string s) {
        int n=s.size();

        int ans=-1;
        for(int i=1;i<n;i++){
            // i-1 se 0 tak 0's count karo
            int zeros=0;
            for(int j=i-1;j>=0;j--){
                if(s[j]=='0') zeros++;
            }

            // i se n-1 tak 1's count karo
            int ones=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') ones++;
            }

            ans=max(ans,zeros+ones);
        }

        return ans;
    }
};