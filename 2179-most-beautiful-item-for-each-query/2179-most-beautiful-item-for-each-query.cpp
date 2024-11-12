class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans;

        // simple binary search
        // sort the items accd to price
        sort(items.begin(), items.end());

        // possible hai ki price kam ho lekin beauty zyada ho, iss case ko
        // handle krne ke liye sorted list me leke chalo ki iss idx tak maxm
        // beauty ye mili hai, and is beauty ka price <=current bande ka price
        vector<int> beauty;

        // index 0 tak beauty is first element ki beauty
        beauty.push_back(items[0][1]);

        for (int i = 1; i < items.size(); i++) {
            // iss index tak maxm beautyis
            int maxm = max(beauty[i - 1], items[i][1]);

            beauty.push_back(maxm);
        }

        // har query par iterate krke ans nikalo
        for (auto it : queries) {
            // current query is it

            // need price <=
            int reqdprice = it;

            // lagao binary search
            int result = -1;
            // result stores index of reqd price
            int l = 0, r = items.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (items[mid][0] <= reqdprice) {
                    // means current item ka price reqd se less than or = hai
                    // possible ans
                    result = mid;
                    // to find maxm beauty, go right, since valid price mil
                    // chuka hai, ab maxm beauty chahiye
                    l = mid + 1;
                } else {
                    // possible ans not found, check left side
                    r = mid - 1;
                }
            }
            // iss result price tak jo bhi maxm beauty wala mila hai ans me push
            // krdo

            // agar -1 hai result means ans nai mila in such case push 0
            if (result == -1) {
                ans.push_back(0);
            } else
                ans.push_back(beauty[result]);
        }

        return ans;
    }
};