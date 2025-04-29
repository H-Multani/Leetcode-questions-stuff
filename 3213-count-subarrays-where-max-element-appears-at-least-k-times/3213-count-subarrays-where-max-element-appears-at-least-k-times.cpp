class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // again idk anything abt sliding window yet
        // imma just try smth
        int left = 0;
        int right = 0;
        int len = nums.size();
        int maxm = *max_element(nums.begin(), nums.end());

        // keep cnt of the subarrays
        long long cnt = 0;

        // keep count of the no of times maxm element has appeared
        int maxm_count = 0;

        // edge case
        // agar pure array me maxm ke k se kam instances hai, then return 0,
        // bcoz the condition will never be satisfied then
        if (count(nums.begin(), nums.end(), maxm) < k)
            return 0;

        while (right < len) {
            // use the new element
            // agar maxm hai toh maxmcount increase karo
            if (nums[right] == maxm)
                maxm_count++;

            // the loop part i did was wrong, as well as the managing the window
            // part

            // doing the correct way, see notes(of this questn) and redo the
            // code when learnt
            // theres some parts of the code i dont know yet, so imm write what
            // i think is right, readting the solns and all
            while (maxm_count >= k) {
                // means our subarray is correct,so we can reduce the size if
                // necessary and also count the subarrays to the right (that we
                // are yet to visit)

                // decrease the maxm count if left wala element is maxm, coz we
                // shrinking the window if the maxm count becomes less than k,
                // we will automatically step out of the loop(or smth)
                if (nums[left] == maxm)
                    maxm_count--;
                // increase left to decrease window size
                left++;

                // now since we have at least k instances of maxm, and we arent
                // at the end of the array(since right<len) so we count all the
                // subarrays that will come to thr right of this subarray, since
                // they will all have at least k instances of maxm

                // like for eg the current subarray has at least k instances, so
                // if we dont shrink the window anymore, and just increase the
                // size, each window will have the k instances of maxm that the
                // original(this current) window had which is just the no of
                // elements from current place to the end of array

                // like if
                // current is [3,2,3] and maxm=3 with k=2, and the array was
                // like [3,2,3,3,4,7] then the subarrays will be
                // [3,2,3,3],[3,2,3,3,4] and [3,2,3,3,4,7]. which is what we got
                // when not decreasing the window anymore but expanding it until
                // the end of array

                // notice that all the subarrays has the
                // original([3,2,3]) with the rest of the elements added one by
                // one so to just acoomodate those subarrays as well as the
                // original, we just add len-right to the count like for above
                // eg we add 6-2=4, which accounts for all the 4 subarrays which
                // could be made, ie [3,2,3],[3,2,3,3],[3,2,3,3,4] and
                // [3,2,3,3,4,7]

                // we do all this, we add this since we cant just stop shrinking
                // the window, coz we need the window to advance and shrink too

                // hence to accomodate all the possible subarrays which could be
                // made starting at this current window, we add the len-right

                // since when we shrink the window, none of the upcoming
                // subarrays(that satisfy or dont) will not start with [3,2,3]
                // like above ones did with current window

                // idk man, read this a couple times to get this to your head
                // or read the solution i saw this from, check notes for that(of
                // this questn, not the actual nb)

                // we can also think of this like counting all subarrays
                // starting frm this l(nai aaya ye agar toh no worries upar wala
                // logic bhi theek h)

                cnt += len - right;
            }

            // move the window forward
            right++;
        }

        return cnt;
    }
};