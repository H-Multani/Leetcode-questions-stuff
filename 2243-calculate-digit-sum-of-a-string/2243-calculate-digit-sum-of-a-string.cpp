class Solution {
public:
    string digitSum(string s, int k) {
        // loop chala do new string bana do

        string ans = "";

        // edge case, agar start me s.size()<k hai toh s bhej do
        if (s.size() <= k)
            return s;

        // ttl leke chalna , har k bande par total nikal kar ans me daal dena

        while (s.size() > k) {

            int ttl = 0;
            ans = "";

            // iterate over the string
            for (int i = 0; i < s.size(); i++) {
                // agar i%k==(k-1) ban jaaye means start se k characters ka
                // digit sum le liye hai apan ne ans me daal kar aage badh jao

                if (i % k == (k - 1)) {
                    // current banda ttl me daal do
                    ttl += (s[i] - '0');

                    // ttl ko ans me daal do
                    ans += to_string(ttl);

                    cout << "added " << ttl << endl;

                    // ttl ko reset kar do agle k ke batch ke liye
                    ttl = 0;
                } else {
                    // we here means normal kahi par hai, k bande le rahe hai,
                    // in between wale stage par hai current bande ko ttl me
                    // include karo bass and aage badho
                    ttl += (s[i] - '0');
                }
            }

            // agar ttl!=0 means last wale bundle me k se kam bande the ans me
            // daal do and return krdo

            // edge case yaha aa sakta hai ki ttl is 0 lekin lena hai, ye case
            // tabhi chalega jab s%k!=0 means last wala dabba exact k size ka
            // hai,

            // basically if last wala dabba alag se nai aara(less than k size ka
            // ) toh nai add karna, otherwise jo bhi ttl hai add kardo ans me

            // basically apan ko k size ke dabbe nikal kar ans me daalne hai,
            // upar wale loop me saare exact k size wale daabe aa chuke hai
            // already , ab agar s.size%k!=0 hai means ek last dabba aayega
            // jiska size k se chhota hoga and uska bhi ans me daalna padega.
            // hence agar ye case fase toh ttl ko ans me daal do
            if (s.size() % k != 0) {
                ans += to_string(ttl);
            }

            // ab ans ka value s me daal do for next iteration
            s = ans;
        }

        return ans;
    }
};