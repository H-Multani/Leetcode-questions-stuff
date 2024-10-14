class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // saare heap me push krdo
        // top wala nikal kar add karo ans me then update karke vapas push krdo
        // heap me, do this k times and return ans

        priority_queue<long long> pq;
        for(auto it:nums){
            pq.push(it);
        }

        long long ans=0;
        while(k--){
            int curr=pq.top();
            pq.pop();
            ans+=curr;
            if(curr%3==0){
                curr/=3;
            }
            else{
                curr/=3;
                curr++;
            }

            pq.push(curr);
        }

        return ans;
    }
};