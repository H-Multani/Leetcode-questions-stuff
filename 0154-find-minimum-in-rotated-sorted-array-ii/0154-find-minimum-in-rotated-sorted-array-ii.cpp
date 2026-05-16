class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minm = INT_MAX;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < minm) {
                minm = nums[mid];
            } else if (nums[mid] > nums[right]) {
                // did nums[right] bcoz if nums[mid]>nums[right] then for
                // left=mid+1 the element will be in the right half of the array
                left = mid + 1;
            } else {

                // we here means mid and right wala same element hai, toh ab
                // pata nai kaisa kya scene hoga, possible hai ki right me
                // smaller mil jaaye, lekin ye bhi possible hai ki actual minm
                // left me hi ho and mid se right tak common elements ho

                // toh apan kya karte hai ki sird 1 element se shrink karte hai
                // right ko bass, since its same value as mid value toh 1 se
                // shrink karne par bass ek duplicate skip hoga, but overall
                // apan search space ko shrink hi kar rahe, even if its by 1
                // element
                right--;
            }
        }
        return minm;
    }
};