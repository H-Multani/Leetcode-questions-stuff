class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        // base case, agar k==1 hai, toh "a" return krdena
        if (k == 1)
            return 'a';

        int n = op.size();

        // length of current word nikal lo
        long long len = 1;

        // naya wala k nikal lo
        long long newk = -1;

        // operation type store karlo, konsa wala operation hai
        int operationtype = -1;

        // loop chalao har query par dhundne ke liye
        for (int i = 0; i < n; i++) {
            // har operation ke liye length*=2 hogi
            // update krdo length ko
            len *= 2;

            if (len >= k) {
                // means mere ko k th char mil sakta hai, no need to make
                // further string

                // current jo bhi operation kiya tha store karlo
                operationtype = op[i];

                // new wala k nikal lo, recursion me jo bhejenge
                newk = k - (len / 2);

                // new wala k nikal lene ke baad ab yaha se break kardo, since
                // boht length mil gai hai, break krdo yehi se
                break;
            }
        }

        // ab recursive call karo, aur iss baari newk wale char ko nikal kar le
        // aana
        char ch = kthCharacter(newk, op);

        // ab ye char nikal jaega apna

        // ab jo isss char par operation hona tha kar denge

        if (operationtype == 0) {
            // means jo char nikala hai vahi seedha seedha jayega, since
            // operation 0 me apan same string ko append karre the
            return ch;
        }

        // we here means operation=1 raha hoga pakka, in such case apan ch+1
        // wala char bhejenge, since operation 1 me apan char+1 karne ke baad
        // add karre the

        // toh yaha par agar ch wala char mila hai, and operation=1 hai, means
        // ki ye char ko pakka char+1 karke append kiya hoga, tabhi ch+1 bhej
        // raha

        // edge case, agar ch=='z' hua toh 'a' return karenge, else ch+1 return karenge
        if(ch=='z') return 'a';
        

        return ch+1;
    }
};