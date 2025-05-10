class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // i think easy hai kind off lets try smth

        // nums1 ke 0cnt nikalo and currsym nikalo
        long long sum1 = 0, zerocnt1 = 0;
        for (auto it : nums1) {
            if (it == 0)
                zerocnt1++;
            else
                sum1 += it;
        }

        // ab in saare 0's me minm +ve integer 1 rakh lenge toh sum banega
        sum1 += zerocnt1;
        // ye minm sum hai jo nums1 se niklega

        // similar nikalo nums2 ke liye
        long long sum2 = 0, zerocnt2 = 0;
        for (auto it : nums2) {
            if (it == 0)
                zerocnt2++;
            else
                sum2 += it;
        }
        sum2 += zerocnt2;
        // ye minm sum hai jo nums2 se niklega

        // ab yaha cases banenge, since its possible ki zerocnt=0 ho dono ka,in
        // which case minm hi ans hai, toh yaha cases banaenge pehle

        // base case, agar dono ka minm sum already same hai toh yehi se return krdo
        if(sum1==sum2) return sum1;

        // cout<<sum1<<" "<<sum2<<endl;
        // agar dono ke 0cnt==0 hai aur dono ka sum alag hai toh minm equal sum
        // cant be made since 0s nai hai
        if (zerocnt1 == 0 && zerocnt2 == 0 && sum1 != sum2)
            return -1;
        // agar dono ke 0cnt==0 hai aur dono ka sum same hai toh minm equal sum
        // is already made return krdo
        if (zerocnt1 == 0 && zerocnt2 == 0 && sum1 == sum2)
            return sum1;

        // ab support chahiye hoga jiska sum kam hai usko
        long long minm = min(sum1, sum2);

        // agar nums1 ko support chahiye and uske paas koi 0s nai h, toh equal
        // sum nai bana sakte return -1
        if (minm == sum1 && zerocnt1 == 0)
            return -1;

        // same with nums2
        if (minm == sum2 && zerocnt2 == 0)
            return -1;

        // otherwise we here means sab ke paas atleast ek 0 hai, atleast the
        // weak sum wala array has a 0, which can be used to get the sum of both
        // arrays to equal

        // in such case dono arrays ka equal sum will be maxm of the minm sum
        // the arrays can make,eg if nums1 can make minm sum=32 and nums2 can
        // make minm sum=12, and nums2 has some zeroes, these 0s can be used to
        // make nums2 ka sum==nums1 ka sum, tabhi max le rahe


        // sum1 and sum2 is minm sum that nums1 and nums2 can make, iss ke aage
        // sum badh sakta hai lekin minm itna hi rahega
        return max(sum1,sum2);
    }
};