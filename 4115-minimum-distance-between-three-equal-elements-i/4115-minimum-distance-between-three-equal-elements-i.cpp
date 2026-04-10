class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // same value wale ke index map me daal do

        // this will help keep all distinct elements with same value ke index
        // close together, toh iterate karne me time nai lagega
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            // nums[i] wali value ka index uske liye store karlo
            mpp[nums[i]].push_back(i);
        }

        // toh mpp[3]={5,7,8,25} means nums[5]=3,nums[7]=3,nums[8]=3,nums[25]=3

        // ab inn index me tuple dhund sakte hai since all tuples will be good
        // tuples since saare tuples ka nums me value same rahega

        int ans = INT_MAX;

        // good tuple dhundo

        // ab apan ko dhundna hai abs(i-j)+abs(j-k)+abs(k-i)
        // realistically dekhe agar toh we can say that indexes increasing ya
        // decreasing rahenge, either way, i!=j!=k,

        // i<j<k leke chale agar toh essentially when we do abs(i-j) is dist bw
        // i and j +Ve, then abs(j-k), which is dist bw j and k +ve, then
        // abs(k-i) which is just dist bw k and i

        // toh overall we do (j-i)+(k-j)+(k-i) agar i<j<k wale order par chale
        // toh, and abs hata de toh, which equates to -i+k+k-i-> 2k-2i

        // toh minm value nikal lenge 2k-2i ka, which can be pair of every
        // arr[i] and arr[i+2] since arr[i+1] is for idx j wala banda

        // har possible valid tuple par iterate karna and dekh lena
        for(auto [_,arr]:mpp){
            // all elements in arr have same value in nums

            int m=arr.size();

            for(int i=0;i<m-2;i++){
                // get minm value of 2k-2i

                // k wala is arr[i+2], i wala is arr[i]

                ans=min(ans,(2*arr[i+2])-(2*arr[i]));
            }
        }

        // if nothing found
        if(ans==INT_MAX) return -1;

        return ans;
    }
};