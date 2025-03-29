class Solution {
public:
    const int mod = 1e9 + 7;

    // custom function likho power calculate karne ka
    // custom wala kaam nai krra hai, TLE aara hai, mik wala
    long long newpow(long long a, long long b) {
        if (b == 0) return 1;
        long long half = newpow(a, b / 2);
        long long result = (half * half) % mod;
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        return result;
    }

    // soe wala funcn likho prime nos nikalne ka
    vector<int> getprime(int limit) {
        // iss limit tak jitne prime nos hai saare nikal kar do

        // initially all nos ko prime maan lo
        vector<bool> isprime(limit + 1, true);

        // loop chalao ab prime har no par iterate karne ka
        // i=2 se chalu karo since smallest prime no is 2
        for (int i = 2; i * i <= limit; i++) {
            // agar current i prime hai
            if (isprime[i]) {
                // we here means current no prime hai, toh iss ke prime hone se
                // konse elements prime nai rahnge ab unko false kardo

                // toh ab j=i*i se chalu karenge apan, since i is a prime no,
                // toh j=i*2 se toh kam se kam chalu karna chahiye, lekin dekha
                // jaaye toh i=2 wale case me j=2*13, 2*17 etc waale saare cases
                // me already false dala hoga, toh reiterate karne ka sense nai
                // hai, in such case better choice will be to start frm i*i and
                // phir +i karte jaene

                // isse kya hoga ki hamesha new elements milenge which need to
                // be made false
                for (int j = i * i; j <= limit; j += i) {
                    // increase j by +i each time
                    isprime[j] = false;
                }
            }
        }

        // ab apne paas isprime me saare vo elements hai jo prime nos hai
        // isprime[i]=true means i th banda prime hai
        // count karlo vetor me daal kar send kardo
        vector<int> ans;
        for (int i = 2; i < limit + 1; i++) {
            if (isprime[i])
                ans.push_back(i);
        }

        return ans;
    }

    vector<int> NGE_Opti(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                nge[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return nge;
    }
    vector<int> PGE_Opti(vector<int> arr) {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i])
                s.pop();
            if (!s.empty())
                pge[i] = s.top();
            s.push(i);
        }
        return pge;
    }

    // prime score find karne ka funcn likho
    vector<int> getprimescores(vector<int>& nums) {
        int n = nums.size();

        // prime scores vector bana lo
        vector<int> primescore(n, 0);

        // maxm element nikalo utne tkk ke prime nos nikalo
        int maxm = *max_element(nums.begin(), nums.end());

        vector<int> prime = getprime(maxm);

        // ab har element par iterate kardo

        for (int i = 0; i < n; i++) {
            // curr no is
            int curr = nums[i];

            // ek ek akrke saare prime nos se divide karte jao
            for (auto val : prime) {
                // agar val>sqrt(curr) means iske aage chk karnae ka sense nai
                // hai, yehi se break kardo
                if (val * val > curr) {
                    break;
                }

                // agar current prime no ek prime factor hai toh count karlo and
                // divide karte jao
                if (curr % val != 0)
                    continue;

                // we here means val is prime factor for curr toh count+1 kardo
                primescore[i]++;

                // ab divide karte chalo, jitni baar iss prime no se divide kr
                // sakte hai

                while (curr % val == 0) {
                    curr /= val;
                }
            }

            if (curr > 1) {
                // means last wala 1 prime no apan ne count nai kiya hoga kahi
                // na kahi, uske liye +1 kardo count me
                primescore[i]++;
            }
        }

        return primescore;
    }

    int maximumScore(vector<int>& nums, int k) {
        // sabse pehle prime scores nikalo
        vector<int> primescores = getprimescores(nums);

        // ab nge pge nikalo
        // dono me 1 change hoga bass ki instead of storing elements,we store
        // indexes agar == hua toh bhi break karna hai
        vector<int> nge = NGE_Opti(primescores);
        // pge ka funcn me change hai thoda,< ke jagah <= laga diya hai maine,
        // so that = wala case bho consider hoga break ke liye
        vector<int> pge = PGE_Opti(primescores);

        // ab subarray cnt store karlo
        int n = nums.size();

        vector<long long> subarraycnt(n, 0);

        for (int i = 0; i < n; i++) {
            // current nums[i] ke liye kitne subarrays honge in which nums[i]
            // has the highest prime score and is the biggest with that prime
            // score

            // no of possible ending pts
            long long endingpts = nge[i] - i;
            // no of possible starting pts
            long long startpts = i - pge[i];

            // ttl no of subarrays=no of possible ending pts*no of possible
            // starting pts
            subarraycnt[i] += endingpts * startpts;
        }

        // subarrays[i]=5 means ki 5 subarrays hai jisme nums[i] is the element
        // with highest prime score and is the biggest number with that prime
        // score

        // ab nums ka sorted karke bana lo, element with idx, so that maxm
        // element at top
        vector<vector<int>> sortednums;
        for (int i = 0; i < n; i++) {
            sortednums.push_back({nums[i], i});
        }

        // sort kardo ab isko
        sort(sortednums.begin(), sortednums.end(),greater<>());

        // sb score banao
        long long score = 1;

        // start frm largest element greedily
        int i = 0; // iterates over the sortednums array

        // for (auto it : primescores) {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : nge) {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : pge) {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : subarraycnt) {
        //     cout << it << " ";
        // }
        // cout << endl;

        while (k > 0) {
            // number konsa hai and uska idx kya hai
            auto num = sortednums[i][0];
            auto idx = sortednums[i][1];

            // kitni baar ye num laga sakte hai apan operations ke liye
            long long operations = min(subarraycnt[idx], (long long)k);

            // ab itni baar ye num ko score me multiply kardo

            // cout<<" here "<<operations<<endl;
            // cout<<score<<endl;

            // toh instead of multiplying one by one, findpower funcn use karlo
            // custom wala phir ek baar me score me multiply kardo
            score = (score * newpow(num, operations)) % mod;

            // k me remove kardo kitne operations ho gaye hai
            k -= operations;

            // move to next
            i++;
            // if (idx >= sortednums.size())
            //     break;
        }

        return score;
    }
};