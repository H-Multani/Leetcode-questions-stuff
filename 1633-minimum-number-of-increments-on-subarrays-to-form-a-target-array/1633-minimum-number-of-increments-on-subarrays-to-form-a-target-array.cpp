class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        // ab ye target array is similar to diff array for lc 3329

        long long ans = 0;

        // current aur previous lelo
        int curr = 0;
        int prev = 0;

        // ab diffference array par loop karo
        for (int i = 0; i < n; i++) {
            // current is at current element
            curr = target[i];

            // no need to check for sign change here since all values are +ve

            // ab yaha apan ne prev jitne steps le liye hai already toh prev tak
            // already pahuch chuke hai and curr ho sakta hai upar ho ya neeche
            // ho

            // agar curr>prev toh apan ko curr-prev jitne steps extra lagenge
            // to get prev value to current value
            // uss case me ans me extra steps add kardo
            if (curr > prev) {
                // diff jitne steps extra lagenge add kardo
                ans += (curr - prev);
            }
            // else curr<=prev means apan pehle hi zyada steps le chuke hai
            // pichle wale subarrays me, toh current element ko bhi uss prev
            // wale subarray me include kar lenge toh koi extra steps nai lagenge thats all

            // ab bass prev ko curr bana do
            prev=curr;
        }

        return ans;
    }
};