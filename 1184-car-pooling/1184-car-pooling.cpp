class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // prefix sum se ho jaega lets try

        // sabse pehle maxm kaha tak trip hogi nikalo, location since utne size ka vector chahiye rahega
        int n=-1;
        for(auto it:trips){
            n=max({n,it[2],it[1]});
        }

        // n+2 size ka banao
        vector<int> prefix(n+2,0);
        // prefix[i]=4 means dist= i par car me 4 passenger baithenge best case me

        // iterate krke add krte jao
        for(auto it:trips){
            int start=it[1];
            int end=it[2];
            int ppl=it[0];

            // prefix me passengers add krdo
            prefix[start]+=ppl;
            prefix[end]-=ppl;
        }

        // ab prefix array bana do
        for(int i=1;i<n+2;i++){
            prefix[i]+=prefix[i-1];
        }

        // agar kahi par bi overall passenger cnt> capacity hua toh return false
        for(auto it:prefix){
            if(it>capacity) return false;
        }
        return true;
    }
};