class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        String xstring=Integer.toString(x);

        int len=xstring.length();
        for(int i=0;i<len;i++){
            if(xstring.charAt(i)!=xstring.charAt(len-i-1)) return false;
        }

        return true;
    }
}