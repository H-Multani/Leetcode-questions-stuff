class Solution {
public:
    int solve(vector<int>& days, int i, vector<int>& costs,vector<int>& memo) {
        if (i >= days.size())
            return 0;

        // agar memo me hai toh yehi se bhej do ans
        if(memo[i]!=-1) return memo[i];
        // 3 options
        int onedaypass = 0, sevendaypass = 0, thirtydaypass = 0;
        // 1 day pass
        // 1 day pass ka cost add karke, agle day pay jao
        // cout<<"1day "<<endl;
        onedaypass += costs[0] + solve(days, i + 1, costs,memo);
        // cout<<onedaypass<<endl;

        // 7 day pass
        // 7 day pass ka cost add karke, agle day day jao, skip to the day jab
        // pass needed hoga
        int j = 0;
        for (j = i; j < days.size(); j++) {
            if (days[i] + 6 < days[j])
                break;
        }
        // cout<<"7day "<<endl;
        sevendaypass += costs[1] + solve(days, j, costs,memo);
        // cout<<sevendaypass<<endl;

        // 30 day pass
        // 30 day pass ka cost add karke, agle day day jao, skip to the day jab
        // pass needed hoga
        j = 0;
        for (j = i; j < days.size(); j++) {
            if (days[i] + 29 < days[j])
                break;
        }
        // cout<<"30day "<<endl;
        thirtydaypass += costs[2] + solve(days, j, costs,memo);
        // cout<<thirtydaypass<<endl;

        // memo update kardo
        memo[i]=min({sevendaypass, thirtydaypass, onedaypass});

        return min({sevendaypass, thirtydaypass, onedaypass});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // tle dera hai, memoize kardo, sirf i change hora hai uske liye 1D DP
        // bana do mast
        int n=days.size();
        // i can go max upto n, toh n+1 size ka banao DP
        vector<int> memo(n+1,-1);
        return solve(days, 0, costs,memo);
    }
};