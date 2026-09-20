class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.size();

        for(auto i=0;i<n;i++){
            // current character ka index nikalo
            int idx=s[i]-'a';

            // reverse the idx
            idx=26-idx;

            cout<<idx<<endl;

            // ans me daal lo
            // i+1 since 1 based indexing
            ans+=(idx*(i+1));
        }

        return ans;
    }
};