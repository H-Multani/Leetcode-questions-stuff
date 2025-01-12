class Solution {
public:
    bool canBeValid(string s, string locked) {
        // basic case, agar odd length hai toh ans ban hi nai skta
        if (s.size() % 2 == 1)
            return false;

        // hint 2,3 follow karo, left to right jao
        int n = s.size();

        stack<int> open;
        stack<int> openclose;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                // means this can be set to open or close both, push to
                // openclose stack
                openclose.push(i);
            } else {
                // means curr wala locked hai, 2 cases, open and close hai
                // current wala
                if (s[i] == '(') {
                    // fixed and open bracket hai, open stack me daal do idx
                    open.push(i);
                } else {
                    // fixed and closed bracket hai, toh iske liye open braket
                    // dhundna hi padega mp choice

                    // some cases here

                    // agar stack me open bracket hai toh wahi se join karke
                    // nikal do
                    if (!open.empty()) {
                        // means stack me ek locked open bracket hai which can
                        // be used to make current bracket valid
                        open.pop();
                    } else if (!openclose.empty()) {
                        // means apan closest wala unlocked bracket ko use kar
                        // sakte hai to make sure current breacket is made valid
                        openclose.pop();
                    } else {
                        // we here means naa locked wala open bracket hai, na
                        // unlocked wala koi bracket hai, toh matlab ki iss
                        // closing bracket ke liye kahi se open bracket nai ban
                        // payega, in such case ans cannot be made, return false
                        return false;
                    }
                }
            }
        }

        // ab possible hai ki kuch locked open brackets ke liye close brackets
        // na mile ho, in such case unlocked wale brackets use karlo
        while(!open.empty() && !openclose.empty() &&
            open.top() < openclose.top()) {
            // means ki open.top() wale opening bracket ke liye openclose.top()
            // wala bracket ko closing bana denge, so that ye opening bracket
            // valid ban jaaye

            // need to make sure ki openclose.top>open.top wala bcoz otherwise
            // situaltion will be like )(, ye nai banana hai apan ko

            // basically we need to make sure ki closing bracket opening waale
            // bracket ke aage aaye so that valid bracket arrangement bane

            // yehi check kara rahe hai, and if we are here, means the current
            // opening bracket can be made valid using unlocked wala bracket,
            // bana do phir
            open.pop();
            openclose.pop();
        }

        // ab kaayede se open wala stack khali hona chahiye, indicating ki saare
        // opening ke liye closing mil chuka hai, lekin agar nai hai
        if (!open.empty()) {
            // we here means kuch opening locked brackets abhi bhi bache hai
            // which cannot be make valid, in such case ans nai ban payega, ie s
            // ko valid nai bana payenge, in such case return false
            return false;
        }

        // we here means saare opening ke liye closing mil gaua hai, in such
        // case s can be made valid, hence in such case, return true
        return true;
    }
};