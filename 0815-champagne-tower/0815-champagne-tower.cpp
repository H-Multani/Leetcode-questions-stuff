class Solution {
public:
    vector<vector<double>> tower;
    void solve(int i, int j, double poured) {
        // agar out of range ho jaaye toh rok dena
        if (i >= tower.size() || j >= tower[i].size())
            return;
        // agar poured becomes 0 return krdo
        if (poured <= 0)
            return;

        // ab poured me current cup full bhar jayega
        // tower[i][j]=(poured>=1)? 1:poured;
        // poured=poured-1.0;
        // agar pehle se filled hua toh kya karenge
        double total = tower[i][j] + poured;
        double overflow;
        if (total > 1) {
            // means overflow hoga total-1
            overflow = total - 1;
            // store kardo yaar tower me
            tower[i][j] = 1;
        } else {
            // means koi overflow nai hoga
            overflow = 0;
            tower[i][j] = total;
        }

        // ab overflow goes to [i+1][j] and [i+1][j+1] equally split

        solve(i + 1, j, overflow / 2);
        solve(i + 1, j + 1, overflow / 2);
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        // har [i][j] th glass me x pour hoga jab, toh vo x-1 hoga pehle to fill
        // current glass, then remaining (x-1)/2 goes right side to [i+1][j] and
        // (x-1)/2 goes to [i+1][j+1]

        // yehi maths laga lenge, and glass tower bana denge empty initially
        // query_row+1 jitna, fir end me dekh lenge ki usme kitna bhara hai

        tower.clear();
        for (int i = 1; i <= query_row + 1; i++) {
            // empty vector banao i size ka
            vector<double> row(i, 0);

            tower.push_back(row);
        }

        // ab this(recursion) causes TLE, toh memoize kardo, i,j,poured changes,
        // bana do memo,

        // yaha ab poured ke liye memo banana is too hard since poured can be
        // 1e9, toh dp use kar lete hai seedha, tower wala array bharte jayenge,
        // since memoize karna is way harder than dp bottom up chalana

        // chala do dp bottom up

        // initially poured daal do first glass me
        tower[0][0] = poured;

        for (int i = 0; i < tower.size() - 1; i++) {
            for (int j = 0; j < tower[i].size(); j++) {
                // ab yaha overflow kitna hoga nikal lo, initially overflow will
                // be glass me jo bhi value hai
                double overflow = tower[i][j];

                if (overflow > 1) {
                    // we here means glass se spill karega [i+1][j] and
                    // [i+1][j+1] me

                    // current glass me 1 rakh do
                    tower[i][j] = 1;
                    // ab glass me 1 reh kar overflow remaining will be
                    overflow = overflow - 1.0;

                    // ab overflow/2 aage wale [i+1][j] and [i+1][j+1] me daal
                    // do, since waha pehle se koi value ho sakti hai hence
                    // overwrite nai karna add karna

                    // pehle se koi value kaise??, maan lo row 3 ke glass 2 bhar
                    // raha hai, ie [3][2] bhar raha hai, toh chances hai ki
                    // usko bharne ke liye [2][1] and [2][2] wale bande ne
                    // overflow mara hoga,
                    // since for [2][1], overflow goes to [3][1] and [3][2],
                    // and for
                    // since for [2][2], overflow goes to [3][2] and [3][3]

                    // toh since 2 glasses se aa raha hai overflow hence
                    // overwrite krne se ye hoga ki apan bass 1 glass ke
                    // overflow ko consider kar rahe, whereas we need to
                    // consider 2 glasses, which is why we add the overflow
                    tower[i + 1][j] += overflow / 2;
                    tower[i + 1][j + 1] += overflow / 2;
                }
            }
        }

        // ab funcn ne bhar diye honge cups poore, return ans

        // ab ye tower[query_row][query_glass] can be bigger than 1 since raw
        // values ke saath khel rahe hai apan, toh maxm yaha ans can be 1.0, toh
        // 1 and tower[query_row][query_glass] me se jo bhi minm hai vahi bhej
        // dena as ans

        // since glass me toh bass 1 hi rahega na max, bacha kucha overflow ho
        // jayega side se

        return min(1.0, tower[query_row][query_glass]);
    }
};