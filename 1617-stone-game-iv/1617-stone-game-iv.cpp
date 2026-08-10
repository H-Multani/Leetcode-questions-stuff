class Solution {
public:
    unordered_map<int,int> memo;
    bool solve(int n){
        // agar n becomes 0 means current banda cannot play anymore, in which case he loose hence return false
        if(n<=0) return false;
        // agar current banda 1 aa gaya means ye chal lega, hence return true
        if(n==1) return true;

        // memo me hai ans toh yehi se bhejdo
        if(memo.find(n)!=memo.end()) return memo[n];

        // we here means kisi ka toh turn hai

        // current banda can take multiple routes, if n=17, then current banda can go 1 step, 2 step,3 step, 4 step

        // basically sqrt(n) steps jaa sakta hai, loop chala lo best ans nikal lo

        bool ans=false;
        int sq=sqrt(n);
        for(int i=1;i<=sq;i++){
            // current banda agae i*i jitne stones le lega toh aage wala chal payega ki nai

            bool aage_se_ans=solve(n-(i*i));

            // agar aage se ans is true, means current step lenge toh aage wala jeet jayega, meaning we will loose, in this case we have to send false as ans, since we cannot win

            // on the other hand

            // agar aage se ans is false, means current step lenge toh aage wala haar jayega, meaning we will win, in this case we have to send true as ans, since we win

            // and current banda always wants to win, hence ans is just opposite of aage se aaya ans

            // and we take OR, since apan hamesha best ans lenge current bande ke liye

            ans=ans | (!aage_se_ans);
        }

        // jo bhi best ans mila hai return kardo
        return memo[n]=ans;
    }
    bool winnerSquareGame(int n) {
        // ok toh efficiently khelna hoga, DP lagega

        // similar logic as part 3 of this problem

        // funcn me n bhej denge and turns calculate karenge, and best wala return kar denge

        // ok toh TLE aara hai and funcn me bass 1 hi value jaa rahi hai, toh vector banane se accha unordered map lelo better rahega
        memo.clear();

        // optimization nai hora rehen do bc normal chalao

        // unordered map me lelo aur kya pakka SQRT nikalne me dikkat jari hogi
        return solve(n);
    }
};