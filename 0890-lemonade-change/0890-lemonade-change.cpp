class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // edge case
        if(bills[0]!=5) return false;

        unordered_map<int,int> mpp;
        mpp[bills[0]]++;

        int len=bills.size();

        for(int i=1;i<len;i++){
            // if arr[i] is 5 then no need for any change just increase freq
            if(bills[i]==5){
                mpp[bills[i]]++;
            }
            else if (bills[i]==10){
                // need to give 5 change
                // if 5 not present(freq=0) return false, since cant give change
                if(mpp[5]==0) return false;

                // else 5 present, just decrease 5 count and increase 10 count
                else{
                    mpp[5]--;
                    mpp[10]++;
                }
            }
            else{
                // arr[i]==20 here
                // need to give 15 change
                // try to give 10 and 5 first, if present dec 10 count and 5 count and increase 20 count
                if(mpp[5]!=0 && mpp[10]!=0){
                    mpp[10]--;
                    mpp[5]--;
                    mpp[20]++;
                }
                // else if 10 and 5 not present try to give 3->5 $ bills, dec 5 count 3 times,if dont have 3, 5$ bills return false
                else if(mpp[5]>=3){
                    mpp[5]--;
                    mpp[5]--;
                    mpp[5]--;
                }
                else return false;
            }
        }

        // if went thru the loop without problems, means no problems with cash occured so erturn true
        return true;


    }
};