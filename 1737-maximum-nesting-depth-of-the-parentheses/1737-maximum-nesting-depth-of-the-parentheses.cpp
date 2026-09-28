class Solution {
public:
    int maxDepth(string s) {
        // basically we have to return ki maxm nested me kitna jaa rahe hai in
        // the string eg (), we go inside 1 nest max 
        // eg (()), we go inside 2 nest max 
        // eg ((())), we go inside 3 nest max 
        // eg ((())+()), we go inside 3 nest max 
        // eg ((()-())+()), we go inside 3 nest max 
        // basically
        // maxm kitne brackets ke andar gaye apan while moving thru the list

        // loop thru the string
        // if encounter '(', we push it to a stack, and when ')' is encountered,
        // we pop it from the stack, coz that bracket has closed now, we arent
        // in that bracket anymore, so cant keep it in the stack
        // the stack size keeps track of how many brackets we are currently in,
        // ie how deep in the nested brackets are we

        // in each iteration, we update the maxm

        stack<char> st;

        int maxm = 0;

        for (auto i : s) {
            if (i == '(') {
                st.push(i);
            }
            if (i == ')') {
                st.pop();
            }
            int val=st.size();

            maxm=max(maxm,val);
        }

        return maxm;
    }
};