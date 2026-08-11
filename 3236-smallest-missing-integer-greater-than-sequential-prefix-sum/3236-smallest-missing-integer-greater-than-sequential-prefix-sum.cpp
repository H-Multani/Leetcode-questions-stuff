class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // pehle toh longest sum nikal lo
        int sum = 0;
        int n = nums.size();
        sum = nums[0];

        // we need nums[0] se start hone wala best sum
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                sum += nums[i];
            } else {
                // yaha aa gaye means jitna sequence sum banna tha ban gaya,break frm loop
                break;
            }
        }

        // sort kardo array ko ab
        sort(nums.begin(),nums.end());

        // sum se bada ya barabar jab tak mile lelo, jab na mile array me break 

        for(int i=0;i<n;i++){
            if(nums[i]==sum){
                sum++;
            }
        } 

        // ye wala bestsum is minm jo nums me nai hai return it
        return sum;
    }
};