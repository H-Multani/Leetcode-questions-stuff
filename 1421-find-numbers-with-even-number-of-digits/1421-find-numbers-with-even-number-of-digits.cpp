class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;

        for(auto it:nums){
            // no of digits=log10(val)+1;
            if(((int)log10(it)+1)%2==0) ans++;
        }

        return ans;
    }
};