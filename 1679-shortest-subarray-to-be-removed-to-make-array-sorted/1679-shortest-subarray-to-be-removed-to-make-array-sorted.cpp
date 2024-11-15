class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // find j th ptr frm rt side
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }

        int i = 0;
        int ans = j;
        // we are removing all elements left of index j bcoz, idx j to n-1 are
        // sorted, hence possible ans

        // start finding correct i and j and find deleted elements=j-i-1

        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {

            // arr[i]>arr[j], jab tak ye hora j aage badhao for better possible
            // ans
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // we have found correct j th element such that arr[i]<=arr[j]
            ans = min(ans, j - i - 1);

            i++;
        }

        return ans;
    }
};