class Solution {
public:
    int dosmth(string val){
        for(int i=0;i<val.size();i++){
            if(val[i]=='0' || val[i]=='1' || val[i]=='8'){
                // rotate to themselves
            }
            else if(val[i]=='2' || val[i]=='5'){
                if(val[i]=='2') val[i]='5';
                else if(val[i]=='5') val[i]='2';
            }
            else if(val[i]=='6' || val[i]=='9'){
                if(val[i]=='6') val[i]='9';
                else if(val[i]=='9') val[i]='6';
            }
            else{
                // become invalid
                return -1;
            }
        }

        int ans=stoi(val);
        return ans;
    }
    int rotatedDigits(int n) {
        
        int ans=0;

        for(int i=1;i<=n;i++){
            int vals=dosmth(to_string(i));
            if(i!=vals && vals!=-1){
                cout<<i<<endl;
                ans++;
            }
        }

        return ans;
    }
};