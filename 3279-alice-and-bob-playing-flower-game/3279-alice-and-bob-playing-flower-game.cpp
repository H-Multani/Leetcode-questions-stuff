class Solution {
public:
    long long flowerGame(int n, int m) {
        // so x and y can be in range 2 to m+n like [2,m+n]

        // when x+y is odd, in all scenarios alice will win,toh we need x+y to
        // be odd, toh for that we have 2 cases

        // x odd y even
        // x even y odd

        // x ke liye 1 to n me se odd number choose karna hai 
        long long oddx=(n+1)/2;
        long long oddy=(m+1)/2;

        // even possible x and y
        long long evenx=n-oddx;
        long long eveny=m-oddy;

        // ab ans will be 
        long long ans1,ans2;

        // x odd and y even
        ans1=oddx*eveny;
        // y odd and x even
        ans2=oddy*evenx;

        cout<<ans1<<" "<<ans2<<" "<<endl;

        return ans1+ans2;
    }
};