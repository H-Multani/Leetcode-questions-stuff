class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // maxm and minm ka index nikal lo
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        // cout << mini << " " << maxi << endl;
        int n = nums.size();
        int ans = n + 1;

        // ok toh yaha 3 cases ho sakte hai

        // case 1-> saare elements front side se nikal lo, uss case me we need
        // to take out max(mini+1,maxi+1) jitne elements

        // since maan lo min is at idx 5 and max is at idx 7, toh left se 8
        // elements nikalne padenge so that both min and max remove ho sake
        ans = min(ans, max(mini + 1, maxi + 1));
        // cout<<"ans is "<<ans<<endl;

        // similarly
        // case 2-> saare elements back side se nikal lo, uss case me we need to
        // take out max(n-mini,n-maxi) jitne elements

        // since maan lo min is at idx 5 and max is at idx 7, and n is 10, toh
        // right se 5 elements nikalne padenge so that both min and max remove
        // ho sake
        ans = min(ans, max(n - mini, n - maxi));
        // cout<<"ans is "<<ans<<endl;

        // case 3-> mini wala right se nikal liye, maxi wala left se nikal liye,
        // and iska vice versa

        // mini wala element dono me se minm wale side se nikala toh its
        // min(mini+1,n-mini)
        // maxi wala element dono me se minm wale side se nikala toh its
        // min(maxi+1,n-maxi)

        ans=min(ans,min(mini+1,n-mini)+min(maxi+1,n-maxi));
        // cout<<"ans is "<<ans<<endl;

        return ans;
    }
};