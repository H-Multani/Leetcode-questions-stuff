class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort kardo, ek loop chala do absolute diff ke liye, fir ek lpop me
        // adjacent ka diff nikalna, jisme aa gaya same uss pair ko ans me daal
        // dena kaam khatam

        // we check only adjacent since sorted hai array, jitna aage wala element se compare karoge utna diff bigger aayega, why go there jab ans nai milna, plus repeating ho toh samajh bhi sakte, distinct hai why bother
        sort(arr.begin(),arr.end());
        int n=arr.size();

        vector<vector<int>> ans;

        int diff=INT_MAX;

        for(int i=0;i<n-1;i++){
            diff=min(diff,arr[i+1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;


        



    }
};