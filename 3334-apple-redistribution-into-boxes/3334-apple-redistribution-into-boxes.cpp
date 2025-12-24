class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // sort kardo boxes ko highest capacity first ke hisab se
        sort(capacity.begin(), capacity.end(), greater<int>());

        // tota kitne apples hai nikal lo
        int ttl = 0;
        for (auto it : apple) {
            ttl += it;
        }

        // ab distribute karte jao boxes me, sabse biggest capacity box filled
        // first since we need minm boxes
        
        // ans lelo count karte chalne 
        int ans=0;
        for (auto it : capacity) {
            ttl-=it;

            if(ttl<=0){
                return ans+1;
            }

            ans++;
        }

        return ans;
    }
};