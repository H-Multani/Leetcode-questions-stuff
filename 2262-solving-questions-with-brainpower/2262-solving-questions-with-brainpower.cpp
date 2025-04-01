class Solution {
public:
    long long dosmth(int i, vector<vector<int>>& ques,vector<long long>& memo) {
        // agar i crosses question ka size return currsum
        if (i >= ques.size())
            return 0;

        // 2 options hai, take nottake

        // agar memo me ans hai toh return krdo
        if(memo[i]!=-1) return memo[i];

        // take, curr i th bande ka points add kardo and move to
        // i+brainpower[i]+1 th idx, since i wala lene ke baad brainpower[i]
        // jitne nai le payenge
        long long take = ques[i][0] + dosmth(i+ques[i][1]+1,ques,memo);

        // not take, i+1 th bande par chale jao
        long long nottake=dosmth(i+1,ques,memo);

        // memo update kardo
        memo[i]=max(take,nottake);

        // dono options me se jo bhi maxm ans dega vahi apna ans hoga
        return max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // recurion and memo wala soln banao pehle toh

        // tle aara hai, meoize kardo, since only 1 moving part ie i, toh 1d memo se kaam ho jayega
        vector<long long> memo(questions.size(),-1);

        // funcn me send karenge apan questions, i(initially 0), currsum
        return dosmth(0, questions,memo);
    }
};