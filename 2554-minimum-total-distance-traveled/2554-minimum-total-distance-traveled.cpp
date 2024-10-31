
class Solution {
public:
    long long solve(int robot_idx, int factory_posn_idx, vector<int>& robot,
                    vector<int>& posn, vector<vector<long long>>& memo) {
        if (robot_idx >= robot.size()) {
            // no more dist to be covered, return 0
            return 0;
        }

        if (factory_posn_idx >= posn.size()) {
            // invalid case
            // this runs only when we have robots to be fixed but no factories
            // remaining, jo kabhi nai hoga(accd to constaints)
            // in such case return intmax
            return 1e12;
        }

        // if already present in memoization, means apan ne iss state(current
        // robot and current factory) ke liye already solve krke rakha hai, yehi
        // se return krdo ans ko, no need to check ahead
        if (memo[robot_idx][factory_posn_idx] != -1) {
            return memo[robot_idx][factory_posn_idx];
        }

        // 2 options

        // take current factory, in this case current bande ka dist nikal
        // lo, and aaage explore kar lo aage explore means i th wala banda
        // settled, move to i+1 th banda, and current factory also settled,
        // move to next factory posn ie j+1
        long long take_current_factory =
            abs(robot[robot_idx] - posn[factory_posn_idx]) +
            solve(robot_idx + 1, factory_posn_idx + 1, robot, posn, memo);

        // option 2: dont take current factory
        // current robot ke liye next factory me search karo ie j+1
        long long skip =
            solve(robot_idx, factory_posn_idx + 1, robot, posn, memo);

        // ab dono options ka distance hai apne paas, since we need minm
        // distance hence return minm

        // ab iss state ke liye ans will be the value returned, toh memo me
        // update kar do current state ke liye ans, so that aage kabhi vapas
        // same state me aaye toh turant ans mil jaye
        memo[robot_idx][factory_posn_idx] = min(skip, take_current_factory);
        // NOTE: here state means current robot and current factory ke pair ke
        // liye answer

        return min(skip, take_current_factory);
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // factory posn ko expand karo, so that limit ko maintain na karna pade
        vector<int> factoryposn;
        for (auto it : factory) {
            while (it[1]--) {
                factoryposn.push_back(it[0]);
            }
        }

        // soln tle phek raha hai, memoize krdo
        int m = robot.size();
        int n = factoryposn.size();
        // memo vector bana lo, of m x n since, apan 2 index maintain kar rhe
        // hai yaha, ie one idx of robot array, and other index of factoryposn
        // array, toh in dono ke size ka hi nikalna bas memo vector
        vector<vector<long long>> memo(m + 1, vector<long long>(n + 1, -1));

        // solve funcn
        return solve(0, 0, robot, factoryposn, memo);
    }
};