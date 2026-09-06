class Solution {
public:
    int n,m;
    vector<vector<int>> memo;
    int solve(int i,int j,string& s,string& t){
        // if j end tak pahuch chuka hai then that means t string is made, return 1
        if(j==m) return 1;

        // agar upar wala nai hua lekin i end tak pahuch gaya then that means string t isnt made, hence return 0
        if(i>=n) return 0;

        // memo me hai toh bhej do
        if(memo[i][j]!=-1) return memo[i][j];

        // we here means 2 options hai comparison ke

        // take and nottake

        // take sirf tabhi hoga agar i th and j th characters match

        int ans1=0,ans2=0;

        // take
        if(s[i]==t[j]){
            // means character match karra hai, ans explore kar sakte hai
            ans1=solve(i+1,j+1,s,t);
        }
        
        // nottake
        // ans2 me i+1 me explore karenge for same j th character
        ans2=solve(i+1,j,s,t);

        // ab dono side se jo ans aaya laga do total karke as ans
        return memo[i][j]=ans1+ans2;
    }
    int numDistinct(string s, string t) {
        // simple DP laga kr dekho
        n=s.size();
        m=t.size();
        // string banate chalo

        // subequences of s banane hai means index s par chalega
        string ans="";


        // instead of comparing strings, apan seedha indexes compare karke aage badhte hai

        // yaha TLE aa sakta hai and 2 things change, i and j, toh utne size ka memo bana do
        
        memo.resize(n,vector<int>(m,-1));
         
        return solve(0,0,s,t);
    }
};