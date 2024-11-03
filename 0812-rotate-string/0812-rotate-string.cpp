class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s=s+s;
        // cout<<s;
        size_t found=s.find(goal);

        

        if(found!=string::npos) return true;
        else return false;
    }
};