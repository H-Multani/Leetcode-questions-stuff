class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        if(n==10) return true;
        int ans=0;
        int s=10;
        
        while(n-s>=0){
            n-=s;
            ans++;
            s--;
        }

        if(ans%2==1) return true;
        return false;
    }
};