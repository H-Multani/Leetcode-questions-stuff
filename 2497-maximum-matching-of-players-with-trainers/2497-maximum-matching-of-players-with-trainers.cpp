class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        vector<bool> gbool(g.size(),false);
        int gi=0,si=0;

        while(gi<g.size() && si<s.size()){
            if(g[gi]<=s[si]){
                gbool[gi]=true;
                gi++;
                si++;
            }
            else{
                si++;
            }
        }

        int truecnt=0;

        for(auto it:gbool){
            if(it) truecnt++;
        }

        return truecnt;
    }
};