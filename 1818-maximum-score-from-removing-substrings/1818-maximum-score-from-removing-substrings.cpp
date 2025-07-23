class Solution {
public:
    int findaabb(string& s) {
        // simple stack leke iterate karo aur count karlo kitne baar 'ab' string
        // milegi apan ko

        // ek stack jo characters store karegi saare characters
        stack<char> st;

        // ek stack jo counting me kam aayega
        stack<char> temp;

        // ek boolean lelo jo bataega if current b can be taken
        bool canbetaken = false;
        int cnt = 0;

        for (auto it : s) {
            // agar current character a hai toh push kardo dono stacks me
            if (it == 'a') {
                st.push(it);
                temp.push(it);
                canbetaken=true;
                continue;
            } else if (it == 'b') {
                // means pop karna hai character stack se
                // agar stack se pop karna possible hai toh kardo pop
                if (canbetaken) {
                    // means peeche ek 'a' hai jiske liye apan ko current me 'b'
                    // mil gaya hai pop frm both stacks

                    // agar stack me banda hai to pop kardo
                    if (!temp.empty()) {
                        st.pop();
                        temp.pop();
                        cnt++;
                    }
                    // means nai le sakte curent wala b kisi ke sath bhi
                    else {
                        // in such case, st me push kardo
                        st.push(it);
                    }
                } else {
                    // we here means current wale 'b' ke liye apan peeche waale
                    // 'a' use nai kar sakte since consecutive nai hai, ie a and
                    // b ke beech me character hai ek which is causing problems

                    // in such case current wale b ko st me daal do
                    st.push(it);
                }
            } else {
                // we here means dusra character hai koi aur, st me daal do aur
                // temp clear kardo since ab temp me jitne 'a' the koi bhi b ke
                // sath pair nai bna payega since ek invalid character aa gaya
                // hai a and b ke beech me
                st.push(it);
                // temp.clear();
                temp=stack<char>();
            }
        }

        // ab st me jitne characters hai ye saare unused reh gaye, nikal kar string bana do
        string updated="";
        while(!st.empty()){
            updated.push_back(st.top());
            st.pop();
        }

        // updated string ulti aai hogi, reverse kardo
        reverse(updated.begin(),updated.end());

        // s ko update kardo
        s=updated;
        return cnt;
    }
    // same cheez but bbaa ke sath
    int findbbaa(string& s) {
        stack<char> st;
        stack<char> temp;
        bool canbetaken = false;
        int cnt = 0;

        for (auto it : s) {
            if (it == 'b') {
                st.push(it);
                temp.push(it);
                canbetaken=true;
                continue;
            } else if (it == 'a') {
                if (canbetaken) {
                    if (!temp.empty()) {
                        st.pop();
                        temp.pop();
                        cnt++;
                    }
                    else {
                        st.push(it);
                    }
                } else {
                    st.push(it);
                }
            } else {
                st.push(it);
                // temp.clear();
                temp=stack<char>();
            }
        }

        string updated="";
        while(!st.empty()){
            updated.push_back(st.top());
            st.pop();
        }

        reverse(updated.begin(),updated.end());

        s=updated;
        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        // same logic as before lekin 'aabb' nd 'bbaa' nikalne wale functions
        // boht complex lagre the simplify karo stack use karke

        int ans=0;
        if (x > y) {
            // means apan pehle 'ab' wale patterns nikalenge then 'ba' wale then
            // return the sum

            int abcnt = findaabb(s);
            cout<<s<<endl;
            int bacnt = findbbaa(s);

            ans = (abcnt * x) + (bacnt * y);
        } else {
            // pehle 'ba' wale pattern nikalenge then 'ab' wale
            int bacnt = findbbaa(s);
            int abcnt = findaabb(s);
            cout<<s<<endl;

            ans = (abcnt * x) + (bacnt * y);
        }

        return ans;
    }
};