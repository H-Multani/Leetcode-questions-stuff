class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // brute force chal gaya, ab thoda efficient sochte hai

        // hint padh liya h maine, toh vo bolra hai ki constraints boht chhote
        // hai, toh lets build an approach

        // apan ko basically saare possible 3 digit even nos bana kar count
        // karna hai aur vector me daalna hai

        // toh agar array is [1,1,2,3,3], toh brute force me apan ke paas valid
        // nos rahenge 132,312,112,332, lekin brute force me yehi exact nos apan
        // ko 2-3 baar milenge (jabki count apan 1 baar hi krre hai), toh game
        // ye hoga ki baar baar aa raha hai number lekin count ni hora hai toh
        // kya faayeda itna mehnat maarne ka(time waste)

        // isse better hai number nikalo aur chk karo banega ki nai , like if
        // array is [1,1,2,3,3] toh apan saare 3 digit even nos banane ka try
        // karenge, jo banega vo add kar denge seedha seedha, like
        // 100 cant be made(since 0 ka freq need=2, present freq of 0 in arr=0)
        // 102 cant be made(since 0 ka freq need=1, present freq of 0 in arr=0)
        // 104 cant be made...
        // 112 can be made, add to vector
        // 114 cant be made(1 ka freq nai hai arr me)
        // 116 cant be made...
        // 132 can be made, add to vector

        // aise saare count karenge apan jo banega seedha add krte jayenge

        // step 1 map me freq daal do digits ki, since no banane ke liye digits
        // lagenge
        unordered_map<int, int> mpp;
        // max size will be 10, since digits will be 0,1,2,3,4,5,6,7,8,9

        // runs O(n)
        for (auto it : digits)
            mpp[it]++;

        vector<int> ans;
        // ab 100 se chalu karke saare even nos nikalo 3 digit

        // runs O(450), since 100 se 1000 tak 3 digit even nos 450 hai bas
        for (int i = 100; i < 1000; i += 2) {
            // curr no is i
            int curr = i;

            // i ke saare digits ek separate map me daal do
            unordered_map<int, int> mp2;
            mp2[curr % 10]++;
            curr /= 10;
            mp2[curr % 10]++;
            curr /= 10;
            mp2[curr % 10]++;
            curr /= 10;

            // ab ye digits agar mpp me hai means ye number bana sakte hai chk
            // kro

            bool canbemade = true;
            // O(3) chalega at max since 3 digit no. hai
            for (auto it : mp2) {
                // i banane ke liye curr digit ka freq needed
                int need = it.second;
                int dgt = it.first;

                // agar atleast itni(need) freq hai digit ki mpp me means ye
                // number bana sakte hai

                if (mpp.find(dgt) == mpp.end() || mpp[dgt] < need) {
                    // we here means digits nai hai mpp me apne paas, apan ye
                    // number nai bana sakte hai
                    canbemade = false;
                }
            }

            // agar number nai bana sakte toh move to next number, otherwise add
            // to ans
            if (canbemade)
                ans.push_back(i);
        }

        // basically if mpp is like {2:1,3:2,4:1} and we need to make number
        // 344, toh mp2 will be {3:1,4:2}, toh apan ke paas mpp me 3 ka freq>=1
        // hai, 4 ka freq>=2 nai hai apne paas mpp me, ie digits kam hai apne
        // paas, toh 344 cant be made,since apan ko digit 4 ka freq>=2 chahiye
        // tha, apne paas 4 ka freq==1 hai, ie digits nai hai apne paas hence
        // number cant be made,similarly a number like 342 can be made since
        // saare digits available hai toh vo ans me add kar denge

        // aise chkk krenge saare nos ke saath bss

        return ans;
    }
};