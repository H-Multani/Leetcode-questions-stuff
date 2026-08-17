class Solution {
public:
    vector<int> pre;
    vector<vector<int>> memo;
    int solve(int l, int r) {

        // if l and r are same means last element par aa gaue hai, ye case me we
        // return 0
        if (l >= r)
            return 0;

        // memo me hai toh bhej do yehi se
        if (memo[l][r] != -1)
            return memo[l][r];

        // means ye [l,r] split karna hai apan ko

        // ab suppose [l..r] is {6,5,4,5}, toh yaha bas 3 places par split kar
        // sakte hai like
        // {6}{5,4,5}
        // {6,5}{4,5}
        // {6,5,4}{5}

        // bas aur koi chaara nai hai, hence split lagane ke liye loop yaha
        // chalega

        // best ans score nikal kar chalna
        int ans = 0;

        // lop frm l to r-1, maan ke chalo ki mid ke just baad hoga partition,
        // toh last element nai le sakte apan since r idx wale element ke rt me
        // hai hi nahi ek bhi element, hence r-1 tak me dekho
        for (int mid = l; mid <= r - 1; mid++) {
            // toh 2 part honge and
            // left to mid hoga left wala side, sum nikal lo
            // and since l can be 0, hence vo check alag se laga dena
            int leftsum = pre[mid] - ((l > 0) ? pre[l - 1] : 0);
            // mid+1 to right hoga rt wala side, sum nikal lo
            int rtsum = pre[r] - pre[mid];

            // ab jo bhi bigger part hoga vo alag kar denga
            if (leftsum > rtsum) {
                // means left wala part removed

                // alice ke score me rt wala part add hoga and usko aage explore
                // kar lenge apan, rt side ke liye range will be mid+1 to r
                ans = max(ans, rtsum + solve(mid + 1, r));
            } else if (rtsum > leftsum) {
                // means rt wala part removed

                // alice ke score me left wala part add hoga and usko aage
                // explore kar lenge apan, left side ke liye range will be l to
                // mid
                ans = max(ans, leftsum + solve(l, mid));
            } else {
                // means same sum aara, toh dono me part ko remove karne wale
                // paths explore kar lenge ans best le lenge

                ans = max(ans, rtsum + solve(mid + 1, r));
                ans = max(ans, leftsum + solve(l, mid));
            }
        }

        // overall jo bhi best ans aaye return kardo
        return memo[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        // mai overthink karra tha ki array {6,2,3,4,5,5}, can be split like
        // {6,5,4,5},{2,3}, turns out ye nai karna, like order has to be same so
        // split like {6,2},{3,4,5,5} is valid

        // simple hi hai fir toh simple prefix+DP

        // prefix bana lo to store sum of ranges
        int ttl = 0;
        for (auto it : stoneValue) {
            ttl += it;
            pre.push_back(ttl);
        }

        // ab pre[i]= sum of all elements from idx 0 to i(inclusive)

        // toh sum of range [l..r] is pre[r]-pre[l-1]

        int n = stoneValue.size();

        // funcn me bhej do, since original array has to be split between idx 0
        // to n-1

        // ab mereko pata hai TLE dega, 2 things change only, l and r both can
        // go n max, toh memo bana do

        memo.resize(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1);
    }
};