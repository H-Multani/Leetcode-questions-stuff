class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, pair<int, int>>
            mpp; // stores node and degree(indegree and outdegree)
        // in the pair, first is how many ppl trust you cnt
        // in the pair, second is how many ppl you trust cnt
        // we need ans ke pair ka first to be ==n-1, ie everyone trusts us
        // and ans ke pair ka second to be ==0, ie we trust nobody
        if (n == 1)
            return 1;
        for (auto it : trust) {
            // it[0] trusts it[1]
            // hence it[0] ka pair ka second increment by 1
            mpp[it[0]].second++;
            // it[1] is trueted by 1 more person
            // and it[1] ka pair ka first increment by 1
            mpp[it[1]].first++;
            // if(mpp.find(it[1])==mpp.end()) mpp[it[1]]=0;
        }

        for (auto it : mpp) {
            // it.second is pair
            // it.second.second is stuff inside the pair

            // we need ans ke pair ka first to be ==n-1, ie everyone trusts us
            // and ans ke pair ka second to be ==0, ie we trust nobody
            if (it.second.second == 0 && it.second.first == n - 1)
                return it.first;
        }

        return -1;
    }
};