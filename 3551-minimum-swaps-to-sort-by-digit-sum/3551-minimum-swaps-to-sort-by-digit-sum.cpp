class Solution {
public:
    static int cntdigit(int i) {
        int sum = 0;

        while (i > 0) {
            sum += (i % 10);
            i /= 10;
        }

        return sum;
    }
    static bool comp(int a, int b) {
        int a1 = cntdigit(a);
        int b1 = cntdigit(b);

        if (a1 == b1)
            return a < b;
        return a1 < b1;
    }
    int minSwaps(vector<int>& nums) {
        // sabse pehle sorting toh kar hi do hisab se, fir problem becomes himn
        // swaps to make arry1 and arry2 same

        vector<int> arr = nums;
        int n = nums.size();
        sort(arr.begin(), arr.end(), comp);

        // since distinct elements hai toh indexes store karlo nums ka kaam
        // aayega aage
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }

        // ab apan ko simple swapping karna hai
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // since elements distinct hai toh elements ko compare kar sakte
            // directly

            if (nums[i] != arr[i]) {
                // meaning kuch swap machana padega

                // swap karne ke liye 2 element chahiye nums[i] and
                // nums[j], since original array me changes karne

                // yaha par arr[i] aana chahiye element, lekin arr[i] ka nums me
                // konsa idx tha-> mpp[arr[i]]
                int j = mpp[arr[i]];

                // ye index ka element in nums is at nums[mpp[arr[i]]]

                // kardo swap
                swap(nums[i], nums[mpp[arr[i]]]);
                // ab swapping karenge toh aage indexes change ho jayenge, toh
                // mpp me index update kardo, elements ke

                // jo banda pehle nums[j] me tha vo ab nums[i] me aa chuka hai, toh uska index update kardo
                mpp[nums[i]] = i;
                // same with j wala banda
                mpp[nums[j]] = j;

                // ek swap ho gaya ans count karlo
                ans++;

            }
        }

        return ans;
    }
};