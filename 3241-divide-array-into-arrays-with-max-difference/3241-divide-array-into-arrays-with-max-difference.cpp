class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // sort krke, 3-3 ke size bana kar bhj do ans me
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i+=3) {
            // 3 elements are nums[i], nums[i+1], nums[i+2]

            // agar valid hai elements toh daal do

            // valid check-> any 2 elements ka diff should be <=k

            // lekin apan bass nums[i] and nums[i+2] ka chk karenge, since agar
            // ye dono valid baithe hai means baaki bhi valid baithenge since
            // array is sorted

            if (abs(nums[i] - nums[i + 2]) <= k) {
                // means valid hai, ans me daal do
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                // we here means valid nai hai current wala array(3 size), and
                // no other 3 value array can be made, since sorted hai elements
                // toh ye best soln hai, isse better dhundna not possible, since
                // baaki saare 3 element pairs will have >k deff definitely
                cout<<"here "<<endl;
                // in such case return empty array
                return {};
            }
        }

        return ans;
    }
};