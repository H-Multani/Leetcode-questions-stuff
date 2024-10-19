class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // for 11-> 1011
        // nos needed are 9->1001 and 10->1010
        // for 31-> 011111
        // nos needed are 15->001111 and 16->010000
        // for 47-> 101111
        // nos needed are 38->100111 and 39->101000

        // for 11-> 1011
        // ans 9 -> 1001

        // for 31-> 011111
        // ans 15-> 001111

        // for 47-> 101111
        // ans 38-> 100111

        // pattern mil gaya ans ke liye
        // continous wale 1 dekh lenge peeche se, aur last waale 1 bit ko 0 kar
        // denge

        // ab question ye hai ki last waale 1 pr jaaye kaise
        vector<int> ans;

        for(auto it:nums){
            // edge case 2 ke lit ans nai milega, return -1
            if(it==2){
                ans.push_back(-1);
                continue;
            }

            // ab apne paas hai prime number
            // let number be 47->101111
            // ab iska last wala 1 pa posn nikalo
            // negate kar do we get ->010000
            // count no of trailing zeroes=4
            long long inverted=~(it);
            int trailing0cnt=__builtin_ctz(inverted);

            // ab itne trailing 0 jitne posn par bit pahuchana hai
            // so we do 1 left shift 4-1=3 times, we get ->1000
            int val=1<<(trailing0cnt-1);
            // ab in dono values ka xor kar do
            // we have 47->101111 and 1000, xor kr do
            // 101111
            // 001000
            // 100111 -> ans, yehi push kara denge

            ans.push_back(it^val);

        }

        return ans;
    }
};