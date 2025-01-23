class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // simple, konse konse columns and rows par servers comm kar skte hai
        // store kar lenge, phir agar koi server ka posn iss me aaya toh means
        // servers cam communitcate, in such case, cnt increase krdena

        // for eg in eg3, servers can communicate on rows={0,1,2,3}, toh in rows
        // ke corresponding count rakh lenge ki kitne servers hai iss row par,
        // which will be like, rows={0:2,1:1,2:1,3:1}, here 0:2 means 0 th row
        // par 2 servers, can comminicate with each other

        // similarly with columns, col={0:1,1:1,2:2,3:1}

        // ab apan iterate karenge each server posn par,and update ans

        // server at (0,0), for row 0, rows[0]=2, means iss row me 2 servers
        // hai, can communicate, include in answer

        // server at (0,1), for row 0, rows[0]=2, means iss row me 2 servers
        // hai, can communicate, include in answer

        // server at (1,2), for row 1, rows[1]=1, means iss row me 1 servers
        // hai, cannot communicate,check for column, column[2]=2, means iss
        // column me 2 servers hai, can communicate, include in answer

        // server at (2,2), for row 2, rows[2]=1, means iss row me 1 servers
        // hai, cannot communicate,check for column, column[2]=2, means iss
        // column me 2 servers hai, can communicate, include in answer

        // server at (3,3), for row 3, rows[3]=1, means iss row me 1 servers
        // hai, cannot communicate,check for column, column[3]=1, means iss
        // column me 1 servers hai, cannot communicate, dont include in answer

        // toh overall ans=4, returned, yehi karo

        unordered_map<int, int> rows, cols;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // means iss row ans column par ek server hai, update kardo
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int ans = 0;
        // ab har server par jao ans ke vaaste
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // means yaha ek server hai, can this server communicate
                    // with other servers??

                    if (rows[i] > 1 || cols[j] > 1) {
                        // means this server can communicate with other servers,
                        // hence considered in ans
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};