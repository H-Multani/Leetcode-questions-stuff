class Solution {
    char logical_and(vector<char> values){
        bool ans=true;
        for(auto it:values){
            if(it=='f') ans=false;
        }

        if(ans) return 't';
        return 'f';
    }
    
    char logical_or(vector<char> values){
        bool ans=false;
        for(auto it:values){
            if(it=='t') ans=true;
        }

        if(ans) return 't';
        return 'f';
    }
    char logical_not(vector<char> values){
        if(values[0]=='t') return 'f';

        return 't';
    }

public:
    bool parseBoolExpr(string ex) {
        stack<char> st;

        // sab kuch push krenge, except ')'
        for (auto it : ex) {
            if (it != ')') {
                // push to stack
                st.push(it);
            } else {
                // means ) mila hai, exression ko evaluate karo
                // firstly saare beech ke t/f store kara lo kahi pr
                vector<char> t_or_f;

                // ab stack se pop karte jao tab tak jab tak iss current ')' ka
                // '(' naa mil jaaye
                // pop karte karte f/t ko vector me daal lena, since iss pr
                // operations karne honge
                while (!st.empty() && st.top() != '(') {
                    // current wala banda nikalo
                    char curr = st.top();
                    st.pop();

                    // ab current wala char agar comma hai toh kuch nai karna,
                    // since commas useless hai, apna kaam t/f wali values se
                    // hai bas, toh vahi store karenge vector me
                    if (curr != ',') {
                        t_or_f.push_back(curr);
                    }
                    // agar ',' mila hai, pop frm stack and move to next banda
                }
                // now we have stack ke top par '(', toh iske just pehle apne
                // paas char hai, ki inn sab t/f(in the vector) ka kya karna
                // hai, like &(t,f), bola ki t,f ka logical & karna hai, and so
                // on

                // toh sbse pehle stack pop karenge so that top par '(' na ho
                st.pop();
                // ab stack top par expression hai that is to be evaluated, ie
                // logical AND,OR,NOT etc
                char expression = st.top();
                // ab iss expression ko pop kar do stack se
                st.pop();

                // expression evaluate karne ke baad op kya aayega?, its wither
                // going to be T or a F, ek char me store kara lo bas
                char op;
                // now evaluate the expression
                if (expression == '&') {
                    // logical & nikalna hai
                    op = logical_and(t_or_f);
                } else if (expression == '|') {
                    // logical & nikalna hai
                    op = logical_or(t_or_f);
                } else {
                    // logical NOT nikalna hai
                    // not nikalne ke liye apan ko vector nai milega, not hota
                    // hai T or F ka, invert kar deta hai bs
                    op = logical_not(t_or_f);
                }

                // ab ye jo op mila hai, isko stack me store karva denge, so
                // that aage ka exression me ye wala op help kar paaye(incase
                // aage expressions hai agar)
                st.push(op);
                // bas ho gaya expression evaluate, aage badha do ab
            }
        }

        // ab agar sab kuch sahi chala hai, toh stack top par bas ek value hona
        // chahiye, ie T or F, utha lo aur uske hisaab se answer dedo
        if(st.top()=='t') return true;

        return false;
    }
};