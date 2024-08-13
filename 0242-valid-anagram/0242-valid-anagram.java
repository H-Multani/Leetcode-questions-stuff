class Solution {
    public boolean isAnagram(String s, String t) {
        char[] snew=s.toCharArray();
        char[] tnew=t.toCharArray();
        Arrays.sort(snew);
        Arrays.sort(tnew);


        return Arrays.equals(snew,tnew);
    }
}