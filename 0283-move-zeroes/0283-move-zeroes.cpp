class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int zerocnt=0;
        for(auto it:nums){
            if(it==0) zerocnt++;
            else{
                ans.push_back(it);
            }
        }

        for(int i=0;i<zerocnt;i++){
            ans.push_back(0);
        }

        nums=ans;
        return;
    }
};