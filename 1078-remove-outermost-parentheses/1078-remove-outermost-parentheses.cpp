class Solution {
public:
    string removeOuterParentheses(string s) {
        // loop kar lenge , since valid string hai meaning har opening ke baad
        // ek closing aayega hi valid wala

        // toh ek counter leke chal lenge , outer most wale ka opening bracket
        // will be at count=1 and similarly the closing bracket of the same
        // opening bracket will again be at cnt=1

        // like in eg1-> s="(()())(())", isme primitive decomposition accd to
        // question hoga
        // which is written like s=(()()) + (())
        // ye primitive strings hai since inko aur split nai kar sakte apan such
        // that parts are valid parenthesis strings

        // p1=(()()), is valid parenthesis string and isme se outermost bracket
        // alag karne hai so p1 becomes ()()

        // similarly p2 becomes () after removal

        // notice that agar count leke chalenge in original string toh

        // idx 0,5,6,9 par cnt=1 hoga, and notice how yehi wale brackets alag
        // karne hai, yehi karenge bass, loop chala denge

        // open bracket par cnt badha denge, close bracket par cnt decrease kar
        // denge and agar jiss idx par cnt becomes 1 meaning wo wala nai lena
        // hai apan ko ans me, baaki sab laga do

        // yaha ek edge case hai open bracket par cnt=1 hoga toh meaning vo
        // bracket ans me include nai karna hai

        // close bracket ke liye cnt=0 hone par vo bracket nai lena hai

        // this is because opening me +1 karre to cnt , toh cnt=1 meaning
        // outermost bracket hai dont consider in ans

        // and closing time -1 karre to cnt, toh cnt=0 meaning outermost bracket
        // se bahar aa chuke hai, tabhi toh cnt=0 ho chuka hai, ab next part
        // chalu hoga(p1 to p2 and so onn)

        // toh open bracket ke liye cnt=1 par nai include karna, and close
        // bracket ke liye cnt=0 par nai include karna

        string ans = "";
        int cnt = 0;
        int n = s.size();
        // iterate over the string
        for (int i = 0; i < n; i++) {
            // agar open bracket hai toh cnt badha do

            if (s[i] == '(') {

                cnt++;

                // agar cnt=1 hai means ye wala include nai krna hai
                if (cnt == 1)
                    continue;
            } else {
                // we here means close bracket hai cnt decrease kardo
                cnt--;

                // agar cnt=0 hai means ye wala include nai krna hai
                if (cnt == 0)
                    continue;
            }

            // we here means andar kahi hai include in ans
            ans.push_back(s[i]);
        }

        return ans;
    }
};