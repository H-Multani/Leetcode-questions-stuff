class Solution {
    public boolean isValid(String word) {
        char[] wordnew = word.toCharArray();
        
        boolean isvowel = false;
        boolean isconsonant = false;
        int charcnt=0;
        int len = wordnew.length;
        if(len<3) return false;
        
        for (int i = 0; i < len; i++) {

            if (wordnew[i] == '@' || wordnew[i] == '#' || wordnew[i] == '$') {
                return false;
            }
            else if (wordnew[i] <= '9' && wordnew[i] >= '0') {
                // isnumber = true;
            }
            else if (wordnew[i] == 'a' || wordnew[i] == 'e' || wordnew[i] == 'i' || wordnew[i] == 'o' || wordnew[i] == 'u'
                    || wordnew[i] == 'A' || wordnew[i] == 'E' || wordnew[i] == 'I' || wordnew[i] == 'O'
                    || wordnew[i] == 'U') {
                isvowel = true;
            }
            else isconsonant=true;
        }

        if(isvowel && isconsonant) return true;

        return false;

    }
}