class Solution {
public:
    int n;
    vector<int> memo;
    int solve(int i,vector<int>& s){
        // agar our of range hai means koi ka turn nai hai return 0
        if(i>=n) return 0;

        // agar memo me hai toh bhej do
        if(memo[i]!=-1) return memo[i];

        // jiski bhi turn hai uske paas 3 choices hai, 1 stone, 2 stone or 3 stone

        // 3no case me current score ko add kar lena and aage recursive call me - wala sign laga dena, automatically recursion se alice ke scores add honge and bob ke subtract honge since -solve(- solve()) bahar aake + ban jaeyag

        // 3 cases chal do and maxm ans lena har case me se


        // since alice kabhi bhi jeetegi toh vahi lenge

        // 1 stone taken
        int ans=s[i]-solve(i+1, s);

        // 2 stone taken
        if(i+1<n){
            ans=max(ans,s[i]+s[i+1]-solve(i+2,s));
        }
        // 3 stone taken
        if(i+2<n){
            ans=max(ans,s[i]+s[i+1]+s[i+2]-solve(i+3,s));
        }

        // jo ans aaya bhej do
        return memo[i]=ans;
    }
    string stoneGameIII(vector<int>& s) {
        // bc simple dp memo laga do

        // alice and bob ka score banate chalna DP me

        // best score jiska hoga vahi jeetega, seedha seedha

        // if alice wins in a particualar scenario, then so be it

        // we keep track of only overall score-> alice score - bob score

        // if overall>0 alice wins
        // if overall<0 alice bob
        // if overall==0 alice tie
        n=s.size();

        // since only 1 thing changes here hence 1D memo bana do
        memo.resize(n+1,-1);

        int diff=solve(0,s);

        if(diff<0){
            // bob wins
            return "Bob";
        }
        else if (diff>0){
            // alice win
            return "Alice";
        }
        else{
            // tie
            return "Tie";
        }

    }
};