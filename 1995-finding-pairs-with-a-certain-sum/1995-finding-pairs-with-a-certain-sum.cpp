class FindSumPairs {
    // map bana lo
    unordered_map<int, int> mpp;
    // nums1 and nums2 store karke rakh lo
    vector<int> num1, num2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // okay num2 is too bigg, toh apan 2 kaam sath me karenge, hints se
        // dekha samajh aaya kuch, apan nums2 ka freq map me store karenge

        // and then nums1 par iterate karke 2 sum questn types banate jayenge
        // soln

        // just read it i swear its ezpz

        // nums1 par baar baar iterate karenge apan, nums2 is too big, toh nums2
        // ke saare elements ko map me daal do
        for (auto it : nums2) {
            mpp[it]++;
        }

        num1 = nums1;
        num2 = nums2;
    }

    void add(int idx, int val) {
        // nums2 me purani value konsi hai
        int oldval = num2[idx];

        // old value ke freq me se ek instance hatao
        mpp[oldval]--;

        // ab ye value+=val banegi, first update kardo
        num2[idx] += val;

        // update karne ke baad map me newval ka freq+1 kardo
        mpp[num2[idx]]++;
    }

    int count(int tot) {
        // num1 is smaller, us par iterate karo
        int ans = 0;

        // runs for at most 1000, since nums1 ka size<=1000 hai
        for (auto it : num1) {
            // apan ko num1[i]+num2[j]=tot chahiye

            // num1[i]=it
            // tot diya hai
            // num2[j]=tot-it;

            // tot-it ka freq nikal lo-> f

            // toh current it wala banda f jitne elements ke saath pair bana kar
            // ttl sum== tot kar payega, count karlo

            // like if tot=5, and it=2, toh apan 5-2=3 ka freq nikalenge nums2
            // me se

            // ie mpp[3]=7 maan lo, toh current wala banda of nums1 can make
            // pairs with 7 elements of nums2, to make nums1[i]+nums2[j]=tot

            // yehi count karlo mast
            ans += mpp[tot - it];
        }

        // end me return krdo ans
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */