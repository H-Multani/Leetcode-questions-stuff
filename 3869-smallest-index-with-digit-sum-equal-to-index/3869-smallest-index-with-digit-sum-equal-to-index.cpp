class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // digits sum nikalo
            int ttl=0;

            while(nums[i]>0){
                ttl+=nums[i]%10;
                nums[i]/=10;
            }

            if(ttl==i) return i;
        }

        // we here means koi nai mila
        return -1;
    }
};