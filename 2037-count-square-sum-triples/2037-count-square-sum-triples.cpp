class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int val=((i*i)+(j*j));
                // agar square root lene ke baad integer aur float wali same value hai means perfect square hai, also check if new value is withing range
                if(sqrt((float)(val))==sqrt(val) && sqrt(val)<=n) ans++;
            }
        }

        return ans;
    }
};