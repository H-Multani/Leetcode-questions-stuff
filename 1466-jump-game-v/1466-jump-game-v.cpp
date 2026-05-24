class Solution {
public:
    int d, n;
    vector<int> memo;

    int solve(int i, vector<int>& arr, int d) {

        // agar memo me hai toh yehi se bhejdo
        if(memo[i]!=-1) return memo[i];;

        // current se kaha kaha jaa sakte hai nikal lo

        // current ko count karlo
        int ans = 1;

        // i-d jaa sakte hai and i-d jaa sakte hai explore karo

        // explore i+1 to i+d tak ka
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            // means yaha visit kar sakte hai karlo visit

            // consition laga do question wali
            if (arr[j] >= arr[i]) {
                // means ye area blocked hai, since question bolra ki saare k
                // wale values bhi chhote hone chahiye
                break;
            }

            // we here means we can explore this region

            ans = max(ans, 1 + solve(j, arr, d));

            // exploration ke time par 1+ kiya kyuki current wale element ko
            // include karna padega, since ans=1 tabhi jayega agar kahi neeche
            // nai jaa paye apan yaha se, lekin agar chale gaye toh current ko
            // include karke we can reach 2(or more) places, toh +1 include karo
        }

        // explore i-1 to i-d tak ka
        for (int j = i - 1; j >= max(0, i - d); j--) {
            // means yaha visit kar sakte hai karlo visit

            // consition laga do question wali
            if (arr[j] >= arr[i]) {
                // means ye area blocked hai, since question bolra ki saare k
                // wale values bhi chhote hone chahiye
                break;
            }

            // we here means we can explore this region

            ans = max(ans, 1 + solve(j, arr, d));
        }

        return memo[i]=ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        // ok toh adjacency list se toh kuch nai hora, since jumps vaise bhi
        // galat hi lagenge, toh better approach would be to do a simple dp,
        // also BFS boht complicated lagra tha iske liye

        this->d = d;

        n = arr.size();

        // ek ans lelo which is best ans available
        int ans = 0;
        // ab best ans nikalo har element se start karke

        // ab mereko pata hai ki TLE fatega, toh DP laga lo, only 1 thing changes which is i toh tk n+1 size ka dp bana lo boht kaam aayega

        memo.resize(n+1,-1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, arr, d));
        }

        return ans;
    }
};