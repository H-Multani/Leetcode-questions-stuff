class Solution {
public:
    double log_base(double x, double base) { return log2(x) / log2(base); }
    bool isPowerOfThree(int n) {

        // edge case n is 0
        if (n == 0)
            return false;
        // edge case n is negative, in such case no ans
        if (n < 0)
            return false;

        // log base 3 lelo and int part lelo uska as 2 different values
        double val1 = log_base(n, 3);

        int val2 = val1;

        cout << val1 << endl;
        cout << val2 << endl;
        cout << val1 - val2 << endl;

        // agar dono values same hai means power of 3 hai, log ka property hai
        // log3(3^x)-> x, toh agar n is actually power of 3, then x seedha
        // seedha bahar aa jaega, otherwise it will be a float/double value, toh
        // bss yehi chk krne se ho jaega kaam

        // log nikalte time, floating point me division karne par jo chhota sa
        // error hai vo dikkat karra hai toh use bachne ke liye, we compare them
        // with epsilon tolerance

        // ✅ This way, even if val1 is 4.999999999999999 instead of exactly 5,
        // it will still count as equal.
        return fabs(val1 - val2) < 1e-10;
    }
};