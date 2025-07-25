class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx=0;

        for(int i=0;i<nums.size();i++){
            if(i>maxidx) return false;

            maxidx=max(maxidx,i+nums[i]);
        }

        if(maxidx>=nums.size()-1) return true;

        return false;
    }
};