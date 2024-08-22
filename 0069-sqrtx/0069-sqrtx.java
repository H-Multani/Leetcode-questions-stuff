class Solution {
    public int mySqrt(int x) {
        // can ask shivansh
        if(x==0 ||  x==1) return x;
        int left = 1, right = x;
        // start frm 1 since minm 1 ka square ho sakta hai answer
        int ans = -1;
        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (mid * mid == x) {
                // this is straight up the answer, since ye x perfect square hoga tabhi mid
                // squared=x ho raha, in such a case return mid directly
                return (int)mid;
            }
            if (mid * mid <x) {
                // this can be a possible answer, update
                ans = (int)(mid);
                // now go right, since left me toh current mid se chhote values hi milenge,toh
                // possible answers hai but may not be right since for eg for x=8, correct
                // values will be 1,2. 1 le sakte hai but 1*1!=x, not even close, apne ko index
                // lena hai such that its at least close to x, and since we are smaller than x
                // curently, toh right jane me we could get bigger value, which could get is
                // closer to x, hence go right
                left = (int)mid + 1;
            } else {
                // this number cant be an answer, since iska square is more than the reqd x,toh
                // sabse pehle toh ek integer chahiye such that square of it is less than to or
                // smaller than x(since questn says rounded down to nearest integer, for eg for
                // x=5,6,7,8 ans will be 2, since sabke sq root rounded down to nearest integer
                // is 2) jo ki current wale se nai mil raha(since current ka mid*mid>x), since
                // we are overshooting the answer required

                // toh ab right jane me sense nai hai, since right me aur values milenge such
                // that mid*mid>x, which in itself is wrong,toh we cant go right, since going
                // right will result in wrong values, hence option bacha hai go left

                // going left we can find a mid such that mid*mid<=x, which could be a possible
                // answer

                // go left
                right = (int)mid - 1;
            }
        }
        return ans;
    }
}