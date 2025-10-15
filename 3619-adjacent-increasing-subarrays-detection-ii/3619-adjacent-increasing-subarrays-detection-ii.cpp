class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // count each increasing subarray ka size

        vector<int> sub;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                cnt++;
            } else {
                sub.push_back(cnt);
                cnt = 1;
            }
        }
        sub.push_back(cnt);

        // ab subarrays banane ke 2 cases ho sakte hai
        int ans = -1;
        // case 1-> 2 adjacent subarrays lelo and dono me se minm size wala
        // could be ans, like if adjacent subarrays are of size 5 and 3,
        // then maxm we can make 2 adjacent suabrrays of size min(5,3)=3

        for (int i = 1; i < sub.size(); i++) {
            // sirf 2 adjacent subarrays se jo ban sakta hai usko include karo
            ans = max(ans, min(sub[i - 1], sub[i]));
        }

        // isse jitne possible ans hai which can be made using 2 adjacent
        // subarrays aa jayega

        // case 2-> agr aubarrays of sizes like 3 4 12 4, then maxm ans ke liye
        // upar wala case 4 dega as ans, however we can make better answer by
        // making 2 adjacent subarrays out of the size 12 subarray, toh size 12
        // wala subarray me se 2 adjacent subarrays bana dena of size 6 each
        // mast

        // iss case ke liye ans nikalo ab
        for(auto it:sub){
            ans=max(ans,it/2);
        }

        return ans;
    }
};