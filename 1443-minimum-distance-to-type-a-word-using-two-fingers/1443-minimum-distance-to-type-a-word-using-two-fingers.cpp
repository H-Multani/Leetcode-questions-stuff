class Solution {
public:
    unordered_map<char, pair<int, int>> mpp;
    vector<vector<vector<int>>> memo;
    long long solve(int i, string& s, char finger1, char finger2) {
        // agar idx range ke out hai toh return krdo yehi se
        if (i >= s.size())
            return 0;
        // minm return krna hai toh out of range k liye 0 return krdo since out
        // of range means puri string parse kar liye hai

        // we here means current character can be taken

        // agar memo me hai ans toh bhej do yehi se
        if (memo[i][finger1 - '@'][finger2 - '@'] != -1)
            return memo[i][finger1 - '@'][finger2 - '@'];

        // finger 1 se likho current character ko
        long long fin1 = 0;
        // finger 2 se likho current character ko
        long long fin2 = 0;

        // finger 1 explore karo

        // agar finger 1 hawa se start krra hai toh no cost added
        if (finger1 == '@') {
            // finger 1 ko current character me rakho and explore next idx
            fin1 = solve(i + 1, s, s[i], finger2);
        } else {
            // nai toh finger 1 ka coordinate nikalo
            auto [x1, y1] = mpp[finger1];
            auto [x2, y2] = mpp[s[i]];

            // ab current character and finger 1 jaha par hai dono ke beech ka
            // difference nikalo and aage explore karo

            // aage explore karte time yaad rakhna ki current character finger 1
            // me tha, finger2 as usual no change, and move to next idx in s

            fin1 = abs(x1 - x2) + abs(y1 - y2) + solve(i + 1, s, s[i], finger2);
        }

        // finger 2 explore karo

        // agar finger 2 hawa se start krra hai toh no cost added
        if (finger2 == '@') {
            // finger 2 ko current character me rakho and explore next idx
            fin2 = solve(i + 1, s, finger1, s[i]);
        } else {
            // nai toh finger 2 ka coordinate nikalo
            auto [x1, y1] = mpp[finger2];
            auto [x2, y2] = mpp[s[i]];

            // ab current character and finger 2 jaha par hai dono ke beech ka
            // difference nikalo and aage explore karo

            // aage explore karte time yaad rakhna ki current character finger 2
            // me tha, finger1 as usual no change, and move to next idx in s

            fin2 = abs(x1 - x2) + abs(y1 - y2) + solve(i + 1, s, finger1, s[i]);
        }

        // ab dono paths explore kar liye hai

        // dono me se jo bhi minm path hai bhej do as ans

        // return krne se pehle memo me update karna
        return memo[i][finger1 - '@'][finger2 - '@'] = min(fin1, fin2);
    }
    int minimumDistance(string word) {
        // simple DP, take nottake approach, ya finger 1 se type hoga current
        // item ya finger 2 se bana do solution

        // character ke location ke liye map me daal do , map se seedha seedha
        // access karenge
        char c = 'A';

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                mpp[c] = {i, j};

                // agar z tak ka mapping kar liye hai toh break frm here
                if (c == 'Z')
                    break;

                // next character par jao
                c++;
            }
        }

        // for(auto it:mpp){
        //     cout<<it.first<<" "<<it.second.first<<"
        //     "<<it.second.second<<endl;
        // }

        // initially we start from both fingers up, ie random character, and we
        // start from idx 0 of s

        // ab itna mereko bhi pata hai ki ye TLE de dega, toh 3 things change
        // here, idx i( maxm value n), then finger1 ka posn(maxm 27 positions,
        // 26 characters+placeholder char), finger2 ka posn(again maxm 27
        // positions)
        int n = word.size();
        memo.resize(n, vector<vector<int>>(27, vector<int>(27, -1)));

        // placeholder me apan specifically @ daalenge since @ ke baad ascii me
        // A,B... aata, toh order me chalta rahega and memo me dikkat nai aayegi
        return solve(0, word, '@', '@');
    }
};