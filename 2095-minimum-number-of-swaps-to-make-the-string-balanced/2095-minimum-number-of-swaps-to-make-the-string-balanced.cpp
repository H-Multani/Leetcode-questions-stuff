class Solution {
public:
    int minSwaps(string s) {
        // stack cnts the no of open brackets
        stack<char> st;
        for (auto it : s) {
            if (it == '[') {
                // means its an open bracket,iske aage iska close wala chahiye,
                // push to stack
                st.push(it);
            }
            // the else part runs means current char is a ']'
            else if (!st.empty()) {
                // if stack not empty means apan ke paas stack me '[' brackets
                // hai for the current ']' bracket, and hence both the '[' ']'
                // together make the brackets balanced, and we have to
                // ignore already balanced strings, so pop frm stack since stack
                // ke current wale top('[') ke liye apan ko closing bracket(']')
                // mil gaya hai, ie this brackets are valid, so no need to
                // consider them for swapping, hence pop frm the stack
                st.pop();
            }
        }

        // now in stack we have all the brackets jinko swap karke balance karna
        // hai
        int n = st.size();
        // itne n brackets ko swaps karke balance banana hai

        // one swap karne se apan ke 2 pair of brackets balanced ho jaenge
        // eg for ]][[,n=2 , after one swap at idx 0 and 3, we have [][], ie 1
        // swap se 2 pair of brackets become balanced, hence for n open brackets
        // we will need n/2 swaps to make all brackets balanced
        if(n%2==0) return n/2;

        // if n is odd, then we will need (n/2)+1, swaps,
        // eg for ]]]]][[[[[, here we have 5 open brackets, and all are
        // unbalanced, ie n=5
        // after 1 swap at idx 3 and 6, we have ]]][][][[[, (2 brackets became
        // balanced now), remaining n=3

        // after 2nd swap at idx 1 and 8, we have ][][][][][,(2 more brackets
        // bcame balanced, ie total 4 brackets are balanced now),remaining n=1

        // now for the rest 1 bracket to be balanced we need one last swap at
        // idx 0 and 9, after the swap we have [[][][][]],(1 more bracket became
        // balanced ), n=0 now, and no of ttl swaps =3
        // hence for n=5,7,3,..., odd values, we need (n/2)+1 swap
        return (n/2)+1;
    }
};