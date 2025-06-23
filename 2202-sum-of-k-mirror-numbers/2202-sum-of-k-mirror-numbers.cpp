class Solution {
public:
    bool ispalindrome(string s){
        // ye string agar palindrome hai toh return krdo true
        int i=0,j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]) return false;

            i++;
            j--;

        }

        return true;
    }

    string conv_to_base(long long num, int k){
        if(num==0) return "0";

        string ans="";

        // loop chala do
        while(num>0){
            // remainder add krdo ans me
            ans+=to_string(num%k);

            // num/k kardo
            num/=k;
        }

        return ans;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;

        int l = 1;
        // l length ke palindromes banane hai apan ko

        // loop jab tk nos nai mil jaate
        while (n > 0) {
            //  l given hai toh half length nikal lo
            int half_length = (l + 1) / 2;

            // iss half length jitne saare digits generate krne honge
            int minm = pow(10, half_length - 1);
            int maxm = pow(10, half_length) - 1;

            for (int num = minm; num <= maxm; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());

                // palindrome banao ab dono halves se
                string pal = "";
                if (l % 2 == 0) {
                    // means even length ka palindrome banana hai apan ko

                    // dono half lelo
                    pal = first_half + second_half;
                } else {
                    // means odd length ka paldindrome banana hai, 2nd half ka
                    // st char chhor kar baki lelo
                    pal = first_half+ second_half.substr(1);
                }

                // decimal wala palidrome mil chuka hai, ab iska base k version nikalo
                long long pal_num=stoll(pal);

                // base k version nikalo
                string base_k=conv_to_base(pal_num,k);

                // agar ye base k wala banda palindrome hai toh ans me add krdo
                if(ispalindrome(base_k)){
                    ans+=pal_num;
                    // ek banda mil gaya h, n-- karo
                    n--;

                    // agar n==0 h toh yehi se break krdo
                    if(n==0) break;
                }
            }

            // ab length l wale saare palindrome nikal liye hai, l aage badhao
            l++;
        }

        return ans;
    }
};