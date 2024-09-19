class Solution {
public:
    vector<int> solve(string s) {
        vector<int> currans;

        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                // current expression(+,-,*) ke

                // left side ke values
                vector<int> left = solve(s.substr(0, i));
                // right side ke values
                vector<int> right = solve(s.substr(i + 1));

                // new we have like for 2*3-4*5, and i=3, ie expression is '-'
                // left side is (2*3)
                // right side is (4*5)
                // and overall we have (2*3)(expression)(4*5)

                // left side solve krke jo values aayi hai unko combine karo
                // right wali values se
                for(auto it1:left){
                    for(auto it2:right){
                        if(s[i]=='+'){
                            currans.push_back(it1+it2);
                        }
                        else if (s[i]=='-'){
                            currans.push_back(it1-it2);
                        }
                        else{
                            currans.push_back(it1*it2);

                        }
                    }
                }
            }
        }

        // if after that loop, currans is empty means string was smth like "12" or smth, in such case comvert the string to integer ans push to ans
        if(currans.empty()){
            auto curr=stoi(s);
            currans.push_back(curr);
        }

        return currans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans = solve(expression);

        return ans;
    }
};