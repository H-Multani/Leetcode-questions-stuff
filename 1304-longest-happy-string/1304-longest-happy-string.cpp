class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push(make_pair(a, 'a'));
        if (b > 0)
            pq.push(make_pair(b, 'b'));
        if (c > 0)
            pq.push(make_pair(c, 'c'));
        string s = "";
        while (true) {
            // if pq is empty, means saare char use kar chuke, in this case
            // break frm loop
            if (pq.empty())
                break;
            // break frm loop current maxm freq wala char nikalo
            pair<int, char> currmax = pq.top();
            pq.pop();
            // pop since this char is being used now
            if (s.size() >= 2 && s[s.size() - 1] == currmax.second &&
                s[s.size() - 2] == currmax.second) {
                // means current character nai daal skte , next max freq wala
                // char nikalo
                // agar pq khali ho gaya h, means aur koi char nai h remaining,
                // break frm loop, since ab kuch nai kr skte string banane ke
                // liye
                if (pq.empty())
                    break;

                pair<int, char> secondmax = pq.top();
                pq.pop();

                // iss se char nikal kar lagao ab

                // secondary char h na ye, toh 1 baar dalo bas, since ye currmax
                // wala ka freq zyada hai, usko isliye nai use kiya since abhi 2
                // baar laga chuke usko, toh ye secondmax buffer character types
                // rakh rahe, toh buffer ho sakta hai ki aage aur need pade
                // kabhi buffer char ki, hence isko 2 bar na dalenge, bas ek
                // baar dalenge, since ho sakta hai ki aage kabhi phir se ek
                // buffer char chahiye, and agar yaha 1 dala hota toh aage ek
                // char rehta apan ke pass reserve me, lekin agar 2 lagaenge toh
                // aage ke liye kuch buffer char nai rahega apne pass, leading
                // to small string, hence bas 1 baar add karo buffer char ko

                // wa wala testcase dekho for eg, waha 'b' apan ne start me 2 baar
                // daal diya, jisko agar 1 baar lagate toh badi string ban skti
                // thi, since vo 'b' baad me phir se buffer char banke use ho jata

                // char push kr diya
                s += secondmax.second;
                // freq -1 kr di, since we can only put current char limited
                // no of times,toh freq update kr di, ki how many more times
                // can we use this character
                secondmax.first--;

                // freq of current char agar 0 nai hui h toh vapas pq me push
                // kar do, since freq!=0 means this char can be used again
                if (secondmax.first > 0)
                    pq.push(secondmax);

                // and jo currmax wala char tha, that can now be used again push
                // back to pq
                pq.push(currmax);

            } else {
                // means current char daal skte h
                // daal do badhiya

                // kitne char dalne hai 1 or 2?
                int cnt = min(currmax.first, 2);
                // itne char laga do s me
                for (int i = 0; i < cnt; i++) {
                    // char push kr diya
                    s += currmax.second;
                    // freq -1 kr di, since we can only put current char limited
                    // no of times,toh freq update kr di, ki how many more times
                    // can we use this character
                    currmax.first--;
                }

                // freq of current char agar 0 nai hui h toh vapas pq me push
                // kar do, since freq!=0 means this char can be used again
                if (currmax.first > 0)
                    pq.push(currmax);
                // agar freq 0 ho gai h, means ab aur nai push kar sakte apan
                // current char ko, in such case dont push the current char back
                // to pq
                // cout<<"this"<<endl;
            }
            // cout<<" curr s is "<<s<<endl;
        }

        return s;
    }
};