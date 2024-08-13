class Solution {
    public boolean isPalindrome(String s) {
        // remove all special characters
        String snew="";

        // method 1
        for(int i=0;i<s.length();i++){
            int val=s.charAt(i); 
            // if (val>=65 && val<=90) || (val>=97 && val<=122) || (val>=48 && val<=57)
            if((val>=65 && val<=90) || (val>=97 && val<=122) || (val>=48 && val<=57)){
                // then add to string
                snew+=s.charAt(i);
            }
        }

        // method 2
        // str = str.replaceAll(
        //   "[^a-zA-Z0-9]", "");

        // method 3
        // for (int i = 0; i < str1.length(); i++) {
           
        //     boolean b1 = Character.isDigit(str1.charAt(i));
        //     boolean b2 = Character.isAlphabetic(str1.charAt(i));
           
        //     if (b1 || b2) {
        //         newstr += str1.substring(i, i + 1);
        //     }
        // }

        snew=snew.toLowerCase();
        int len=snew.length();
        for(int i=0;i<len;i++){
            if(snew.charAt(i)!=snew.charAt(len-i-1)) return false;
        }

        return true;


    }
}