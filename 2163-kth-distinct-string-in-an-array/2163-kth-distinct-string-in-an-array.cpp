class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        // stores string and its frequency

        for(auto it:arr){
            mpp[it]++;
        }

        int cnt=0;
        // keeps cnt of kitne distinct strings mile hai abhi tak
        // when cnt reaches k, that string is our answer


        int len=arr.size();
        for(int i=0;i<len;i++){
            if(mpp[arr[i]]==1){
                // curr string is distinct
                cnt++;

                if(cnt==k) return arr[i];
            }
        }

        // we out the loop means no string is distinct, return ""
        return "";
        
    }
};