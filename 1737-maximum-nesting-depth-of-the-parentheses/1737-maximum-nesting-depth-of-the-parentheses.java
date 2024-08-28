class Solution {
    public int maxDepth(String s) {
        int ans=0;
        Stack<Character> st=new Stack<>();

        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                // push to stack
                st.push(s.charAt(i));
                // update maxm depth
                ans=Math.max(ans,st.size());
            }
            else{
                // ) found pop frm st since we moving out of a () parenthesis, else dont do anything
                if(s.charAt(i)==')') st.pop();
            }
        }

        return ans;
    }
}