class Solution {
public:
    int minimumDeletions(string nums) {
        // edge case agar string me ek hi char hai toh 0 hoga ans
        if(nums.size()==1) return 0; 

        // ghum phir kar final string should b of type aaabbbb, vaisa banane ke
        // liye apan ko orgiinal string me left side se saare b delete karne
        // padenge (so that waha bass a rahe) and similarly right side se saare
        // a delete karne pdenge(so that waha bass b rahe )

        // toh ek kaam karlo,prefix sum se nikal lo ki current index ke left me
        // kitne b hai since ue alag karne padegenge and current index ke right
        // me kitne a hai (since right se a remove krne padenge so that waha
        // bass b rahe)

        // uske baad simple bass har index ke liye check karlo ki konsa index
        // par minm bande nikalne padenge

        int n = nums.size();
        vector<int> leftb(n, 0);
        vector<int> righta(n, 0);

        // left me pade saare b count karlo
        if (nums[0] == 'b')
            leftb[0] = 1;
        for (int i = 1; i < n; i++) {
            leftb[i] = leftb[i - 1] + ((nums[i] == 'b') ? 1 : 0);

            // ((nums[i] == 'b') ? 1 : 0) includes ki agar current element b hai
            // toh usko leftb[i] me count karenge apan
        }
        // right me pade saare a count karlo
        if (nums[n - 1] == 'a')
            righta[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            righta[i] = righta[i + 1] + ((nums[i] == 'a') ? 1 : 0);
        }

        // for (auto it : leftb) {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : righta) {
        //     cout << it << " ";
        // }

        // ab har index par chal kar best wala ans nikalo
        int ans = INT_MAX;

        for (int i = 1; i < n - 1; i++) {
            // yaha se left me leftb[i] jitne b nikalne padenge and
            // yaha se right me righta[i] jitne a nikalne padenge

            // overall we need to remove leftb[i-1]+righta[i+1] jitne characters
            // to make the string balanced, minm of this value will be our ans
            ans = min(ans, leftb[i - 1] + righta[i + 1]);

            // we do not use leftb[i] since maan lo current index se pehle b
            // jitne the nikal diye, and current idx par b hai, and right me bhi
            // saare b hi pade hai, toh we really dont need to remove the
            // current character, since yaha idx se vaise bhi apan switch karre
            // hai a to b, toh current index par b hai means yaha se b ka series
            // start hora thats it, so why should we remove current idx wala b
            // also since right me vaise bhi saare b pade hai, waha ek aur chala
            // jaega bass reducing cost, hence we use leftb[i-1]

            // similar reson for righta[i]

            // we do not use righta[i] since maan lo current index se aage a
            // jitne the nikal diye, and current idx par a hai, and left me bhi
            // saare a hi pade hai, toh we really dont need to remove the
            // current character, since yaha idx se vaise bhi apan switch karre
            // hai a to b, toh current index par a hai means yaha par a ka
            // series end hora thats it, so why should we remove current idx
            // wala a also since left me vaise bhi saare a pade hai, waha ek aur
            // chala jaega bass reducing cost, hence we use righta[i+1]
        }

        // edge cases ye ho sakte hai ki saare a nikal do to make best string,
        // or saare b nikal do to get best string

        // saare b nikal doge toh we need to remove leftb[n-1] jitne b
        // saare a nikal doge toh we need to remove righta[0] jitne a

        // dono me se best ans bhej do
        ans=min({ans,righta[0],leftb[n-1]});


        return ans;
    }
};