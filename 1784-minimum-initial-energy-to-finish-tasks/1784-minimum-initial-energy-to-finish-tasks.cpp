class Solution {
public:
    static bool comp(vector<int>& a1, vector<int>& a2) {
        // jo task ka difference zyada hai usko pehle rakho

        return (a1[1]-a1[0])>(a2[1]-a2[0]);
    }

    bool solve(int ttl, vector<vector<int>>& tasks) {
        // nikalo loop chala kar

        for (auto it : tasks) {
            if (it[1] - ttl > 0)
                return false;

            ttl -= it[0];
            // cout << ttl << " ";
        }

        // cout << endl;
        // cout << endl;

        // we here means ho jayega tasks saare, in such case return true
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        // ok toh ye kar sakte ki heaviest reqt wala item pehle karlo, so that
        // easier reqt walo ke liye energy rahe apan ke paas

        // tasks ko sort karna padega accd to descedning order of task[i][1], it
        // second element ke hisab se

        // this doesnt work... since eg2 dekho, 32 par saare tasks hone ke baad
        // bhi last task [1,3] me energy hai mere paas 2 lekin reqt 3 hone ke
        // wajah se nai kar paa raha

        // another approach, jo task difficult hai usko pehle
        // karo, difficult means minm reqt and actual reqt me diff zyada hai,
        // toh jis tasks me minm and actual ka diff zyada hai unko pehle karna
        // padega, so that aage walo ke liye energy rahe spare me

        // iss approach ka fayeda ye hai ki jis task ka difference zyada hai
        // meaning actual me kam energy lagega lekin reqt zyada hai vo tasks
        // pehle honge, jiska fayeda ye hai ki end me vahi tasks rahenge jinka
        // actual requirement is not very farr from minm reqt
        sort(tasks.begin(), tasks.end(), comp);

        // ab sorting ho gayi, ab apan binary search on ans laga kar check kar
        // sakte hai

        // minm energy reqd is 0, and maxm energy reqd will be sum of all minm
        // energies+1, since worst case me sab apni apni energy leke chalenge
        // and apne tasks finish karke aage badhenge, saving par koi focus nai
        // rahega

        int l = 0, r = 0;

        for (auto it : tasks) {
            r += it[1];
        }

        r++;

        int ans = r;

        // binary search chala do

        // cout << l << " " << r << endl;

        while (l <= r) {
            // mid nikalo
            int mid = l + ((r - l) / 2);

            // cout << "mid " << mid << endl;

            // ab mid se start karke kya apan saare tasks finish kar paenge?

            if (solve(mid, tasks)) {
                // means iss minm se tasks ho jaenge saare, in such case, update
                // ans

                ans = mid;

                // cout << "ans is " << mid << endl;

                // search left for better ans
                r = mid - 1;
            } else {
                // means nai kar paenge saare tasks solve, search right for
                // possible ans
                l = mid + 1;
            }

            // cout << endl;
        }

        return ans;
    }
};