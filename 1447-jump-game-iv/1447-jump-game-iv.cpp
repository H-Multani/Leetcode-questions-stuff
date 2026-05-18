class Solution {
public:
    int minJumps(vector<int>& arr) {
        // isme bhi BFS chala do
        int n = arr.size();

        // 3 areas hai explore karne ke liye , 3rd wale ke liye indexes chahiye
        // rahenge value ke map bana lo
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        // q bana lo
        queue<int> q;

        // ek steps wala array bana lo which will store minm steps to each
        // location
        vector<int> dist(n, INT_MAX);

        // start karlo 0 se
        q.push(0);

        // first wale bande ka dist 0 rakh do
        dist[0] = 0;

        int steps = 0;

        while (!q.empty()) {

            // current level par kitne elements hai nikalo
            int m = q.size();

            // chal lo bhai iss level par

            while (m--) {

                // curr nikalo
                int i = q.front();
                q.pop();

                // ab yaha se kaha jaa sakte hai chale jao

                // 3 location hai agar waha ka distance zyada hai means we have
                // found smaller path to this index, in such case explore karlo

                if (i - 1 >= 0 && dist[i - 1] > steps) {
                    // explore karne ke liye q me daal do
                    q.push(i - 1);
                    // and distance update kardo
                    dist[i - 1] = steps + 1;
                }

                if (i + 1 < n && dist[i + 1] > steps) {
                    // explore karne ke liye q me daal do
                    q.push(i + 1);
                    // and distance update kardo
                    dist[i + 1] = steps + 1;
                }

                // 3rd path explore karo

                for (auto idx : mpp[arr[i]]) {
                    // har index par jao, yaha sare paths explore kar sakte hai,
                    // as long as idx!=i, karlo explore

                    // only explore if idx!=i and new wala distance chhota hai
                    // tabhi
                    if (idx != i && dist[idx] > steps) {
                        // update kardo steps ko and q me daal do
                        q.push(idx);

                        // distance update kardo
                        dist[idx] = steps + 1;
                    }
                }

                // dikkat-> agar aage wale indexes par jaaye toh same
                // mpp[arr[i]] wale indexes par har baari loop chalega for
                // exploration, like if for value 7, indexes are
                // {1,3,5,8,9,12,14}, toh jab idx 1 ke liye loop chaloge toh
                // usme best paths aa hi jaenge for indexes (minm distances
                // wale) 3,5,8,9,12,14 toh inn indexes par fir se loop chala kar
                // explore karne ka need nai hai, unnecessary loop chal raha vo

                // ab ye path explore kar liya hai toh same path par vpapas
                // explore nai karenge aage since ek baari explore karne par hi
                // best path wale q ke top par milenge

                // toh iss value ke loop fir se na chale hence uss index wale
                // vector ko hi alag kardo
                mpp[arr[i]].clear();

                // fayeda 7->{1,3,5,8,9,12,14} idx 1 ke liye loop chalega ,
                // baaki indexes minm steps par mil jaenge, toh fir se
                // 3,5,8,9,12,14 ke liye loop chalane ka sense nai banta, toh
                // iska vector clear kar dena, so that loop nai chalega to TLE
                // nai aayega
            }

            // current level sab explore kar liye, ab aage level ke liye steps
            // count badha lo

            steps++;
        }

        return dist[n - 1];
    }
};