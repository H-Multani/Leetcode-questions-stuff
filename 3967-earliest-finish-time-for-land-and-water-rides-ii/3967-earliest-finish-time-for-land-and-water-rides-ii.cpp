class Solution {
public:
    int solve(vector<int>& st1, vector<int>& dur1, vector<int>& st2,
              vector<int>& dur2) {
        // pehle activity 1 karenge then activity 2 always here

        int ans1 = INT_MAX;
        // now we iterate through activity 1 and find the activity that ends the
        // earliest,
        for (int i = 0; i < st1.size(); i++) {
            ans1 = min(ans1, st1[i] + dur1[i]);
        }

        // ab we iterate through the second activity and find ki konsi activity
        // better jayegi iss first wali activity ke sath
        int ans2 = INT_MAX;

        for (int i = 0; i < st2.size(); i++) {
            // activity 1 ended at ans1

            // ab yaha 2 cases hai, activity 2 ke liye

            // case 1, current activity already open thi pehle se, in which case
            // ans2 will be previous end time+duration(of current activity)
            // since ride is open and apan directly jump kar lenge.

            // case 2, current activity ko start hone me kuch time hai like
            // activity 1 ended at time 7 and current new activity is to start
            // at time 10, in which case we will have to wait for activity 2 to
            // start, toh overall ending time ans2 will be start(current
            // activity)+duration(current activity)

            // toh ye dono cases me duration of current activity already add
            // karre hai apan, bass start ka difference hai,

            // ek case me we start directly at ans1(when activity available but
            // we havent started ie st2[i]<ans1),

            // second case me we start at st2[i](current activity ka start hona
            // baaki hai even after first activity ended, ie st2[i]>=ans1)

            // toh ez way will be to take max of ans1 and st2[i], so that jo bhi
            // later wala hai usse hi duration calculate huye, according to both cases
            ans2 = min(ans2, max(ans1, st2[i]) + dur2[i]);
        }


        // now we have overall minm time for both activities combined
        return ans2;
    }
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        // again 2 choices here

        // choice 1-> pehle land karlo fir water
        int pehleland_firwater =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        // choice 2-> pehle water karlo fir land dekhna
        int pehlewater_firland =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);

        // dono me se jo best ans de return kardo
        return min(pehleland_firwater, pehlewater_firland);
    }
};