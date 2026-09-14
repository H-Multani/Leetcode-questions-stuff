class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // kaha overlap hoga ye boht saare cases hai 2 rectangles se , har case
        // ko nai dekh sakte

        // kaha overlap nai hoga ye dekhte hai

        // maan lo rec1 is neeche wala

        // agar rec1 ka top right corner is smaller than rec2 ka bottom left
        // corner in atleast 1 coordinate, then overlap nai hoga

        // ie rec1 ka top right ka x and y coordinate se bada wala x ya y mila
        // agar rec2 ke bottom left me, means koi overlap nai hoga

        // used OR here since rec1 ka top rt and rec2 ka botom left can have 3
        // cases jab overlap nai karega

        // case 1
        // rec2 is above rec1, iss case me rec1 ka y coordinate will be lesser
        // than rec2 ka y coordinate, even if x ka value rec1 ka bigger ho,
        // imagine 2 rectangles ek ke neeche ek, upar wale ka botom left ka x
        // might be smaller than rec2 ka top rt lekin no overlap since y is boht
        // different
        // case 2
        // rec2 is to right of rec1, iss case me rec1 ka x coordinate will be
        // lesser than rec2 ka x coordinate, even if y ka value rec1 ka bigger
        // ho, imagine 2 rectangles ek ke baju me ek, right wale ka botom left
        // ka y might be smaller than rec2 ka top rt lekin no overlap since x is
        // boht different
        // case 3
        // rec2 is to right and above of rec1, iss case me rec1 ka x and y
        // coordinate will be lesser than rec2 ka x and y coordinate, imagine 2
        // rectangles ek ke diagonal me dusra, iss case me koi overlap sochne
        // par bhi nai hoga since rec1 ka top rt is neeche than rec2 ka bottom
        // left

        // yehi 3 cases ko dhyan se dekhenge toh we see, ki rec2 ka bottom ka
        // koi bhi coordinate is bigger than rec1 ke top ka corresponding
        // coordinate, meaning overlap nai hoga

        // toh overall if rec1 ka top x is smaller than rec2 ka bottom x, OR
        // rec1 ka top y is smaller than rec2 ka bottom y, OR both

        // iss case me nai banega overlap, likh diya

        if (rec1[2] <= rec2[0] || rec1[3] <= rec2[1]) {
            // iss case me koi overlap nai hoga
            return false;
        }

        // ulta kardo,
        // maan lo rec2 is neeche wala
        if (rec2[2] <= rec1[0] || rec2[3] <= rec1[1]) {
            // iss case me koi overlap nai hoga
            return false;
        }

        // we here means overlap toh hoga yaar
        return true;
    }
};