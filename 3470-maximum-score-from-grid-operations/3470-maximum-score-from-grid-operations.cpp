class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevtaken, ll prevheight, ll col, vector<vector<int>>& grid,
              vector<vector<ll>>& colprefixsum) {
        
        // base case
        if(col==n) return 0;

        // ek result le lengge
        ll result = 0;

        // agar memo me hai toh yehi se bhejo ans
        if(t[prevtaken][prevheight][col]!=-1){
            return t[prevtaken][prevheight][col];
        }

        // current column ke liye heights par iterate karenge

        // height==0 means current column par koi black clr nai kiya hai
        for (int height = 0; height <= n; height++) {
            // we here means height jitne row tak black kiya current column me

            // prev col se jo score milra nikalo
            ll prevcol = 0;
            // current col se jo score milra nikalo
            ll currcol = 0;

            // previous column se ttl tabhi le paunga agar prev wale ka score
            // included nai hai, ie prevtaken=false

            // also prev col se tabhi lenge score agar current col ki height
            // zyada ho prev column ke height se
            if (!prevtaken && col - 1 >= 0 && height > prevheight) {

                // current height tak ka ttl sum nikalo prev column se subtract
                // with prev column ki height tak ka ttl sum
                prevcol += colprefixsum[height][col] -
                           colprefixsum[prevheight][col];

                // by this we get sum of white elements jo pichle column me hai
                // jinke liye current col me adjacent black elements hai
            }

            // agar prevheight>height, means mai current column me contribution
            // le sakta previous columns ke black walo se

            // peeche wale col me black ke adjacent wale whites current column
            // me honge, unka bhi sum nikal lo

            if (prevheight > height) {
                // previous col ki height tak ka ttl sum nikalo current column
                // se subtract with curent column ki height tak ka ttl sum frm
                // current col
                currcol +=
                    colprefixsum[prevheight][col+1] - colprefixsum[height][col+1];
                // by this we get sum of white elements jo current column me hai
                // jinke liye pichla col me adjacent black elements hai
            }

            // ab agar current col ko consider kiya hai toh bana lo ttl, aage
            // true bhej dena indicating ki current ka sum liye hai consider me

            // curr score taken me include current col ka nikala score, and
            // previous column se jo score aaya tha vo bhi
            ll currColScoreTaken =
                currcol + prevcol +
                solve(true, height, col + 1, grid, colprefixsum);

            // ab agar current col ko consider nahi kiya hai toh bana lo ttl,
            // aage false bhej dena indicating ki current ka sum nahi liye hai
            // consider me

            // curr score not taken me previous column se jo score aaya tha bass
            // usko include karenge,current ke score ko include nai karenge
            ll currColScoreNotTaken =
                prevcol + solve(false, height, col + 1, grid, colprefixsum);

            // dono cases me prevcol has to be included, since vo score previous
            // column se aa raha hai, uska current column se koi relation nai
            // hona chahiye

            // and ofcourse current column ki height bhej denge since aage wale
            // ke liye wahi height prevheight banegi, and col+1 toh hai hi
            // already


            // ab dono cases me se jo bhi best ans de lelo
            result=max({result,currColScoreNotTaken,currColScoreTaken});
        }
        
        // update ans before return
        return t[prevtaken][prevheight][col]=result;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        // col prefix sum nikal lo
        vector<vector<ll>> colprefixsum(n + 1, vector<ll>(n + 1, 0));
        // ye n+1 size ka banaenge so that calculation me dikkat na jaye indexes
        // ki

        // first row and first col will be free, baaki sab bhar dena prefix sum
        // se

        // so, bharenge jab toh 1 based indexing se bharenge colprefixsum ko,

        // colprefixsum ko bhar do

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {

                // colprefixsum ko 1 based indexing se bhar rahe hai, hence grid
                // me indexes me -1 hoga dono side
                colprefixsum[row][col] =
                    colprefixsum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        // ab recursive funcn call kar denge

        // TLE dega, memoize kardo
        // 3 things change, 
        // first wala true false, 2 values size 2
        // second wala n tak jayega, toh n+1 size
        // third wala bhi n tak jayega, toh n+1 size
        // n can be maxm 100, toh n+1-> 101

        // initialize with -1
        memset(t,-1,sizeof(t));

        return solve(false, 0, 0, grid, colprefixsum);

        // false-> indicating previous column se kuch sum nai nikala
        // 0    -> prev col ka koi height nai hai black me toh 0 kardo
        // 0    -> starting frm 0 th column
    }
};