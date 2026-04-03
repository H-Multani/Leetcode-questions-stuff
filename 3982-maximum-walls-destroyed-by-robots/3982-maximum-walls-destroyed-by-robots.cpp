class Solution {
public:
    typedef pair<int, int> pii;
    vector<vector<int>> memo;

    int countwalls(vector<int>& walls, int l, int r) {
        // l and r are values, ki ye range hai iske beech me kuch ho toh karlo
        // count

        // left se right ke beech me kitne element count karo

        // left wala banda include ho toh kar lena
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();

        // right wala banda se just bda par ruk jana, since right wala banda
        // also included, cant use lower bound since lower bound gives idx>=
        // element, and upper bound gives idx> element, toh right wale value se
        // just bada ka idx nikal kar dega
        int rt = upper_bound(walls.begin(), walls.end(), r) - walls.begin();

        return rt - left;
    }
    int solve(vector<int>& walls, vector<pii>& robodist, vector<pii>& range,
              int i, int prev) {

        // edge case
        if (i == robodist.size())
            return 0;
        // i gone out of range kuch ans nai bhej paoge rturn 0

        // memo me hai toh bhej do
        if (memo[i][prev] != -1)
            return memo[i][prev];

        // current element ke liye left wala range kya hai
        int leftstart = range[i].first;

        if (prev == 1) {
            // means previous bullet fired toward right

            // in such case current ke liye left wala range will change, since
            // peeche wale ne right me chalai bullet, kaafi range usne hi cover
            // karli( range bw current robot and prev robot)

            leftstart = max(leftstart, range[i - 1].second + 1);
            // range[i-1].second+1 since peeche wale ki right wali bullet max to
            // max range[i-1].second tak gai hogi, means range[i-1].second+1 tak
            // bullet leja sakte apan
        }

        // ab current posn se apan bhi left shoot kare toh explore karo
        int left = countwalls(walls, leftstart, robodist[i].first) +
                   solve(walls, robodist, range, i + 1, 0);

        // countwalls funcn se leftstart se current robo ki posn tak jitne bhi
        // robots shoot down kiye count karlo
        // baaki solve() me i+1 since current wala shoot kar diya aage wala kya
        // karega ye dekho, and sent 0 since current wale ne left shoot kiya hai

        // same cheez karo right shoot ke liye
        int rt = countwalls(walls, robodist[i].first, range[i].second) +
                 solve(walls, robodist, range, i + 1, 1);

        // right ke liye count walls from current posn to right wala range

        // ab dono me se jo bhi maxm ans de vahi hai apna overall ans
        return memo[i][prev] = max(left, rt);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {

        int n = robots.size();

        // vector of pair bana lo which will store robot and distances
        vector<pii> robodist(n);
        for (int i = 0; i < n; i++) {
            robodist[i] = {robots[i], distance[i]};
        }

        // ab robodist ko sort kardo robots ke location ke hisab se,
        // fayeda?->sab robots ek line me aa gaye ab, visualize karna easy hoga
        // konsa robot kaha khada since otherwise current robot ke aage kon
        // khada, peeche kon khada is very hard to find out
        sort(robodist.begin(), robodist.end());

        // walls ko bhi sort karlo so that order me aa jaaye walls toh count
        // karna easy hoga ki current range me kitni walls
        sort(walls.begin(), walls.end());

        // ab range vector bana lo which will store range for each robot, ye
        // necessary nai hai lekin baar baar range calculate karne se accha hai
        // ek bari bana do
        vector<pii> range(n);

        for (int i = 0; i < n; i++) {
            int pos = robodist[i].first;
            int dist = robodist[i].second;

            // ab left me limit and right me limit bata do, i-1,i+1 idx handle
            // kar lena
            int leftlimit = (i - 1 >= 0) ? robodist[i - 1].first + 1 : 1;
            int rtlimit = (i + 1 < n) ? robodist[i + 1].first - 1 : 1e9;
            // since left me robot is at idx robodist[i].first, and apan bass
            // uss elft wale robot tak jaa sakte hai at best, since bullet stop
            // at robot, hence robodist[i].first+1, since robodist[i].first par
            // toh robot khada hai already, toh bullet at max ek aage tak rukegi
            // aur kya

            // similarly with right side, robot at max right wale robot ke
            // location ke 1 pehle tak rukegi aur kya

            // ye ho gaye real stops, agar inke aane se pehle range khatam ho
            // gai toh, range is [pos-dist,pos+dist]

            // left limit ke liye jo pehle khatam ho jaye wahi tak bullet jayegi
            int l = max(pos - dist, leftlimit);

            // right limit ke liye jo pehle khatam ho jaye wahi tak bullet
            // jayegi
            int r = min(pos + dist, rtlimit);

            range[i] = {l, r};
        }

        // ye TLE de dega, memo laga do, 2 things change idx and prev ka value,
        // utne ka hi bana do, idx will go till n, and prev will have values 0,1
        memo.assign(n + 1, vector<int>(2, -1));

        // ab first wale robot se start karlo and bhej do
        return solve(walls, robodist, range, 0, 0);
        // 0-> starting frm idx 0
        // 0-> prev robot kaha hitt kiya, if prev=0, means hit to left, if
        // prev=1 means hit to right
    }
};