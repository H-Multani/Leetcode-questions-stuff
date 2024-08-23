/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left=1,right=n;
        int ans=n+1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                // curr version is bad
                ans=mid;

                // go left
                right=mid-1;
            }
            else{
                // curr version is true->good
                left=mid+1;
            }
        }

        return ans;

    }
}