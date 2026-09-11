class Solution {
public:
    int totalNumbers(vector<int>& d) {
        // yaha brute force kar sakte, O(n^3) wala approach

        int ans=0;
        int n=d.size();
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    
                    // agar ek bhi value repeat toh skip maardo
                    if(i==j || j==k || k==i) continue;

                    int val=(d[i]*100)+(d[j]*10)+(d[k]);

                    if(val%2==0 && val>=100) st.insert(val);
                }
            }
        }

        return st.size();

    }
};