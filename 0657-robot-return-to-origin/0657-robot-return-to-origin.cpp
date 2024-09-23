class Solution {
public:
    bool judgeCircle(string moves) {
        int updown=0,lftrt=0;
        for(auto it:moves){
            if(it=='U'){
                updown++;
            }
            if(it=='D'){
                updown--;
            }
            
            if(it=='L'){
                lftrt--;
            }
            if(it=='R'){
                lftrt++;
            }

        }

        if(updown==0 && lftrt==0) return true;
        return false;
    }
};