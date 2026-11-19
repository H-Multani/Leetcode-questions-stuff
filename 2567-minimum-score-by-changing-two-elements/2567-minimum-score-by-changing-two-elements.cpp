class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // ok toh sabse pehle toh any 2 integers bola hai, toh meaning order
        // doesnt matter as such

        // toh sort kar dete hai apan iska logic samajh aayega
        sort(nums.begin(), nums.end());

        // ab saare elements order me hai apne paas

        // logic dekho ab

        // low is minm diff bw any 2 integers
        // high is maxm diff bw any 2 integers

        // toh low toh kuch bhi ho sakta hai, lekin high will always be
        // last-first element since order me hai elements toh maxm diff edge
        // wale 2 elements se hi niklega

        // toh overall score ko decrease karne ke liye apan ye edge wale
        // elements ko paas laa sakte ek dusre ke

        // like if sorted array like [-1,2,....,13,15]

        // toh low toh kuch bhi ho sakta hai lekin abhi high is
        // 15-(-1)->15+1->16

        // ab iss high ko kam kar sakte hai apan, since 2 elements change kar
        // sakte hai na toh -1 ko second smallest tak le aao and biggest element
        // ko second biggest tak le aao, yehi kar sakte ie [-1,2,...,13,15]
        // becomes [2,2,....13,13] ab high becomes 13-2=> 11 this is the best
        // ans i can get here since agar biggest(15) ko zyada small kiya toh
        // second biggest ab biggest ban jayega

        // similarly agar smallest(-1) ko zyada badaya toh ab 2 becomes new
        // smallest ye scene

        // toh ab notice karna ki low wala toh 0 ban jayega brodie, chahe koi
        // bhi operation karo (ie smallest ko 2nd smallest tak lana OR biggest
        // ko 2nd biggest tak lana) dono cases me low ka value is hamesha 0 hi
        // aayega isse lower nai jana wala

        // toh low will become 0 end me, toh focus here is ki high ka value
        // decrease karna hai as much as possible

        // ab iss logic ke 3-4 cases hai bass which will give best ans

        // 1-> 2 smallest elements ko 3 rd smallest element jitna bana denge, ie
        // [1,2,3....] becomes [3,3,3.....]

        // ye use case tab hoga jab smallest elements are having bigger jump
        // like for eg array is [1,20,35,......99,100,101]
        // ab yaha high will be 101-1=100 and low will be kuch value too, notice
        // ki yaha 2 operations me 1-35 wala jump and 20-35 wala jump is better
        // than ek front se ek back se wala case

        // like instead of 1->20 and 101->100 wala jumps (which decreases
        // overall ans by 20 (100-20)) we can do 1->35 nd 20->35 (which
        // decreases overall ans by 36 (101-35)) which is best option
        // dono cases me low=0 banega, no need to worry abt that

        // toh array becomes  [35,35,35,......99,100,101]

        // similarly we have another case
        // 2-> 2 biggest elements ko 3 rd biggest jitna bana denge
        // if array like [1,2,3....80,100,120] then 2 step me high ko kam karne
        // ka sabse best way is to make 120-> 80 and 100-> 80, yehi karenge

        // and final 3rd case will be simple that is ek start se alag karo ek
        // end se alag karo

        // toh overall 3 cases
        // 1-> 2 smallest elements ko 3rd smallest jitna bana do
        // 2-> 2 biggest elements ko 3rd biggest jitna bana do
        // 3-> 1st smallest becomes 2nd smallest and 1st biggest becomes 2nd
        // biggest

        // in all cases low becomes 0(since sab me common elements ban rhe toh
        // low becomes 0)

        // toh high badhlega bass

        // 3 cases

        // case 1-> high is -> biggest element- 3rd smallest element (since 1st
        // and 2nd smallest ko 3rd smallest wale value bana diye toh direct 3rd
        // smallest se compare karo high nikalne ke liye)
        // this is nums[n-1]-nums[2]

        // case 2-> high is ->3rd biggest element- smallest element (since 1st
        // and 2nd biggest ko 3rd biggest wale value bana diye toh direct 3rd
        // biggest se compare karo high nikalne ke liye)
        // this is nums[n-3]-nums[0]

        // case 3-> high is ->2nd biggest element- 2nd smallest element (since
        // 1st biggest ko 2nd biggest wale value bana diye and 1st smallest ko
        // 2nd smallest bana diye  toh direct 2rd biggest se compare karo 2nd
        // lowest se high nikalne ke liye)
        // this is nums[n-2]-nums[1]

        int n=nums.size();

        return min({nums[n-1]-nums[2],nums[n-3]-nums[0],nums[n-2]-nums[1]});
    }
};