class Solution {
public:
    bool checkString(string s) {
        bool bfound=false;
        for(auto it:s){
            if(!bfound && it=='a') continue;
            
            // we here means ya b mila hai ya bfound is true
            if(it=='b'){
                // means b mila hai, iss case me bfound ko true kardo
                bfound=true;
                // and continue forward
            }
            else{
                // we here means 'a' mila hai and bfound=true means saare a dont appear before b
                return false;
            }
        }

        return true;
    }
};