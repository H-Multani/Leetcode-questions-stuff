class Solution {
public:
    // segment tree update karne ka funcn
    void updatetree(int i, int l, int r, int idx, vector<long long>& segtree) {
        if (l == r) {
            // means we are at leaf node, visited mark karod
            segtree[i] = 1;
            return;
        }

        // nai mila toh dhundo kis side hai idx
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            // means search left side

            // left side me idx (2*i)+1 hoga
            // l se mid tk me dhundenge
            updatetree((2 * i) + 1, l, mid, idx, segtree);
        } else {
            // means rt side search karo
            // left side me idx (2*i)+2 hoga
            // mid+1 se r tk me dhundenge
            updatetree((2 * i) + 2, mid + 1, r, idx, segtree);
        }

        // explore krne ke baad current node ko update kardena
        // current ka value will be left child ka value+rt child ka value
        segtree[i]=segtree[(2*i)+1]+segtree[(2*i)+2];


    }

    // segment tree me query karne ka funcn
    long long querytree(int querystart,int queryend, int i,int l, int r, vector<long long>& segtree){
        // if out of bound return 0
        if(r<querystart ||l>queryend){
            return 0;
        }

        if(l>=querystart && r<=queryend){
            // means node exactly query ke andar hai
            // node ka value return krdo
            return segtree[i];
        }

        int mid=l+(r-l)/2;

        long long left=querytree(querystart,queryend,2*i+1,l,mid,segtree);
        long long right=querytree(querystart,queryend,2*i+2,mid+1,r,segtree);

        return left+right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        // store ki nums2 ka har banda konse idx par hai
        unordered_map<int, int> mpp;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            mpp[nums2[i]] = i;
        }

        // segment tree
        vector<long long> segmenttree(4 * n);

        long long ans = 0;

        // since we start frm idx=1, toh idx 0 wala element update kardo

        // values sent= tree ka starting ka idx, root node represent 0 to
        // n-1 (tbhi 2 values 0 and n-1),the element we have updated(nums1 ke 0
        // th idx par jo bhi element hai uska idx in nums2), the segment tree
        updatetree(0, 0, n - 1, mpp[nums1[0]], segmenttree);

        for (int i = 1; i < n; i++) {
            // current bande ka idx nikal lo nums2 me
            int idx = mpp[nums1[i]];

            // left side me kitne elements hai unka count

            // querytree ka funcn likho, we send ->0 query start, idx query
            // end,root ka idx 0, that root represents 0 to n-1(hence 0 and
            // n-1),then the segment tree
            long long leftcommoncnt =
                querytree(0, idx, 0, 0, n - 1, segmenttree);
            long long leftnotcommoncnt = i - leftcommoncnt;

            long long elements_after_idx_in_nums2 = n - 1 - idx;

            long long rtcommoncnt =
                elements_after_idx_in_nums2 - leftnotcommoncnt;

            ans += leftcommoncnt * rtcommoncnt;

            // abhi i th element ko dekha hai toh update kar dena tree ko
            updatetree(0, 0, n - 1, idx, segmenttree);
        }

        return ans;
    }
};