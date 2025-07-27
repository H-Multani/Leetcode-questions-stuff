class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // har bande ke liye chk krna ia beginning to be too much , having to
        // check again and again for each banda, and storing each posible pair
        // of hills and valleys, not to mention ek banda can be part of valley
        // nearby as well as a hill looking further indexes

        // toh sbse best hai adjacent alag kardo alag nums banao
        vector<int> nodupe;
        nodupe.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nodupe.back() != nums[i]) {
                nodupe.push_back(nums[i]);
            }
        }

        // for (auto it : nodupe) {
        //     cout << it << " ";
        // }
        // cout << endl;

        // ab apan ke paas duplicated elements alag ho gaye hai, ab bas har
        // element ke liye chk karo if its part of hill or valley thats all

        // check karne se no good, still counting too many hills and valleys,
        // elements ko draw karo heights leke, toh jaha jaha changes dikh rahe
        // hai ki yaha tak decreasing hora thaa ab increasing hai, us change ko
        // count karo

        // like for 2 4 1 6 5 , 2 to 4 is increasing, then 4 to 1 is decreasing,
        // means direction change, means 1 hill hai cnt krlo nd so onn

        int cnt = 0;
        int n = nodupe.size();
        bool increasing = true;

        // agar start wala decreasing hai toh false kardo otherwise incresing
        // rehen do

        // edge case
        if(n==1) return 0;

        if (nodupe[0] > nodupe[1])
            increasing = false;
        cout<<increasing<<endl;
        for (int i = 1; i < n; i++) {

            // sirf current and prev element ko dekhenge apan

            if (nodupe[i] > nodupe[i - 1] && increasing) {
                // means pehle bhi increasing hi tha, abhi bhi increasing hai,
                // nothing to be added here, no hill aur valley found, continue
                continue;
            }
                // cout<<"here"<<endl;
            if (nodupe[i-1] > nodupe[i] && increasing==false) {
                // means pehle bhi decreasing hi tha, abhi bhi decreasing hai,
                // nothing to be added here, no hill aur valley found, continue
                // cout<<"here"<<endl;
                continue;
            }

            // we here means direction change hui hai, toh cnt karlo and boolean
            // value ko T->F and vice versa kardo
            // cout<<i<<" ";
            cnt++;
            if(increasing) increasing=false;
            else increasing=true;
        }

        return cnt;
    }
};