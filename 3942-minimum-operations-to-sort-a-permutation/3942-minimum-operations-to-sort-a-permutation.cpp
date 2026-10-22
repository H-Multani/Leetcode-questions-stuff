class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // ek cheez pata hai ki agar nums already increasing ya decreasing order
        // me nai raha toh kuch bhi karlo nai aa payega order me, since rotation
        // and reverse se bass array rotate hora, elements relatively same posn
        // par hai, ie 4 ke left me agar 3 tha and rt me 5 tha, toh reverse ke
        // baad 4 ke rt me 3 hoga and left me 5 hoga bass, aur kuch nai hai

        // toh kaat peet kar order check karte hai pehle

        // now to check if ascending nature hai ya descending nature hai nums ka
        int asc_cnt = 0;
        int dsc_cnt = 0;

        for (int i = 1; i < n; i++) {
            // ascending order ke liye we need nums[i]==(nums[i-1]+1)%n, hua toh
            // +1 count hoga asc cnt me
            asc_cnt += (nums[i] == (nums[i - 1] + 1) % n);
            // descending order ke liye we need nums[i-1] == (nums[i] + 1) % n,
            // hua toh +1 count hoga dsc cnt me
            dsc_cnt += (nums[i - 1] == (nums[i] + 1) % n);
        }

        if (asc_cnt == n - 1 && nums[0] == 0) {
            // means ye already ascending order me hai, in such case return 0 ,
            // since no operation reqd
            return 0;
        }

        if (asc_cnt == n - 1) {
            // means normal ascending nature ka hai like [3,4,0,1,2] iss type ka

            // yaha 2 possibility hai apne paas, ya left rotate karte bana lo ya
            // rt rotate karke bana lo

            // jisme kam steps lage
            int left = 0, rt = 0;

            // maan lo array is [3,4,0,1,2], n=5, isko if we left rotate 2 times
            // we have [0,1,2,3,4], toh we left rotated n-nums[0] times to reach
            // the correct order, yehi formula hai
            left = n - nums[0];

            // again ab rt rotate ka hai kuch available nai hai but check this
            // out [3,4,0,1,2] me reverse+ left rotate 1 time + reverse we get
            // [3,4,0,1,2]-> [2,1,0,4,3]-> [1,0,4,3,2]-> [2,3,4,0,1]
            // toh overall [3,4,0,1,2]-> [2,3,4,0,1], which is essentially 1
            // time rt rotation

            // toh 1 rt rotation-> reverse+(1 left rotation)+reverse

            // for x rt rotations
            // toh x rt rotation-> reverse+(x left rotation)+reverse

            // ab dekho
            // [3,4,0,1,2] ko we right rotate 3 times we have [0,1,2,3,4] which
            // is what we need, toh yaha apan ne 0 ko rt me rotate kiya jab tak
            // vo ghum kar front me na aa jaaye, toh we rotated right by total
            // 2+1=3 times

            // if array was to be [......0,1,2,3,4,5], then apan ko 5+1=6 baari
            // rt rotate karna padta to reach correct state

            // toh overall nums.back()+1 jitne baari rt rotate karna hai
            // ttl steps used= 1(reverse)+(nums.back()+1)+1(reverse)
            rt = 1 + (nums.back() + 1) + 1;
            // can also be written as nums.back()+3 lekin samajh nai aayega vo
            // this is better

            return min(left, rt);
        }

        // ascending nai h toh descending dekhlo
        if (dsc_cnt == n - 1) {

            // yaha bhi 2 options hai ya left rotation karlo ya rt rotation
            // karlo, yaha formula different honge bass thode

            // ab maan lo array was like [4,3,2,1,0] tab bhi reverse karna padta
            // once, hence descending ke case me apan 1 baari start me reverse
            // kar denge, so that ab array becomes ascending wala, fir seedha
            // ascending wala logic laga do

            // left ke liye apan ascending me n-nums[0] karte the

            // yaha apan ne bola ki descending is nothing but ascending+reverse,
            // hence left ke liye ascending wale funcn me ek baari reverse hoga
            // toh uska count rakh lenge(+1)

            // ab yaad hai ki ascending me n-nums[0] karte the, yaha ke liye we
            // do

            // reverse then n-nums[0] left shift

            // lekin actually reverse thodi karre apan, toh jo waha nums[0] tha
            // vo yaha nums.back() hoga, toh count karne ke liye we simply do
            // n-nums.back()+1(reverse)
            int left = n - nums.back() + 1;

            // ab right ke liye dekhte

            // upar apan karte the ki reverse+(left rotation)+reverse
            // ab apan ko yaha mandatory ek reverse lagana hai start me toh we
            // have

            // reverse(mandatory)+ (reverse+(left rotate)+reverse)
            // ye start ke 2 reverse toh ek dusre ko cancel kar denge na since
            // [1,2,3] ko reverse kiye we got [3,2,1], again reverse we got
            // [1,2,3], same as original, why even waste steps

            // toh overall we have (left rotate)+reverse

            // left rotate ke liye we did (ascending ka rt rotate ka left wala
            // part) nums.back()+1

            // maan lo array was [3,2,1,0,4]
            // left rotate kiya 4 baar we got [4,3,2,1,0], isme reverse kar diya
            // toh we got [0,1,2,3,4] which is correct

            // pehle yaha we did ki 0 left rotate ho ho kar end par pahuch jaaye
            // so that ek reverse me seedha order me aa jaaye,

            // toh for [3,2,1,0,4], ka 0 end par laane ke liye we did nums[0]+1
            // jitne baar left rotate, kaise nikala?, 0 ke left me 3 element
            // hai(nums[0]) uske baad 0 front par aa jayega lekin abhi arr would
            // be like [0,4,3,2,1],reverse karne se ans sahi nai aayega, hence 0
            // ko left me pahuchana hai hence nums[0]+1 operations then reverse

            // toh overall we have (nums[0]+1) left rotations then +1 for
            // reverse

            // maan lo array was [4,3,2,1,0], isme dekho zara, nums[0]+1=5 left
            // rotations+1 reverse-> 6 operations, lekin yaha toh 0 already end
            // par hai why even do left rotations

            // toh iss case me we did faltu ka left rotation not needed,notice
            // how we did left rotation total 5 times and n=5

            // matlab n=5 baari left rotate karne ke baad vahi array aa gaya toh
            // why even rotate in the first place

            // ye check apan %n se kar sakte

            // if left rotation cnt =5%5=0 means 5 baar left rotate karlo ya
            // same chhor do same hi pahuchenge, isse step bachenge apne

            // toh overall for left rotation we had nums[0]+1 rotations lekin ho
            // sakta 0 already end me ho leading to faltu n rotations, toh in
            // such case we do (nums[0]+1)%n, so that agar n=5 ke liye 5 left
            // rotation ho toh vo ruk jaaye since koi sense nai n rotations ka

            // overall we have (nums[0]+1)%n +1(reverse) rotations

            // toh right rotation ka logic is 
            int rt=(nums[0]+1)%n +1 ;

            // ab dono me se jaha kam steps lage utha lo
            return min(rt,left);
        }

        // dono nai h toh matlab nai bana sakte
        return -1;
    }
};