class Solution {
public:
    bool hasAlternatingBits(int n) {
        // binary number bana kar string me daal do, bade se bada binary number is of size 32 string length
        string s="";

        while(n>0){
            s+=(n%2==0)? "0":"1";

            n/=2;
        }

        // check karo if kahi same bits mil gaye toh rok dena
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])return false;
        }

        return true;
    }
};