class Solution {
public:
    int binsearch(int val,vector<int>& arr){
        // bana lo ans
        int ans=-1;
        int l=0,r=arr.size()-1;

        // we need arr[mid]>=val
        while(l<=r){
            // mid nikalo
            int mid=l+(r-l)/2;

            if(arr[mid]>=val){
                // this is possible ans update 
                ans=max(ans,mid);

                // right me jao for better ans, since we need the biggest index we can find
                l=mid+1;
            }
            else{
                // means ans nai mila, go left for possible ans
                r=mid-1;
            }
        }

        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // custom binary search likhna padega apan ko jo descending array par
        // chale

        // for each element of nums1, apa binary search chalaenge nums2 par for
        // best element

        // ans nikal lenge
        int ans=0;

        // maxm distance nikalna hai yaad rakhna

        for(int i=0;i<nums1.size();i++){
            // current nums[i] ke liye aage j dhundo using binary search

            int j=binsearch(nums1[i],nums2);

            // agar j>=i means its a possible ans, in such case update ans
            if(j>=i){
                ans=max(ans,j-i);
            }
        }

        return ans;
    }
};