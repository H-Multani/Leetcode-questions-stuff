class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // ok toh maxm pair sum minimize karna hai agar toh pair aise banane
        // padenge ki maxm wala element gets paired with minm element so that
        // pair sum is somewhere in the middle

        // similarly 2nd max with 2nd min and 3rd max with 3 rd min, and so onn,
        // iske alava kuch bhi karoge toh bigger sum aayega

        // toh yehi logic chala denge and pair sum banate chalenge, har pair sum
        // ka maxm le lenge, and ans me dal kar send

        // this works since we need smallest maximum pair sum, toh maxm pair sum
        // of (1st max,1st min),(2nd max,2nd min),(3rd max,3rd min) se aise pair
        // sum milenge such that maxm pair sum is smallest, since sabse biggest
        // elements ko pair bana diya smallest ke sath, ab iss smallest ke alva
        // koi ke sath karoge pair toh pairsum biggest aayega, so best plan
        // chalne do

        sort(nums.begin(),nums.end());

        // ab first and last ke idx lelo to get (1st max,1st min) aand so on
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<j){
            // pair will be nums[i] and nums[j]

            // maxm pair lelo
            ans=max(ans,nums[i]+nums[j]);

            // i and j update kardo to get to next maxm and next minm
            i++;j--;
        }

        return ans;
    }
};