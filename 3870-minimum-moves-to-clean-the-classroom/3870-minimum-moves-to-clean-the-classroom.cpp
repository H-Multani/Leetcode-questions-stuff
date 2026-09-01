class Solution {
public:
    using vb = vector<bool>;
    using vbb = vector<vb>;
    using vbbb = vector<vbb>;
    using vbbbb = vector<vbbb>;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    struct state {
        int row, col, energyleft, collectedmask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // max energy use rakh lo for revive
        int maxenergy = energy;

        // ek int jo litter ka bit store karega, bitmasking, essentially har
        // litter will correspond to a bit, if bit is true means vo litter utha
        // liya and so onn

        // abhi pehle ek litter ka location store karne ke liye array lelo,
        // since classroom is 20x20 hence same here
        int litterbit[20][20];

        // abhi tak kitna litter uthaya
        int littercnt = 0;
        // start x and y nikal lo
        int stx = 0, sty = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // litter bit me -1 kardo yaha litter nai hai
                litterbit[r][c] = -1;

                // startx and y update kardo
                if (classroom[r][c] == 'S') {
                    stx = r, sty = c;
                } else if (classroom[r][c] == 'L') {
                    // litter bit update kardo
                    litterbit[r][c] = littercnt;
                    // meaning current posn wala litter has position littercnt,
                    // 1st,2nd etc

                    // aage badha do
                    littercnt++;
                }
            }
        }

        // agar litters collect ho gaye hai toh overall will be 2^littercnt-1,
        // since saare bits 1 honge

        // each bit denotes 1 litter
        int allcollected = (1 << littercnt) - 1;

        if (littercnt == 0) {
            // koi litter nai hai
            return 0;
        }

        // ab BFS chal lenge

        // q me 4 cheez store karenge, toh state hi lelo
        queue<state> q;
        // starting push kardo q me
        // starting from x,y
        // with maxenergy
        // initially 0 litter picked
        q.push({stx, sty, maxenergy, 0});
        // ab isko visited mark kardo

        // 4 state ka visited vector banega
        // m, then n, then for energy we make maxenergy
        // then for mask, mask ka value can be 2^littercnt, laga diya
        vbbbb vis(m, vbbb(n, vbb(maxenergy + 1, vb(1 << littercnt, false))));

        // start wale ko visited mark kardo
        vis[stx][sty][maxenergy][0] = true;

        int ans = 0;

        // bfs chaldo
        while (!q.empty()) {
            // current level par kitne bande(ya better is current steps lenge
            // toh kaha tk pahuchenge)

            int currsize = q.size();
            while (currsize--) {

                // current band kon
                state curr = q.front();
                q.pop();

                // agar yaha tak pahucha hua bit mask is same as allcollected ke
                // meaning we have collected all stuff, return ans frm here
                if (curr.collectedmask == allcollected) {
                    return ans;
                }

                // agar energy 0 hai yaha toh koi sense nai hai explore karne ka
                if (curr.energyleft == 0) {
                    continue;
                }

                // ye sab nai toh saare directions me move kar sakte
                for (auto &it : dir) {
                    // agla row column nikalo
                    int nextrow = curr.row + it[0];
                    int nextcol = curr.col + it[1];

                    // valid hona chahiye, nai hai toh aage badho
                    if (nextrow < 0 || nextrow >= m || nextcol < 0 ||
                        nextcol >= n)
                        continue;

                    // konsa cell next
                    char cell = classroom[nextrow][nextcol];

                    // agar ye cell is X, tab toh aage bhi badhne ka need nai,
                    // invalid hai kyuki
                    if (cell == 'X')
                        continue;

                    // aagr energy -1 hoke jayegi
                    int nextenergy = curr.energyleft - 1;

                    // bitmask same jayega
                    int nextbitmask = curr.collectedmask;

                    // if cell is R then energy reset
                    if (cell == 'R')
                        nextenergy = energy;
                    // if cell is L then litter mil gaya, bit include kardo
                    // current wale bitmask me hi
                    else if (cell == 'L') {

                        // konse wale litter pae aaye, bit nikalo uska
                        nextbitmask |= (1 << litterbit[nextrow][nextcol]);

                        // ab ye wala bit 1 set ho gaya
                    }

                    // ab explore karenghe aage q me daal do updated values ko

                    // agar visited nai hai, toh karlo visit
                    if (!vis[nextrow][nextcol][nextenergy][nextbitmask]) {
                        // visited mark kardo
                        vis[nextrow][nextcol][nextenergy][nextbitmask] = true;
                        // q me daal do
                        q.push({nextrow, nextcol, nextenergy, nextbitmask});
                    }
                }
            }
            // ye khatam ho jaaye toh mvoes badha do agle level par jao
            ans++;
        }
        // we here means koi ans nai mila, return -1
        return -1;
    }
};