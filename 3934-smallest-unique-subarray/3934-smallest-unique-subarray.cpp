class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;

    ll findpow(ll a,ll base){
        // binary exponentiation ezpz you know it
        if(base==0) return 1;

        ll half=findpow(a,base/2);
        ll ans=(half*half)%mod;

        if(base%2==1){
            // ek aur lagega
            ans=(ans*a)%mod;
        }

        return ans;
    }

    bool check(vector<int>& nums,int size,int base){
        int n=nums.size();

        int i=0,j=0;

        // hash bana do ek
        ll hash=0;
        // map me hash value ke counts le lenge, uniqie hash ka cnt 1 rahega
        unordered_map<ll,int> mpp;

        // base^(size-1) baar baar nai nikalenge nikal kar rakh lo, using binary exponentiation
        ll p=findpow(base,size-1);

        // sliding window chala lo
        while(j<n){
            // current banda hash me daal do
            hash=((hash*base)+nums[j])%mod;

            // agar window not of correct size extend
            if(j-i+1<size){
                j++;
            }
            else{
                // sahi subarray mil gaya hai

                // pehle hash ka freq update kardo
                mpp[hash]++;

                // window aage badhane ke liye left wala banda remove karna padega
                // from hash we need to remove element*(base^(size-1))-> element*p alag karna padega

                hash=((hash-(nums[i]*p))%mod +mod)%mod;

                // ye value -ve aa sakta hash-nums[i]*p ka toh mod -ve aane lagega toh uske liye +mod karke %mod kiya

                // ab left wala remove kar diya hai, ptr aage badha do
                i++;
                // j wala bhi badha do since size sahi wala chahiye
                j++;
            }
        }

        // saare hash ka value aa gaya hoga apne paas ab koi bhi hash ka freq=1 means uniqie subarray hai return true, else false
        for(auto it:mpp){
            if(it.second==1) return true;
        }

        return false;

         


    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        // base nikal lo, max+1
        int base=*max_element(nums.begin(),nums.end())+1;

        // binary search ke liye l and r
        int l=1;
        int r=n;

        // worst case me ans will be n
        int ans=n;

        while(l<=r){
            // mid nikalo
            int mid=l+(r-l)/2;

            // check if mid size ka unique subarray milra kya, milra toh means ans update and smaller dhundo, otherwise valid dhundo rt me jaa kar 
            if(check(nums,mid,base)){
                ans=mid;
                // check left for better ans
                r=mid-1;
            }
            else{
                // check right side for valid ans
                l=mid+1;
            }
        }

        return ans;

    }
};