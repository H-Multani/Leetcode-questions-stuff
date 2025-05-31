class Solution {
public:
    int n;

    // num aayega coordinate nikal kr bhejo
    pair<int, int> getcood(int num) {
        // row frm top
        int rt=(num-1)/n;
        // row frm bottom
        int rb=n-1-rt;

        int col=(num-1)%n;

        if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0)){
            // means col go rt to left
            col=n-1-col;
        }
        // else col go left to rt like always

        // end me pair bana kar bhj do
        return make_pair(rb,col);

    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        // steps naam ka variable lelo, will keep track of steps we have taken
        // till now(basically lvl store karega, BFS wala)
        int steps = 0;

        // BFS ka queue lelo
        queue<int> q;

        // visited lelo, so that same location par aake restart na krna pade,
        // saving extra steps
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // 1 se start krre h which is at [n-1][0] toh usko true mark krdo,
        vis[n - 1][0] = true;

        // q me push krdo 1 ko
        q.push(1);

        // BFS wala loop chalao
        while (!q.empty()) {
            // kitne h iss level par
            int N = q.size();

            // current level par explore kro
            while (N--) {
                // current bnda nikalo
                int curr = q.front();
                q.pop();

                if (curr == n * n) {
                    // means we have reached the end, return the no od steps it
                    // took to get here
                    return steps;
                }

                // apan curr par khade h, toh yaha se we can go to
                // curr+1,curr+2,...curr+6 (dice ke 6 sides hote h jis se +1 to
                // +6 jaa sakte h apan)

                // loop chala do, since yehi 6 bande apne neighbours honge
                for(int k=1;k<=6;k++){
                    // new neighbour/ new value will be
                    int val=curr+k;

                    // agar ye value >n*n hua means overstep krre h apan board se break frm loop
                    if(val>n*n) break;

                    // new cood nikalo
                    auto cood=getcood(val);

                    int row=cood.first;
                    int col=cood.second;

                    // agar unvisited h toh q me dal kar explore krlo
                    if(vis[row][col]){
                        // already visited move along
                        continue;
                    }

                    // nai gaye ho toh visited mark krdo, then explore
                    vis[row][col]=true;
                    // q.push(val);

                    // agar yaha kuch ladder/snake nai h toh val par hi chle jao
                    if(board[row][col]==-1){
                        q.push(val);
                    }
                    else{
                        // means yaha snake/ladder h,toh board wali value daal do
                        q.push(board[row][col]);
                    }

                }
            }

            // we here means 1 step end, step++
            steps++;
        }

        // since koi ans nai mila we cant get to n*n
        return -1;
    }
};