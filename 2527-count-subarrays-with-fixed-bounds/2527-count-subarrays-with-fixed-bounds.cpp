class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int mink_posn = -1;
        int maxk_posn = -1;
        int culprit_idx = -1;

        for (int i = 0; i < nums.size(); i++) {

            // agar nums[i] out of range hai means vo culprit hai
            if (nums[i] < minK || nums[i] > maxK) {
                culprit_idx = i;
            }

            // mink k posn update karo
            if (nums[i] == minK)
                mink_posn = i;
            // maxk k posn update karo
            if (nums[i] == maxK)
                maxk_posn = i;

            // smaller idx nikal lo
            long long smaller = min(mink_posn, maxk_posn);

            // temp nikal lo
            long long temp = smaller - culprit_idx;

            // agar temp<0 hai means ki apan iss subrray ko count nai kar sakte
            // since iss subrray ke beech me ek banda h culprit_idx par jo out
            // of range hai, this out of range banda doesnt allow current
            // subarray to be valid

            // apna current subarray is frm smaller idx upto i ie [smaller,i],
            // ye apan ka valid subarray hai, iske beech me agar kahi invalid
            // value aa gai means ye subarray isnt valid, ye invalid value is at
            // culprit_idx, toh agar temp<0 hai means smaller se i ke beech me
            // culprit hai jiske karan current wala subarray is invalid and cant
            // be counted

            if (temp >= 0)
                ans += temp;

            // ans+=temp kyu?, since temp is the dist bw the smaller idx and
            // closest wala culprit idx

            // agar maan lo culpritidx=2 and smaller=5 and i=7, toh apna valid
            // subarray is [5,7] which is valid since beech me culprit wala nai
            // aara kahi bhi, lekin isse pehle wale le agar like [4,7] and
            // [3,7], these are also valid since idx 3,4 waale beech me honge
            // range ke, therefore not culprit and therefore can be takein in
            // current subarray as valid, toh all in all 3 subarrays are valid
            // which end at i those are [3,7],[4,7],[5,7], ie smaller-culpritidx
            // = 5-2 = 3

            // yahi count krre hai apan

            // essentially apan cnt krre hai ki current idx i par khatam hone
            // waale kitne valid subarrays hai
        }

        return ans;
    }
};