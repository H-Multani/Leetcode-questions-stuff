class Solution {
public:
    int maxDiff(int num) {
        // first maxm ke liye, first non-9 char ko 9 bana do
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
                curr[i] = '9';
            }
        }

        // maxm update karo
        maxm = stoi(curr);

        // minm cant be made 0

        curr=to_string(num);

        // 2 casse h,

        // case 1 agar pehla banda is 1, replace first non0, non1, digit to
        // 0, like 12340 hai toh 2 wale ko 0 kardo, isse chhota nai banega

        // case 2: first digit>1, replace with 1

        if (curr[0] == '1') {
            // replace first non-0,non-1 digit to 0
            int dgt = -1;
            for (auto it : curr) {
                if (it != '0' && it != '1') {
                    // get first non 0,non 1 digit
                    dgt = it - '0';
                    break;
                }
            }

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] - '0' == dgt) {
                    // maxm ke liye iss digit ko 9 bana do
                    curr[i] = '0';
                }
            }
        }
        else{
            // means koi aur digit hai, 1 bana do
            dgt=curr[0]-'0';

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] - '0' == dgt) {
                    // maxm ke liye iss digit ko 9 bana do
                    curr[i] = '1';
                }
            }
        }

        cout<<curr<<endl;

        int minm=stoi(curr);

        return maxm-minm;
    }
};