class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // toh sabse pehle power wala array banana padega

        // for that what we can do is loop until n becomes 0 and do the
        // following operation

        int mod = 1e9 + 7;

        // powers array long long lelo since prefix sum isme hi bana lenge
        vector<long long> powers;
        while (n > 0) {
            // current n ka log2 lelo, log2 will be some float value, integer
            // part lelo iska

            // iss integer part ka power of 2 lelo, this will give us the
            // smallest power of 2 number smaller than(or equal to) the current
            // n

            // like for n=15, log2(15)=3.907, integer part=3, 2^3=8, this is the
            // nearest power of 2 smaller than or == to 15, include this in the
            // powers array, and remove this much frm n
            // powers={8}, n=15-8=7
            // for n=7, log2(7)=2.8074, int part=2, 2^2=4, add to powers array
            // and remove frm n
            // powers={8,4}, n=7-4=3
            // for n=3, log2(3)=1.585, int part=1, 2^1=2, add to powers array
            // and remove frm n
            // powers={8,4,2}, n=3-2=1
            // for n=1, log2(1)=0, int part=0, 2^0=1, add to powers array
            // and remove frm n
            // powers={8,4,2,1}, n=1-1=0

            // by this method we got the powers array, ye method log wala bas
            // mereko laga ki chal sakta hai, maine dekha nai hai ye kahi se bhi

            // just thought ki this might work, since log se we get the closest
            // power of 2, toh vo remove karte jayenge and end me 0 pahuch jaega
            // no worries

            int val = log2(n);

            // power of 2 lelo iss val ka
            // val = pow(2, val);
            // isko apan aur kam complexity me kar sakte hai using left shift
            // operator, since 2 ka hi power nikalna hai, since we need 2^val,
            // toh we can do 1 (leftshift) val times, to get to the same value
            val=(1<<val);

            // ab isko powers array me daal do
            powers.push_back(val);
            // as well as remove frm n
            n -= val;
        }

        // ab powers array sorted chahiye apan ko, lekin notice that powers
        // array apan ko already sorted mila hai just descending order me,
        // simply reversing the array will do the trick
        reverse(powers.begin(), powers.end());

        // ab prefix sum use karke queries par iterate kar lenge

        // toh queries me O(1) wala iteration karne ke liye pehle prefix product
        // wala array bana lo
        // n = powers.size();
        // for (int i = 1; i < n; i++) {
        //     powers[i] = (powers[i] * powers[i - 1]);
        // }

        // toh prefix sum khelne ke bajaye apan logically dekhe agar, toh powers
        // array ka max size will be like 15 at best, since n goes upto 10^9,
        // why not brute force the last querying part

        // nai toh ye modulo nikalne me fermats little theorem lag jayega, which
        // is tedious, nai man hai karne ka

        // ab queries par iterate karke ans array bana lo
        vector<int> ans;
        for (auto it : queries) {
            int start = it[0];
            int end = it[1];

            int prod = 1;

            for (int i = start; i <= end; i++) {
                prod = (powers[i] * prod) % mod;
            }

            ans.push_back(prod);
        }

        return ans;
    }
};