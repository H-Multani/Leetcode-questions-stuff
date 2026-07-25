class Solution {
public:
    int maxProduct(int n) {
        // jitne digits hai nikal lo aur sort kardo
        vector<int> dgt;

        while(n>0){
            dgt.push_back(n%10);
            n/=10;
        }

        sort(dgt.begin(),dgt.end());
        n=dgt.size();

        int ans;

        if(n==1) ans=dgt.back();
        else ans=dgt[n-1]*dgt[n-2];

        return ans;
        
    }
};