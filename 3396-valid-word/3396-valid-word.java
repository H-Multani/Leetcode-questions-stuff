class Solution {
    public boolean isValid(String word) {
        int len=word.length();
        if(len<3) return false;
        boolean isvowel=false,isconsonant=false;
        for(int i=0;i<len;i++){
            char curr=word.charAt(i);

            if(curr=='#' || curr=='@' || curr=='$') return false;

            // matlab abhi tk special char nai mile hai

            // number hai kya??
            if(curr>='0' && curr<='9'){
                // number hai
            }
            // vowel hai kya??
            else if(curr=='a' ||curr=='e' ||curr=='i' || curr=='o' || curr=='u' ||curr=='A' ||curr=='E' || curr=='I' ||curr=='O' ||curr=='U'){
                // vowel hai
                isvowel=true;
            }
            else{
                // consonant hai only
                // if me number chk karaya->false, nai hai number
                // else if me vowel chk karaya->false, vowel nai hai
                // else me,consonant hi hoga
                isconsonant=true;
            }
        }

        if(isvowel && isconsonant) return true;

        return false;
    }
}