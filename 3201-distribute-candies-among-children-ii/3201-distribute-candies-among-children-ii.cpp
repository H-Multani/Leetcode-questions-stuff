class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        // child 1 ke liye chalo
        // child1 ke minm ke liye child2,3 ko limit dedo
        int minch1 = n - (limit * 2);

        // possible hai ki ye minch1 is negative like in eg2, toh 0 se chalu
        // krna iss case me
        minch1 = max(minch1, 0);

        // child1 ka ending is limit, since isse zyada nai de sakte h kisi bhi
        // child ko
        int maxch1 = min(n, limit);
        // case possible ki n=2 h limit=100 h toh 2 candies de skte h at max

        // ab iterate karo, child1 ka fix krke, har option ke liye child2,child3
        // ka nikalo
        for (int i = minch1; i <= maxch1; i++) {
            // we here means abhi apan ne child 1 ke liye i amt of candies fix
            // kardi hai

            // ab child2,child3 ke liye bacha candies hua
            int N = n - i;

            // ab child2 ke minm ke liye child3 ko limit jitni candies dedo, and
            // remaining apan child2 ko denge minm
            int minch2 = max(0, N - limit);
            // child3 ko limit jitni de di toh child2 ko N-limit denge, since we
            // need child1+child2+child3=n

            // and negative values se bachne ke liye 0 se maxm le liya

            // ab child2 ka maxm nikalo, at max ch2 can get limit jo of candies
            int maxch2 = min(N, limit);
            // since agar N=2 h, lekin limit is 3, toh candies toh 2 hi de
            // payenge na toh maxm available lelo

            // toh ab child2 can have candies in range [minch2,maxch2], for eg
            // if this is [3,7], means child2 can have 3,4,5,6,7 candies thats
            // all

            // and child2 ke count kar lenge ttl ways by maxch2-minch2+1

            // toh if i=3 maan lo, and range for ch2 is [2,5], means total
            // ways=5-2+1=4, konse wale 4 ways hai ye??

            // these 4 ways are ways to set candies for child2 and child3 if
            // child1 gets 3 candies,

            // ye 4 ways will be ,limit=5 maan lo
            // [3,2,3]
            // [3,3,2]
            // [3,4,1]
            // [3,5,0]

            // and these 4 ways are valid ways, to be counted, notice that sab
            // me child1 has 3 candies, aise karke apan count karenge aage walo
            // ke liye ie, agar child1 ko i candies di toh kitne ways ban sakte
            // h baaki ko set karne ke

            // agar interval is valid [minch2,maxch2], toh ways count krlo
            if(minch2<=maxch2) ans+=(maxch2-minch2+1);
        }

        return ans;
    }
};