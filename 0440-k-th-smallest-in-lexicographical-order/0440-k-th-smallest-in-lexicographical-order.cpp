class Solution {
public:
// the soln i referred to 
// https://youtu.be/pQ_BQ9J9p-c?si=4ZwB1khxW09R114d
    long long cnt(long long curr, long long next, long long n) {
        int currentcnt = 0;
        while (curr <= n) {
            currentcnt += (next - curr);
            // move deeper inside the current element
            curr *= 10;
            // next ko aage badhao, but theres 2 condns here
            // next*=10 or next=n+1
            // worst case curr=n, and next=n+1, iss case me bhi normal chalega

            // if next>n+1, means we are stepping out of bounds of the given
            // range of n, we cant do that, hence we have to make sure that the
            // 'next' variable stays in range, ie 'next' can be 2 values either
            // next*=10 OR n+1, dono me se jo minimum hoga vo lenge as the
            // 'next' value, since curr se next tak ke elements skip karne hai,
            // we cant mess with the 'next' value as that will mess with the
            // range(accd to me ig)
            // hence we set next as minm of (n*10,n+1)
            next = min(next * 10, n + 1);
        }
        // we out of loop means saare values that can be skipped frm 'curr' to
        // 'next' have been counted, now return the count
        return currentcnt;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1;
        // k-=1, since we start frm 1, ie we have counted 1 in our ans,need k-1
        // more nos
        while (k > 0) {
            long long valuecnt = cnt(curr, curr + 1, n);

            if (valuecnt <= k) {
                k -= valuecnt; // skipping the elements under surrent tree
                curr++;        // move to next subtree values stuff
            } else {
                // since we are moving inside the same tree(same tree me
                // neeche jaa rahe hai)
                // hence first count the current element, ie skip the current
                // element and move inside the tree
                k -= 1;
                // then move inside the tree
                curr *= 10;
            }
        }
        return curr;
    }
};