class Solution {
public:
    int scoreOfParentheses(string s) {
        // normal loop se kar sakte ig,

        // stack use kar sakte hai, lekin mai vector se kaam chala lunga
        vector<int> vec;
        // will act as a stack

        // score lelo ek kaam aayega
        int ans = 0;

        // loop thru the string
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // agar open bracket hai '(' toh jo score bana hai push kardo
                vec.push_back(ans);

                // ab ye apan ne purana wala score store karva liya abhi tak ka,
                // ab aage jitna banega uska alag se score nikalna padega

                // toh iss case ke liye score ko bhi 0 kardo
                ans = 0;
            } else {
                // we here means closing bracket hai pakka pakka

                // yaha 2 cases banenge, apan ek peeche wala dekhenge agar

                // case 1
                // peeche opening hua meaning current situation is like (), iss
                // case me 1 point milega
                if (s[i - 1] == '(') {
                    // peeche tak jitne points mile the utne honge hi, +1 point
                    // bhi hoga

                    // toh overall score is
                    ans = vec.back() + 1;
                } else {
                    // case 2
                    // peeche bhi closing bracket hai, meaning situation is like
                    // ...))..

                    // toh ye peeche wala toh solved hoga na already, and iska score already ans me hoga, toh uss score ko 2x kar dena hai seedha seedha as question said

                    // toh peeche wala tak ka score is already stored in ans, ab uss score ko double karna hai toh 2x hoga seedha

                    // new score is
                    ans=vec.back()+(ans*2);
                }

                // we here means sab score calaulate kar chuke hai 

                // ab pop back karna padega, since andar waale brackets ka score calculate kar liye hai, ab yaha se pop back karenge toh bahar wale brackets ke score milenge apan ko already stored in vec, unko bhi toh ans me include karna hai na

                vec.pop_back();
            }
        }

        return ans;
    }
};