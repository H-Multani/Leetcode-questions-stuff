class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mpp,
              vector<vector<int>>& memo) {
        // target nikalo, ie next element j and k ke pehle kon hoga, such that
        // arr[i]+arr[j]=arr[k] and i<j<k, ie target=arr[i]=arr[k]-arr[j]
        int target = arr[k] - arr[j];

        // agar current j,k ke liye soln already hai toh yehi se return kardo
        if (memo[j][k] != -1)
            return memo[j][k];

        // kya ye target exist bhi karta hai??
        if (mpp.find(target) != mpp.end() && mpp[target] < j) {
            // agar target exist karta hai toh target ka idx we need to be less
            // than j, since we are making i<j<k type thing

            // we here means ye target can be a part of our fibonacci sequence
            int i = mpp[target];

            // ab iss i and j ko leke aage explore karo, since i<j<k, and aage
            // wale elements ke liye we need i and j th element, hence funcn me
            // we send current i and j as new j and k

            // and jo bhi yaha se aayega will be the length of fibonacci
            // sequence we could make, hence return kardo +1 karke

            // ab jo solution aayega it will be answer for memo[j][k] toh vo
            // store karlo
            memo[j][k] = solve(i, j, arr, mpp, memo) + 1;
            return memo[j][k];

            // the +1 is to account for the curent k th wala banda

            // the solve funcn will send us ki i and j se start karke kitne
            // length ka fibonacci sequence bana lekin apan ko pata hai ki i and
            // j se pehle ek k bhi hai which is also in sequence, hence uss k th
            // element ko include karne ke liye we do +1
        }

        //  we here matlab ab iske age sequence nai ban paa raha hai fibnacci
        //  wala

        // we know ki j and k wale bande are in fibonacci sequence, and that
        // iske upar waale funcn call me there was probably a l wala idx too,
        // since that l wala idx is taken care of already, and we know ki j and
        // k are in fibonacci, toh we return 2 from here, since yaha se aur aage
        // 2 se zyada size ka fibonacci sequence nai banne wala

        // yaha par bhi memo me store karlo, since ye 2 bhi answer hoga for
        // memo[j][k], hence update memo
        memo[j][k] = 2;
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        // simple recursion
        int n = arr.size();

        unordered_map<int, int> mpp;
        // map me idx store karlo since all values ditinct
        for (int i = 0; i < n; i++)
            mpp[arr[i]] = i;

        int ans = 0;

        // apan memoize kar sakte hai soln ko, yaha 2 cheez change hori hai, ie
        // j and k, toh 2D memo bana lenge,simply, and agar memo me answer hai
        // pehle toh wahi se return kardege, nai toh explore kardenge
        vector<vector<int>> memo(n, vector<int>(n, -1));
        // -1 indicate ki memo[j][k] ke liye koi soln nai mila hai abhi tkk

        // 2 for loops for j and k

        // start j frm 1 since recursive funcn me peeche wale idx par jayenge to
        // make {i,j,k} such that i<j<k
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // ab ye j and k th elements ko end elements leke recursive
                // fibonacci likho, to make {i,j,k} such that i,j,k th elements
                // are in fibonacci and i<j<k

                // ab yaha se recursively fibonacci banane me length kitna aaya
                int length = solve(j, k, arr, mpp, memo);

                // this length can be ans, update ans

                // we dont need length of 2, since 2 se fibonacci nai banta
                // hai, we need atleast 3 elements
                if (length >= 3)
                    ans = max(ans, length);
            }
        }

        // memoize kar diya hai soln ko apne hisaab se maine, since recursive
        // funcn me 2 cheez change hori thi which was j and k, hence memo bhi 2D
        // banaya tha, and recursive funcn me bhi return karvane se pehle memo update karvaya hai 

        return ans;
    }
};