/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1, right = n;
        int badver = n + 1;
        while (left <= right) {
            int mid = left + ((right-left) / 2);

            

            // mid wala bad version hai kya
            if (isBadVersion(mid)) {
                // true means current version is bad
                // update current version
                badver = mid;
                // since current version is bad, ho sakta hai iske peeche wala koi version bad
                // ho,

                // current version bad means iske aage wale sare version will be bad too(accd to
                // question), so no sense in going right side(since all will be bad version but
                // none will be the first bad version), left me ho sakta hai mil jaaye the first
                // bad version, since could be ki iss vale version ke pehle koi aur version mil
                // jaaye which would be first bad version
                // so go left side
                right = mid - 1;
            } else {
                // false means current version is not bad
                // current version is not bad means, isse pehle wale koi versions bhi bad nai
                // honge, since if 1 version is bad uske aage saare versions will be bad, so if
                // current is not bad, means iske pehle wale saare versions are also not bad
                // versions, so no sense in trying to find bad version in left side since all
                // will be good versions, so go right side to find first bad version
                
                // overall go right side
                left=mid+1;
            }
        }
        return badver;
    }
}