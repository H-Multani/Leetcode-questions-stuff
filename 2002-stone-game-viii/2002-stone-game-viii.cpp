class Solution {
public:
    int n;
    vector<int> pre;
    vector<int> memo;
    long long solve(int i) {

        // agar end par pahuch chuke hai means current bande ne saare le liye, hence send pre[n-1]
        if(i==n-1) return pre[n-1];

        // memo me hai toh wahi se bhejdo
        if (memo[i] != INT_MIN)
            return memo[i];

        // much simpler way to do this is

        // current i aaya hai means current banda can either take i jitne stones
        // and let other person explore from i+1 or, skip and explore taking i+1
        // stones themselves

        // toh alice ke paas 1 choice ye hai ki i stones take karle and bob will
        // explore from i+1

        // this works since current banda take i stones and replaces with 1
        // stone, toh aage wala banda pichla stone toh lega hi, and aage vo khud
        // new i(previously i+1) wale stone se le sakta hai
        long long take = pre[i] - solve(i + 1);

        // ya second choice is alice can explore taking i+1 stones instead
        long long nottake = solve(i + 1);

        return memo[i] = max(take, nottake);
    }
    int stoneGameVIII(vector<int>& stones) {
        // simple DP chal lo, alice ne kitne stone nikale, fir agli chance me
        // bob ne kitne stone nikale, total kar lenge and maxm difference nikal
        // kar bhej denge

        // and to simulate ki i stones left se nikale hai, iske liye index leke
        // chalenge, if we are at current idx i, then that means left se idx 0
        // to i wale stones remove ho chuke hai

        // notice that jitne remove kiye hai, utne size ka 1 stone rakh diya
        // vapas, toh that means agle bande ko removed walo ka sum + more lena
        // padega

        // lekin ye left se i tak ka sum baar baar na karna pade toh uske liye
        // prefix sum kar lenge, and this works only because stones hamesha left
        // se nikal rahe hai

        // we have to maximize the difference for alice and minimize the
        // difference from bob side, which can also be written as ki alice apna
        // score badhane ka try karri and bob apna score badhane ka try karra

        // if alice ka score increase, then difference increase, if bob ka score
        // increase then score difference decrease, toh that clearly means bob and alice sirf apna score increase karne ka try karenge

        n = stones.size();
        int ttl = 0;
        // pre bhardo
        for (auto it : stones) {
            ttl += it;
            pre.push_back(ttl);
        }

        // alice hamesha idx 0 se start karegi obviously

        // ab yaha 1 thing changes only which is i, which can do till n, toh
        // memo bana do

        memo.resize(n + 2, INT_MIN);

        // instead of starting from 0 and 0 ka alag se case likhu, beeter is 1
        // se start karu
        return solve(1);
    }
};