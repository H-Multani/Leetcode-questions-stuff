class Solution {
    public int mySqrt(int x) {
        int left=0,right=x;
        int ans=0;
        while(left<=right){
            long mid=left+(right-left)/2;
            if(mid*mid==x){
                return (int)mid;
            }else if(mid*mid<x){
                // possible answer hai
                // update ans
                ans=(int)mid;
                //go right
                left=(int)mid+1;
            }
            else{
                // mid*mid>x, we have overshot the range
                // go left
                right=(int)mid-1;
            }
        }
        return ans;
    }
}