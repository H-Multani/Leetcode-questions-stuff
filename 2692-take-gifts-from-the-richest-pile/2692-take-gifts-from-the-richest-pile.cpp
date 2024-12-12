class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // pq bana lo store <value,index>, update karte jao phir toh bss values
        // and until k iterations pass
        priority_queue<pair<int, int>> pq;
        for (auto i = 0; i < gifts.size(); i++) {
            pq.push({gifts[i], i});
        }
        long long ans = 0;

        // loop until k turns end
        while (k--) {
            // current maxm wala top par hoga, uss pile se nikalo
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            // now take val-sqrt(val) jitne gifts
            // remaining gifts=>sqrt(val)
            // ab iss val ko update karo val becomes sqrt(val)
            val = sqrt(val);

            // push back to pq, with the same index, since uss idx wale value
            // par kaam hua hai
            pq.push({val, idx});
        }

        // now pq me saare updated values hai har idx ke, kitne gifts bache hai
        // at each idx,hence in saare ka sum kardo bas since that is what is
        // needed

        while (!pq.empty()) {
            ans += pq.top().first;
            // since pq.top().first jitne gift bache hai ab ans me add kardo
            // pop frm pq, since iss idx wale remaining gifts count kar liye hai
            pq.pop();
        }

        return ans;
    }
};