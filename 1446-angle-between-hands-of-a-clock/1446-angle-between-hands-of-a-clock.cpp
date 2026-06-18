class Solution {
public:
    double angleClock(int hour, int minutes) {
        // hour hand kaha hai, uske hisab se nikalenge actual angle

        double hr, mins;

        // minuite ka simple hai, 360/60-> 6 degrees per minuite passed, toh
        // minuite hand is at minutes*6 degrees from top(12)
        mins = 6 * minutes;


        // hour ke liye
        // 360/12-> 30 degrees per hour, toh sabse pehle toh vo bana lo

        // edge case, agar hour=12 uss case me 0 se karna count
        if(hour==12) hour=0;

        hr=30*hour;

        // ab minuites pass hue honge toh utna aur aage badhega

        // 60 mins me 1 hr pass hota-> 30 degrees move in 60 mins, toh per minuite 30/60=0.5 degrees per minuite aage badhega

        // toh minuites ke hisab se hour hand kitna aage badha nikal kar add kardo 
        hr+=(0.5*minutes);

        // ab top(12) se dono hands ka angle nikal liye hai difference karlo for ans
        double ans=abs(hr-mins);


        // now its possible ki hr hand and min hand ke beeech me itna dist ko ki difference nikalne se bigger wala angle aa raha hai, like ho sakta time is 11:05, iss case me angle will be the larger one

        // aise cases me angle ko 360 se subtract kar lenge toh andar wala mil jayega, toh usko bhi ans me le lena

        ans=min(ans,360.0-ans);

        return ans;
    }
};