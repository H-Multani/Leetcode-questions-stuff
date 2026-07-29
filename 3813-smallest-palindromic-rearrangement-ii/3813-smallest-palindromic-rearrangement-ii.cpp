class Solution {
public:
    // ncr ka funcn likh lo
    long long nCr(int n,int r,int k){
        // now we know 
        // nCr==nC(n-r)
        // toh r agar bada hai toh nCn-r use karenge
        r=min(r,n-r);

        long long ans=1;

        for(int i=1;i<=r;i++){
            ans=(ans*(n-r+i))/i;

            // yaha par bhi check laga do ki agar>k aa gaya ans means iss dabbe me hi hai ans no need to calculate further
            if(ans>=k) return k;
        }

        // we here means ways k se chhota hai, subtract hoga, return kardo
        return  ans;

    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid=' ';
        if (n % 2 == 1)
            mid = s[n / 2];

        // ek vector lelo which stores freq
        vector<int> freq(26, 0);
        // freq nikal lo except mid char
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue;

            freq[s[i] - 'a']++;
        }

        // ab half freq nikalo which will be used to build half result
        for (int i = 0; i < 26; i++) {

            freq[i] /= 2;
        }

        // half result bana lenge
        string halfans = "";
        int half = n / 2;

        // half tak loop chalao ans banano

        for (int i = 0; i < half; i++) {
            // current index par konsa char aayega

            // lekin agar koi character yaha nai aa paya toh ???
            // uss case me ans ban hi nai payega, toh check daalo
            bool found=false;

            // isme 26 me se konsa char aayega nikal lo
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    // means we are using this character toh freq reduce kardo 1
                    // se
                    freq[j]--;

                    // remaining ke liye no of ways nikalo
                    long long ways = 1;
                    int letters = 0;
                    // ways nikal lo current char current posn par jayega toh

                    // total kitne letters hai nikal lo, ncr me numerator ke
                    // liye
                    for (int c = 0; c < 26; c++) {
                        // count karlo
                        letters += freq[c];
                    }

                    // ab ways banano
                    for (int c = 0; c < 26; c++) {
                        if (freq[c] > 0) {
                            ways *= nCr(letters, freq[c], k);
                            // letters update kardo
                            letters -= freq[c];
                        }

                        // early break ke liye condition daaldo, minor
                        // optimization
                        if (ways >= k)
                            break;
                    }

                    // ab agar ways>=k hai means this block contains k th wala
                    // string which is ans toh karlo explore
                    if (ways >= k) {
                        // we here means sahi jagah par current character jaa
                        // rha haim daal do halfans me
                        halfans.push_back(j + 'a');

                        // we here means char daal paoge, 
                        found=true;
                        // fixed this character at i th position, we are done
                        // here, break frm loop
                        break;
                    }
                    // we here means current posn par j th char daalne se nai
                    // banega kaam, since aur aage ka chahiye,k me se ways hata
                    // do aur aage search kardo
                    k -= ways;
                    // jo character alag kiya tha vapas laga do
                    freq[j]++;
                }
            }

            if(!found){
                // means koi char nai daal paye,
                return "";
            }
        }

        // half result aa gaya hai, isko reverse krke add kardo ans me mid ke sath
        string ans=halfans;
        reverse(halfans.begin(),halfans.end());

        if(mid!=' '){
            ans.push_back(mid);
        }
        ans+=halfans;

        return ans;

    }
};