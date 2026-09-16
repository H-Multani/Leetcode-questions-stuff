class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> memo;
    int solve(int n, int k, int i) {
        // agar k==0 hua means ek configuration made , return cnt 1
        if (k == 0)
            return 1;

        // base case agar i==n pahuch gaya hai means range khatam ho chuki hai,
        // lekin since upar k==0 par nai chala means k is remaining here, toh ye
        // configuration nai ban paya, in such case return 0
        if (i >= n)
            return 0;

        // memo me hai toh yehi se bhejdo
        if (memo[i][k] != -1)
            return memo[i][k];

        // we here means yaha explore kar sakte hai
        int ans = 0;

        // yaha option hai ki current point par bande ko rakhna hai bhi ki nai
        // since allowed hai to share points

        // option 1-> skip current point, agle point se rakhna
        // aage k bande rakhne hai and i+1 se rakhna hai
        ans = (ans + solve(n, k, i + 1)) % mod;

        // option 2-> take current point, n tak point le sakte hai

        for (int j = i + 1; j < n; j++) {
            // current point leke ans me take kardo

            // current banda suppose takes from i=4, toh j=5 se next banda le
            // sakta hai

            // i=4,j=5-> current banda took 1 gap
            // i=4,j=6-> current banda took 2 gap, and so onn

            // current banda took current point, toh agla banda can take from j,
            // yehi likh denge

            // agla banda can take from j and aage k-1 bando ko sett karna baaki
            // hai vahi bhej diya
            ans = (ans + solve(n, k - 1, j)) % mod;
        }

        return memo[i][k] = ans;
    }
    int numberOfSets(int n, int k) {
        // ok toh n gaps hai apne paas essentially, and k
        // bande daalne hai uske andar

        // ab har banda 1 gap lega minm case me , toh minm k gaps rehne chahiye

        // toh sabse pehle k gaps me bharne ka dekhna pdega counting,

        // gaps can be different sizes as well too,

        // toh har location par current bande ke liye, we can take 1 gap,2 gap,3
        // gap etc and explore for other bande

        // aise karte karte DP laga sakte yaha

        // send kitne gaps hai, and kitne bande baithne hai abhi

        // ab n gaps hai 0 to n-1 tak ke points me, ye confuse karra ki gap lu
        // ya points lu

        // ok toh gaps nai bhejo points bhejte hai ki current banda kkitne point
        // tak lega

        // ab yaha TLE dega hi, memo bana lo
        // return solve(n, k, 0);

        // batao memo tak me TLE aa raha hai, ab ek hi option bacha, bottom up
        // banane ka

        // bana do bottom up, for that memo wale ko reuse kar lete apan,
        // initialize all values with 0 here
        memo.assign(n + 1, vector<int>(k + 1, 0));

        // base cases upar k==0 par hamesha 1 tha, hence memo me k==0 wale sab
        // par 1 daal do
        // also i>=n hai toh ans is to be 0
        // toh for every i<n and k==0, ans is 1
        for (int i = 0; i < n; i++) {
            memo[i][0] = 1;
        }

        // notice ki maine memo me n+1 hone ke baad bi bass n tak bhara, yehi
        // tha i<n wala logic, ki i<n hoga toh k==0 par ans is 1, otherwise ans
        // is 0 even at k=0

        // itne hi hai base cases toh, ab loop chala do aur kya, i chalega loop
        // par and k chalega apne wale part par jaise recursion me chalra tha

        // initially bas logic transfer kiya recursive se, and loop is empty

        // ab andar dekhra toh we can see that we access i+1 and k-1, toh i wala
        // loop n+1 tak chalna and k wala loop 1 se start karna

        // basically, k wala dekho we access k-1 wala banda, meaning k wale ka
        // ans aane se pehle k-1 ka ans hona chahiye, toh meaning k=0 se start
        // nai kar sakte k=1 se start karna padega ie L to R jayenge

        // and i ko dekho, apan hamesha i+1 wale par le rahe hai, meaning i+1
        // wala ka value pehle bharega i wale se, which means i wala loop right
        // to left chalega, toh chal do n-1 to 0 tak ka loop

        // ab yaha andar wala loop konsa bahar wala konsa doesnt really matter,
        // maine aise likh diya, mik ne alag likha tha

        for (int K = 1; K <= k; K++) {
            // yahi suffix sum lete chalo
            // ek prevrow vector bana lo usme hi banana

            // lekin prevrow me toh kar k ke liye n to 0 ka sum chahiye, ye
            // nikalne me hi dumm nikal jayega, loop ulte kardo , andar wala
            // loop i par chalega and bahar wala k par chalega

            // ab prevrow me current k ke vaaste saare n-1 walo ka sum rakh
            // lenge
            vector<int> prevrow(n + 1);

            // prevrow[n - 1] = memo[n ][k - 1];
            // bhar do
            for (int x = n - 1; x >= 0; x--) {
                prevrow[x] = (prevrow[x + 1] + memo[x][K - 1]) % mod;
            }

            // yaha ulta kiya dhyan dena, usually prefix me 0 to n bharte, ye
            // suffix sum bhar rhe toh n-1 to 0 bhar rhe
            
            // ie prevrow[i]=sum of all elements from i to n-1

            for (int i = n - 1; i >= 0; i--) {
                // current bande ke liye ans memo[i][j]

                // yaha bhi take and skip ka dekhna hoga kya scene

                // take ke liye
                int skip = memo[i + 1][K];

                int take = 0;

                // same loop laga do recursion wala, exact same loop btw
                // for (int j = i + 1; j < n; j++) {

                //     // waha we took solve(k-1,j) yaha memo me same k-1 jayega
                //     // and i ki jagah j jayega
                //     take = (take + memo[j][K - 1]) % mod;
                // }

                // notice ki upar wala loop me k-1 is same always, meaning
                // pichla wala row hai uske elements ko add karre hai apan

                // ab we are essentially doing
                // memo[i+1][k]+memo[i+2][k]+...memo[i+n-1][k]

                // ye toh prefix sum karke nikal sakte hi yaar, toh since abhi i
                // wala loop ke andar ke k wale loop me hai and yaha i+1 ka need
                // hai, ie i wale loop me i+1 wale ka need hai, toh iss loop ke
                // bahar prefix sum banate chalo, so that i wale ka prefix sum
                // will be useful for i-1 wala loop

                // yaha we need previous row ka sum of elements from i+1 th
                // banda to n-1 th banda, which is essentially i+1 se end tak ka
                // sum, which is prevrow[i+1]

                take = (prevrow[i + 1]) % mod;

                // toh ghum fir kar k-1 wali row ka saare elements ka sum
                // chahiye suffix ka sum,

                // end me ans for solve(i,k) banaye the, yaha ans is for
                // memo[i][k]

                memo[i][K] = (skip + take) % mod;

                // prevrow ka kaam aayega aage wale ke liye,
            }
        }

        // end me ans is solve(0,k) memo se nikal kar bhekj do aur kya
        return memo[0][k];
    }
};