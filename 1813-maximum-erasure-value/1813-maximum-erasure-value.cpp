class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int> mpp; 

        int ans=0;
        int sm=0;

        while(r<n){
            mpp[nums[r]]++;
            sm+=nums[r];

            while(l<=r && (r-l+1)!=mpp.size()){
                mpp[nums[l]]--;
                sm-=nums[l];
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }

            // cout<<l<<" "<<r<<" "<<sm<<endl;
            ans=max(ans,sm);

            r++;
        }

        return ans;
    }
};