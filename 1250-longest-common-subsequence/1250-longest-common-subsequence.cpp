class Solution {
public:
    int m,n;
    // memo banao of size 1001 since ip is like that
    int solve(string& s1, string& s2, int i,int j,vector<vector<int>>& memo){
        if(i>=m || j>=n) return 0;

        // agar memo me h toh bhej do
        if(memo[i][j]!=-1) return memo[i][j];

        // agar i th and j th char same hai toh dono ko aage badhao
        if(s1[i]==s2[j]){

            // memo me update karke bhejna
            memo[i][j]=1+solve(s1,s2,i+1,j+1,memo);
            return memo[i][j];
        }

        // nai toh 2 options hai
        // option1-> i ko aag badhao, and j ko same rakho
        // option1-> j ko aag badhao, and i ko same rakho

        // dono me se jo bhi maaxm dega vohi ans hoga

        // memo me update karke bhejna
        memo[i][j]=max(solve(s1,s2,i+1,j,memo),solve(s1,s2,i,j+1,memo));
        return memo[i][j];
    }
    int longestCommonSubsequence(string s1, string s2) {
        m=s1.size();
        n=s2.size();

        // TLE, memo banao
    vector<vector<int>> memo(m,vector<int>(n,-1));

        return solve(s1,s2,0,0,memo);
    }
};