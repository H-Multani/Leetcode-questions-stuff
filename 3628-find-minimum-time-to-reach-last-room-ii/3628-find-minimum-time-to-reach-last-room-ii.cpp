#define pipii pair<int, pair<int, int>>

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // lc 3341 ka code

        // pura code same as lc 3341, bss step count (1 or 2) wala logic ka
        // explanation likha maine

        int n, m;
        n = moveTime.size();
        m = moveTime[0].size();

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;

        while (!pq.empty()) {
            int currtime = pq.top().first;
            int currx = pq.top().second.first;
            int curry = pq.top().second.second;

            pq.pop();

            // jab first time (n-1,m-1) par pahuchenge it will be smallest time,
            // yehi se return krdo ans ko(mik probably)
            if (currx == n - 1 && curry == m - 1)
                return currtime;

            if (time[currx][curry] < currtime)
                continue;

            vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto it : dir) {
                int newx = it[0] + currx;
                int newy = it[1] + curry;

                if ((newx >= 0 && newx < n) && (newy >= 0 && newy < m)) {

                    // yaha par mik ka logic lagega ab i+j ke hisaab se step cnt
                    // decide hoga, here i=newx and j=newy

                    // if i+j is even means 2 sec wala count krna hai
                    // if i+j is odd means 1 sec wala count krna hai
                    // ye toh mai khud notice kar liya tha

                    // seedha seedha apply krdo new neighbour par(old par nai,
                    // since old par toh abhi baithe hai na), since uss par hi
                    // ja rahe hai apan, toh jis new neighbour par jaa rahe hai
                    // uske i+j ke hisaab se steps count honge

                    int steps;
                    if ((newx + newy) % 2 == 0)
                        steps = 2;
                    else
                        steps = 1;
                    // foolproof formula, if i+j is even, we need 1 sec wala
                    // count and if i+j is odd we need 2 sec wala vahi kiya hai,
                    // by this steps me apne aap count ho jaega kitne sec wala
                    // lena, bss ab neeche wale code me +1(prev code) ke jagah
                    // steps daal denge

                    if (time[newx][newy] == INT_MAX ||
                        time[newx][newy] > max(currtime + steps,
                                               moveTime[newx][newy] + steps)) {

                        time[newx][newy] =
                            max(currtime + steps, moveTime[newx][newy] + steps);

                        pq.push({time[newx][newy], {newx, newy}});
                    }
                }
            }
        }
        return time[n - 1][m - 1];
    }
};