class Solution {
public:
    typedef pair<char, int> pci;

    struct comp {
        bool operator()(const pci& a, const pci& b) const {
            // yaha smaller char pehle
            if (a.first < b.first)
                return false;
            if (a.first > b.first)
                return true;

            // we here means same char hai, agar bada idx is pehle, return true
            if (a.second > b.second)
                return false;
            return true;
        }
    };
    string clearStars(string s) {
        // ek pq le lenge, which will store the smallest char, alongwith its
        // index, 

        // custom comparator likh do since we need smallest char with biggest
        // idx at top
        priority_queue<pci, vector<pci>, comp> pq;
        int n = s.size();

        // vector bool lelo to indicate ki ye idx wala delete kiya hai
        vector<bool> del(n, false);

        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }

        // ab left se iterate karo s par star alag karo
        for (int i = 0; i <n; i++) {
            // agar current banda star hai toh
            if (s[i] == '*') {
                // smallest wala char nikalo which is to left of this star
                // ie idx<i

                // smallest char to the left of this star with biggest idx is at pq.top
                
                // remove kardo
                del[pq.top().second]=true;
                pq.pop();
            }
            else{
                // means normal char hai, add krdo pq me
                pq.push({s[i],i});
            }
        }

        // ab iterate karo del array par jo char removed hai usko count nai
        // karna, and baaki ka ans bana kar bhj do
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (del[i] || s[i] == '*')
                continue;

            ans += s[i];
        }

        return ans;
    }
};