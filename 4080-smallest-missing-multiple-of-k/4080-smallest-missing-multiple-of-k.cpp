class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // set me bharte jao,nai mile toh return as ans

        set<int> st;

        for(auto it:nums){
            if(it%k==0){
                st.insert(it);
            }
        }

        // ke ke multiples par chalo and return kardo

        int n=nums.size();

        // at best n+1 tak ka loop chalana padega 

        for(int i=1;i<=n+1;i++){
            if(st.find(i*k)==st.end()) return i*k;
        }

        return -1;
    }
};