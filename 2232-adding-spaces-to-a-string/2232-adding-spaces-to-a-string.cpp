class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        // for spaces array
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && i==spaces[j]){
                // means iss index ke pehle space chahiye ans me

                // hence add space
                ans+=' ';

                // move to next index that requires space
                j++;
            }
            // add current character frm s
            ans+=s[i];
        }

        return ans;
    }
};