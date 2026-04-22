class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {

        // simply iterate over the queries and indexes compare karate jao,
        // agae>2 indexes differ, move to next word in dictionary for possible
        // ans

        // now iterate over the queries make the ans
        vector<string> ans;

        for (auto curr : q) {

            // if curr="note" and d[i]="joke"-> thes differ in idx 0, since
            // curr[0]=n and d[i][0]=j, also differ in idx 2, toh isme 2 edit
            // karke bana sakte ans, in such case ans me include kar dena

            int n = curr.size();

            bool found = false;

            for (auto it : d) {

                if (found)
                    break;

                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (curr[i] != it[i]) {
                        cnt++;
                        if (cnt > 2)
                            break;
                    }
                }

                if(cnt<=2){
                    found=true;
                    break;
                }
            }

            if(found) ans.push_back(curr);
        }

        return ans;
    }
};