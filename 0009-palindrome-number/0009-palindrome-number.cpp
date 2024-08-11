class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s=to_string(x);
        int length=s.size();
        for(int i=0;i<length/2;i++){
            if(s[i]!=s[length-1-i]) return false;
        }
        return true;
    }
};