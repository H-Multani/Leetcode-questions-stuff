class Solution {
    public String removeStars(String s) {
        Stack<Character> st=new Stack<>();
        int len=s.length();

        for(int i=0;i<len;i++){
            if(s.charAt(i)=='*'){
                // digits mile hai
                // pop frm stack
                st.pop();
            }
            else{
                // character mile hai
                // push to stack
                st.push(s.charAt(i));
            }
        }

        // stack has all tge required chracters
        String ans="";
        while(!st.isEmpty()){
            // ans+=st.peek();
            ans =ans+st.peek();
            st.pop();
        }
        StringBuilder finalans=new StringBuilder();
        finalans.append(ans);

        finalans.reverse();

        return finalans.toString();

    }
}