class Solution {
public:
    int mod = 1e9 + 7;
    // custom power funcn likh lo bhai reqd h
    int power(int a, int b){
        if(b==0) return 1;

        long long half=power(a,b/2);
        long long result=(half*half)%mod;

        if(b%2==1){
            result=(result*a)%mod;
        }

        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;

        // sort krdo nums ko since apna kaam min and max se h bss
        sort(nums.begin(), nums.end());

        // 2 ptrs lo
        int l = 0, r = nums.size() - 1;

        // ab loop chala kar count krlo
        while (l <= r) {
            // current minm is l wala banda
            int minm = nums[l];
            // current maxm is r wala banda ie nums[r]

            // jab tk r wala banda invalid hai(ie minm+maxm>target) tbb tkk r-- karo,
            // so that we reach minm good ans
            while (r >= 0 && nums[l] + nums[r] > target) {
                // means minm+maxm ka sum>target h, invalid subsequence, r ko peeche
                // karo
                cout<<"here"<<endl;
                r--;
            }

            // agar r has crossed l, then that means current l wale ke sath koi
            // maxm nai ban payega break out of loop
            if (r < l)
                break;
        

            // ab jo maxm hai vo valid h
            int maxm = nums[r];


            // we here means r wala banda is a valid maxm banda

            // ab l ko minm leke koi bhi nums[i] lelo frm l to r, vo valid hi
            // rahega, since maxm sum<=target kar diye hai apan abhi

            // beech me kitne elements aa sakte hai har subsequence ke liye
            // le/naa le same cheez h since apna kaam minm and maxm se hai and
            // apan ne current minm ko fix krdiya h toh maxm koi bhi lelo yaha l
            // to r tkk me, sab valid honge, toh count krlo pehle toh kitne
            // elements aa sakte hai subsequence me

            int cnt=r-l;

            // har element ke liye 2 options tale/ nottake for different subsequences
            // toh overall 2^cnt jitne options banenge all valid

            // toh ans me add krdo
            ans=(ans+(power(2,cnt)))%mod;

            // move to next minm element
            l++;
        }

        return ans;
    }
};