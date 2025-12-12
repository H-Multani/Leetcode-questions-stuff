class Solution {
public:
    static bool comp(vector<string>& m1, vector<string>& m2) {
        int val1 = stoi(m1[1]);
        int val2 = stoi(m2[1]);

        // edge case agar banda same timestamp par offline jaa raha hai toh
        // message event se pehle saare offline wale process honge, like agar
        // timestamp 2 par 3 bande offline jaa rahe hai and message vent hora
        // hai toh pehle ye offline jayenge uske baad message event hoga
        if (val1 == val2) {

            // pehla offline then message, correct position
            if (m1[0] == "OFFLINE" && m2[0] == "MESSAGE")
                return true;
            // pehla offline then offline, correct position(posn doesnt matter)
            if (m1[0] == "OFFLINE" && m2[0] == "OFFLINE")
                return true;
            // pehla message then offline, wrong position, switch
            if (m1[0] == "MESSAGE" && m2[0] == "OFFLINE")
                return false;
        }

        // dono message wale hai toh yehi handle kar lega
        return val1 <= val2;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        // pehle toh timestamp ke hisab se sort kardo

        sort(events.begin(), events.end(), comp);

        // event print kara do
        // for (auto it : events) {
        //     cout << it[0] << " " << it[1] << " " << it[2] << endl;
        // }

        // cout << endl;

        // ab chalu karo ans banana
        vector<int> ans(n, 0);

        // ek map lelo which will store ki current id wala banda will be free on
        // which next timestamp
        unordered_map<int, int> mpp;

        // ab iterate karna chalu kardo
        for (auto event : events) {
            // agar current event is message type
            if (event[0] == "MESSAGE") {
                // means message type event

                // sabse pehle ALL aur HERE wala edge case banao
                if (event[2] == "ALL") {
                    // iss case me toh har id par ek mention count add kardo
                    // khatam
                    for (int i = 0; i < n; i++) {
                        ans[i]++;
                    }

                    // agle event par jao straight
                    continue;
                }
                if (event[2] == "HERE") {
                    // timestamp ke hisab se jo bhi banda online baitha hai usko
                    // count karlo
                    int val = stoi(event[1]);

                    for (int i = 0; i < n; i++) {
                        // agar map me nai hai means online hai
                        if (mpp.find(i) == mpp.end()) {
                            // count karlo
                            ans[i]++;
                        } else {
                            // means banda map me hai

                            // banda online kab aayega

                            // agar next online time current timestamp se neeche
                            // hai toh means banda iss current timestamp par
                            // online baitha hoga, in such case count badha
                            // dena, since online hai banda

                            if (mpp[i] <= val)
                                ans[i]++;
                        }
                    }

                    // agle event par jao
                    continue;
                }

                // we here means iterate karna padega ab

                // id banate chalo, iterate over the mentions_string
                int currid = 0;
                bool is_id = false;
                for (auto i : event[2]) {
                    // agar current wala is number toh add kardo
                    if (i >= '0' && i <= '9') {
                        currid = (currid * 10) + (i - '0');
                        is_id = true;
                    } else {
                        // we here means char hai, so its either characters " ",
                        //"i","d", ho sakta currid bani ho kuch

                        // agar id=0 hai toh dikkat dega, boolean variable lelo
                        // ek which will store if its an actual id or not since
                        // space ke baad currid=0 hogi fir char 'i' milega toh
                        // galat count na ho jaaye since id can be 0 also, and
                        // agar char space,i,d mile toh uss time toh currid=0
                        // hogi, toh galti se count na karle iss id wale bande
                        // ko tabhi boolean liya
                        if (is_id) {
                            // means id bani hai
                            // iss id par mention cnt raise kardo
                            ans[currid]++;
                        }

                        currid = 0;
                        // we here means ab reset karne ke baad new id nai ban
                        // rahi yaha toh is_id=false kar denge, and agar new id
                        // banna chalu hogi toh true kar denge, 
                        
                        // haal filhaal toh
                        // is_id=false, so that " " aane ke baad reset karne ke
                        // baad, "i"char aayega next agar toh galat count nai
                        // hoga id ka , similarly next char "d" aane par galat
                        // counting nai hogi id ki
                        is_id = false;
                    }
                }

                // one last time currid ko check karlo, since possible ki string
                // ends on last id
                if (is_id) {
                    // iss id par mention cnt raise kardo
                    ans[currid]++;
                }

            } else {
                // means offline type event, constraint dekho it is confirmed
                // that ye event tabhi hoga jab banda online ho

                // id se value nikalo
                string id = event[2];

                // ab string se id integer nikalo
                int val = stoi(id);
                int val2 = stoi(event[1]);

                // ye id wala ab next online tabhi aayega jab timestamp+60 ho
                // jaaye

                // map me daal do
                mpp[val] = val2 + 60;
                // update to newest latest online time for current id
                // cout << " id " << val << " next free at " << mpp[val] << endl;
                // cout<<"val2 "<<val2<<endl;
            }

            // har event ke baad print karo counting
            // for (auto it : ans) {
            //     cout << it << " ";
            // }
            // cout << endl;
        }

        return ans;
    }
};