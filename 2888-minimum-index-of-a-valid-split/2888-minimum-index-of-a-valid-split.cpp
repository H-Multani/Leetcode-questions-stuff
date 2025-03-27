class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // simple hi lagra hai

        // hints se thoda help liya, otherwise this can also be done using
        // prefix sum, keeping cnt of hot many times dominant element came in
        // this much part of array, but here we keep it simple

        // abhi wala logic is given 1 dominant element, agar 2 me split karenge
        // toh bhi vo same dominant element dono me se 1 side dominant rahega hi
        // since uska freq>nums.size/2 hai

        // but for valid ans we need ki common element dominant ho dono side,
        // means ki abhi nums ka jo dominant element hai vahi same element ko
        // dono subarrays me dominant element hona padega, agar ho gaya toh
        // vahi ans hai, otherwise valid ans nai banega kuch bhi karlo

        // toh basically we will try to make nums ka dominant element to also be
        // the dominant element of both the subarrays

        // dominant value nikalo
        unordered_map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;

        int x = -1;
        int val = 0;

        for (auto it : mpp) {
            if (val < it.second) {
                x = it.first;
                val=it.second;
            }
        }

        // x ka 1 value hi hoga bass, ab count lelo
        int cnt = 0;

        // this cnt will be count of how many x are present in current subrray

        // first subarray always starts with 0 and at max goes upto idx n-2,
        // vahi tkk ka loop chalao
        // cout<<x<<endl;
        int n = nums.size();
        for (int i = 0; i <= n - 2; i++) {
            if (nums[i] == x)
                cnt++;

            // maan lo current subarray is frm 0 to i, ie [0,i], ttl i+1
            // elements

            // kya current subarray me x dominant hai??
            // if cnt>size of subarray/2, means current subarray me x dominant
            // hai,
            if (cnt <= (i + 1) / 2) {
                // we here means current subarray me x is not dominant element,
                // aage badhao subarray, to make x dominant in this subarray
                continue;
            }

            // we here means current subarray [0,i] me x is dominant value

            // toh mpp[x] freq hai x ka, itne ttl me se cnt jitne x current
            // subarray me hai, remaining x are in next subarray

            // toh aage wale subarray me kitne x hai
            int aagecnt = mpp[x] - cnt;
            // cout<<i<<" "<<aagecnt<<endl;

            // aage wala subarray is [i+1,n-1], kya iss aage wale subarray me
            // bhi x dominant value hai??

            // aage wale subarray ka size is (n-1)-(i+1)-1 => n-i-1
            // agar aage wale subarray ka x cnt>(n-i-1)/2 hai means x aage wale
            // subarray me bhi dominant hai

            // agar aage wale and current wale dono subarrays me x is dominant,
            // means this is valid split

            // in such case return i as ans, since we needed minm index where
            // valid split is happening
            if (aagecnt > (n - i - 1) / 2) {
                // we here means ki valid split hai yaha , since aage wale
                // subarray[i+1,n-1] me bhi x is dominant and current wale
                // subarray[0,i] me bhi x is dominant

                // return i as ans frm here
                return i;
            }
        }

        // we here means ki koi valid split nai mil saka apan ko, in such case return -1
        return -1;
    }
};