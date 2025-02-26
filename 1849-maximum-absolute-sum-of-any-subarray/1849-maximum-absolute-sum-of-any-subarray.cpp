class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // agar absolute wala condn hata de toh ye simply maxm subarray sum hai,
        // which is done easily be kadanes algo

        // kadanes only focuses on +ve maxm subarray sum , agar minm subarray
        // sum nikale it will be a big -ve number, take abs of that number(since
        // questn bola hai abs ke liye ), we get big +ve number, which is also
        // possible correct ans

        // toh all in all apan ko bass 2 cheez karni hai, maxm subarray sum and
        // minm subarray sum nikalna hai, thats all, 2 baar kadanes lagana hai,
        // ek baar maxm ke liye, ek minm ke liye, phir dono ans ka abs lelo, jo
        // maxm hai vahi return kardo

        // i got all this frm the hints, so thoda help liya h waha se

        int ans1 = 0, currsum = 0;
        // ans1 for maxm subarray sum
        // basic kadanes algo
        for (auto it : nums) {
            // current bande ko include karo currsum me
            currsum += it;

            // update ans1
            ans1 = max(ans1, currsum);

            // agar currsum -ve chale jaaye toh usko 0 bana do
            if (currsum < 0)
                currsum = 0;

            // cout<<"currsum is "<<currsum<<endl;
            // cout<<"ans is "<<ans1<<endl;
        }

        // ab ulta kadanes algo lagao
        // ans2 for minm subarray sum
        int ans2 = 0;

        currsum = 0;
        for (auto it : nums) {
            // current bande ko include karo currsum me
            currsum += it;

            // update ans1
            ans2 = min(ans2, currsum);

            // agar currsum +ve chale jaaye toh usko 0 bana do
            if (currsum > 0)
                currsum = 0;
        }

        // cout<<ans1<<" "<<ans2<<endl;

        // now we have ans1-> maxm subarray sum, ans2->minm subarray sum, dono
        // ka abs lelo, jo maxm ans hai return krdo

        return max(abs(ans1),abs(ans2));
    }
};