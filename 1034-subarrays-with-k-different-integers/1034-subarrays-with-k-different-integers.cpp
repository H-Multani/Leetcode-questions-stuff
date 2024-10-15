class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // no of subarrays with exactly k distinct integers=no of subarrays with
        // at most k distict integers-no of subarrays with at most k-1 distinct
        // integers, common sense really, idk why this didnt click

        // so we make a function that calculates for at most k distinct distinct
        // integers
        int no_of_subarrays_with_atmost_k_distinct_int =
            no_of_subarraysWith_at_most_K_Distinct(nums, k);
        int no_of_subarrays_with_atmost_k_minus1_distinct_int =
            no_of_subarraysWith_at_most_K_Distinct(nums, k - 1);

        return no_of_subarrays_with_atmost_k_distinct_int -
               no_of_subarrays_with_atmost_k_minus1_distinct_int;
    }
    int no_of_subarraysWith_at_most_K_Distinct(vector<int>& nums, int k) {
        // returns the count of subarrays with at most k distinct integers

        // yaha par lagao sliding window
        int right = 0, left = 0, ans = 0;
        int len = nums.size();

        // map stores the freq of the different elements, this is used to keep
        // count of how many distinct values we have found
        // so if for eg map size=3 means we have found 3 distinct values
        // the 3 values could have different frequencies but that doesnt matter
        // as long as the freq are +ve values, and the element only in map if
        // the freq are +ve, else itll be removed from map
        unordered_map<int, int> mpp;

        while (right < len) {
            // use the new element, freq badhao
            mpp[nums[right]]++;

            // reduce window if necessary
            while (mpp.size() > k) {
                // means current window me more than k distinct values hai
                // toh we have to shrink the window such that we have only <=k
                // distinct values

                // reduce the freq of the left element, since we have to remove
                // it
                mpp[nums[left]]--;

                // if freq reach 0, remove the element from map
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);

                // left aage badhao, shrink the window
                left++;
            }

            // now we have a subarray with at most k distinct values
            // now we add to ans, all the possible subarrays bw left and right
            // think like this

            // since current subarrary/window me, <=k distinct values hai
            // toh isse chhote saare subarrays me bhi <=k distinct values honge
            // definitely toh vo vali saare subarrays add karne hai,not like all
            // of the subarrays that start from left(the index). we cant just go
            // n*(n+1)/2 for the subarrays bcoz as we move the window forward,
            // the various subarrays will automatically get added

            // so for eg
            // current is [...,4,3,4,3,2,...], right=7,left=3, the subarrays
            // accounted here are [4],[4,3],[4,3,4],[4,3,4,3],[4,3,4,3,2],(or
            // the subarrays accounted are
            // [4,3,4,3,2],[3,4,3,2],[4,3,2],[3,2],[2]) ie total 5 subarrays, ie
            // right-left+1 and as the window will move forward we will account
            // for the rest of the subarrays also this is basically for all the
            // subarray combination that start at left(the index) and upto
            // right(the index)
            ans += (right - left + 1);
            // yehi hai bhai explanation best mera, iske baad toh solns dekhne
            // honge(ye notes of this questn, nb waale nai, yaha waale notes)

            // move window forward
            right++;
        }

        return ans;
    }
};