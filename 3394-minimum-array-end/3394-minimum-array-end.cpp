class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        // inital ans is x

        for (int i = 1; i < n; i++) {
            // first banda mil chuka hai (x) toh start frm 2nd banda, hence
            // start i frm 1 to n

            //new banda is 
            ans=(ans+1)|x;
        }

        // now we have the n-1 th banda, return it
        return ans;
    }
};