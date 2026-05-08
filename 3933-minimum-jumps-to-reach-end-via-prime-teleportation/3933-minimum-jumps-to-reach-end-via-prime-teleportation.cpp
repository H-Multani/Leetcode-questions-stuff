class Solution {
public:
    // sieve funcn to find all primes
    vector<bool> getsieve(int limit) {
        vector<bool> isprime(limit + 1, true);

        isprime[0] = false;
        isprime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isprime[i]) {
                // means current element is prime, ab iske prime hone se aage
                // iske jitne multiples non prime ban jaenge sab flse kardo

                for (int j = i * i; j <= limit; j += i) {
                    isprime[j] = false;
                }
            }
        }

        return isprime;
    }
    int minJumps(vector<int>& nums) {

        // firstly sieve bana do which will be used to get prime nos
        int maxm = *max_element(nums.begin(), nums.end());

        vector<bool> sieve = getsieve(maxm);
        // maxm 9500 ish elements in this sieve
        int n = nums.size();

        // use a map which will store element and indeices, will help when
        // multiple times same element aaye, toh q me daalne me easier hoga
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        // ek set le lenge which will store used prime nos, ye prime nos ko
        // already use kar chuke hai these wont be needed again
        unordered_set<int> seen;
        // logic is ek baari koi prime par aaye toh uske saare options ek baar
        // me q me daal denge, sab explore ho jaenge, toh apan ko baar baar same
        // exploreation nai karna padega

        // visited array bana do
        vector<bool> vis(n + 1, false);

        // q bana do for BFS
        queue<int> q;
        // this q stores indexes of places visited

        // first index daal do q me
        q.push(0);
        // yaha visited mark kardo
        vis[0] = true;

        // ek steps count krne ke liye counter lelo
        int steps = 0;

        // bfs chal do
        while (!q.empty()) {
            int m = q.size();
            // current step par apan m indexes tak jaa sakte hai

            // explore all indexes and aage

            while (m--) {
                // current element nikalo
                int curridx = q.front();
                int curr = nums[curridx];
                // pop from queue
                q.pop();

                // agar galti se last element par pahuch gaye toh return kitne
                // steps aaye hai apan till here
                if (curridx == n - 1)
                    return steps;

                // we here means already visited mark kar diya hoga

                // curridx se apan ke paas 2 options hai,

                // option 1,adjacent par jao

                // i+1 par jao
                // agar i+1 is already visited then q me mat dalna
                if (curridx + 1 < n && !vis[curridx + 1]) {
                    // means we can visit, q me daal do
                    q.push(curridx + 1);
                    // visited mark kardo
                    vis[curridx + 1] = true;
                }
                // i-1 par jao
                // agar i-1 is already visited then q me mat dalna
                if (curridx - 1 >= 0 && !vis[curridx - 1]) {
                    // means we can visit, q me daal do
                    q.push(curridx - 1);
                    // visited mark kardo
                    vis[curridx - 1] = true;
                }

                // option 2, current wala agar prime hai then we can go to any
                // multiple of this and explore

                // agar element is prime and vo prime agar explore ni kiye hai
                // toh karo explore
                if (sieve[curr] && seen.find(curr) == seen.end()) {
                    // means current element is prime AND apan ne usko explore
                    // nai kiya hai

                    // iss prime ke har multiple ko nums me dhundo and q me daal
                    // do as possible areas to explore, for this we will use the
                    // map above

                    for (int j = curr; j <= maxm; j += curr) {
                        // means j is multiple of prime no,

                        // map me dhundo agar nai hai toh aage dekho
                        if (mpp.find(j) == mpp.end())
                            continue;

                        // we here means map me hai indexes, explore each index
                        for (auto idx : mpp[j]) {
                            // agar current index is not visited, toh usko q me
                            // laga do for processing
                            if (!vis[idx]) {
                                // means idx is unvisited, explore this

                                // q me daal do
                                q.push(idx);
                                // ab visited mark kardo
                                vis[idx] = true;
                            }
                        }
                    }

                    // ab current prime ke liye saare paths explore kar liye,
                    // set me daal do so that baad me fir se explore na ho yehi
                    // same prime
                    seen.insert(curr);
                }
            }
            // now we have explored all possible paths from these m elements

            // steps increase karke aage badho
            steps++;
        }

        return steps;
    }
};