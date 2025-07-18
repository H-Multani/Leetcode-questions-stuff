class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // code banao
        int N = nums.size();
        int n = N / 3;

        // left se n smallest elements ka sum store karo
        vector<long long> leftminsum(N, -1);
        // sum maintain krne vaaste variable
        long long sm = 0;

        // ab nums me se n smallest elements nikalne hai left vaaste, toh at
        // best case apan 0 se 2n-1 idx tak se elements le sakte hai, since
        // bache hue n elements will be needed for right side(in worse case)

        // toh -1 indicates ki yaha par se nai le sakte elements
        // leftminsum[i] batayega ki 0 se i wale idx tak minm n elements ke sum
        // kya honge
        // max heap lelo which will store the minm n elements
        priority_queue<long long> pq1;
        for (int i = 0; i <= (2 * n) - 1; i++) {
            // sum me current elemet ko include kardo
            sm += nums[i];
            // pq me bhi daal do
            pq1.push(nums[i]);

            // lekin apan ko minm n elements ka sum chahiye na, toh agar pq me
            // >n elements hue toh sum se alag karna padega alag kar dena
            if (pq1.size() > n) {
                // top wala element nikal kar sum se alag kardo
                sm -= pq1.top();
                pq1.pop();
            }

            // we here means apan ke paas minm n elements ka sum hai

            // sum update kardo
            leftminsum[i] = sm;
        }

        // ab same cheez lekin right side me maxm n elements nikalo
        vector<long long> rightmaxsum(N, -1);
        sm = 0;
        // ab right me se maxm n elemnts ka sum nikalna hai, toh we chk frm 3n-1
        // idx upto n idx, since start se n elements will be needed for left
        // side wala sum

        // heap lelo yaha bhi lekin since maxm elements chahiye, toh min heap
        // lo, so that minm element ko jaldi nikal pao

        // same thing as above basically
        // rightmaxsum[i] indicates ki idx=i se end(3n-1) tak me maxm n elments
        // ka sum kya hai
        priority_queue<long long, vector<long long>, greater<long long>> pq2;
        // toh here we start frm idx=3n-1, upto idx=n
        for (int i = (3 * n) - 1; i >= n; i--) {
            // curr bande ko include karo
            sm += nums[i];
            pq2.push(nums[i]);

            if (pq2.size() > n) {
                // remove kardo smallest element sum se and pq se
                sm -= pq2.top();
                pq2.pop();
            }

            // sum update kardo arr me
            rightmaxsum[i] = sm;
        }

        // ab apan ke paas hai
        // leftminsum[i] which tells ki 0 se i tkk ka minm n elements ka sum kya
        // hai, and
        // rightmaxsum[i] which tells ki i se end tkk ka maxm n elements ka sum
        // kya hai,

        // dono me i th wala banda included hai

        // ab overall nikalo
        long long ans = LLONG_MAX;
        for (int i = 0; i < N - 1; i++) {
            // we need to minimize the left-right value

            // toh 0 se i tak ka minm left value nikalenge and i+1 se end tkk ka
            // maxm right value nikalenge and dono ka diff kar denge

            // 0 to i then i+1 to end since, agar i tkk le liya, its possible ki
            // same element is used for maxm sum and minm sum making ans wrong

            // agar invalid hai toh skip krdo
            if (rightmaxsum[i + 1] == -1)
                continue;
            if (leftminsum[i] == -1) {
                // we here means ab left se sum nai milne wala, break kar jao
                // aage chk mat karo
                break;
            }

            // nai toh left se i tkk k minm nikalo, and i+1 se end tkk ka maxm
            // nikalo and subtract krdo, which might be ans
            ans=min(ans,leftminsum[i]-rightmaxsum[i+1]);
        }

        return ans;
    }
};