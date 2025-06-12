class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest=INT_MIN;

        int mindist=INT_MAX;

        for(auto it:nums){
            if(abs(it)<=mindist){

                if(abs(it)==mindist){
                    closest=max(closest,it);
                }
                else{
                    closest=it;
                }
                mindist=abs(it);
            }
        }

        return closest;
    }
};