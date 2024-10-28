class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;

        for (auto it : nums) {
            // current banda is it

            // chk if curr banda is perfect square number
            int root = (int)sqrt(it);

            if (root * root == it) {
                // means current banda is perfect square

                // in such case curr banda konsa element hai subsequence ka,
                // since for all we know this curr banda could be 4, continuing
                // some sequence starting from 2, mpp[2] will give us ki 2 konsa
                // wala banda tha sequence ka, and +1 to that we have 1+1=2, ie
                // 4 is the 2nd banda of the sequence starting from 2

                // like for eg 2, its not a perfect square no. hence ye starting
                // banda hai sequence ka, iska value in map is 1, ie mpp[2]=1

                // now we reach 4, 4 is perfect square of 2, 2 is already
                // starting of some sequence, so ye 4 continues the sequence,
                // mpp[2] give us ki 2 konsa banda tha sequence ka, jo bhi banda
                // tha uska next in the sequence is 4, so mpp[2]=1, ie 2 was 1st
                // banda of the sequence, so 4 will be= mpp[sqrt(4)]+1=1+1=2, ie
                // 2nd banda of sequence hence mpp[4]=2

                // now we reach 16, 16 is perfect square of 4, 4 is already
                // in some sequence probably, so ye 16 continues the sequence,
                // mpp[4] give us ki 4 konsa banda tha sequence ka, jo bhi banda
                // tha uska next in the sequence is 16, now mpp[4]=2, ie 4 was
                // 2nd banda of the sequence, so 16 will be=
                // mpp[sqrt(16)]+1=2+1=3, ie 2rd banda of sequence hence
                // mpp[16]=3 and so onn

                // similarly for sequence like 3,9,81
                // mpp[3]=1
                // mpp[9]=mpp[sqrt(9)]+1=1+1=2
                // mpp[81]=mpp[sqrt(81)]+1=2+1=3....

                // hence we have
                mpp[it] = mpp[sqrt(it)] + 1;
            } else {
                // means current banda is not a perfect square, but this could
                // be starting of a sequence, hence map me ye value laga do with
                // value 1 indicating ki ye first banda hai iss new subsequence
                // ka
                mpp[it]=1;
            }
        }

        // now after this loop we have info abt each element in the map, for eg
        // if we have pair (81,3) in map means 81 is the 3rd banda of some
        // sequence and so onn

        // and we have to find the size of maxm sequence, so this can be done by
        // iterating over the values of all keys in map, suppose the key 625 has
        // the maxm value, ie 3, in such case, 3 is the size of the biggest
        // sequence that can be formed that follows the rules of the question,
        // bs yehi maxm nikal kar return kar do
        int ans = 0;

        for (auto it : mpp) {
            ans = max(ans, it.second);
        }

        // if after iterating(for maxm value of all keys), ans is still 1, means
        // no sequence could be formed, in such case retuen -1

        if(ans==1) return -1;

        return ans;
    }
};