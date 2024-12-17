class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // freq nikal lo pehle toh
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }

        // saare char alongwith freq store krdo pq me, largest char element at
        // top
        priority_queue<pair<char, int>> pq;
        for (auto it : mpp) {
            pq.push({it.first, it.second});
        }

        // ab loop chalao jab tak ans na bane
        string ans = "";

        while (true) {
            // agar pq is empty, get out of the loop
            if (pq.empty())
                break;

            // pq ke top par sbse bada char hoga nikalo usko
            auto curr = pq.top();
            pq.pop();

            char currchar = curr.first;
            int freq = curr.second;

            // repeat limit jitne char se kam freq hai toh puri laga do
            if (freq <= repeatLimit) {
                // ans me daal do characters
                for (int i = 0; i < freq; i++) {
                    ans += currchar;
                }

                // move onto the next char in pq
                continue;
            } else {
                // means repeat limit se zyada characters hai, repeat limit
                // jitne characters daal do

                for (int i = 0; i < repeatLimit; i++) {
                    ans += currchar;
                }
                // freq update kardo
                freq -= repeatLimit;

                // ab iske aage currchar nai laga sakte hai since repeatLimit
                // cross kar liye hai

                // next lexicographic biggest character nikalo and ek lagao
                // atleast so that we can reset the count for currchar

                // agar next biggest lexicographic char nai hai, toh means apan
                // aage string nai bana sakte aur, in such case break frm the
                // loop
                if (pq.empty())
                    break;

                // next lexicographic biggest is
                auto nextbiggest = pq.top();
                pq.pop();

                // iss 2nd biggest waale ka 1 char daalo
                int secondfreq = nextbiggest.second;
                char secondchar = nextbiggest.first;

                if (secondfreq > 1) {
                    // 1 char ans me daal kar vapas pq me push kardo isko with
                    // bachi kuchi freq
                    ans += secondchar;
                    secondfreq--;
                    pq.push({secondchar, secondfreq});
                } else {
                    // means 1 char bacha hai bas, laga do ans me
                    ans += secondchar;
                    // ab freq 0 ho chuki hai iss second waale char ki toh koi
                    // faayeda nai hai pq me push karna ka
                }

                // ab 1 char laga diya hai apan ne second biggest char ka, toh
                // ab vapas currchar laga sakte hai ab since count reset ho
                // chuka hai, yaha nai lagao, pq me push kardo sedhe next
                // iteration me apne aap lagega phir se

                // yaha bas currchar and uski freq laga do pq me vapas
                pq.push({currchar,freq});
            }
        }

        // ab we are here means ans jitna banna tha ban chuka hai, return krdo
        return ans;
    }
};