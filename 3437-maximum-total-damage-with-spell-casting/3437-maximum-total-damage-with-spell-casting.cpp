class Solution {
public:
    typedef long long ll;
    int n;
    vector<ll> t;

    // har idx par take/ skip karke try maar lenge
    ll solve(vector<ll>& nums, int i,unordered_map<long long, long long>& mpp) {
        // base case
        if (i >= n) {
            // out of range, alag kardo
            return 0;
        }

        // agar memo me ans hai toh bhej do yehi se
        if(t[i]!=-1) return t[i];

        // 2 options take and skip

        // current bande ko skip kardo, toh i+1 th bande par jaa kar check karo,
        // since i th bande ko nai liya toh just next wale i+1 wale par jaa
        // sakte hai apan
        ll skip = solve(nums, i + 1,mpp);

        // take current banda, iss case me current bande ko include karenge ,
        // toh nums[i] ko le lenge toh nums[i]+2 th bande tak nai le sakte toh
        // get next valid element, using lower bound

        // current i ko le liya toh i+1 th bande se searching chalu karo, since
        // lower bound use krre hai toh nums[i]+3 ka value dhundna, since
        // nums[i]+2 tak invalid hai(accd to questn), nums[i]-2 tk bhi invalid
        // hai lekin peeche se apan valid hi lete aa rahe hai toh no need to
        // check
        int j =
            lower_bound(nums.begin(), nums.end(), nums[i] + 3) - nums.begin();

        // toh next valid index to be explored is j

        // ab nums[i] ko include karne ke liye saare instances count karne
        // padenge apan ko, toh jitne nums[i] hai saare count karke include
        // karlo ans me apne
        ll take=(mpp[nums[i]]*nums[i])+solve(nums,j,mpp);


        // update memo
        t[i]=max(take,skip);
        // dono me se jo option maxm damage de utha lo
        return max(take, skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        // map me daal do value and freq, then freq ko array me daal do, then
        // usme take not take chala kar dekh sakte
        unordered_map<long long, long long> mpp;
        for (auto it : power) {
            mpp[it]++;
        }

        // ab iterate over the map and store unique value in vector
        vector<long long> nums;
        for (auto it : mpp) {
            nums.push_back(it.first);
        }

        // sort nums so that nums[i]-2 to nums[i]+2 nikalne me dikkat na ho, by
        // this we can use lower_bound and easily get ki aage konsa wala number
        // lena hai current wala lene ke baad
        sort(nums.begin(), nums.end());
        n = nums.size();

        // ab is nums par take nottake chala do bass

        // obviously TLE aayega,toh memoize karlo
        // only 1 thing changes which is index, which goes upto n, utne size ka lelo bss

        t.assign(n+1,-1);

        // starting idx 0
        return solve(nums, 0,mpp);
    }
};