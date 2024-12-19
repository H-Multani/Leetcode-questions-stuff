class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        // currently i th idx par hai toh
        // 0 se i tak ka maxm
        vector<int> prefixmax(arr.begin(),arr.end());
        // i se n-1 tak ka minm
        vector<int> suffixmin(arr.begin(),arr.end());

        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixmin[i] = min(suffixmin[i + 1], arr[i]);
        }

        // ab chunks count kardo
        for (int i = 0; i < n; i++) {
            // currently i th wale par hai

            // 0 se leke i-1 tak ka minm nikalo
            int pehlekamax;
            if (i > 0)
                pehlekamax = prefixmax[i - 1];
            else
                pehlekamax = -1;

            // i se n-1 tak ka minm nikalo
            int baad_ka_minm = suffixmin[i];

            // now, if pehle ka max<baad ka minm, means that yaha par chunk
            // break karenge toh operation ke baad sorted milega

            // like in eg2 we split at [1,0] and [2,3,4], yaha i=2 par pehle ka
            // maxm=1 and baad ka minm=2, means pehle ka max<baad ka min, means
            // yaha chunk baat skte hai, toh baat diya (chunks=[1,0] and
            // [2,3,4])
            // [1,0] ko nai chhera ab,
            // but for [2,3,4], at i=1 par pehle ka maxm=2 and baad ka minm=3,
            // means pehle ka maxm<baad ka min, means baat sakte hai chunk, toh
            // baat diya (chunks=[2]and [3,4])

            // [2] ko nai chhera ab,
            // again for [3,4] at i=1 par pehle ka maxm=3 and baad ka minm=4,
            // means pehle ka max<baad ka minm, ie baat sakte hai chunk, toh
            // baat dia (chunks=[3] and [4])

            // [3] ko nai chhera ab,
            // again for [4] at i=0 par
            // pehle ka maxm=-1 and baad ka minm=4, means pehle ka max<baad ka
            // minm, ie baat sakte hai chunk, toh baat dia ([4])

            // total chunks = [1,0],[2],[3],[4], total 4 chunks

            // currently apan yehi situation chk kar rhe hai phir, agar i-1 tak
            // ka max < i se end tak ka minm, means chunks can be made here,
            // baat do chunks ko(ad increse chunk cnt)

            if(pehlekamax<baad_ka_minm) ans++;
        }

        // ab apne paas ans me maxm chunk cnt pada hai return kar do
        return ans;
    }
};