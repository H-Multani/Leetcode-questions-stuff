class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // sabse pehle toh sort karna padega
        sort(arr.begin(),arr.end());

        // ab agar start par 1 already hai to baaki elements order me karenge(nai hai toh), otherwise aage badhte jaenge

        // thing to note is apan element ko bas kam kar sakte hai aage nai badha sakte, need to keep that in mind

        if(arr[0]!=1) arr[0]=1;

        int n=arr.size();
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1){
                // sahi hai aage badho, no need to change anything here, diff is <=1, chah kar bhi arr[i] ko aage nai badha sakte since only reduce karne ka option hai apne paas
            }
            else{
                // galat hai, this means arr[i] is boht bigger than arr[i-1], in this case, arr[i] ko arr[i-1]+1 par laa kar chhor do, so that biggest ans tak badh bhi paaye and valid bhi rahe
                arr[i]=arr[i-1]+1;
            }
        }

        return arr[n-1];
    }
};