class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucket sort

        // basic plan for bucket sort is its a bucket of elements with freq==i,
        // aage dekhna aayega samajh

        int n = nums.size();

        // freq nikal lo har value ka
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }

        // ab bucket banao
        // bucket of size n+1, since at max freq can be=n(all elements common)

        vector<vector<int>> bucket(n + 1);
        // yaha i=freq
        // bucket[i]={..}, vo elements jinka freq==i hai
        // toh bucket[3]={4,8,1} means ki elements 4,8,1 ka freq==3 hai nums me

        // and since idx already sorted hai, means arrays are sorted accd to freq already

        // element bhar do
        for(auto it:mpp){
            int element=it.first;
            int freq=it.second;
            bucket[freq].push_back(element);
        }

        // pick element frm right to left frm bucket since we need hightst freq
        vector<int> ans;
        for(int i=n;i>=0;i--){
            // current bucket empty h toh aage badho

            if(bucket[i].size()==0) continue;

            // bucket se element nikalte jao
            while(bucket[i].size()>0 && k>0){
                // element nikalo and add krdo
                ans.push_back(bucket[i].back());
                // ab last wala element bucket se nikal do
                bucket[i].pop_back();

                // k update krdena
                k--;
            }
        }

        return ans;
    }
};