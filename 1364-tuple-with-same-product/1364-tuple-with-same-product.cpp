class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // brute force nai chalne wala obv, tle phek rha

        // pt1: noticed smth har possible (a,b,c,d) se 8 possible pairs ban
        // sakte hai
        // pt2: hint 2 se dekha thoda, toh uspr build kiya approach apna

        // yehi 2 pts se bana rha mai approach, consider (a,b,c,d) where
        // a*b==c*d==12, toh agar hum har 2 elements ka product store karenge
        // toh 12 ke liye apne paas 2 pairs honge (a,b) and (c,d), no chance
        // that a,b,c,d have common stuff like pairs become like (a,b) and
        // (a,d), not possible since all values off array are distinct and
        // possible nai hai ki (a,b) and (a,d) ek pair ho unless b==d(which is
        // also not possible, since distinct element lene hai)

        // so for product 12 we have freq 2 ie apne paas 2 pairs hai,(jinke
        // obviously a,b,c,d alag alag hai) ab iss 2 pairs se 8 valid tuples ban
        // sakte hai, which are->
        // (a,b,c,d),(a,b,d,c),(b,a,c,d),(b,a,d,c),
        // (c,d,a,b),(c,d,b,a),(d,c,a,b),(d,c,b,a)

        // all in all har 2 pairs se apan 8 tuples bana sakte hai

        // for odd number of freq, lets say we have 5 as freq, toh means we have
        // 5 pairs of elements, like 1:(a,b),2:(c,d),3:(e,f),4:(g,h),5:(i,j),
        // here a*b=c*d=e*f=g*h=i*j

        // toh total possible tuples pairs(tuple banane wale pairs, each pair
        // has 4 elements) will be 10, like
        // {(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5)}, where
        // (1,4)=>(a,b,g,h), and so onn
        // toh overall count of possible tuples= 8*10=80 possible valid tuples,
        // yehi logic banana hai

        // similarly for even no of freq we have eg freq=4, tuple pairs will be
        // {(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)}, total 6 valid tuple pairs,
        // hence total no of tuples possible= 6*8=48, ans

        // yehi logic lagana hai

        // first get the products and frequencies
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i != j) {
                    // means i and j are different elements, product nikalo and
                    // freq update karo
                    mpp[nums[i] * nums[j]]++;
                }
            }
        }

        // ab apne paas all possible products and frequencies hai

        int ans = 0;

        for (auto it : mpp) {
            // cout<<it.first<<" "<<it.second<<endl;
            int freq = it.second;

            // current product ke liye frequency is freq

            // ab iss frequency ke hisaab se tuple pairs count karo
            int tuplepairs = 0;

            // if(freq%2==0){
            //     // even number of pairs , toh tuple pairs will be x(x-1)/2

            //     // if freq=4, no of tuple pairs=4*3/2=6
            //     // if freq=6, no of tuple pairs=6*5/2=15
            //     tuplepairs=freq*(freq-1)/2;
            // }
            // else{
            //     // odd number of pairs , toh tuple pairs will be x(x-1)/2

            //     // if freq=5, no of tuple pairs=4*5/2=10
            //     // if freq=7, no of tuple pairs=6*7/2=21
            //     tuplepairs=freq*(freq-1)/2;
            // }
            // jab dono case me ek formula hi lagra hai, toh alag alag kyu
            // likhna
            tuplepairs = freq * (freq - 1) / 2;

            // ans me update krdo, har tuple pairs ke liye 8 valid tuples, toh
            // ans updated like

            ans+=8*(tuplepairs);
        }

        return ans;
    }
};