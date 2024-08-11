class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String newword1="";
        String newword2="";

        for(String it:word1){
            newword1+=it;
        }
        for(String it:word2){
            newword2+=it;
        }

        return newword1.equals(newword2);
    }
}