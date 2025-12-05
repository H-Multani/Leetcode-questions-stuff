class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // we do prefix sum here

        // pehle sum lelo fir usko kam karte jana
        int ttl = 0;
        for (auto it : nums)
            ttl += it;

        // ab iterate karte jao aur second sum banate jao, jaha dono ka
        // difference even aa gye waha count inrease kardena
        int cnt = 0;
        int sum = 0;
        for (auto it : nums) {
            // current wale ko first subarray me daal do
            sum += it;

            // second subarray se nikalo isko
            ttl -= it;

            cout << ttl << endl;

            // agar dono ka difference even hai toh cnt increase
            if (abs(ttl-sum)%2==0 && ttl != 0)
                cnt++;
            // edge case make sure ki ttl non 0 ho since agar 0 hua toh subarray empty ho jaega 
        }

        return cnt;
    }
};