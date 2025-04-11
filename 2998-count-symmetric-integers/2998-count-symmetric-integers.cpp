class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;

        for(int i=low;i<=high;i++){
            // curr bande ko convert to string
            string curr=to_string(i);

            // sum of first and last halves kardo
            int sum1=0,sum2=0;

            if(curr.size()%2==1) continue;

            for(int j=0;j<curr.size()/2;j++){
                sum1+=curr[j]-'0';
            }
            for(int j=curr.size()/2;j<curr.size();j++){
                sum2+=curr[j]-'0';
            }

            if(sum1==sum2) ans++;
        }

        return ans;
    }
};