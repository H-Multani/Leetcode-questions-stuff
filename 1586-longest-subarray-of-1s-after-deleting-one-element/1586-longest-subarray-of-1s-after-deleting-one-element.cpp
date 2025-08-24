class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // ez sliding window

        // 0 ka count lelo, and at max iss cnt ko 1 jaane dena, uske aage
        // shrink, nai toh keep extending

        int ans=0;
        int n=nums.size();

        int l=0,r=0;

        int zerocnt=0;

        while(r<n){
            // right wale ko include karo
            if(nums[r]==0) zerocnt++;

            // shrink if necessary
            while(zerocnt>1){
                // left wala banda alag karo

                // agar left wala zero tha toh 0cnt update karna
                if(nums[l]==0) zerocnt--;

                l++;
            }

            // current jo bhi hai window is the best possible ans, lelo, update ans
            ans=max(ans,r-l);
            // window me no of elements=r-l

            // extend window
            r++;
        }

        return ans;
    }
};