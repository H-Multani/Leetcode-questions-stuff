class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st_idx) {
        // pehle toh index nikalo target ka, then har valid index ka distance
        // nikal lena from starting index, from both side, ie moving forward and
        // backward

        // startindex is useless shit, we dont even need to start frm it, apan
        // ka kaam bass index se hai and index ka distance from startindex se
        // hai bass, toh while loop chalane ka bhi need nai hai simple iteration
        // karlo

        int len = words.size();

        int ans = INT_MAX;

        for (int i = 0; i < len; i++) {
            if (words[i] == target) {
                // means this is a valid index for target, ab iss index se
                // starting index ka distance nikal lo, utna hi steps chalna
                // padega

                // distance is abs(st_idx-i) agar same array me chal rahe, aur
                // agar rotating array banana hai toh

                // maan lo st_idx is 1 and target is at idx 5
                // [_,1,_,_,_,5,_]-> idx 1->2->3->4->5 , abs(5-1)=4 steps
                // [_,1,_,_,_,5,_]-> idx 1->0->6->5, n-abs(5-1) = 3 steps

                // yehi tareeka hoga since agar direct jaoge toh abs(i-st_idx)
                // steps lagenge hi , and ghum kar jaoge toh abs(i-st_idx) itne
                // steps se bach jaoge, lekin elements toh array me n hi hai
                // overall, toh agar abs(i-st_idx) steps alag bhi kar diye toh
                // n - abs(i-st_idx) steps hi toh bache ghum kar vapas aane ke
                // liye


                // ye 2 ways hai best ans ke liye, get best ans

                ans=min({ans,abs(i-st_idx),len-abs(i-st_idx)});
            }
        }

        // agar koi target nai mila toh return -1
        if(ans==INT_MAX) return -1;

        return ans;
    }
};