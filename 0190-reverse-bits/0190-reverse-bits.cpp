class Solution {
public:
    int reverseBits(int n) {
        // binary bana kar string me daal do
        string s = "";

        while (n > 0) {
            s += ((n % 2 == 0) ? "0" : "1");

            n /= 2;
        }
        // ab ho sakta hai ye value chhoti ho toh 32 bits na lage ho, in such
        // case 32 bits banane ke liye extra 0's daal do

        // string temp="00111001011110000010100101000000"; cout<<"needed length
        // "<<temp.size()<<endl; cout<<"length "<<s.size()<<endl;

        // agar 32 se kam bits hai toh start me add kardo bits
        while (s.size() < 32) {
            s += '0';
        }
        // cout<<"length "<<s.size()<<endl;
        // cout << s << endl;

        // ab iss s ko reverse kardo since we needed reverse order of bits,
        // (for this ki kaise wala reverse, example se sab clear ho jaega)
        reverse(s.begin(), s.end());

        // ab iska value bana do, har place par jao ans usko binary se integer
        // bana do
        int ans = 0;
        int dgt = 0;
        for (auto it : s) {
            // 1<<dgt is a very cheap way to do pow(2,dgt), since, for each
            // position we will need powers of 2 like 0,1,2,....32, toh vo
            // calculate karte chalne ke liye dgt variable le liya

            // 1<<dgt is better for time complexity since its jus left shift
            // operation on 1, dgt no of times

            // whereas pow() takes a lot more time complexity internally

            // toh (1<<dgt) se toh iss place ka siginificance pata chala ki 2 ka
            // konsa power lagega yaha, and then it-'0' will tell konsa bit
            // aayega iss posn par ezpz
            ans += (1 << (dgt)) * (it - '0');

            // since moving to next digit, increase place value wala variable, 
            dgt++;
        }

        return ans;
    }
};