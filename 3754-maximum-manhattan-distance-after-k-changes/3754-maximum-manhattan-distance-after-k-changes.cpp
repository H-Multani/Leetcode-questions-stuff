class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=-1;

        int east=0;
        int west=0;
        int north=0;
        int south=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                east++;
            }
            else if(s[i]=='W') west++;
            else if(s[i]=='N') north++;
            else if(s[i]=='S') south++;

            // current manhatan dist
            int currd=abs(east-west)+abs(north-south);

            // curr kitne steps liye h
            int steps=i+1;
            int wasted=steps- currd;

            int extra=0;

            if(wasted!=0){
                // steps!= ,manhattan dist
                extra=min(2*k,wasted);
            }

            // sinal current manhattan dist
            int finalcurrMD=currd+extra;

            // max manhattan dist update krdo
            ans=max(ans,finalcurrMD);
        }

        return ans;
    }
};