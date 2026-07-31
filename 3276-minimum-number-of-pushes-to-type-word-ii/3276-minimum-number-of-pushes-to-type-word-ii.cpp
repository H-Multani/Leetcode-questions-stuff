class Solution {
public:
    int minimumPushes(string word) {
        // saare characters ko freq ke hisab se sort kardo
        // highest freq wale 8 characters are at 1 push
        // next highest freq wale 8 char at 2 push
        // next highest freq wale 8 char at 3 push, and so on, and bana do ans

        // map me store karlo, 26 chars hi honge bas
        unordered_map<char, int> mp;
        for (auto it : word) {
            mp[it]++;
        }

        // ab pq me daal do pair of freq, characters, so that we can get highest
        // freq wale chars pehle

        // ek kaam karo sirf freq hi daal do, char ka koi kaam nai, freq se hi
        // steps count kar lenge
        priority_queue<int> pq;

        for (auto it : mp) {
            pq.push(it.second);
        }

        // now we have highest freq at top, then 2nd highest nd so onn

        // first 8 highest freq wale ko 1 push par dena, next 8 ko 2 push and so
        // on

        // 26 characters honge utna hi loop chala do ans bana do

        // pq me bhi 26 values hongi at max

        // first 8 values ko 1 push ke hisab se count krna
        // next 8 values ko 2 push ke hisab se count krna
        // and so on

        // toh idx 0 to 7 walo ko 1 push
        // toh idx 8 to 15 walo ko 2 push
        // and so on
        // toh idx i walo ko (i/8)+1 push

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            // pq se top wala banda nikalo

            // agar pq khali break krdo
            if (pq.empty())
                break;

            // top wala nikalo
            int freq = pq.top();
            // cout<<freq;
            pq.pop();

            // iss freq ke char ke liye we map it to (i/8)+1 jitne push

            int push=(i/8)+1;

            // ans me daal do 

            // jitni freq hai character ki, utni baar push count kiye jaenge, toh overall total pushes for this character will be freq*push

            // laga do ans me
            ans+=(push*freq);
        }

        return ans;
    }
};