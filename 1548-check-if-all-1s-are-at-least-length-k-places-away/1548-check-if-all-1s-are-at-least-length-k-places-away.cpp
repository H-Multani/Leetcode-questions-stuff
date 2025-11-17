class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // prevk

        int prevk=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prevk==-1){
                    prevk=i;
                    continue;
                }

                if(i-prevk<=k) return false;

                prevk=i;
            }
        }

        return true;
    }
};