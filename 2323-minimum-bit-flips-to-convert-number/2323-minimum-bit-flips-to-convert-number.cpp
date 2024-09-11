class Solution {
public:
    int minBitFlips(int start, int goal) {
        // approach
        // iss ko dry dun karke dekh lena, toh acche se samajh aaega
        // dono nos ka xor lelo, agar different honge bits toh xor me 1 aa jaega
        // un values(indexes) ke liye
        int ans;
        ans = start ^ goal;
        // now jitne bits change karne hai utne 1 apne xor(ans) me hai, so for
        // final ans just count the number of 1s in the xor
        return __builtin_popcount(ans);
    }
};