class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        // free waale gaps daal do free arr me
        vector<int> free;
        free.push_back(st[0]);
        for (int i = 1; i < st.size(); i++) {
            free.push_back(st[i] - et[i - 1]);
        }
        free.push_back(eventTime - et[et.size() - 1]);

        int n = free.size();

        // prefiz sum ke liye max left and max right nikal lo
        vector<int> maxleftfree(n, 0);
        vector<int> maxrtfree(n, 0);

        // right free wala vector bhar do
        for (int i = n - 2; i >= 0; i--) {
            maxrtfree[i] = max(maxrtfree[i + 1], free[i + 1]);
        }
        // left free wala vector bhar do
        for (int i = 1; i < n; i++) {
            maxleftfree[i] = max(maxleftfree[i - 1], free[i - 1]);
        }

        // ab ans bana lo
        int ans = 0;
        // iterate over the free array

        for (int i = 1; i < n; i++) {
            // duration of current event
            int currevent = et[i - 1] - st[i - 1];

            // chk if ye event can be moved somewhere

            // case 1 moving completely out
            if (currevent <= max(maxleftfree[i - 1], maxrtfree[i])) {
                // means pura event hi alag kar diye kahi aur laga diye changing
                // the order

                // ans will be sum of the 2 gaps+ event ka duration since vo
                // area ab free
                ans = max(ans, free[i - 1] + currevent + free[i]);
            }

            // case 2 event shifted to one side only(relative order same), in
            // such case part 1 wala kaam karo, 2 gaps ka addn will be the gap
            // that can be made, update ans iff isse accha ans aayega toh
            ans=max(ans,free[i-1]+free[i]);
        }

        return ans;
    }
};