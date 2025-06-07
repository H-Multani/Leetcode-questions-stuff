class Solution {
public:
    int maxDifference(string s) {
        // freq nikal lo
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }

        // segregate karo between even and odd freq wale maps
        unordered_map<char,int> evenfreq,oddfreq;

        for(auto it:mpp){
            if(it.second%2==1){
                // pura element hi odd freq wale me daal do
                oddfreq[it.first]=it.second;
            }
            else{
                evenfreq[it.first]=it.second;
            }
        }

        // ab iterate over odd freq wala array and make the ans
        int ans=INT_MIN;
        // ans1 stores +ve maxm
        // ans2 stores -ve maxm


        for(auto it:oddfreq){
            // a1 banao
            int a1=it.second;

            cout<<a1<<endl;

            // ab a2 ke liye even freq wale map me iterate karo
            for(auto it2:evenfreq){
                int a2=it2.second;

                ans=max(ans,a1-a2);
            }
        }


        return ans;
    }
};