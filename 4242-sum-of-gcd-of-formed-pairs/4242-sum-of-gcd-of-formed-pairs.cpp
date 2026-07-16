class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        // jo bola hai vahi kardo aur kya

        // mxi banate chalenge sath me
        long long mxi;
        int n=nums.size();
        // prefixgcd bana lenge
        vector<long long>pre;
        mxi=nums[0];
        for(auto it:nums){
            // update mxi
            mxi=max(mxi,1LL*it);

            // gcd nikal kar add kardo pre me
            pre.push_back(__gcd(mxi,1LL*it));
        }

        // sort kardo pre ko
        sort(pre.begin(),pre.end());

        // pairs bana kar gcd nikalte chalo and ans me add kardo
        long long ans=0;

        for(int i=0;i<n/2;i++){
            // 1st and last element ka gcd nikal kar ans me daal do
            ans+=__gcd(pre[i],pre[n-i-1]);
        }

        return ans;

    }
};