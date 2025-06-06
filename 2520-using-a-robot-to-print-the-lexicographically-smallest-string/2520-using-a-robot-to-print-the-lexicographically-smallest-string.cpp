class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        // smallest char to right wala array banao
        vector<char> rt(n);

        // since last char ke rt me koi smaller char nai h
        rt[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rt[i] = (char)(min(rt[i + 1], s[i]));
        }

        // rt[i]='a' means ki i th bande ke right me smallest char is 'a',
        // including i th char btw

        // stack banao for operations
        stack<char> st;
        string ans = "";

        // iterate over the string
        for (int i = 0; i < n; i++) {
            // current char ko stack me push kardo
            st.push(s[i]);

            // ab ye i th char hai apne paas, iske aage(i+1 to end) agar koi
            // smaller char hai toh usko pehle dalenge since we need
            // lexicographic smallest

            // now the smallest char frm i+1 to end is rt[i+1]

            // current char is at stack top

            // minm char nikalo to the right
            char minchar;
            if(i+1<n){
                // means min char will be
                minchar=rt[i+1];
            }
            else{
                // means we are at the end of the string, in such case right me koi char hai hi nai, toh min char will be curr char
                minchar=s[i];
            }


            while (!st.empty() && minchar >= st.top()) {
                // means ki right side par bigger char hai, ie current top ke
                // right side me saare characters curr top wale chars se bade
                // hai, toh chhote char ko apan string me add kar denge which is
                // at stack top, and bade char ko baad me add karenge, since we
                // need lexicographic smallest

                // toh stack top wale chhote char ko yehi par ans me daal dena
                // would be best since aage wale char sab bade bade hai, toh
                // chhota wala char pehle aayega toh string chhoti banegi

                // chhote char ko stack se nikal kar ans me daal denge, and do
                // so until right side wala(i+1 to end) char is smaller, in
                // which case apan pehle uss char ko add karenge

                char curr = st.top();
                st.pop();
                ans += curr;
            }
        }

        // ab jitne lexicographic order me lagne the char sab lag chuke hai

        // stack me jitne char h sab order me daal do aur kya
        while (!st.empty()) {
            char curr = st.top();
            st.pop();
            ans += curr;
        }

        return ans;
    }
};