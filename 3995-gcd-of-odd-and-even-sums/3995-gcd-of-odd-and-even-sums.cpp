class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // n odd elements, 1+3+5+7+9+...n elements, sum of n elements of ap=>
        // (n/2)*(2a+(n-1)d)
        // a=1,d=2, formula-> (n/2)*(2n)-> n*n
        // similarly for even
        // a=2,d=2, formula-> (n/2)*(2+2n)-> n*(n+1)

        int oddsum=n*n;
        int evensum=n*(n+1);

        return __gcd(oddsum,evensum);
    }
};