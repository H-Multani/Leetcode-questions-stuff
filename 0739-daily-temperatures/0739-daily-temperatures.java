class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st=new Stack<>();// stores indexes
        int[] ans=new int[temperatures.length];

        for(int i=0;i<temperatures.length;i++){
            while(!st.isEmpty() && temperatures[i]>temperatures[st.peek()]){
                // ans mil gaya
                // st.peek wale index ke liye
                ans[st.peek()]=i-st.peek();
                st.pop();
            }
            st.push(i);
        }
        // jo element nai mile hau, unke index st me hai
        while(!st.isEmpty()){
            ans[st.peek()]=0;
            st.pop();
        }
        return ans;

    }
}