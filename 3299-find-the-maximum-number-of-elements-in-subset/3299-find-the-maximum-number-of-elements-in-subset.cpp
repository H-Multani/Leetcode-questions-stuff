class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // freq nikal lo pehle toh
        unordered_map<long long, long long> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        // element 1 se jitne ban sakte hai count karlo pehle toh
        int ans = (mpp[1] % 2 == 0) ? mpp[1] - 1 : mpp[1];

        // if we have 5 1s, then we can make 3 subsets frm it
        // {1},{1,1,1},{1,1,1,1,1}, biggest size is 5

        // if we have 6 1s, then we can make 3 subsets
        // frm it {1},{1,1,1},{1,1,1,1,1} , biggest size is 5

        // toh n 1s ke liye we can check if count of 1s is even or odd, even hai
        // toh cnt-1, else cnt jitna max banega thats all

        // ab aage baaki vals ke liye dekhte hai

        // ab ek kaam karte map par iterate karte

        // agar map empty nai hai means kam se kam 1 size ka toh banega
        if (!mpp.empty())
            ans = max(ans, 1);

        // ab map se 1 remove kardo, loop me dikat karega nai toh ye
        if (mpp.find(1) != mpp.end())
            mpp.erase(1);

        // ab karo map me iterate
        for (auto it : mpp) {

            int currans = 0;
            // current it.first ko leke chalna hai x

            if (it.second >= 2) {
                // means yaha se start kar sakte hai

                long long val = it.first;

                while (mpp.find(val) != mpp.end() && mpp[val] >= 1) {

                    // means aage bana sakte hai subset

                    // edge case, agar val ka freq==1 tha means yehi rukna
                    // padega, since freq==1 means aage nai badh sakte since aur
                    // bade size wale subsets ke liye freq>=2 needed
                    if (mpp[val] == 1) {
                        // means yehi tak ka safar tha current subset ke liye,
                        // break frm loop

                        // this case me subset ka size only increases by 1
                        // yehi kardo bas

                        currans++;
                        break;
                    } else {
                        // means current element will contribute 2 times in
                        // subset like {3,9,3} me 3 came 2 times and

                        // {2,4,16,4,2} me 2 came 2 times and 4 came 2 times,

                        // similarly current element contribtes 2 to overall
                        // size

                        currans += 2;
                    }

                    // val aage badha do
                    val = val * val;
                }

            } else {
                // we here means freq==1 hai

                // freq agar current element ki 1 hai toh vo vaise bhi at best 1
                // size ka subset bana payega, since 3 size ke liye we will need
                // freq of current element to be 2, jo nai hai

                // in such case, best ans is 1
                currans = 1;
            }

            // currans kabhi bhi even nai ho sakta, upar wale case me its
            // possible ki we stop at {2,4,4,2} kyuki 16 nai mile map me, in
            // such case currans will be even, not needed, but this can be made
            // valid by subtracting 1 size, ie making {2,4,4,2}-> {2,4,2}, since
            // freq last wale ki 2 thi lekin apan 1 consider kiye, toh ye size-1
            // karna padega

            if (currans % 2 == 0)
                currans--;

            // currans update kardo
            ans = max(ans, currans);
        }

        return ans;
    }
};