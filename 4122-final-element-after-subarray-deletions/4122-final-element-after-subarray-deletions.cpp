class Solution {
public:
    int finalElement(vector<int>& nums) {
        // big array lelo [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u]

        // a and u edge wale maan lo have no significant value, like ye kabhi
        // max ya min nai banega

        // ab maan lo alice ki turn maxm is o, minm is at s, toh alice
        // [p,q,...t,u] tak ka subarray remove karegi

        // remaining-> [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o], o is maxm, bob turn, i
        // is minm maan lo, toh bob remove [j,k...n,o] wala subarray playing
        // optimally

        // remaining-> [a,b,c,d,e,f,g,h,i], i is minm, alice turn maan lo e is
        // maxm, alice remove [f..i] tak ka subarray playing optimally

        // remaining-> [a,b,c,d,e], e is maxm, bob turn, c
        // is minm maan lo, toh bob remove [d,e] wala subarray playing
        // optimally

        // remaining-> [a,b,c], c is minm, alice turn maan lo b is
        // maxm, alice remove [c] tak ka subarray playing optimally

        // remaining-> [a,b], b is maxm, bob turn, ab yaha a chhota ho ya na ho
        // bob playing optimally will remove [b] toh 1 element bacha overall ans
        // is a

        // this whole thing can go other way too toh agar start me s ki jagah d
        // hota minm toh right side wala area lete apan, in such case u aata ans

        // toh overall we have 2 possible ans a and u which is start and end element

        // ab jo ans hoga yehi me se hoga, and since alice start kar rhi hai toh maxm hi legi hence ye thought chala kar maxm(a,u) will be ans, dekh lo
        int n=nums.size();
        return max(nums[0],nums[n-1]);
    }
};