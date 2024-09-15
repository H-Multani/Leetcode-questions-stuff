class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mpp;
        // stores a string(key) and at what idx it was first found(i)

        // first found wala index bcoz we need biggest substring right, we wont
        // get biggest substring if we keep updateing the index right
        // see the vdo itll make more sense
        // https://youtu.be/6Xf5LfM-ciI?si=e-MtIG0zpVSTHsre

        vector<int> arr(5, 0); // for a,e,i,o,u
        string curr = "00000";
        mpp[curr] = -1; // currently all vowel at 0 cnt
        int ans = 0;
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                arr[0] = (arr[0] + 1) % 2;
            } else if (s[i] == 'e') {
                arr[1] = (arr[1] + 1) % 2;
            } else if (s[i] == 'i') {
                arr[2] = (arr[2] + 1) % 2;
            } else if (s[i] == 'o') {
                arr[3] = (arr[3] + 1) % 2;
            } else if (s[i] == 'u') {
                arr[4] = (arr[4] + 1) % 2;
            }

            // convert the current array to string
            curr = "";
            for (auto it : arr) {
                curr += to_string(it);
            }

            // if curr string found in map, then its a possible ans, update ans
            if (mpp.find(curr) != mpp.end()) {
                // update how?
                // the updated sub string length is
                // current index(i) - last jis idx par curr wali string mili
                // thi(mpp[curr])
                ans = max(ans, i - mpp[curr]);
            } else {
                // add the curr string to map, along with at which index it was
                // first found
                mpp[curr] = i;
            }
        }

        return ans;
    }
};