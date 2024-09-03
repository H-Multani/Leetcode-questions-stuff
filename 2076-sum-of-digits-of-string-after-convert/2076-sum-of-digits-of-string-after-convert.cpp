class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=to_string(s[i]-'a'+1);
        }
        // int value=stoi(s);
        int ans=0;
        s=temp;
        cout<<s<<endl;
        while(k--){
            string temp="";
            int sum=0;
            for(auto it:s){
                sum+=(it-'0');
            }
            cout<<sum<<endl;

            temp=to_string(sum);
            s=temp;
        }
        ans=stoi(s);
        return ans;

    }
};