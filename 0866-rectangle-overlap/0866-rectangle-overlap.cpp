class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // kaha overlap nai hoga ye dekhte hai

        // agar rec1 ka top right corner is smaller than rec2 ka bottom left
        // corner

        if(rec1[2]<=rec2[0] || rec1[3]<=rec2[1]){
            // iss case me koi overlap nai hoga
            return false;
        }

        // ulta kardo, 
        // agar rec2 ka top right corner is smaller than rec1 ka bottom left
        // corner
        if(rec2[2]<=rec1[0] ||  rec2[3]<=rec1[1]){
            // iss case me koi overlap nai hoga
            return false;
        }

        // we here means overlap toh hoga yaar 
        return true;
    }
};