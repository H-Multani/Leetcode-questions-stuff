class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        int[] ans = new int[2];
        int startidx = -1;
        int endidx = -1;

        // for finding starting idx
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                // this is a possible answer, update
                startidx = mid;
                // now for startng index, we need smallest index such that numd[mid]==target,
                // smalles index mid ke aage toh milne nai wala, so no need to go to the right
                // side, hence go left
                right = mid - 1;
            } else if (nums[mid] > target) {
                // means apan target ke bohot aage aa chuke hai, to get correct target value
                // index we need to go left side, since right me jaenge toh target se aur badi
                // values milengi which is wrong since apan ko target ka hi index chahiye tha
                // so no sense in going right side since current mid target se bada hai, right
                // jaenge toh aur badi values milegi jo apne use ka nai hai since we need
                // smallest index of target value, so to at least get some index of target we go
                // towards where target is ie to the left
                // go left
                right = mid - 1;
            } else {
                // means apan target ke bohot peeche aa chuke hai, to get correct target value
                // index we need to go right side, since left me jaenge toh target se aur chhoti
                // values milengi which is wrong since apan ko target ka hi index chahiye tha
                // so no sense in going left side since current mid target se chhota hai, left
                // jaenge toh aur choti values milegi jo apne use ka nai hai since we need
                // smallest index of target value, so to at least get some index of target we go
                // towards where target is ie to the right
                // go right
                left = mid + 1;

            }
        }

        // now apan ko minm index mil chuka hai, do same stuff for maxm index
        left = 0;
        right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                // possible ans, update
                endidx = mid;
                // there could be ending idx to the right side, probably, and left jane me
                // ending index toh milne nai wala, starting mil jaega maybe vo baat alag hai
                // but ending nai milega, so to get ending index go to the right side

                // since ho sakta hai ki curent ke right side me rahe ending index, chances
                // zyada hai, hence go right
                left = mid + 1;
            } else if (nums[mid] > target) {
                // we here means apan target ke boht aage aa chuke hai already, curent ke right
                // me jaenge toh aur door chale jaenge target ke, and apne ko trget ka index
                // chahiye, so we need to at least move towards the direction of target. and
                // target mid ke left side me hai, so to at least get some index of target we
                // move towards left side
                // go left
                right = mid - 1;
            } else {
                // nums[mid]<target
                // we here means apan target ke boht peeche aa chuke hai already, curent ke left
                // me jaenge toh aur door chale jaenge target ke(since left side wale elements
                // smaller hone), and apne ko trget ka index chahiye, so we need to at least
                // move towards the direction of target. and target mid ke right side me hai, so
                // to at least get some index of target we move towards right side
                // go right
                left=mid+1;
            }
        }

        ans[0]=startidx;
        ans[1]=endidx;
        return ans;
    }
}