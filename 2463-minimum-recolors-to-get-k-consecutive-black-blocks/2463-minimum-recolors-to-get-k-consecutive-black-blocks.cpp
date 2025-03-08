class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // sliding window, hint padha tab palle pada

        // hints jo bolra vhi kardo, k size ka har possible substring lelo, har
        // substring me kitne colour karne padenge count karlo, jo bhi minm
        // count ho return kardo

        // start from left most side at idx 0, (left,right) will be the k size
        // ka substring
        int left = 0, right = k;
        int ans = INT_MAX, n = blocks.size();

        while (right <= n) {
            // current block utha kar check karo ki kitne baar colour karna
            // padega

            // basically agar current substring liya toh kitne blocks ko colour
            // karna padega to make this (left,right) substring an occurence of
            // k consecutive black blocks

            // basically agar current substring ko k consecutive black wala
            // banana hai toh kitne blocks colour karne padenge apan ko

            int cnt = 0;

            for (int i = left; i < right; i++) {
                // agar white hai curent wala toh colour karna padega, count
                // karlo
                if (blocks[i] == 'W')
                    cnt++;
            }

            // ans update kardo, minm count chahiye apan ko
            ans = min(ans, cnt);

            // windo aage badha do
            left++;
            right++;
        }

        // ab jo bhi ans aaya return kardo
        return ans;
    }
};