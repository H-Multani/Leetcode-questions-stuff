class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // we use a priority queue since it stores minm element at top
        // so we can just take the 2 top elements and perform the operation on
        // them, and then push the next element to the priority queue,
        // and it'll automatically be in the right position.
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int count = 0;
        // push all elements to the priority queue
        for (auto it : nums) {
            pq.push(it);
        }

        // loop and perform operation on the 2 top elements of the pq, add the
        // value to pq, loop until we get a top element that is bigger than or =
        // k we check only until we get top element>=k since, the top element of
        // pq is the smallest element of the whole priority queue, and if the smallest
        // element is greater than or = k, means the rest of the elements are
        // obviously greater than k
        while (pq.top() < k) {
            // store first top element in variable
            long long first = pq.top();
            // pop the top element
            pq.pop();

            // store second top element in variable
            long long second = pq.top();
            // pop the top element
            pq.pop();

            // perform the operation
            long long value = (min(first, second) * 2) + max(first, second);

            // push to the priority queue
            pq.push(value);
            // increase count
            count++;
        }

        return count;
    }
};