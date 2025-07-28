class Solution {
    map<long long, long long> mpp;

public:
    void calculate(int i, vector<int> arr, long long subset) {
        if (i >= arr.size()) {
            // means bana chuke subset
            // map me update kr do
            mpp[subset]++;
            return;
        }

        // simple take/not take approach
        // not take
        // jo subset OR yaha tk bana tha vahi aage bhej do
        calculate(i + 1, arr, subset);
        // take
        // subset OR me current wala banda include karke bhejo
        calculate(i + 1, arr, subset | arr[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // cosntraints too small
        // brute force laga sakte

        // map bana do
        // saare subsets bana kar sabka bitwise OR nikal lo
        // end me ye bitwise OR map me push kar do, ki ye bitiwse orr wale kitne
        // subset mile hai
        // end me maximum bitwise or ka freq bhj dena
        mpp.clear();

        // funcn call karo, initially saare bits 0 bhejo since bitwise OR
        // karenge toh aopne aap settle hota jaega
        calculate(0, nums, 0);
        // maxm wala subset value ka freq nikalo
        long long maxm;
        for (auto it : mpp) {
            // apan map use kar rahe hai, last element is the reqd element with maxm freq
            maxm=it.first;
            cout << it.first << " " << it.second << endl;
        }
        cout << "maxm is " << maxm << endl;
        // return maxm key ka value, since apan ko need tha uss OR ka jo maxm
        // subsets me aa raha, aur freq chahiye thi ki kitne subsets ka same OR
        // hai
        return mpp[maxm];
    }
};