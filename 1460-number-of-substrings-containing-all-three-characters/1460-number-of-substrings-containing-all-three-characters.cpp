class Solution {
public:
    int numberOfSubstrings(string s) {
        // similar logic as lc 3306, insted of next consonant, we store next a,
        // next b, next c, and sliding windo as always

        int n = s.size();
        vector<int> nexta(n), nextb(n), nextc(n);
        int lasta = n, lastb = n, lastc = n;

        for (int i = n - 1; i >= 0; i--) {
            nexta[i] = lasta;
            nextb[i] = lastb;
            nextc[i] = lastc;

            // char update kardo
            if (s[i] == 'a')
                lasta = i;
            if (s[i] == 'b')
                lastb = i;
            if (s[i] == 'c')
                lastc = i;
        }

        // sb sliding window chala do
        int l = 0, r = 0, ans = 0;

        // map to store freq of a,b,c
        unordered_map<char, int> mpp;

        while (r < n) {
            // current character include karlo
            mpp[s[r]]++;

            // k wali condn nai hai yaha par toh shrinking ke liye windo count
            // karna chalu kardo

            // this is basically the shrink windo step + update ans step
            while (mpp.size() == 3) {
                // since we will be here as soon as the windo becomes valid, toh
                // r wale se hi chalu karenge similar to lc 3306

                // if (s[r] == 'a') {
                //     // agar 'a' hai toh next a wale array se add karenge
                //     ans += nexta[r] - r;
                // }
                // if (s[r] == 'b') {
                //     // agar 'b' hai toh next b wale array se add karenge
                //     ans += nextb[r] - r;
                // }
                // if (s[r] == 'c') {
                //     // agar 'c' hai toh next c wale array se add karenge
                //     ans += nextc[r] - r;
                // }
                ans+=n-r;
                // cout<<s.substr(l,r-l+1)<<" "<<ans<<endl;

                // ab iss l se chalu hone waale saare valid windows count kar
                // liye hai apan ne, hence l wale char ko window se nikal do, ie
                // shrink windo to move to next l
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    // agar freq 0 pahuch gai toh map se alag kar do
                    mpp.erase(s[l]);
                }

                l++;
            }

            // windo aage badhao
            r++;
        }

        return ans;
    }
};