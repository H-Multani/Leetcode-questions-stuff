class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        long long ans = 0;

        // diff vector bana lo
        vector<int> diff(n, 0);

        for (int i = 0; i < n; i++) {
            diff[i] = target[i] - nums[i];
        }

        // ab prev aur current lelo
        int prev = 0, curr = 0;

        // ab iterate karo difference arrays par

        for (int i = 0; i < n; i++) {
            // curr lelo
            curr = diff[i];

            // sabse pehle ye dekho ki kya curr aur prev ke beech me sign change
            // hua hai??, agar hua hai toh iss diff sign wale element ke liye
            // alag se operations lagenge
            if ((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                // we here means sign change hua hai alag se calcualte karo

                // means jitna curr hai utne operations lagenge since iska ab
                // alag se counting chalega
                ans += abs(curr);
            }
            // otherwise we here means same sign hai abhi
            // yaha same as lc 1526, agar curr>prev hai means extra steps
            // lagenge toh bass curr-prev jitne steps hi lagenge
            else if (abs(curr) > abs(prev)) {
                // abs since curr and prev can be -ve as well
                ans += abs(curr - prev);
            } else if (abs(curr) <= abs(prev)) {
                // we here means prev jitne phele steps le chuke hai no extra
                // steps needed here, toh we dont need any new steps here

                // do nothing here
            }

            // prev ko update kardo
            prev=curr;
        }

        return ans;
    }
};