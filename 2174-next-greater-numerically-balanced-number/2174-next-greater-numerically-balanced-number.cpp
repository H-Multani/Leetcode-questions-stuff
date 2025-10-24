class Solution {
public:
    int nextBeautifulNumber(int n) {
        // n se loop chalu karlo, jaha ans mile bhej dena

        // har i value ke liye nearby n+10000 ke andar hi most probably valid
        // wala testcase mil jayega(i guess) toh TLE nai aana chahiye
        for (long long i = n + 1; i < 10000000; i++) {
            // ab iss value ka freq array nikalo

            // made freq array since vector banata toh time increase ho sakta
            // tha
            int freq[10] = {0};

            long long temp = i;

            // works for at most 7 times
            // toh T.C={O(1)}
            while (temp > 0) {
                freq[temp % 10]++;
                temp /= 10;
            }

            // agar saare frequencies match kaare hai toh bhej do as ans
            bool isans = true;

            // works for at best 10 times
            // toh T.C={O(1)}
            for (int j = 0; j < 10; j++) {
                // agar freq 0 hai toh skip kar sakte ho
                if (freq[j] == 0)
                    continue;

                if (j != freq[j]) {
                    isans = false;
                    break;
                }
            }

            if (isans)
                return i;
        }

        // kuch nai mila bhai return 0
        return 0;
    }
};