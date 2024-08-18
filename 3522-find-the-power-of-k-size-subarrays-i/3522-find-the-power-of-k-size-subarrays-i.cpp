class Solution {
public:
    bool issorted(vector<int>& nums,int i,int j){
        for(int k=i;k<j;k++){
            // nums[k]<nums[k+1] to chk if sorted
            // nums[k]+1==nums[k+1] to chk if consecutive
            if(nums[k]<nums[k+1] && nums[k]+1==nums[k+1]){
                // return false;
            }
            else return false;
        }
        return true;
    }
    int maxval(vector<int>& nums,int i,int j){
        int ans=nums[i];
        for(int k=i;k<=j;k++){
            ans=max(ans,nums[k]);
        }

        return ans;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;

        if(nums.size()==1){
            ans.push_back(nums[0]);
            return ans;
        }

        if(k==1) return nums;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(j-i+1!=k) continue;

                // cout<<" i and j are "<<i<<" "<<j<<endl;
                // for(auto k=i;k<=j;k++){
                //     cout<<nums[k]<<" ";
                // }
                // cout<<endl;
                // size is 3, check if is sorted
                bool sorted=issorted(nums,i,j);
                if(sorted){
                    ans.push_back(maxval(nums,i,j));
                }
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};