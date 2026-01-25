class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        // yaha simple sliding windo toh kaam nai karegi since any k elements
        // lene bola hai, toh agar any k elements lena hai toh randomized array
        // me lena toh dikkat since we need to select only biggest and smallest
        // elements and k-2(ish) elements in between them , toh ab ye karna isnt
        // really posible normal me , sorting kardo, since usse kya hoga ki k
        // elements consecutive rahenge, toh ye max-min wala difference le sakte
        // hai toh setraignt forward ho jaega kaam pura, since smalles will be
        // arr[l] and largest will be arr[r], and k size ka window leke chalenge
        // toh all GG

        int ans = INT_MAX;
        int n = nums.size();

        // sort kardo array ko
        sort(nums.begin(), nums.end());

        int l = 0, r = k - 1;
        // means window is from [l,r], ab window ko pehle ek baari check kar
        // lenge, then aage badhenge
        ans = min(ans, nums[r] - nums[l]);

        // ab chalaenge sliding window, since order me hai elements toh smallest
        // and largest aise le sakte hai ki beech wale elements dikkat na kare,
        // ie smallest and largest ke beech wale elements order me lete jaa
        // sakte, so that minm nikalne and maxm nikalne me time na lage

        for(int l=0;l+k-1<n;l++){
            int r=l+k-1;

            // isse [l,r] ka window ban gaya apne paas, check karke ans update kardo
        ans = min(ans, nums[r] - nums[l]);
        }


        return ans;
    }
};