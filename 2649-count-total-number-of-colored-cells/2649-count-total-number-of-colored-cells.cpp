class Solution {
public:
    long long coloredCells(int oldn) {
        // jiase jaise n increase hora hai, some things are happening

        // 1. beech wali line is increasing like 1,3,5,7,9...., ie odd numbers
        // me ie for n=2->colorcells=3,for n=3->colorcells=5,for
        // n=4->colorcells=7 and so on
        // formula for this line is (2*n)-1
        long long n=oldn;
        // toh sabse pehle toh ye middle line ka add karo
        long long ans = 0;
        ans += (2 * n) - 1;

        // ab upar and neeche wali lines ko dekho

        // for upar wali lines

        // for n=2, no of boxes coloured=1;
        // for n=3, no of boxes coloured=4;
        // for n=4, no of boxes coloured=9;
        // for n=5, no of boxes coloured=16;

        // toh all in all, beech wali line ke alava, upar wale side me (n-1)^2,
        // jitne colured boxes rahenge, examples se toh yehi samajh aa raha hai

        // similarly, neeche wale side me bhi (n-1)^2, boxes coloured rahenge,
        // toh all in all ans me 2*((n-1)^2) add kardo

        ans += 2 * ((n - 1) * (n - 1));

        // ab saare count kar liye hai coloured boxes, beech wale line me honge
        // (2n-1) colured boxes and upar and neeche side rahenge (n-1)^2 boxes
        // each side, hence 2 baar laga diya, ab return krdo ans
        return ans;
    }
};