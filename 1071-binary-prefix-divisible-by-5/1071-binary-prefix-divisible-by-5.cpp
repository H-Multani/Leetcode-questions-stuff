class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        // prefix sum lagega yaha, banate jayenge sum ko starting 0

        // left shift by 1 + nums[i] karke binary representation se decimal
        // representation banega , fir toh bass usko check karna hai if
        // divisible by 1, also we dont even need to left shift by 1, sinc eleft
        // shift by 1 means multiply 2 thats all toh irl we have to do
        // val*2+nums[i] thats all

        // toh ek val=0 leke chalenge and har i par we do val*2+nums[i], isse ye
        // hoga ki saare bits left shift ho jaenge and +nums[i] se LSB set ho
        // jayega toh digit sahi banega

        // ok it becomes too big of a number since nums can go too bigg, toh
        // instead of that what i think we can do is %100 kardo, isse number
        // range ke bahar bhi nai hoga and divisibility bhi check ho jaegi,
        // since 100 ke upar toh sab repeat hi hona hai bitwise dekha jaaye toh

        // i can use 1000 also that will also work, i can use 10 also

        int val = 0;

        vector<bool> ans;

        for (auto it : nums) {
            // current val ko shift karo left side once, ie multiply 2
            val *= 2;

            // ab current wala bit ie LSB laga do, agar it==1 means +1 hoga and
            // it==0 means +0 hoga thats all

            // we could do val|nums[i] lekin since +1 hi karna hai always toh 1
            // bit +1 karne se apne se set ho jayega toh no need to worry, can
            // do both ways
            val += it;

            // ab in val we have the current value of xi, ie vo value jiska
            // binary representation is subarray nums[0...i]

            // agar %5==0 hai toh true bhej do otherwise false
            ans.push_back((val % 5) == 0);

            val = val % 10;
        }

        return ans;
    }
};