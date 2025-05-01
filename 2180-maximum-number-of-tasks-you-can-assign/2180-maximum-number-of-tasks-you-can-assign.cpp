class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills,
               int strength, int mid) {
        // kitne pills use kar liya h
        int pillused = 0;

        // multiset lelo, usme top se sbse strongest mid workers daalo, since we
        // need to chk if mid no of tasks can be done, toh sbse strongest mid
        // workers uthayenge, since strongest worker can do more task
        multiset<int> st(workers.begin(), workers.begin() + mid);

        // ab mid no of easiest tasks uthana padega, toh start loop frm i=mid-1,
        // since task sorted already

        // yaha apan approach 1 laga rhe, ie use strongest worker on strongest
        // task an finish it
        for (int i = mid - 1; i >= 0; i--) {
            // current task is hardest(since task wala array is sorted), apan ne
            // mid jitne tasks uthaaye hai easiest waale, unn easiest tasks me
            // se hardest curr wala h

            // reqd strength is
            int req = tasks[i];
            // set sorted in ascending order toh strongest worker ke liye peeche
            // se first banda chahiye
            auto it = prev(st.end());
            // this is basically arr[n-1] but set me

            // kya ye strongest worker kar payega current task ko
            if (*it >= req) {
                // we here means kar lega in such case set se nikal do to
                // indicate that worker has done the task
                st.erase(it);
            }
            // nai hua?, kya pills use krke ho payega?
            else if (pillused >= pills) {
                // we here means pill khatam ho chuki hai, current wala banda
                // nai solve kar payega task solve, means we cant finish mid
                // tasks, hence return false
                return false;
            } else {
                // we here means pills use kar sakte hai apan

                // pill ab strongest ko thodi khilayenge, strong wala toh kar
                // lega pill leke, lekin phir weaker wala nai kar payega kuch
                // aage waale tasks ke liye and uss time uske paas pill bhi nai
                // hogi

                // toh yaha approach 2 lagao, which is

                // find the weakest banda which can do this task using pills

                // ab agar pill dedi toh req power needed=req-strength, ie itna
                // minm strength phir bhi lagega, itni power wala weakest banda
                // dhundo
                auto weakest = st.lower_bound(req - strength);

                if (weakest == st.end()) {
                    // means koi worker hi nai mila, in such case task cant be
                    // completed, means apan ne easiest mid tasks liye the usme
                    // se 1 task nai ho payega, means mid no of tasks cant be
                    // completed, in such case return false
                    return false;
                }

                // we here means mil gaya weakest worker jisko pill dene se ye
                // hard task ho jayega, toh in this case set se nikal do worker
                // ko to indicate that usne task kar diya hai
                st.erase(weakest);
                // also since we used a pill toh pillcnt++ krdo
                pillused++;
            }
        }

        // we here means mid no of tasks can be done, in such case return true
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0, r = min(n, m);
        // minm toh 0 tasks kar sakte h, maxm me maan lo workers=2, tasks=100,
        // maxm tasks done=2, and workers=100, tasks=2, maxm tasks done=2 again

        // hence minm lena padega tasks and workers ka for r

        // dono arrays ko sort kardo
        sort(tasks.begin(), tasks.end());
        // workers ko desc me sort krna since multiset me dalne me asani hogi
        sort(workers.begin(), workers.end(), greater<int>());

        int ans = 0;

        // binary search ka basic code
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // ab dekhenhe if we can do mid no of tasks

            if (check(tasks, workers, pills, strength, mid)) {
                // we here means we can do mid no of tasks, in such case ans
                // upadate karo and chk right side for bigger ans
                ans = mid;

                l = mid + 1;
            } else {
                // we here means we cant do mid no of tasks, in such case search
                // left side for possible ans
                r = mid - 1;
            }
        }

        return ans;
    }
};