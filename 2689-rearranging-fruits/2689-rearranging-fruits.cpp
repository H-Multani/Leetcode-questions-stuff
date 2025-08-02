class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // map lelo t store basket1 freq
        unordered_map<int, int> mpp;

        // end me apa ko minm element ka need padega nikal lo yehi
        int minm = INT_MAX;

        for (auto it : basket1) {
            mpp[it]++;
            minm = min(minm, it);
        }

        // ab basket2 par iterate karke remove kardo freq ko
        for (auto it : basket2) {
            mpp[it]--;
            minm = min(minm, it);
        }

        // ab apne pass map me vo freq hai jo extras hai thats all

        // ab vector lelo jisme final list rakhenge cost ka which need to be
        // swapped to other basket
        vector<int> swapped;

        // map me iterate karke nikal lo elements ko
        for (auto it : mpp) {
            int cost = it.first;
            int freq = abs(it.second);
            // abs value since freq can be -ve

            // agar freq is ever odd number means cant be split return -1 frm
            // here
            if (freq % 2 == 1)
                return -1;

            // agar freq=0 hai means cost is already equally spread among both
            // baskets no need to do anything,
            if (freq == 0)
                continue;

            // agar freq=4 means 'cost' wala item 6 baar aa raha hai extra in
            // one of the baskets, ab inn 6 elements ko 3-3 me split karna hai
            // second and 1st basket me, toh agar 6 elements 1st basket me hai
            // extra toh isme se 6/2=3 elements 2nd basket me jayenge and vise
            // versa

            // toh freq/2 jitne elements swap hoke jayenge next basket me

            // daal do swapped array me freq/2 jitne elements 'cost' waale, ye
            // saare current basket se agli wali basket me jayenge
            for (int i = 0; i < freq / 2; i++) {
                swapped.push_back(cost);
            }
        }

        // ab jitne elements hai swap hone waale sort karke likh do
        sort(swapped.begin(), swapped.end());

        // ab 2-2 ke pairs banao, and pair ke baad cost ke liye pair me se
        // min(first,second) wala banda hi overall cost me contribute karega
        // accd to question

        // that means if swapped.size=n hai toh first ke n/2 elements hi
        // contribute karenge overall cost me , toh loop n/2 tak ka chalao bas,
        // since aage walo ka access useless hai
        int n = swapped.size();
        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            // ab i th banda will contribute for the overall cost

            // 2 cases,

            // case1: direct swap, in such case swapped[i] wala bande ka cost
            // seedha seedha lagega overall ans me, since we will directly swap
            // the biggest element to be sent to other basket frm swapped array
            // and swap that element with this current smallest element
            // incurring the overall cost of swapped[i]

            // like swap(a,b), toh min(a,b) cost incur hoga

            // case 2: indic=rect swapping, like we need to swap (a,b) suppose,
            // lekin swap karenge toh minm ab bhi bada hai direct wal like
            // a=5,b=10, toh min(a,b)=5 cost aayega, lekin minm element=1
            // suppose

            // ye minm element can be in both baskets, apan ko bas indirect
            // swapping karni hai, like instead of swap(a,b) we do swap(a,minm)
            // then swap(minm,b), toh by this we are doing swap(a,b) overall,but
            // in this case we only incurr the cost
            // swap(a,minm)+swap(b,minm)=1+1=2, which is much better than direct
            // swap

            // toh case 1-> 1 step direct swap
            // and case 2-> 2 step indirect swap

            // dono me se jo bhi minm hoga vo apan ans ke liye consider kar
            // lenge

            // case1 me cost incurr hogi swapped[i]
            // case2 me cost incurr hogi 2*minm, since 2 swap krre hai jisme
            // minm will be counted twice

            ans += min(swapped[i], minm * 2);
        }

        return ans;
    }
};