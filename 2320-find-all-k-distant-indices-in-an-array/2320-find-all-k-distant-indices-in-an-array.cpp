class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(i-j)<=k && nums[j]==key){
                    // we here means i th wala banda k wali range me aata hai, ans me daal do i ko
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};