class Solution {
    public int searchInsert(int[] nums, int target) {
        // insert posns could be from 0 to len-1, take those left and rt
        int left = 0, right = nums.length - 1;
        int posn = nums.length;
        int ans = 0;// maan lo initially apan element start me rakhenge
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                // means we have to push an element in array that is already present, toh uss
                // element ke posn par insert karenge directly
                // in eg1. we found 5 at idx 2 and target is also 5, toh we push our element at
                // the same posn where we found the occurence, now there can already be at most
                // 1 occurence of each value in nums, since constraint say all values are
                // distinct and sorted, so 5 mila hai toh 1 baar hi milega thats it, we dont
                // have to think of a case where multiple 5's are found in nums, since uske liye
                // alag approach hota thoda sa, but here its simple so we just return the index
                // of current element since iske posn pr hi lagaenge apna element

                // posn mil gaya, straight return as ans
                return mid;
            } else if (nums[mid] < target) {
                // means apan ka mid target se chhota hai, toh agar target ko insert karvana hai
                // toh vo current wale element ke aage hi lagega most probably, toh left jaane
                // ka koi sense nai hai since target current wale se aage hi lagega(ie to the
                // right), so go right
                left = mid + 1;

                // also, since apan ko pata hai ab ki target ko mid wale element ke aage rakhna
                // padega(since we are in this else if block), since apne ko target to mid ke
                // aage rakhna padega, hence one possible position for target could be just
                // after mid, ie at mid+1, since mid ke aage rakhna hi hai, toh mid+1 is a
                // posible(maybe) position jaha rakh sakte, ab rakhenge ki nai vo loop update
                // kar dega, but currently toh mid+1 is a possible correct position right

                // so mid+1, is a possible posn jaha apan target ko rakh sakte hai, toh update
                // ans as well, update to keep the possible position in ans
                ans = mid + 1;
            } else {
                // means apan ka mid target se bada hai, toh agar target ko insert karvana hai
                // toh vo current wale element ke peeche hi lagega most probably(since sorted
                // order chahiye right), toh right aane ka koi sense nai hai since target
                // current wale se peeche hi lagega(ie to the left), so go left

                right = mid - 1;
            }
        }

        return left;
    }
}