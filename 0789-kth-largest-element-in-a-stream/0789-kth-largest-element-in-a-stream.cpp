class KthLargest {
    vector<int> newnums;
    int knew;
    priority_queue<int,vector<int>,greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        // store the values in private variables
        newnums = nums;
        knew = k;

        // nai chal raha tha pichla wala, pq yahi bana lo

        // push values to a pq

        for (auto it : newnums) {
            if (pq.size() < knew)
                pq.push(it);
            else {
                // size=k hai
                // curr top se compare karo
                // if bigger, pop top element, and push current element in its
                // place
                if (pq.top() < it) {
                    // pop current top
                    pq.pop();
                    // add new element
                    pq.push(it);
                }
            }
        }
        // now k th biggest element will be at the top of the pq

    }

    int add(int val) {
        // use the private variables to access the vector and add the new val
        newnums.push_back(val);


        // compare val with top element of pq
        if(!pq.empty() && pq.size()==knew &&val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        else if(pq.empty() || pq.size()<knew){
            // agar emoty hai pq toh push kar do value ko
            pq.push(val);
        }
            // return val;
        return pq.top();



    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */