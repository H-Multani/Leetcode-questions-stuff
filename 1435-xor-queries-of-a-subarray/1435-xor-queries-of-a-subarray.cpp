class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // xor prop used a^a=0,
        // a^b=x, x^a=b, and x^b=a

        // prefix me XOR lete chalenge
        // like take xor of elements jaise chalte jaaye aage
        // xor ka array ban jaega=[1,2,6,14]
        // ab 1-> 1
        // ab 2-> 1^3
        // ab 6-> 1^3^4
        // ab 14->1^3^4^8

        // ab query boli ki 0 th se leke 1 idx wala toh apan kya karenge ki
        // return kr denge seedhe xor[1] as ans, since vo hoga 2, ie 1^3

        // else agar query be like [1,2], means 1 idx se leke 2 idx tk ka xor
        // krna hai ie need xor 3^4,
        // ab prefix waale ka 2 element uthaenge, xor[2]=6, and xor[1-1]=1,

        // xor[2]=> 1^3^4, and xor[0]=>1, dono ka xor lelo
        // we get 1^1^3^4=> 3^4, yehi mil gaya answer seedha seedha, push kar
        // dena


        // basically for query [a,b], we do xor[b]^xor[a-1], aur jo bhi aaega,
        // push kar denge ans me
        // agar a=0 hua toh, we send xor[b] as ans 

        // bade waale testcases par chala akr dekh lo, aa jaega samajh

        vector<int> xor1;
        int curr = 0;
        for (auto it : arr) {
            curr ^= it;
            xor1.push_back(curr);
        }
        vector<int> ans;
        for (auto it : queries) {
            int a = it[0];
            int b = it[1];
            if (a != 0)
                ans.push_back(xor1[b] ^ xor1[a - 1]);
            else 
                ans.push_back(xor1[b]);
        }

        return ans;
    }
};