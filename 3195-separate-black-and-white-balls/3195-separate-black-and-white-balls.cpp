class Solution {
public:
    long long minimumSteps(string s) {
        long long zerocnt = 0;
        long long ans = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // current wala 0 hai cnt kar lo bas
                zerocnt++;
            } else {
                // 1 mila hai
                // isko rt side bhejna hai, rt me bhejne ke liye isko saare
                // zeroes se swap karna hoga to its right(since adjacent swap hi
                // kar skte h apan ), so that saare zeroes left me aa jaaye iske
                // and ye right side chala jaaye

                // zerocnt is the no of 0's to the right of current 1, toh utne
                // swaps toh karne hi padenge minm, hence zerocnt ko add kar do
                // ans me and aage badho
                ans += zerocnt;
            }
        }

        // in end we have the minm swaps we need to set all 1's in the rt side,
        // and all 0's in the left side
        return ans;
    }
};