class Solution {
public:
    int countLargestGroup(int n) {
        // sum of digits banate jao har no. ka , count increase krte jao, phir maxm size return krdena
        unordered_map<int,int> mpp;

        for(auto i=1;i<=n;i++){
            // digit ka sum nikalo
            int curr=i;

            int sum=0;
            while(curr>0){
                sum+=curr%10;
                curr/=10;
            }

            mpp[sum]++;
        }


        int maxm=-1;

        for(auto it:mpp){
            maxm=max(maxm,it.second);
        }

        // maxm freq nikal li, ab iss freq waale bande kitne h cnt karo
        int ans=0;

        for(auto it:mpp){
            if(it.second==maxm) ans++;
        }

        return ans;
    }
};