class Solution {
public:
    vector<string> ans;
    int n;

    void solve(int toopen, int toclose, string curr) {
        // agar edge par pahuch gaye (toopen==0 and toclose==0) means curr valid
        // ban chuka hai option ek, ans me daal do
        if (toopen == 0 && toclose == 0) {
            ans.push_back(curr);
            return;
        }

        // we here means we have 2 options

        // option 1-> open a bracket here, iske liye condition bass ek rahegi ki
        // toopen>0, ie bracket open karne ke liye hona bhi chahiye
        if (toopen > 0) {
            // open kar sakte yaha kardo

            // since yaha ek bracket open kiya hai toh aage toopen-1 jayega, and
            // since yaha bracket open kiya toh usko aage close bhi karna
            // padega, toh toclose+1 jayega

            // curr me bhi bracket daal kar bhejna
            solve(toopen - 1, toclose + 1, curr + '(');
        }

        // option 2-> close a bracket here, iske liye condition bass ek rahegi
        // ki toclose>0 hona chahiye, ie bracket close karne ke liye hona bhi
        // chahiye

        if (toclose > 0) {
            // close kar sakte yaha kardo

            // since yaha ek bracket close kiya hai toh aage toclose-1 jayega,
            // that is all

            // curr me bhi bracket daal kar bhejna
            solve(toopen, toclose - 1, curr + ')');
        }

        return ;
    }

    vector<string> generateParenthesis(int n) {
        // backtracking kar sakte hai
        this->n = n;

        // har place par 2 options honge, ya current par ek bracket open karlo,
        // ya ek close karlo

        // open brackets remaining would be n at start, and closed brackets will
        // be 0 at start

        // open brackets-> brackets left to be openend

        // close brackets-> brackets remaining to be closed

        // current par open lagana hai toh open-- kar denge, close++ kar denge

        // agar current par close karna hai toh close-- kar denge

        // end me open==0 hona chahiye and close=0 hona chahiye

        // indicating that 0 brackets left to open and 0 brackets left to close
        solve(n, 0, "");

        return ans;
    }
};