class Solution {
public:
    bool isprime(int val){
        if(val==1) return false;
        for(int i=2;i*i<=val;i++){
            if(val%i==0) return false;
        }

        return true;
    }
    int countPrimeSetBits(int left, int right) {
        // prime ka funcn bana denge, and left to right ka loop chala denge

        int ans=0;

        while(left<=right){
            // left wale me kitne set bits
            int bits=__builtin_popcount(left);

            // agar prime hai toh count karlo
            if(isprime(bits)) {cout<<left<<" has bits "<<bits<<endl;ans++;}
            left++;
        }

        return ans;
    }
};