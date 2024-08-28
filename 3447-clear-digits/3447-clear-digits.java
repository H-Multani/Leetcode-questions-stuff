class Solution {
    public String clearDigits(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                // number found, pop frm stack
                st.pop();
            } else {
                // push all non number characters
                st.push(s.charAt(i));
            }
        }

        // after all this all elements remaining present in stack
        // store all elements in a string and return as answer
        String ans = "";
        while (!st.isEmpty()) {
            ans = st.peek() + ans;
            st.pop();
        }

        return ans;
    }
}