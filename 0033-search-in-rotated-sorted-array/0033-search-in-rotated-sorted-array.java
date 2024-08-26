class Solution {
    public int search(int[] nums, int target) {
        // take left and right
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            // so far normal

            // now check which half is in sorted order
            else if (nums[left] <= nums[mid]) {
                // means left se mid tak sorted hai
                // search if target can be present in the sorted part
                if (target >= nums[left] && target < nums[mid]) {
                    // means target can b found in left side
                    // go left
                    right = mid - 1;
                } else {
                    // means target can not be found in the sorted part
                    // go to the other side(right)
                    // go right
                    left = mid + 1;
                }
            } else {
                // means left se mid tak sorted nai hai, ie mid se right tak sorted part hai
                // array ka
                // search if target can be present in the sorted part
                if (target <= nums[right] && target > nums[mid]) {
                    // means target can b found in sorted part, ie the right side hence to find
                    // target move to the right side
                    // go right
                    left = mid + 1;
                } else {
                    // means target cannot be found in sorted part
                    // so go to the other side, ie the left side, since sorted part me nai hai toh
                    // unsorted wale half me hoga pakka
                    // go left
                    right=mid-1;
                }
            }
        }
        return -1;
    }
}