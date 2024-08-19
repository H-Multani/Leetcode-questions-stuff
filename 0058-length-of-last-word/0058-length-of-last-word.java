class Solution {
    public int lengthOfLastWord(String s) {
        ArrayList<Character> arr;
        ArrayList<Character> ans=new ArrayList<Character>();
        s=s.concat(" ");

        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' ') continue;

            arr=new ArrayList<Character>();

            while(s.charAt(i)!=' '){
                arr.add(s.charAt(i));
                i++;
            }

            ans=arr;
        }

        return ans.size();
    }
}