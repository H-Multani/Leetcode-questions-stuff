class Solution {
public:
int n;
    bool check(int p,int q,vector<int>& nums){

        // 0 to p is increasing???
        for(int i=1;i<=p;i++){
            if(nums[i-1]>=nums[i]){
                // we here means 0 to p is not increasing
                return false;
            }
        }
        // p to q is decreasing???
        for(int i=p+1;i<=q;i++){
            if(nums[i-1]<=nums[i]){
                // we here means p to q is not decreasing
                return false;
            }
        }
        // q to n-1 is increasing???
        for(int i=q+1;i<=n-1;i++){
            if(nums[i-1]>=nums[i]){
                // we here means q to n-1 is not increasing
                return false;
            }
        }

        cout<<"hre "<<p<<" "<<q<<endl;
        // teeno me se nai fata koi means all good
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        n=nums.size();

        // loop ke ye constrains since 0<p<q<n-1 needed, vahi kiya h bs
        for(int p=1;p<n;p++){

            for(int q=p+1;q<n-1;q++){
                if(check(p,q,nums)){
                    return true;
                }
            }
        }

        return false;
    }
};