class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        priority_queue<int> maxheap;
        // to store farthest endings
        priority_queue<int, vector<int>, greater<int>> past;
        // past endings of queries

        // sort the queres based on starting
        sort(queries.begin(), queries.end());

        int j = 0;
        // pointing to queries

        int used = 0;
        // counting no of queries already used

        for (int i = 0; i < n; i++) {
            // jis query par khade h abhi, kya uska starting impact karega idx i
            // wale bande ko
            while (j < q && queries[j][0] == i) {
                // in such case max heap me daal do ending ko iss query ki
                maxheap.push(queries[j][1]);
                // by this the most impacting wala query top par aa jayega

                // go to next query
                j++;
            }

            // first chk if we can inmpact current i from past queries endings
            nums[i] -= past.size();

            // agar isse nums[i]>0 bacha, means aur queries lagengi iss i th
            // bande ko 0 karne ke liye
            while (nums[i] > 0 && !maxheap.empty() && maxheap.top() >= i) {
                // means we will need more queries, maxheap se top wali nikal
                // lo, since that will be most impactful

                int ending = maxheap.top();

                // ab ending mil gayi h , isko maxheap se pop kardo
                maxheap.pop();

                // ab we have used 1 query to settle nums[i] toh usedcnt++
                used++;

                // ab is ending ko past wale pq me push kardo, since ho sakta
                // hai current ending future me koi aur ending ko settle krne me
                // kaam aa jaaye
                past.push(ending);

                // ab since nums[i] par impact hua h iss query ka ie -1 hua hai,
                // toh nums[i]-- karna mat bhulna
                nums[i]--;
            }

            // iske baad bhi agar nums[i]>0 means heap khatam ho gaya lekin
            // nums[i]==0 nai ho paya, toh matlab nums[i] cannot be made 0
            // anynmore since iske aage wali queries will not include idx i wala
            // element

            // which means jitni queries i ko accomodate krri thi vo nums[i] ko
            // 0 nai pahucha paayi, means zero array cant be made, return -1
            if (nums[i] > 0)
                return -1;

            // clr out past indices which are outdated, matlab jo i se pehle end
            // hore the unko alag kardo
            while (!past.empty() && past.top() <= i)
                past.pop();
        }

        return q - used;
    }
};