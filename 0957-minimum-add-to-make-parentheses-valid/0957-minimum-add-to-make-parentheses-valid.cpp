class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st1;
        int opencnt=0;
        for(auto it:s){
            if(it=='('){
                st1.push(it);
            }
            else if(!st1.empty()){
                st1.pop();
            }
            else opencnt++;
        }

        return st1.size()+opencnt;
    }
};