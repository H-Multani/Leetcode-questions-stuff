class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,l=0,r=0;
        int n=nums.size();
        while(r<n-1){
            // farthest kitna jaa sakte
            int farthest=0;

            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }

            // new range update karo
            // l start hoga frm r+1
            l=r+1;
            // r will be farthest
            r=farthest;
            jumps++;
        }

        return jumps;
    }
};