class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1,
                      int x2, int y2) {

        // one way to check if any overlap is ki rectangle ka nearest point lelo
        // to centre of circle and dist nikal lo, if this dist<=radius means
        // overlap present, return ans

        // and given hai ki axis aligned hai, meaning ya koi side se connection
        // hoga, ya kisi edge se

        // toh ye kar sakte ki nearest point ke x and y nikal sakte hai

        // nearest x nikalne ke liye 3 cases hai
        int nearx;
        // bottom left wala x se bhi peeche hai cx, then
        // agar cx<x1, then nearest x wala point to circle centre is x1, imagine left me circle hai, right me rectangle hai, like eg1
        if(xc<x1) nearx=x1;

        // top rt wala x se aage hai cx, then
        // agar cx>x2, then nearest x wala point to circle centre is x2, imagine rt me circle , left me rectangle
        else if(xc>x2) nearx=x2;

        // case 3, dono ke beech me hai kahi,malab x1<xc<x2 wala scene hai, iss case me nearest point ka x will be gotten by dropping perpendicular on rectangle ka side, and since rect is axis aligned, hence perpendicular bhi x=xc par hi rukega, toh iss case me nearest x is xc
        else nearx=xc;

        // same with y

        int neary;

        if(yc<y1) neary=y1;
        else if(yc>y2) neary=y2;
        else neary=yc;

        int xdist=nearx-xc;
        xdist=xdist*xdist;
        int ydist=neary-yc;
        ydist=ydist*ydist;

        // ab iska distance nikalo radius se
        // usual dist me hota hai sqrt((x-x1)^2 + (y-y2)^2)
        // yaha apan sqrt nai karenge, square both sides, hence radius ka square nikalenge left me and rt me bacha hua item, then compare directly
        if((radius*radius)<(xdist+ydist)){
            // we here means radius is smaller than distance, to nearest point, in such case no overlap
            return false;
        }

        // we here means overlap hoga
        return true;

    }
};