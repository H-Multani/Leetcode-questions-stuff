class Solution {
public:
    // KMP ka compute wala funcn
    void compute(vector<int>& pattern, vector<int>& lps) {
        int m = pattern.size();

        // length of previous longest prefix and suffix
        int len = 0;

        // since there is no proper prefix and suffix of pattern[0..0]
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            // agar i th banda same as len wala banda then
            if (pattern[i] == pattern[len]) {
                // pattern match hora hai idx aagr badhao
                len++;
                // since ye longest prefix and suffix pattern mila hence update
                // kardo
                lps[i] = len;
                // i aage badha do
                i++;
            } else {
                // means pattern match nai karra, check len ka value
                if (len != 0) {
                    // len non 0 hai

                    // len-1 kardo valid ke liye, can also do lps[len-1] since
                    // waha bhi same len stored hai

                    // lps wali len lelo
                    len = lps[len - 1];
                } else {
                    // means len is 0,

                    // lps ko 0 kardo yaha
                    lps[i] = 0;

                    // i aage badha do
                    i++;
                }
            }
        }
    }
    bool KMP(vector<int>& pat, vector<int>& text) {

        int n = text.size();
        int m = pat.size();
        vector<int> ans;

        // LPS bana do which will store longest proper prefix which is also
        // suffix lps[i]=longest proper prefix of pat[0...i] which is also
        // suffix of pat[0...i]
        vector<int> lps(m,0);
        compute(pat,lps);

        // i lelo which will run on the text array
        // j lelo which will run on the pat array

        int i = 0, j = 0;

        while (i < n) {
            // agar pattern and text me char same hai toh dono idx aage badha do
            if(pat[j]==text[i]){
                i++;
                j++;
            }

            if(j==m){
                // means pattern mil gaya stop right here

                // usual kmp se count milta tha kitni baar aara pattern, yaha ek baar me kaam chal jayega hence return true frm here
                return true;
            }
            else if (i<n && pat[j]!=text[i]){
                // we here means match na kara,need to check pattern again aage 

                if(j!=0){
                    // we here means j isnt 0 means kuch match karre hai abhi bhi

                    // j ko lps se start kar denge so that aage ka comparison wahi se jo jaha se need hai
                    j=lps[j-1];
                }else{
                    // we here means j=0 par hai, agle i se try karo matching ka
                    i++;
                }

            }
        }
        // we here means kuch pattern nai mila
        return false;
    }
    bool rotationPossible(vector<int>& v1, vector<int>& v2) {
        // v2 ko double karlo, naam dedo text since mai usually text par KMP
        // chalana jaanta bas

        vector<int> text = v2;
        text.insert(text.end(), v2.begin(), v2.end());

        // ab KMP me search if v1 is present as subarray in text
        return KMP(v1, text);
    }
    int sortableIntegers(vector<int>& nums) {
        // KMP use kar lenge yaha par
        int n=nums.size();

        // sabse pehle ek sorted array banano
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        // saare possible sortable integer par chalo
        for (int k = 1; k <= n; k++) {
            // divisible hai?
            if (n % k != 0)
                continue;

            // we here means divisor ban jayega meaning subarrays me split kar
            // sakte hai

            // boolean variable to check if current k can be considered for ans
            // or not
            bool valid = true;

            // check karte ab

            // pure array ko k size ke subarrays me baat denge apan, and har k
            // size ka subarray check karenge if valid, agar invalid hua toh
            // boolean false kar dena and dont include in ans

            // since har k size ka subarray dekhenge apan hence start idx 0,
            // subarray from 0 to k-1, next subarray idx k to 2k-1 etc and so
            // onn, hence pointer increases by k
            for (int st = 0; st < n; st += k) {
                // current block nikalo

                // st index se chalu hoga and st+k-1 idx tak jayega, toh
                // constructor me st+k likhenge since ek idx aage tak ka dena
                // hota
                vector<int> v1(nums.begin() + st, nums.begin() + st + k);

                // target block nikalo sorted wale se, ye comparison me kaam
                // aayega
                vector<int> v2(sorted.begin() + st, sorted.begin() + st + k);

                // we want this v1 wala block to be similar to target block v2,
                // rotations kar kar ke

                // for checking this we will check if v1 is present in v2+v2
                // ,(ulta bhi kar sakte no worries), agar present hoga means
                // rotations karke valid ban jayega, for this we use KMP

                if (!rotationPossible(v1, v2)) {
                    // we here means v1 me kitne bhi rotation karke v2 nai bana
                    // sakte, meaning this k is not sortable
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};