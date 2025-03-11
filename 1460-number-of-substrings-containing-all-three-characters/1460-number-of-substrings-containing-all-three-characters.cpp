class Solution {
public:
    int numberOfSubstrings(string s) {
        // similar logic as lc 3306, sliding windo as always
        // lekin vo next a,b,c wala vector nai lagega
        int n=s.size();
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

                // since we here when window valid, toh ab iss r ke aage jitne
                // char lagaoge saare valid substring banaenge, toh count karlo

                ans += n - r;

                // all these n-r substring all start frm same L

                // ab iss l se chalu hone waale saare valid windows count kar
                // liye hai apan ne, hence l wale char ko window se nikal do, ie
                // shrink windo to move to next l
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) {
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