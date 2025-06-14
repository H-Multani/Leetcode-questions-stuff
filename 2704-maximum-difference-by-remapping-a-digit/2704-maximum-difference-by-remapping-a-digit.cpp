class Solution {
public:
    int minMaxDifference(int num) {
        // maxm ke liye, first non-9 digit ko 9 bana do
        string curr = to_string(num);

        int dgt = -1;
        for (auto it : curr) {
            if (it != '9') {
                // get first non 9 digit
                dgt = it - '0';
                break;
            }
        }

        // agar dgt=-1 means saare 9 bhare hai, in such case replace 9 with 9
        // (note pt 2 makes this valid)
        if (dgt == -1)
            dgt = 9;

        int maxm;

        // replace this first non-9 digit with 9 and make new number
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] - '0' == dgt) {
                // maxm ke liye iss digit ko 9 bana do
                curr[i]='9';
            }
        }

        // maxm update karo
        maxm=stoi(curr);

        // ab maxm ban chuka h, minm banao

        // minm ke liye first non-0 digit ko 0 bana do
        curr=to_string(num);
        dgt=-1;
        for (auto it : curr) {
            if (it != '0') {
                // get first non 0 digit
                dgt = it - '0';
                break;
            }
        }

        // agar dgt=-1 means saare values 0 hai, in such case replace 0 with 0
        if(dgt==-1) dgt=0;

        int minm;

        // ab minm banao
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] - '0' == dgt) {
                // maxm ke liye iss digit ko 9 bana do
                curr[i]='0';
            }
        }

        // update minm
        minm=stoi(curr);
        

        return maxm-minm;
    }
};