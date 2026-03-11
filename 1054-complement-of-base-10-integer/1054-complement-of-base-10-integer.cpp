class Solution {
public:
    int bitwiseComplement(int n) {
        
        // edge case, age n==0 hai toh return 1
        if(n==0) return 1;

        // number ka binary string banao
        string s="";

        while(n>0){
            s+=((n%2==1)?'1':'0');
            n/=2;
        }

        // reverse kardo string ko
        reverse(s.begin(),s.end());
        cout<<s<<endl;

        // flip maar do
        n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }

        // ab iska integer value bana do

        // for that first reverse the string
        reverse(s.begin(),s.end());
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans+=(1<<i);
            }
        }

        cout<<ans;

        return ans;

    }
};