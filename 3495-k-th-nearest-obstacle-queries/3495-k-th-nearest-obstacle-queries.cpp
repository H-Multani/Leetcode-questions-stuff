class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for(auto it:queries){
            int dist=abs(it[0])+abs(it[1]);
            // if((it[0]<0 && it[1]>0) || (it[1]<0 && it[0]>0)) dist=abs(it[0])+abs(it[1])+1;
            // else dist=;
            pq.push(dist);
            cout<<pq.top()<<endl;
            if(pq.size()<k) ans.push_back(-1);
            else if(pq.size()==k) ans.push_back(pq.top());
            else{
                pq.pop();
                ans.push_back(pq.top());
            }
        }
        return ans;

    }
};