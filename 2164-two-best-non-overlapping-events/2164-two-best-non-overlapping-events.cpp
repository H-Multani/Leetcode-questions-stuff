class Solution {
public:
    int n;
    int t[100001][3];
    // [100001]-> since i could be this big at max
    // [3]-> since cnt could be this big at max
    // kuch nai h upper bound hai bss
    int binarysearch(vector<vector<int>>& events, int val) {
        // iss val se strictly "bada" start time wala pehla event ka index bhejo
        int l = 0, r = n - 1;
        int ans = -1;
        // since -1 invalid idx hai

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // check if
            // mid wale element ke starting>val, if yes, its possible ans
            if (events[mid][0] > val) {
                // possible ans hai, update
                ans = mid;
                // check left side for lower start times closer to val but
                // still>val
                r = mid - 1;
            } else {
                // means colision hoga, check rt side for better ans where
                // starting time>val
                l = mid + 1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& events, int i, int cnt) {
        // if cnt==2 means 2 events le liye hai cant take more
        // i>=n, out of bound jaye toh return 0
        if (cnt == 2 || i >= n)
            return 0;

        // mempoized soln, yaha aa chuke pehle toh mat karo explore
        if(t[i][cnt]!=-1){
            return t[i][cnt];
        }

        // 2 options, take current event
        // take ke liye first of all current wala include karo
        int take = events[i][2];
        // ab binary search se find karo ki iske aage minm konsa event le sakte
        // hai
        int nextvalid_event_idx = binarysearch(events, events[i][1]);
        // ab apne paas next valid event ka idx hai, wala par jaa kar solve
        // funcn lagao
        // nextvalid_event_idx could be an invalid index(-1), in such case nai
        // explore karna, ie explore only if nextvalid_event_idx is valid idx
        if (nextvalid_event_idx != -1)
            take += solve(events, nextvalid_event_idx, cnt + 1);
        // cnt+1 since apan ne current event le liya hai

        // dont take current event
        int not_take = 0;
        // ie current event nai le rhe hai, solve funcn called for i+1 idx
        not_take += solve(events, i + 1, cnt);
        // no cnt+1, since apan ne current event ko nai liya hai

        // ab jo best option hoga take/not take approach ka vohi return krdena
        // best option will be jo maxm value op me de

        // iss i and cnt ke liye correct soln store kardo pehle hi 
        t[i][cnt]=max(take,not_take);
        return max(take, not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());

        // tle dera h, memoize karna padega
        // t ko initialize kardo
        memset(t,-1,sizeof(t));
        // saari values -1 kar dega t ka

        int cnt = 0;
        return solve(events, 0, cnt);
    }
};