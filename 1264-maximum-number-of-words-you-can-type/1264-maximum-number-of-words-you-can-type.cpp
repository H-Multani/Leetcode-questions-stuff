class Solution {
public:
    int canBeTypedWords(string text, string bl) {
        // words alag kardo
        text+=" ";

        vector<string> word;
        string temp="";
        for(auto it:text){
            if(it==' '){
                word.push_back(temp);
                temp="";
            }
            else temp+=it;
        }

        // set me daal do characters ko
        set<char> st;
        for(auto it:bl){
            st.insert(it);
        }

        int ans=0;
        for(auto it:word){

            bool count=true;
            for(auto ch:it){
                if(st.find(ch)!=st.end()){
                    count=false;
                    break;
                }
            }
            if(count) ans++;
        }

        return ans;
    }
};