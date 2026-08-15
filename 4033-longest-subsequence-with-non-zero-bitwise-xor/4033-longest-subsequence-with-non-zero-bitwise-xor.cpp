class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // ok toh yaha essentially 2 hi options ho sakte hai

        // ya toh saare elements ka XOR hoga non zero, in which case ans is n
        // or
        // if saare ka XOR 0 hai then n-1 ka XOR pakka non 0 hoga GG laga lo

        int n=nums.size();
        int overall=0;
        for(auto it:nums){
            overall^=it;
        }

        // agar n elements ka XOR is non 0 then n is the ans
        if(overall!=0) return n;

        // yaha ek edge case ban sakta hai ki saare elements 0 hai in which case ans will be 0

        // else koi bhi ek non zero bande ko alag karke best ans bana sakte in which case ans is n-1

        // loop chala kar dhund lo
        for(auto it:nums){

            // agar non 0 mil gaya means iss 1 non 0 ko alag kar denge toh overall XOR is non 0, hence n-1 is ans, since best subsequence is with n-1 elements
            if(it!=0) return n-1;
        }

        // we here means saare elements 0 mil gaye, iss case me ans is 0
        return 0;
    }
};